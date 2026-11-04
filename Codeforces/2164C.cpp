#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

bool cmp(PII a, PII b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

void solve() {
    ll n, m;
    priority_queue<ll, vector<ll>, greater<ll> > sw1, sw2;
    vector<PII > mo1, mo2;
    cin >> n >> m;
    PII mo[m + 10];
    for (ll i = 1, a; i <= n; i++) {
        cin >> a;
        sw1.push(a);
    }
    for (ll i = 1; i <= m; i++) {
        cin >> mo[i].first;
    }
    for (ll i = 1; i <= m; i++) {
        cin >> mo[i].second;
    }
    for (ll i = 1; i <= m; i++) {
        if (mo[i].second == 0)
            mo2.push_back(mo[i]);
        else
            mo1.push_back(mo[i]);
    }
    sort(mo1.begin(), mo1.end(), cmp);
    sort(mo2.begin(), mo2.end(), cmp);

    ll ans = 0;
    for (auto [hp,val]: mo1) {
        while (!sw1.empty() && sw1.top() < hp) {
            sw2.push(sw1.top());
            sw1.pop();
        }
        if (sw1.empty()) {
            break;
        }
        val = max(val, sw1.top());
        sw1.pop();
        sw1.push(val);
        ans++;
    }
    while (!sw1.empty()) {
        sw2.push(sw1.top());
        sw1.pop();
    }
    for (auto [hp,val]: mo2) {
        while (!sw2.empty() && sw2.top() < hp) {
            sw2.pop();
        }
        if (sw2.empty()) {
            break;
        }
        sw2.pop();
        ans++;
    }
    cout << ans << endl;
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
