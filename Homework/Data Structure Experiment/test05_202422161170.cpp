#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100;

template <class T> struct Stack {
    T stk[N];
    ll pos;
    Stack() : pos(-1) {}
    bool empty() { return pos == -1; }
    ll size() { return pos + 1; }
    void push(T x) { stk[++pos] = x; }
    T top() { return stk[pos]; }
    void pop() { pos--; }
};

int main() {
    string expr;
    cout << "Ver1\n";
    cout << "input\n";
    cin >> expr;
    cout << "output\n";
    Stack<char> op;
    Stack<ll> num;
    ll pri[256] = {};
    pri['+'] = pri['-'] = 1;
    pri['*'] = pri['/'] = 2;
    pri['('] = 3;
    expr = '$' + expr + '$';
    for (char c : expr) {
        if (isdigit(c)) {
            num.push(c - '0');
            continue;
        }
        while (pri[op.top()] >= pri[c] && num.size() >= 2) {
            ll b = num.top();
            num.pop();
            ll a = num.top();
            num.pop();
            if (op.top() == '+') {
                a += b;
            } else if (op.top() == '-') {
                a -= b;
            } else if (op.top() == '*') {
                a *= b;
            } else if (op.top() == '/') {
                a /= b;
            } else if (op.top() == '$') {
                num.push(a);
                num.push(b);
                op.pop();
                break;
            }
            num.push(a);
            op.pop();
        }
        if (c != ')') {
            if (c == '(') {
                op.push('$');
            } else {
                op.push(c);
            }
        }
    }
    cout << "=" << num.top() << "\n";
    cout << "end\n";
    system("pause");
    return 0;
}