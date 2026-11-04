#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>

void solve() {
    ll n, k;
    cin >> n >> k;
    ll a[n + 10];
    map<ll, ll> b;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    if (b.size() == n) {
        for (ll i = 1; i <= k; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    vector<ll> uns;
    for (ll i = 1; i <= n; i++) {
        if (b.count(i) == 0)
            uns.push_back(i);
    }
    if (uns.size() == 1) {
        ll t1, t2;
        for (auto [key,val]: b) {
            if (key != a[n]) {
                t1 = key;
                break;
            }
        }
        for (auto [key,val]: b) {
            if (key != t1) {
                t2 = key;
                break;
            }
        }
        uns.push_back(t1);
        uns.push_back(t2);
        for (ll i = 0; i <= k - 1; i++) {
            cout << uns[i % 3] << " ";
        }
        cout << endl;
        return;
    }
    if (uns.size() == 2) {
        ll t1;
        for (auto [key,val]: b) {
            if (key != a[n]) {
                t1 = key;
                break;
            }
        }
        uns.push_back(t1);
        for (ll i = 0; i <= k - 1; i++) {
            cout << uns[i % 3] << " ";
        }
        cout << endl;
        return;
    }
    if (uns.size() >= 3) {
        for (ll i = 0; i <= k - 1; i++) {
            cout << uns[i % 3] << " ";
        }
        cout << endl;
        return;
    }
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

/*
321142

122312
 */
