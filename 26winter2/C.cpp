#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n;
    cin >> n;
    // cout << endl;
    PII a[n + 10];
    ll index = 1, pos = -1, flag1 = 0, flag2 = 0;
    map<ll, ll> raw;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        raw[a[i].first]++;
        raw[a[i].second]++;
    }
    for (auto [k, v] : raw) {
        raw[k] = index;
        index += 2;
    }
    ll b[index + 10] = {};
    for (ll i = 1; i <= n; i++) {
        a[i].first = raw[a[i].first];
        a[i].second = raw[a[i].second];
        b[a[i].first] += 1;
        b[a[i].second + 1] -= 1;
        // cout << a[i].first << " " << a[i].second << endl;
    }
    // cout << endl;
    for (ll i = 1; i <= index; i++) {
        b[i] += b[i - 1];
        if (b[i] == 0) {
            pos = i;
            break;
        }
        // cout << b[i] << " ";
    }
    // cout << endl;
    if (pos == -1) {
        cout << -1 << endl;
        return;
    }
    ll ans[n + 10] = {};
    for (ll i = 1; i <= n; i++) {
        if (a[i].second < pos) {
            ans[i] = 1;
            flag1 = 1;
        } else if (a[i].first > pos) {
            ans[i] = 2;
            flag2 = 1;
        }
    }
    if (flag1 && flag2) {
        for (ll i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    cout << -1 << endl;
    return;
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
