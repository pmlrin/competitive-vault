#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 10, L = 18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> greaterStack, smallerStack;
    vector<int> suffixMinima, suffixMaxima;
    long long answer = n;

    for (int right = 1; right <= n; right++) {
        int added = right - 1;
        if (added > 0) {
            while (!suffixMinima.empty() &&
                   a[suffixMinima.back()] >= a[added]) {
                suffixMinima.pop_back();
            }
            suffixMinima.push_back(added);

            while (!suffixMaxima.empty() &&
                   a[suffixMaxima.back()] <= a[added]) {
                suffixMaxima.pop_back();
            }
            suffixMaxima.push_back(added);
        }

        while (!greaterStack.empty() && a[greaterStack.back()] < a[right]) {
            greaterStack.pop_back();
        }
        int previousGreater = greaterStack.empty() ? 0 : greaterStack.back();

        while (!smallerStack.empty() && a[smallerStack.back()] > a[right]) {
            smallerStack.pop_back();
        }
        int previousSmaller = smallerStack.empty() ? 0 : smallerStack.back();

        answer += suffixMinima.end() - upper_bound(suffixMinima.begin(),
                                                   suffixMinima.end(),
                                                   previousGreater);
        answer += suffixMaxima.end() - upper_bound(suffixMaxima.begin(),
                                                   suffixMaxima.end(),
                                                   previousSmaller);

        greaterStack.push_back(right);
        smallerStack.push_back(right);
    }

    cout << answer << '\n';
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
