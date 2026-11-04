#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll a[n + 10], sum = 0, ans = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (ll i = 1; i + k - 1 <= n; i++) {
        ll tmp = 0, sumt = 0;
        for (ll j = i; j <= i + k - 1; j++) {
            tmp = max(tmp, a[j]);
            sumt += a[j];
        }
        ans = max(ans, sum - sumt + k * tmp);
    }
    cout << ans << endl;
}

void solve2() {
    ll n, k;
    cin >> n >> k;
    ll a[n + 10], sum = 0, ans = 0, sumt = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    deque<PII> q;
    for (ll i = 1; i <= k; i++) {
        while (!q.empty() && q.back().second < a[i]) {
            q.pop_back();
        }
        q.push_back({i, a[i]});
        sumt += a[i];
    }
    ans = sum - sumt + k * q.front().second;
    for (ll i = k + 1; i <= n; i++) {
        while (!q.empty() && q.front().first < i - k + 1) {
            q.pop_front();
        }
        sumt -= a[i - k];
        while (!q.empty() && q.back().second < a[i]) {
            q.pop_back();
        }
        q.push_back({i, a[i]});
        sumt += a[i];
        ans = max(ans, sum - sumt + k * q.front().second);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    // T = 1;
    cin >> T;
    while (T--) {
        solve2();
    }
    return 0;
}
