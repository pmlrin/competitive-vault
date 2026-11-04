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

priority_queue<PII, vector<PII >, CompareMin> fli;
priority_queue<ll, deque<ll>, greater<ll> > prt;

void solve() {
    ll n, m1, m2;
    cin >> n >> m1 >> m2;
    ll m12 = (m1 + m2) * 2;

    PII raw[m12 + 10], f1[m1 + 10], f2[m2 + 10];
    ll c1[N] = {}, c2[N] = {};
    for (ll i = 1; i <= m12; i++) {
        cin >> raw[i].first;
        raw[i].second = i;
    }
    auto cmp1 = [](PII a,PII b)-> bool { return a.first < b.first; };
    sort(raw + 1, raw + m12 + 1, cmp1);
    for (ll i = 1; i <= m12; i++) {
        raw[i].first = i;
    }
    auto cmp2 = [](PII a,PII b)-> bool { return a.second < b.second; };
    sort(raw + 1, raw + m12 + 1, cmp2);
    for (ll i = 1; i <= m1 * 2; i += 2) {
        f1[i / 2 + 1].first = raw[i].first;
        f1[i / 2 + 1].second = raw[i + 1].first;
    }
    for (ll i = 1; i <= m2 * 2; i += 2) {
        f2[i / 2 + 1].first = raw[m1 * 2 + i].first;
        f2[i / 2 + 1].second = raw[m1 * 2 + i + 1].first;
    }
    sort(f1 + 1, f1 + 1 + m1, cmp1);
    sort(f2 + 1, f2 + 1 + m2, cmp1);

    /*for (ll i = 1; i <= m1; i++) {
        cout << f1[i].first << " " << f1[i].second << endl;
    }
    for (ll i = 1; i <= m2; i++) {
        cout << f2[i].first << " " << f2[i].second << endl;
    }*/

    ll cur = 1;
    for (ll i = 1; i <= m1 + m2; i++)
        prt.push(i);

    for (ll i = 1; i <= m12; i++) {
        if (f1[cur].first == i && !prt.empty()) {
            c1[prt.top()]++;
            fli.push((PII){f1[cur].second, prt.top()});
            prt.pop();
            cur++;
        }
        if (!fli.empty() && fli.top().first == i) {
            prt.push(fli.top().second);
            fli.pop();
        }
    }

    cur = 1;
    for (ll i = 1; i <= m12; i++) {
        if (f2[cur].first == i && !prt.empty()) {
            c2[prt.top()]++;
            fli.push((PII){f2[cur].second, prt.top()});
            prt.pop();
            cur++;
        }
        if (!fli.empty() && fli.top().first == i) {
            prt.push(fli.top().second);
            fli.pop();
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
