#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define PII pair<ll, ll>
const ll N = 10000 + 10, M = 19000000 + 10;

ll n, p1 = 0, p2 = 0, p3 = 0, ans[N];
vector<ll> prime;
bitset<M> b;

void eular(ll m) {
    b[1] = true;
    for (ll i = 2; i <= m; i++) {
        if (b[i] == false)
            prime.push_back(i);
        for (auto p: prime) {
            if (i * p > m)
                break;
            b[i * p] = true;
            if (i % p == 0)
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    if (n == 1) {
        cout << "-1" << endl;
        return 0;
    }
    if (n == 2) {
        cout << "1 1" << endl;
        return 0;
    }
    eular(M - 10);
    ll sum = n * (n + 1) / 2;
    for (auto i: prime) {
        if (sum - i <= 1)
            break;
        if (b[sum - i] == false) {
            p1 = i, p2 = sum - i;
            break;
        }
    }
    if (p1 + p2 == sum) {
        for (ll i = n; i >= 1; i--) {
            if (p1 - i >= 0) {
                p1 -= i;
                ans[i] = 1;
            }
        }
        for (ll i = 1; i <= n; i++) {
            if (ans[i] == 0)
                cout << "1 ";
            else
                cout << "2 ";
        }
    } else {
        for (ll i = 0; i <= 6000; i++) {
            ll flag = 0;
            for (ll j = 0; j <= 6000; j++) {
                if (sum - prime[i] - prime[j] <= 1)
                    break;
                if (b[sum - prime[i] - prime[j]] == false) {
                    p1 = prime[i], p2 = prime[j], p3 = sum - prime[i] - prime[j];
                    if (p1 != p2) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1)
                break;
        }
        for (ll i = 1; i <= n; i++) {
            if (i == p2)
                cout << "3 ";
            else if (i == p1)
                cout << "2 ";
            else
                cout << "1 ";
        }
        //
    }
    cout << endl;
    return 0;
}
// 101
