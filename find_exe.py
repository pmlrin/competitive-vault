#!/usr/bin/env python3
"""
find_exe.py —— 查找文件夹下的 .exe 文件，并可选择移入回收站（可恢复）

用法：
    python find_exe.py              # 只扫描当前目录
    python find_exe.py -r           # 递归扫描所有子目录
    python find_exe.py -d D:\\tools  # 指定扫描目录

删除方式：
    优先使用 send2trash 库（pip install send2trash）；
    Windows 上没有该库时自动调用系统 API SHFileOperationW，效果同样是进回收站。
"""

import argparse
import os
import sys


# ----------------------------- 工具函数 -----------------------------
def human_size(n: int) -> str:
    """把字节数格式化成易读形式"""
    size = float(n)
    for unit in ("B", "KB", "MB", "GB", "TB"):
        if size < 1024 or unit == "TB":
            return f"{size:.0f} {unit}" if unit == "B" else f"{size:.1f} {unit}"
        size /= 1024
    return f"{size:.1f} TB"


def move_to_recycle_bin(path: str) -> None:
    """把文件移入回收站（不直接永久删除）"""
    # 方案 1：跨平台的 send2trash
    try:
        from send2trash import send2trash

        send2trash(path)
        return
    except ImportError:
        pass

    # 方案 2：Windows 原生 API（无需安装任何库）
    if sys.platform == "win32":
        import ctypes
        from ctypes import wintypes

        class SHFILEOPSTRUCTW(ctypes.Structure):
            _fields_ = [
                ("hwnd", wintypes.HWND),
                ("wFunc", wintypes.UINT),
                ("pFrom", wintypes.LPCWSTR),
                ("pTo", wintypes.LPCWSTR),
                ("fFlags", ctypes.c_uint16),
                ("fAnyOperationsAborted", wintypes.BOOL),
                ("hNameMappings", ctypes.c_void_p),
                ("lpszProgressTitle", wintypes.LPCWSTR),
            ]

        FO_DELETE = 3
        FOF_ALLOWUNDO = 0x0040  # 关键：允许撤销 → 进回收站
        FOF_NOCONFIRMATION = 0x0010
        FOF_SILENT = 0x0004
        FOF_NOERRORUI = 0x0400

        op = SHFILEOPSTRUCTW()
        op.hwnd = None
        op.wFunc = FO_DELETE
        op.pFrom = path + "\0"  # ctypes 会自动补一个结尾 \0，形成双 \0 结尾
        op.pTo = None
        op.fFlags = FOF_ALLOWUNDO | FOF_NOCONFIRMATION | FOF_SILENT | FOF_NOERRORUI

        ret = ctypes.windll.shell32.SHFileOperationW(ctypes.byref(op))
        if ret != 0 or op.fAnyOperationsAborted:
            raise OSError(f"移入回收站失败（错误码 {ret}）")
        return

    raise RuntimeError("当前系统不支持移入回收站，请先 pip install send2trash")


def find_exe_files(base_dir: str, recursive: bool):
    """查找 .exe 文件（不区分大小写）"""
    result = []
    if recursive:
        for root, _dirs, names in os.walk(base_dir):
            for name in names:
                if name.lower().endswith(".exe"):
                    result.append(os.path.join(root, name))
    else:
        for name in os.listdir(base_dir):
            full = os.path.join(base_dir, name)
            if os.path.isfile(full) and name.lower().endswith(".exe"):
                result.append(full)
    result.sort(key=lambda p: p.lower())
    return result


def print_list(files, base_dir):
    """带编号打印文件列表"""
    for i, p in enumerate(files, 1):
        rel = os.path.relpath(p, base_dir)
        try:
            size = human_size(os.path.getsize(p))
        except OSError:
            size = "?"
        print(f"  [{i:>3}] {rel}    ({size})")


# ----------------------------- 主流程 -----------------------------
def main():
    parser = argparse.ArgumentParser(description="查找 .exe 文件并可选移入回收站")
    parser.add_argument("-r", "--recursive", action="store_true", help="递归扫描子目录")
    parser.add_argument("-d", "--dir", default=".", help="要扫描的目录，默认当前目录")
    args = parser.parse_args()

    base = os.path.abspath(args.dir)
    if not os.path.isdir(base):
        print(f"目录不存在：{base}")
        return 1

    files = find_exe_files(base, args.recursive)
    if not files:
        print(f"在 {base} 下没有找到 .exe 文件。")
        return 0

    print(f"在 {base} 下共找到 {len(files)} 个 .exe 文件：\n")
    print_list(files, base)
    print()

    while files:
        raw = input(
            "输入编号移入回收站（多个用空格/逗号分隔），all=全部，q=退出： "
        ).strip()

        if raw.lower() in ("q", "quit", "exit"):
            print("已退出，未删除任何文件。")
            return 0

        if raw.lower() == "all":
            indexes = list(range(len(files)))
        else:
            indexes = []
            bad = False
            for tok in raw.replace(",", " ").split():
                if not tok.isdigit() or not (1 <= int(tok) <= len(files)):
                    print(f"无效编号：{tok}\n")
                    bad = True
                    break
                indexes.append(int(tok) - 1)
            if bad or not indexes:
                if not raw:
                    print("输入不能为空。\n")
                continue

        targets = [files[i] for i in sorted(set(indexes))]

        print("\n即将移入回收站：")
        for p in targets:
            print("  -", os.path.relpath(p, base))

        if input(f"确认删除以上 {len(targets)} 个文件？(y/N): ").strip().lower() != "y":
            print("已取消。\n")
            continue

        for p in targets:
            rel = os.path.relpath(p, base)
            try:
                move_to_recycle_bin(p)
                print(f"[OK]   已移入回收站: {rel}")
                files.remove(p)
            except Exception as e:  # noqa: BLE001
                print(f"[FAIL] {rel} -> {e}")

        print()
        if files:
            print(f"剩余 {len(files)} 个 .exe 文件：\n")
            print_list(files, base)
            print()

    print("没有剩余文件，结束。")
    return 0


if __name__ == "__main__":
    sys.exit(main())
