#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 5e5 + 10, inf = 1e17;

ll n, f[N], ans = 0;

struct Trie {
    ll index = 0;
    struct Node {
        ll cnt = 0;
        ll son[30] = {};
    } node[N * 2];
    ll getid(char ch) { return ch - 'a'; }
    void insert(string s) {
        ll sons, root = 0, len = s.size();
        for (ll i = 0; i <= len - 1; i++) {
            sons = getid(s[i]);
            if (!node[root].son[sons])
                node[root].son[sons] = ++index;
            root = node[root].son[sons];
            node[root].cnt++;
            if (f[node[root].cnt] < i + 1) {
                ans = ans - (f[node[root].cnt] ^ node[root].cnt) +
                      ((i + 1) ^ node[root].cnt);
                f[node[root].cnt] = i + 1;
            }
        }
    }
} T;

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        string s;
        cin >> s;
        ans += i;
        T.insert(s);
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
