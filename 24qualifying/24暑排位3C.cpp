#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50, M = 50, inf = 1145141919810;

ll n, ol, num[M], num2[N];
char s[N], t[N], p[N];
vector<ll> odd, odd2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    n = strlen(s);
    for (ll i = 0; i <= n - 1; i++) {
        num[s[i] - 'a' + 1]++;
    }
    odd.push_back(0);
    for (ll i = 1; i <= 26; i++) {
        if (num[i] % 2)
            odd.push_back(i);
    }
    ol = odd.size() - 1;
    if (n % 2 == 0) {
        for (ll i = 1; i <= ol / 2; i++) {
            num[odd[i]]++;
            num[odd[ol - i + 1]]--;
        }
        for (ll i = 1; i <= 26; i++) {
            for (ll j = 1; j <= num[i] / 2; j++) {
                cout << (char) (i + 'a' - 1);
            }
        }
        for (ll i = 26; i >= 1; i--) {
            for (ll j = 1; j <= num[i] / 2; j++) {
                cout << (char) (i + 'a' - 1);
            }
        }
    } else {
        ll index, flag;
        for (ll k = 1; k <= ol; k++) {
            index = flag = 0;
            odd2.clear();
            odd2.push_back(0);
            for (ll i = 1; i <= ol; i++) {
                if (i == k)
                    continue;
                odd2.push_back(odd[i]);
            }
            for (ll i = 1; i <= 26; i++) {
                num2[i] = num[i];
            }
            for (ll i = 1; i <= (ol - 1) / 2; i++) {
                num2[odd2[i]]++;
                num2[odd2[ol - i]]--;
            }
            for (ll i = 1; i <= 26; i++) {
                if (flag == 1)
                    break;
                for (ll j = 1; j <= num2[i] / 2; j++) {
                    index++;
                    if (t[index] != 0 && t[index] < (char) (i + 'a' - 1) && flag != 2) {
                        flag = 1;
                        break;
                    }
                    if (t[index] != 0 && t[index] > (char) (i + 'a' - 1)) {
                        flag = 2;
                    }
                    t[index] = (char) (i + 'a' - 1);
                }
            }
            index++;
            if (t[index] != 0 && t[index] < (char) (odd[k] + 'a' - 1) && flag != 2) {
                flag = 1;
                continue;
            }
            if (t[index] != 0 && t[index] > (char) (odd[k] + 'a' - 1)) {
                flag = 2;
            }
            t[index] = (char) (odd[k] + 'a' - 1);
            for (ll i = 26; i >= 1; i--) {
                if (flag == 1)
                    break;
                for (ll j = 1; j <= num2[i] / 2; j++) {
                    index++;
                    if (t[index] != 0 && t[index] < (char) (i + 'a' - 1) && flag != 2) {
                        flag = 1;
                        break;
                    }
                    if (t[index] != 0 && t[index] > (char) (i + 'a' - 1)) {
                        flag = 2;
                    }
                    t[index] = (char) (i + 'a' - 1);
                }
            }
            if (flag != 1) {
                for (ll i = 1; i <= n; i++)
                    p[i] = t[i];
            }
        }
        for (ll i = 1; i <= n; i++)
            cout << p[i];
    }
    return 0;
}

/*
aabcd
bbcde
bbbbb
abcde
abcdef
zzzbbbzzzc
zzzbbbbzzz
zzzbbbzz
zzbbzz
zb

zzzbbbzzzc

afcccfaabbb

aaabbbcccddde
aaaabbbbcccdd
aaaabbbbccdde

aabbcdedcbbaa
aabbdcccdbbaa

aabcccd
abcccba

aaabzzzz

aaabbbcddd
aaaabbbbdd
 */
