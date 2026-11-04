#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

void solve() {
    ll x, y;
    cin >> x >> y;
    if (x == 0 || y == 0) {
        cout << x << " " << y << endl;
        return;
    }
    vector<ll> rp, rq, bp, bq;
    rp.push_back(0);
    rq.push_back(0);
    ll t = x;
    while (t) {
        rp.push_back(t % 2);
        t /= 2;
    }
    t = y;
    while (t) {
        rq.push_back(t % 2);
        t /= 2;
    }
    ll len = max(rp.size(), rq.size()) + 1;
    if (rp.size() < len) {
        for (ll i = rp.size(); i <= len; i++)
            rp.push_back(0);
    }
    if (rq.size() < len) {
        for (ll i = rq.size(); i <= len; i++)
            rq.push_back(0);
    }
    len--;


    ll p, q, ans;
    ll tp = 0, tq = 0, tans, flag = 0;
    bp = rp, bq = rq;

    for (ll i = len; i >= 1; i--) {
        if (bp[i] == 1 && bq[i] == 1) {
            bp[i] = 0;
            flag = 1;
        }
        if (bp[i] == 0 && bq[i] == 0 && flag) {
            bp[i] = 1;
        }
        tp += (bp[i] << (i - 1));
        tq += (bq[i] << (i - 1));
    }

    tans = abs(x - tp) + abs(y - tq);
    p = tp, q = tq, ans = tans;
    tp = 0, tq = 0;
    bp = rp, bq = rq;

    flag = 0;
    for (ll i = len; i >= 1; i--) {
        if (bp[i] == 1 && bq[i] == 1) {
            bq[i] = 0;
            flag = 1;
        }
        if (bp[i] == 0 && bq[i] == 0 && flag) {
            bq[i] = 1;
        }
        tp += (bp[i] << (i - 1));
        tq += (bq[i] << (i - 1));
    }

    tans = abs(x - tp) + abs(y - tq);
    if (tans < ans) {
        p = tp, q = tq, ans = tans;
    }
    tp = 0, tq = 0;
    bp = rp, bq = rq;

    flag = 0;
    for (ll i = len; i >= 1; i--) {
        if (bq[i] == 0) {
            tans = abs(x - tp - (1ll << (i - 1)));
            if (tans < ans) {
                p = tp + (1ll << (i - 1)), q = y, ans = tans;
            }
        }
        if (bp[i] == 1 && bq[i] == 1)
            break;
        tp += (bp[i] << (i - 1));
        tq += (bq[i] << (i - 1));
    }

    tp = 0, tq = 0;
    bp = rp, bq = rq;

    flag = 0;
    for (ll i = len; i >= 1; i--) {
        if (bp[i] == 0) {
            tans = abs(y - tq - (1ll << (i - 1)));
            if (tans < ans) {
                p = x, q = tq + (1ll << (i - 1)), ans = tans;
            }
        }
        if (bp[i] == 1 && bq[i] == 1)
            break;
        tp += (bp[i] << (i - 1));
        tq += (bq[i] << (i - 1));
    }

    cout << p << " " << q << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    //T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}


/*
3
127 24
2 11
2 23

127 1111111
24  0011000

2  00010 00010
11 01011 01100
23 10111 11000
 */
