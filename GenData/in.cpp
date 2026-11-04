/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

mt19937 seed(time(0));

void solve() {
    mt19937 rnd(seed());
    ll n = rnd() % 10 + 1;
    cout << n << endl;
    for (ll i = 1; i <= n; i++) {
        cout << rnd() % 500 << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1e5;
    cout << T << endl;
    while (T--) {
        solve();
    }
    return 0;
}*/
#include <cctype>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <vector>

int main() {
    // ---------- 正确数据（25个）----------
    const std::string base = "xuewuzhijingqiyouhaoran";
    std::set<std::string> correctSet;
    // 手动加入原始形式，保证包含
    correctSet.insert("XueWuZhiJingQiYouHaoRan");

    // 随机生成 25 个不同的大小写变体
    std::mt19937 rng(42); // 固定种子，可复现
    std::uniform_int_distribution<int> coin(0, 1);
    while (correctSet.size() < 25) {
        std::string variant;
        for (char c : base) {
            variant.push_back(coin(rng) ? std::toupper(c) : c);
        }
        correctSet.insert(variant);
    }
    std::vector<std::string> correctVec(correctSet.begin(), correctSet.end());

    // ---------- 错误数据（25个）----------
    const std::string motto = "XueWuZhiJingQiYouHaoRan";

    // 超长字符串（长度2000和1999）
    std::string long2000 = motto;
    while (long2000.size() < 2000)
        long2000 += "XueWuZhiJing";
    long2000.resize(2000);

    std::string long1999 = "QiYouHaoRan";
    while (long1999.size() < 1999)
        long1999 += "QiYouHaoRan";
    long1999.resize(1999);

    std::vector<std::string> wrongVec = {
        // 超短（1~3）
        "X",   // 长度 1
        "Xu",  // 长度 2
        "Xue", // 长度 3
        // 缺末尾字符
        "XueWuZhiJingQiYouHaoRa", // 少 'n'
        // 尾部添加可见字符
        "XueWuZhiJingQiYouHaoRan!", // 尾部叹号
        "XueWuZhiJingQiYouHaoRanA", // 尾部多字母
        // 头部缺失
        "ueWuZhiJingQiYouHaoRan", // 缺少首字母 'X'
        // 中间插入标点
        "XueWuZhiJing.QiYouHaoRan", // 中间点
        "XueWuZhiJing-QiYouHaoRan", // 中间连字符
        "XueWuZhiJing_QiYouHaoRan", // 中间下划线
        // 拼音拼写错误
        "XueWuZhiJingQiYouHaoRang", // Ran -> Rang
        "XueWuZhiJingQiYouHaoLan",  // Ran -> Lan
        "XueWuZhiJinQiYouHaoRan",   // Jing -> Jin
        "XueWuZhiJingQiYuoHaoRan",  // You -> Yuo
        // 包含校训子串但前后有其他内容
        "XueWuZhiJingQiYouHaoRanXueWu", // 校训前缀再连部分
        "HelloXueWuZhiJingQiYouHaoRan", // 前面加单词
        // 字符全部相同但顺序重排（忽略大小写后不等）
        "XueWuZhiJingHaoRanQiYou",
        // 字母数字混合
        "XueWu123ZhiJing",
        // 无关字符串
        "ShanDongDaXue",
        // 单独的子串
        "XueWuZhiJing", // 前半句
        "QiYouHaoRan",  // 后半句
        // 长度与校训相同但末尾为数字
        "XueWuZhiJingQiYouHaoRa1",
        // 尾部多一个数字
        "XueWuZhiJingQiYouHaoRan2",
        // 超长字符串
        long2000, // 长度 2000
        long1999  // 长度 1999
    };

    // ---------- 输出到文件 1.in ~ 50.in ----------
    int fileId = 1;
    auto writeFile = [&](const std::string &content) {
        std::ofstream out(std::to_string(fileId) + ".in");
        out << content << '\n';
        ++fileId;
    };

    for (const auto &s : correctVec)
        writeFile(s);
    for (const auto &s : wrongVec)
        writeFile(s);

    return 0;
}