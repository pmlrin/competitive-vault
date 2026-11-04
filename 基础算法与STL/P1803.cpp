#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>

bool cmp(const PII &a, const PII &b) { return a.second < b.second; }

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<PII> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0, R = -1; i < n; i++) {
        while (a[i].first < R && i < n) {
            i++;
        }
        if (i >= n) {
            break;
        }
        ans++;
        R = a[i].second;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}