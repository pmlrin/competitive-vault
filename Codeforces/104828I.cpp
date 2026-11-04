#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

void dfs(ll curx, ll cury, ll step) {
    if (step >= 60) {
        if (curx == 0)
            curx = (1ll << 60);
        if (cury == 0)
            cury = (1ll << 60);
        cout << "! " << curx - 1 << " " << cury - 1 << endl;
        return;
    }
    ll div = (1ll << step);
    ll adda = div - curx, addb = div - cury;
    ll ans00 = 1, ans01 = 1, ans10 = 1, judx, judy;
    cout << "? " << adda + 1 << " " << addb + 1 << endl;
    cin >> ans00;
    if (ans00 % div != 0)
        ans00 = div;
    ans00 /= div;
    if (addb + div + 1 < (1ll << 61)) {
        cout << "? " << adda + 1 << " " << addb + div + 1 << endl;
        cin >> ans01;
        if (ans01 % div != 0)
            ans01 = div;
        ans01 /= div;
    }
    if (adda + div + 1 < (1ll << 61)) {
        cout << "? " << adda + div + 1 << " " << addb + 1 << endl;
        cin >> ans10;
        if (ans10 % div != 0)
            ans10 = div;
        ans10 /= div;
    }
    if (ans00 % 2 == 0) {
        judx = 1;
        judy = 1;
    } else if (ans01 % 2 == 0) {
        judx = 1;
        judy = 0;
    } else if (ans10 % 2 == 0) {
        judx = 0;
        judy = 1;
    } else {
        judx = 0;
        judy = 0;
    }
    curx += (judx << step);
    cury += (judy << step);
    dfs(curx, cury, step + 1);
}

void solve() {
    ll ans00, ans01, ans10;
    cout << "? 1 1" << endl;
    cin >> ans00;
    cout << "? 1 2" << endl;
    cin >> ans01;
    cout << "? 2 1" << endl;
    cin >> ans10;
    if (ans00 % 2 == 0)
        dfs(0, 0, 1);
    else if (ans01 % 2 == 0)
        dfs(0, 1, 1);
    else if (ans10 % 2 == 0)
        dfs(1, 0, 1);
    else
        dfs(1, 1, 1);
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
12 7

 */
