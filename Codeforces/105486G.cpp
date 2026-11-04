#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

set<ll> s;

void calc(ll x, ll y) {
    ll b[15];
    if (x < y)
        swap(x, y);
    b[1] = x, b[6] = y;
    b[4] = (b[1] ^ b[6]);
    b[3] = (b[1] ^ b[4]);
    b[5] = (b[4] ^ b[6]);
    b[2] = (b[1] & b[3]);
    b[7] = (b[2] ^ b[3]);
    b[8] = (b[3] & b[4]);
    b[9] = (b[3] | b[4]);
    b[10] = (b[4] & b[5]);
    for (ll i = 1; i <= 10; i++) {
        s.insert(b[i]);
        //cout << b[i] << " ";
    }
    //cout << endl;
}

void solve() {
    ll n;
    cin >> n;
    ll a[n + 10];
    s.insert(0);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        if (i >= 2)
            calc(a[i - 1], a[i]);
    }
    cout << s.size() << endl;
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

/*
10 10
10 00 10  same

0 1

10 01
10 11 01
10 11 10 01
10 11 00 01

101 010
101 111 010
101 111 101 010
101 111 000 010

101                 011
101         110     011 1^6=4
101     011 110 101 011 1^4=3 4^6=5
101 001 011 110 101 011 1&3=2
101 001 011 110 101 011 010 2^3=7
101 001 011 110 101 011 010     111 100 3|4=9 4&5=10

 */
