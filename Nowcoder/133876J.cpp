#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

PII c[10][10], juda[60][7], judb[60][7];

bool cmp(PII a, PII b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second > b.second;
}

void check(const PII x[], PII ret[]) {
    PII a[6];
    for (ll i = 1; i <= 5; i++) {
        a[i] = x[i];
        if (a[i].second == 1) {
            a[i].second = 14;
        }
    }
    sort(a + 1, a + 6, cmp);
    map<ll, ll> card, color;
    for (ll i = 1; i <= 5; i++) {
        card[a[i].second]++;
        color[a[i].first]++;
    }
    ll len = 0;
    ret[0] = {0, 999};
    for (auto i : card) {
        ret[++len] = i;
    }
    sort(ret + 1, ret + 1 + len, cmp);
    if (color.size() == 1 && card.count(14) && card.count(13) &&
        card.count(12) && card.count(11) && card.count(10)) {
        ret[0].first = 10;
        return;
    }
    if (color.size() == 1 && card.size() == 5) {
        ll flag = 1;
        for (ll i = 1; i <= 4; i++) {
            if (a[i].second != a[i + 1].second + 1) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            ret[0].first = 9;
            return;
        }
        if ((card.count(14) && card.count(2) && card.count(3) &&
             card.count(4) && card.count(5))) {
            ret[0] = {9, 999};
            for (ll i = 5; i >= 1; i--) {
                ret[6 - i] = {i, 1};
            }
            return;
        }
    }
    if (card.size() == 2 && ret[1].second == 4) {
        ret[0].first = 8;
        return;
    }
    if (card.size() == 2 && ret[1].second == 3) {
        ret[0].first = 7;
        return;
    }
    if (card.size() == 5 && color.size() == 1) {
        ret[0].first = 6;
        return;
    }
    if (card.size() == 5) {
        ll flag = 1;
        for (ll i = 1; i <= 4; i++) {
            if (a[i].second != a[i + 1].second + 1) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            ret[0].first = 5;
            return;
        }
        if ((card.count(14) && card.count(2) && card.count(3) &&
             card.count(4) && card.count(5))) {
            ret[0] = {5, 999};
            for (ll i = 5; i >= 1; i--) {
                ret[6 - i] = {i, 1};
            }
            return;
        }
    }
    if (card.size() == 3 && ret[1].second == 3) {
        ret[0].first = 4;
        return;
    }
    if (card.size() == 3 && ret[1].second == 2) {
        ret[0].first = 3;
        return;
    }
    if (card.size() == 4 && ret[1].second == 2) {
        ret[0].first = 2;
        return;
    }
    ret[0].first = 1;
    return;
}

void solve() {
    string t;
    ll b[60] = {};
    memset(juda, 0, sizeof(juda));
    memset(judb, 0, sizeof(judb));
    for (ll i = 1; i <= 2; i++) {
        for (ll j = 1; j <= 4; j++) {
            cin >> t;
            if (t[1] == 'C') {
                c[i][j].first = 1;
            } else if (t[1] == 'D') {
                c[i][j].first = 2;
            } else if (t[1] == 'H') {
                c[i][j].first = 3;
            } else {
                c[i][j].first = 4;
            }
            if (t[0] == 'A') {
                c[i][j].second = 1;
            } else if (t[0] == 'T') {
                c[i][j].second = 10;
            } else if (t[0] == 'J') {
                c[i][j].second = 11;
            } else if (t[0] == 'Q') {
                c[i][j].second = 12;
            } else if (t[0] == 'K') {
                c[i][j].second = 13;
            } else {
                c[i][j].second = t[0] - '0';
            }
            b[c[i][j].first - 1 + (c[i][j].second - 1) * 4]++;
        }
    }

    for (ll i = 0; i <= 51; i++) {
        if (b[i]) {
            continue;
        }
        c[1][5].first = i % 4 + 1;
        c[1][5].second = i / 4 + 1;
        check(c[1], juda[i]);
    }
    for (ll i = 0; i <= 51; i++) {
        if (b[i]) {
            continue;
        }
        c[2][5].first = i % 4 + 1;
        c[2][5].second = i / 4 + 1;
        check(c[2], judb[i]);
    }

    ll jud = 1;
    for (ll i = 0; i <= 51; i++) {
        if (b[i]) {
            continue;
        }
        b[i] = 1;
        ll res = -1;
        for (ll j = 0; j <= 51; j++) {
            if (b[j]) {
                continue;
            }
            for (ll k = 0; k <= 5; k++) {
                if (juda[j][k].first > judb[i][k].first) {
                    res = max(res, 1ll);
                    break;
                } else if (juda[j][k].first < judb[i][k].first) {
                    res = max(res, -1ll);
                    break;
                }
                if (k == 5) {
                    res = max(res, 0ll);
                    break;
                }
            }
        }
        b[i] = 0;
        jud = min(jud, res);
    }

    if (jud == 1) {
        cout << "WoYaoYanPai" << endl;
    } else if (jud == 0) {
        cout << "PaiMeiYouWenTi" << endl;
    } else {
        cout << "GeiWoCaPiXie" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
