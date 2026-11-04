#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

struct ChildProcess {
    HANDLE process = nullptr;
    HANDLE input = nullptr;
    HANDLE output = nullptr;

    ChildProcess() = default;
    ChildProcess(const ChildProcess &) = delete;
    ChildProcess &operator=(const ChildProcess &) = delete;

    ~ChildProcess() {
        if (process != nullptr) {
            if (WaitForSingleObject(process, 0) == WAIT_TIMEOUT)
                TerminateProcess(process, 1);
            CloseHandle(process);
        }
        if (input != nullptr)
            CloseHandle(input);
        if (output != nullptr)
            CloseHandle(output);
    }
};

static void writeLine(HANDLE pipe, const string &line) {
    string data = line + "\n";
    size_t written = 0;
    while (written < data.size()) {
        DWORD chunk = 0;
        DWORD remaining = static_cast<DWORD>(data.size() - written);
        if (!WriteFile(pipe, data.data() + written, remaining, &chunk,
                       nullptr) ||
            chunk == 0) {
            throw runtime_error("failed to write to a role process");
        }
        written += chunk;
    }
}

static string readLine(HANDLE pipe) {
    string line;
    char ch;
    while (true) {
        DWORD bytesRead = 0;
        if (!ReadFile(pipe, &ch, 1, &bytesRead, nullptr) || bytesRead == 0) {
            throw runtime_error("role process closed its output unexpectedly");
        }
        if (ch == '\n')
            break;
        if (ch != '\r')
            line.push_back(ch);
        if (line.size() > 4096)
            throw runtime_error("role output line is too long");
    }
    return line;
}

static void startChild(ChildProcess &child, const string &executable,
                       int role) {
    SECURITY_ATTRIBUTES security{sizeof(SECURITY_ATTRIBUTES), nullptr, TRUE};
    HANDLE childInputRead = nullptr;
    HANDLE parentInputWrite = nullptr;
    HANDLE parentOutputRead = nullptr;
    HANDLE childOutputWrite = nullptr;

    if (!CreatePipe(&childInputRead, &parentInputWrite, &security, 0) ||
        !SetHandleInformation(parentInputWrite, HANDLE_FLAG_INHERIT, 0) ||
        !CreatePipe(&parentOutputRead, &childOutputWrite, &security, 0) ||
        !SetHandleInformation(parentOutputRead, HANDLE_FLAG_INHERIT, 0)) {
        throw runtime_error("failed to create pipes");
    }

    STARTUPINFOA startup{};
    startup.cb = sizeof(startup);
    startup.dwFlags = STARTF_USESTDHANDLES;
    startup.hStdInput = childInputRead;
    startup.hStdOutput = childOutputWrite;
    startup.hStdError = GetStdHandle(STD_ERROR_HANDLE);

    PROCESS_INFORMATION info{};
    string command = "\"" + executable + "\" " + to_string(role);
    vector<char> commandLine(command.begin(), command.end());
    commandLine.push_back('\0');
    BOOL created = CreateProcessA(nullptr, commandLine.data(), nullptr, nullptr,
                                  TRUE, 0, nullptr, nullptr, &startup, &info);

    CloseHandle(childInputRead);
    CloseHandle(childOutputWrite);
    if (!created) {
        CloseHandle(parentInputWrite);
        CloseHandle(parentOutputRead);
        throw runtime_error(
            "failed to start E.exe; build it beside scheduler.exe first");
    }

    CloseHandle(info.hThread);
    child.process = info.hProcess;
    child.input = parentInputWrite;
    child.output = parentOutputRead;
}

static string siblingExecutablePath() {
    char path[MAX_PATH];
    DWORD length = GetModuleFileNameA(nullptr, path, MAX_PATH);
    if (length == 0 || length == MAX_PATH) {
        throw runtime_error("could not determine scheduler.exe path");
    }
    string result(path, length);
    size_t slash = result.find_last_of("\\/");
    result = slash == string::npos ? "" : result.substr(0, slash + 1);
    return result + "E.exe";
}

int main() {
    try {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        array<vector<long long>, 4> values;
        unordered_set<long long> seen;
        long long total = 0;
        for (int role = 0; role < 4; ++role) {
            long long count;
            if (!(cin >> count) || count < 0 || count > 100000) {
                throw runtime_error(
                    "expected four blocks: n followed by n array elements");
            }
            values[role].resize(static_cast<size_t>(count));
            for (long long &value : values[role]) {
                if (!(cin >> value))
                    throw runtime_error("missing array element");
                if (!seen.insert(value).second)
                    throw runtime_error(
                        "array elements must be globally distinct");
            }
            if (!is_sorted(values[role].begin(), values[role].end()) ||
                adjacent_find(values[role].begin(), values[role].end()) !=
                    values[role].end()) {
                throw runtime_error(
                    "each role's array must be strictly increasing");
            }
            total += count;
        }
        if (total % 2 == 0)
            throw runtime_error("the total number of elements must be odd");

        string executable = siblingExecutablePath();
        array<ChildProcess, 4> children;
        for (int role = 0; role < 4; ++role)
            startChild(children[role], executable, role);

        for (int role = 0; role < 4; ++role) {
            writeLine(children[role].input, to_string(values[role].size()));
            string row;
            for (size_t i = 0; i < values[role].size(); ++i) {
                if (i != 0)
                    row.push_back(' ');
                row += to_string(values[role][i]);
            }
            writeLine(children[role].input, row);
            writeLine(children[role].input, to_string(total));
        }

        while (true) {
            istringstream request(readLine(children[0].output));
            char operation;
            long long argument;
            if (!(request >> operation >> argument))
                throw runtime_error("malformed message from role 0");

            if (operation == '?') {
                string query = "? " + to_string(argument);
                for (ChildProcess &child : children)
                    writeLine(child.input, query);

                long long sum = 0;
                for (ChildProcess &child : children) {
                    istringstream response(readLine(child.output));
                    long long count;
                    if (!(response >> count) || count < 0)
                        throw runtime_error("invalid count from a role");
                    sum += count;
                }
                writeLine(children[0].input, to_string(sum));
            } else if (operation == '!') {
                string answer = "! " + to_string(argument);
                for (ChildProcess &child : children)
                    writeLine(child.input, answer);

                for (ChildProcess &child : children) {
                    istringstream response(readLine(child.output));
                    long long reported;
                    if (!(response >> reported) || reported != argument) {
                        throw runtime_error(
                            "roles disagreed on the final answer");
                    }
                }
                cout << argument << '\n';
                return 0;
            } else {
                throw runtime_error("unknown message from role 0");
            }
        }
    } catch (const exception &error) {
        cerr << "scheduler: " << error.what() << '\n';
        return 1;
    }
}