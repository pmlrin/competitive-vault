#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>

ll mag[10];

ll dfs(ll num[], ll step) {
    //cout << step << endl;
    if (step >= 7) {
        ll ans = 0, pnum[10];
        for (ll i = 1; i <= 5; i++) {
            pnum[i] = num[i];
            //cout << pnum[i] << " ";
        }
        //cout << endl;
        while (1) {
            ll flag = 0;
            for (ll i = 1; i <= 4; i++) {
                if (pnum[i] >= 5) {
                    ans++;
                    pnum[i] -= 5;
                    flag = 1;
                }
            }
            if (flag == 0)
                break;
        }
        while (1) {
            ll flag = 0;
            for (ll i = 1; i <= 4; i++) {
                if (pnum[i] >= 4 && pnum[5] >= 1) {
                    ans++;
                    pnum[i] -= 4;
                    pnum[5] -= 1;
                    flag = 1;
                }
            }
            if (flag == 0)
                break;
        }
        while (1) {
            ll flag = 0;
            for (ll i = 1; i <= 4; i++) {
                if (pnum[i] >= 3 && pnum[5] >= 2) {
                    ans++;
                    pnum[i] -= 3;
                    pnum[5] -= 2;
                    flag = 1;
                }
            }
            if (flag == 0)
                break;
        }
        return ans;
    }
    ll ret = 0;
    ret = max(ret, dfs(num, step + 1));
    if (mag[step] == 0)
        return ret;
    if (step <= 4) {
        vector<ll> cho;
        for (ll i = 1; i <= 4; i++) {
            if (i != step)
                cho.push_back(i);
        }
        for (ll i = 1; i <= 3; i++) {
            if (num[cho[i - 1]] >= 1) {
                num[cho[i - 1]] -= 1;
                num[step] += 1;
                ret = max(ret, dfs(num, step + 1));
                num[cho[i - 1]] += 1;
                num[step] -= 1;
            }
            if (num[cho[i - 1]] >= 2) {
                num[cho[i - 1]] -= 2;
                num[step] += 2;
                ret = max(ret, dfs(num, step + 1));
                num[cho[i - 1]] += 2;
                num[step] -= 2;
            }
            if (num[cho[i - 1]] >= 3) {
                num[cho[i - 1]] -= 3;
                num[step] += 3;
                ret = max(ret, dfs(num, step + 1));
                num[cho[i - 1]] += 3;
                num[step] -= 3;
            }
        }
        for (ll i = 1; i <= 3; i++) {
            for (ll j = 1; j <= 3; j++) {
                if (i == j)
                    continue;
                if (num[cho[i - 1]] >= 1 && num[cho[j - 1]] >= 1) {
                    num[cho[i - 1]]--, num[cho[j - 1]]--;
                    num[step] += 2;
                    ret = max(ret, dfs(num, step + 1));
                    num[cho[i - 1]]++, num[cho[j - 1]]++;
                    num[step] -= 2;
                }
                if (num[cho[i - 1]] >= 2 && num[cho[j - 1]] >= 1) {
                    num[cho[i - 1]] -= 2, num[cho[j - 1]]--;
                    num[step] += 3;
                    ret = max(ret, dfs(num, step + 1));
                    num[cho[i - 1]] += 2, num[cho[j - 1]]++;
                    num[step] -= 3;
                }
            }
        }
        if (num[cho[0]] >= 1 && num[cho[1]] >= 1 && num[cho[2]] >= 1) {
            num[cho[0]]--, num[cho[1]]--, num[cho[2]]--;
            num[step] += 3;
            ret = max(ret, dfs(num, step + 1));
            num[cho[0]]++, num[cho[1]]++, num[cho[2]]++;
            num[step] -= 3;
        }
    } else {
        if (step == 5) {
            for (ll i = 1; i <= 4; i++) {
                if (num[i] >= 1) {
                    num[i] -= 1;
                    num[5] += 1;
                    ret = max(ret, dfs(num, step + 1));
                    num[i] += 1;
                    num[5] -= 1;
                }
            }
        }
        if (step == 6) {
            if (mag[5] == 1) {
                for (ll i = 1; i <= 4; i++) {
                    if (num[i] >= 1) {
                        num[i]--;
                        num[5]++;
                        ret = max(ret, dfs(num, step + 1));
                        num[5]--;
                        num[i]++;
                    }
                }
            } else {
                for (ll i = 1; i <= 4; i++) {
                    for (ll j = 1; j <= 4; j++) {
                        if (i == j)
                            continue;
                        if (num[i] >= 1 && num[j] % 5 == 4) {
                            num[i] -= 1;
                            num[j] += 1;
                            ret = max(ret, dfs(num, step + 1));
                            num[i] += 1;
                            num[j] -= 1;
                        }
                    }
                }
            }
        }
    }
    return ret;
}

void solve() {
    ll n, num[10];
    cin >> n;
    for (ll i = 1; i <= 5; i++)
        num[i] = 0;
    for (ll i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s[1] == 'D')
            num[1]++;
        if (s[1] == 'C')
            num[2]++;
        if (s[1] == 'H')
            num[3]++;
        if (s[1] == 'S')
            num[4]++;
    }
    for (ll i = 1; i <= 6; i++)
        cin >> mag[i];
    cout << dfs(num, 1) << endl;
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
1
5
2D 3D 4D 5D 6H
1 1 1 0 0 0
 */
