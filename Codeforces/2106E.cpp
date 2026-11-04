#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
#define lson (root*2)
#define rson ((root*2)+1)
#define mid ((l+r)/2)

const ll N = 200000 + 50, inf = 1145141919810;

ll n, a[N], pos[N];
vector<ll> ign, da;
set<ll> Ta, Ti;

void findign(ll l, ll r, ll p) {
    ign.clear();
    while (l <= r) {
        ll m = (l + r) / 2;
        if (m == p)
            return;
        if (m > p) {
            r = m - 1;
            if (a[m] < a[p]) {
                Ti.insert(a[m]);
            }
            ign.push_back(a[m]);
        }
        if (m < p) {
            l = m + 1;
            if (a[m] > a[p]) {
                Ti.insert(a[m]);
            }
            ign.push_back(a[m]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        ll q, l, r, k;
        cin >> n >> q;
        Ta.clear();
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
            Ta.insert(a[i]);
        }
        for (ll i = 1; i <= q; i++) {
            ll ans = 0, flag = 0;
            cin >> l >> r >> k;
            if (pos[k] < l || pos[k] > r) {
                cout << -1 << " ";
                continue;
            }
            da.clear();
            Ti.clear();
            findign(l, r, pos[k]);
            Ti.insert(k);
            for (auto p: ign) {
                Ta.erase(p);
            }
            /*for (auto j = Ta.begin(); j != Ta.end(); ++j)
                cout << *j << " ";
            cout << endl;*/
            while (l <= r) {
                ll m = (l + r) / 2;
                if (a[m] == k) {
                    flag = 1;
                    break;
                } else {
                    if (a[m] < k && m < pos[k]) {
                        l = m + 1;
                    }
                    if (a[m] < k && m > pos[k]) {
                        //cout << "OK1" << endl;
                        ll tmp = *Ti.rbegin();
                        //cout << 1 << " " << tmp << endl;
                        if (tmp > k) {
                            Ti.erase(tmp);
                            ans += 1;
                            r = m - 1;
                            //cout << endl << 1 << " " << tmp << endl;
                        } else {
                            //cout << "OK2" << endl;
                            tmp = *Ta.rbegin();
                            //cout << 2 << " " << tmp << endl;
                            if (tmp > k) {
                                Ta.erase(tmp);
                                da.push_back(tmp);
                                ans += 1;
                                r = m - 1;
                                //cout << endl << 2 << " " << tmp << endl;
                            } else {
                                ans = -1;
                                break;
                            }
                        }
                    }
                    if (a[m] > k && m > pos[k]) {
                        r = m - 1;
                    }
                    if (a[m] > k && m < pos[k]) {
                        //cout << "OK3" << endl;
                        ll tmp = *Ti.begin();
                        //cout << 3 << " " << tmp << endl;
                        if (tmp < k) {
                            Ti.erase(tmp);
                            ans += 1;
                            l = m + 1;
                            //cout << endl << 1 << " " << tmp << endl;
                        } else {
                            //cout << "OK4" << endl;
                            tmp = *Ta.begin();
                            //cout << 4 << " " << tmp << endl;
                            if (tmp < k) {
                                Ta.erase(tmp);
                                da.push_back(tmp);
                                ans += 1;
                                l = m + 1;
                                //cout << endl << 2 << " " << tmp << endl;
                            } else {
                                ans = -1;
                                break;
                            }
                        }
                    }
                }
            }
            ans += *Ti.end() - 1;
            if (flag)
                cout << ans << " ";
            else
                cout << -1 << " ";
            for (auto p: ign) {
                Ta.insert(p);
            }
            for (auto p: da) {
                Ta.insert(p);
            }
        }
        cout << endl;
    }
    return 0;
}

/*
1
1 1
1
1 1 1
 */
