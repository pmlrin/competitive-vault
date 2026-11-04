#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

ll n;
string s;

void solve() {
    cin >> n >> s;
    ll cnt = 0;
    vector<ll> ans;
    for (ll i = 0; i <= s.size() - 1; i++) {
        if (s[i] == '0') {
            cnt++;
            ans.push_back(i + 1);
        }
    }
    cout << cnt << endl;
    for (auto i: ans)
        cout << i << " ";
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
