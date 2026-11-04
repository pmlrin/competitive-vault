#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 1e5 + 10;

struct CompareMin {
    bool operator()(const PII &a, const PII &b) const {
        return a.first > b.first;
    }
};

void solve() {
    ll n, m1, m2;
    cin >> n >> m1 >> m2;
    PII f1[m1 + 10], f2[m2 + 10];
    ll c1[N] = {}, c2[N] = {};
    priority_queue<PII, vector<PII >, CompareMin> fli;
    priority_queue<ll, deque<ll>, greater<ll> > prt;
    for (ll i = 1; i <= m1; i++) {
        cin >> f1[i].first >> f1[i].second;
    }
    for (ll i = 1; i <= m2; i++) {
        cin >> f2[i].first >> f2[i].second;
    }
    auto cmp = [](PII a,PII b)-> bool { return a.first < b.first; };
    sort(f1 + 1, f1 + 1 + m1, cmp);
    sort(f2 + 1, f2 + 1 + m2, cmp);

    for (ll i = 1; i <= m1 + m2; i++) {
        prt.push(i);
    }

    for (ll i = 1; i <= m1; i++) {
        while (!fli.empty() && fli.top().first < f1[i].first) {
            prt.push(fli.top().second);
            fli.pop();
        }
        if (!prt.empty()) {
            c1[prt.top()]++;
            fli.push((PII){f1[i].second, prt.top()});
            prt.pop();
        }
    }

    while (!prt.empty()) {
        prt.pop();
    }
    while (!fli.empty()) {
        fli.pop();
    }
    for (ll i = 1; i <= m1 + m2; i++) {
        prt.push(i);
    }

    for (ll i = 1; i <= m2; i++) {
        while (!fli.empty() && fli.top().first < f2[i].first) {
            prt.push(fli.top().second);
            fli.pop();
        }
        if (!prt.empty()) {
            c2[prt.top()]++;
            fli.push((PII){f2[i].second, prt.top()});
            prt.pop();
        }
    }

    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        c1[i] += c1[i - 1];
    }
    for (ll i = 1; i <= n; i++) {
        c2[i] += c2[i - 1];
    }
    for (ll i = 0; i <= n; i++) {
        ans = max(ans, c1[i] + c2[n - i]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
