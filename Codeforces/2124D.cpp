#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50;

ll n, k, b[N], bb[N];
PII a[N];
vector<ll> res, bone;

bool cmp1(PII x,PII y) {
    return x.first < y.first;
}

bool cmp2(PII x,PII y) {
    return x.second < y.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T, resl, bonel;
    cin >> T;
    while (T--) {
        ll tmp = 0, bbcnt = 0;
        cin >> n >> k;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
            b[i] = 0;
        }
        res.clear();
        bone.clear();
        res.push_back(0);
        bone.push_back(0);
        sort(a + 1, a + 1 + n, cmp1);
        for (ll i = 1; i <= k; i++) {
            b[a[i].second] = 1;
            tmp = max(tmp, a[i].first);
        }
        for (ll i = k + 1; a[i].first == tmp; i++)
            b[a[i].second] = 1;
        sort(a + 1, a + 1 + n, cmp2);
        for (ll i = 1; i <= n; i++) {
            if (b[i]) {
                res.push_back(a[i].first);
                bb[++bbcnt] = 1;
                if (a[i].first != tmp)
                    bone.push_back(a[i].first);
                else
                    bb[bbcnt] = 0;
            }
        }
        resl = res.size() - 1;
        bonel = bone.size() - 1;

        /*for (ll i = 1; i <= resl; i++)
            cout << res[i] << " ";
        cout << endl;
        for (ll i = 1; i <= bonel; i++)
            cout << bone[i] << " ";
        cout << endl;*/

        ll flag = 0, L, R, jud = 0;
        if (bonel <= 0) {
            cout << "YES" << endl;
            continue;
        }
        for (ll l = 1, r = bonel; l <= r; l++, r--) {
            if (bone[l] != bone[r]) {
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }
        if (flag)
            continue;
        for (ll i = 1; i <= resl; i++) {
            if (bb[i] == 1) {
                L = i;
                break;
            }
        }
        for (ll i = resl; i >= 1; i--) {
            if (bb[i] == 1) {
                R = i;
                break;
            }
        }
        jud = abs(L - (resl - R + 1));
        //cout << jud << endl;
        for (ll l = L, r = R; l <= r;) {
            if (bb[l] && bb[r]) {
                l++, r--;
            } else if (bb[l] && bb[r] == 0) {
                jud++, r--;
            } else if (bb[l] == 0 && bb[r]) {
                jud++, l++;
            } else {
                l++, r--;
            }
        }
        //cout << jud << endl;
        if (resl - jud >= k - 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
