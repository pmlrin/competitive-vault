#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50;
const ll BA = 1, BC = 2, CB = 3, CA = 4, CABA = 5, BACA = 6;

ll n, q, num[10];
string s;
vector<ll> opt[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        char x, y;
        ll lba, lbc, lcb, lca, iba = 1, ibc = 1, icb = 1, ica = 1;
        cin >> n >> q >> s;
        s = ' ' + s;
        for (ll i = 1; i <= 4; i++) {
            opt[i].clear();
            opt[i].push_back(0);
        }
        num[BA] = num[CA] = num[CB] = num[CABA] = num[BACA] = 0;
        for (ll i = 1; i <= q; i++) {
            cin >> x >> y;
            if (x == 'b' && y == 'a')
                opt[BA].push_back(i);
            if (x == 'b' && y == 'c')
                opt[BC].push_back(i);
            if (x == 'c' && y == 'b')
                opt[CB].push_back(i);
            if (x == 'c' && y == 'a')
                opt[CA].push_back(i);
        }
        lba = opt[BA].size() - 1;
        lbc = opt[BC].size() - 1;
        lcb = opt[CB].size() - 1;
        lca = opt[CA].size() - 1;

        while (ibc <= lbc && ica <= lca) {
            while (ibc <= lbc && ica <= lca && opt[BC][ibc] > opt[CA][ica]) {
                ica++;
            }
            if (ibc > lbc || ica > lca)
                break;
            opt[BC][ibc] = opt[CA][ica] = 0;
            num[CABA]++;
            ibc++, ica++;
        }
        //cout << num[CBA] << endl;
        while (icb <= lcb && iba <= lba) {
            while (icb <= lcb && iba <= lba && opt[CB][icb] > opt[BA][iba]) {
                iba++;
            }
            if (icb > lcb || iba > lba)
                break;
            opt[CB][icb] = opt[BA][iba] = 0;
            num[BACA]++;
            icb++, iba++;
        }
        //cout << num[CBA] << endl;
        for (auto i: opt[BA]) {
            if (i)
                num[BA]++;
        }
        for (auto i: opt[CA]) {
            if (i)
                num[CA]++;
        }
        for (auto i: opt[CB]) {
            if (i)
                num[CB]++;
        }
        for (ll i = 1; i <= n; i++) {
            if (s[i] == 'b' && num[BA] >= 1) {
                s[i] = 'a', num[BA]--;
            } else if (s[i] == 'b' && num[BACA] >= 1) {
                s[i] = 'a', num[BACA]--, num[CB]++;
            } else if (s[i] == 'b' && num[CABA] >= 1) {
                s[i] = 'a', num[CABA]--;
            } else if (s[i] == 'c' && num[CA] >= 1) {
                s[i] = 'a', num[CA]--;
            } else if (s[i] == 'c' && num[CABA] >= 1) {
                s[i] = 'a', num[CABA]--;
            } else if (s[i] == 'c' && num[BACA] >= 1) {
                s[i] = 'a', num[BACA]--;
            } else if (s[i] == 'c' && num[CB] >= 1) {
                s[i] = 'b', num[CB]--;
            } else if (s[i] == 'c' && num[BACA] >= 1) {
                s[i] = 'b', num[BACA]--;
            }
        }
        for (ll i = 1; i <= n; i++)
            cout << s[i];
        cout << endl;
    }
    return 0;
}

/*
1
2 2
cb
c b
b a

1
3 2


 */
