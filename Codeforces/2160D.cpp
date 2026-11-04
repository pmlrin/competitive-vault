#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 300 + 10;

ll n, ans[N * 2];
vector<ll> qu, unk;

void solve() {
    cin >> n;
    qu.clear();
    unk.clear();
    for (ll i = 1; i <= n * 2; i++)
        ans[i] = 0;
    for (ll i = 1, k, rec; i <= n * 2; i++) {
        qu.push_back(i);
        k = qu.size();
        cout << "? " << k << " ";
        for (auto j: qu) {
            cout << j << " ";
        }
        cout << endl;
        cin >> rec;
        if (rec != 0) {
            ans[i] = rec;
            qu.pop_back();
        } else {
            unk.push_back(i);
        }
    }
    qu.clear();
    for (ll i = 1; i <= n * 2; i++) {
        if (ans[i])
            qu.push_back(i);
    }
    for (auto i: unk) {
        qu.push_back(i);
        ll k = qu.size(), rec;
        cout << "? " << k << " ";
        for (auto j: qu) {
            cout << j << " ";
        }
        cout << endl;
        cin >> rec;
        ans[i] = rec;
        qu.pop_back();
    }
    cout << "! ";
    for (ll i = 1; i <= n * 2; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
