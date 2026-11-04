#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e5 + 10, inf = 1e17, Len = 72;
const ll Simple = 1, Complex = 2;
const ll Before = 3, After = 4;

ll n;
string raw_msg;
map<ll, string> Guess12, Guess25;
map<ll, char> LongDe;
map<char, ll> LongEn;

ll JudgeSimOrCom(string s) {
    if (s[Len] == '0') {
        return Simple;
    }
    return Complex;
}

ll ComSender(string s) {
    if (s[1] == '0') {
        return Before;
    }
    return After;
}

ll GetNumber(string s, ll l, ll r) {
    ll ret = 0;
    for (ll i = r; i >= l; i--) {
        ret = ret * 2 + s[i] - '0';
    }
    return ret;
}

string DecodeLong(ll num) {
    string ret;
    while (num) {
        if (num % 38) {
            ret = ret + LongDe[num % 38];
        }
        num /= 38;
    }
    ll len = ret.size();
    for (ll i = 0; i <= len / 2 - 1; i++) {
        swap(ret[i], ret[len - i - 1]);
    }
    return ret;
}

string DecodeShort(ll num) {
    string ret;
    for (ll i = 1; i <= 3; i++) {
        ret = ret + (char)('A' + num % 26);
        num /= 26;
    }
    ret = ret + (char)('0' + num % 10);
    num /= 10;
    ret = ret + LongDe[num % 36 + 1];
    num /= 36;
    if (num) {
        ret = ret + LongDe[num];
    }
    ll len = ret.size();
    for (ll i = 0; i <= len / 2 - 1; i++) {
        swap(ret[i], ret[len - i - 1]);
    }
    return ret;
}

ll Encode(string s, ll count) {
    ll num = 0, len = s.size();
    for (ll i = 0; i < 11; i++) {
        num = num * 38;
        if (i < len) {
            num = num + LongEn[s[i]];
        }
    }
    __int128 ret = 47055833459ll;
    ret = ret * num;
    ret = ret / (1ll << (64 - count));
    ret = ret % (1ll << count);
    return (ll)ret;
}

string FindName(ll ha, ll len) {
    if (Guess12.count(ha) && len == 12) {
        return "#" + Guess12[ha];
    }
    if (Guess25.count(ha) && len == 25) {
        return "#" + Guess25[ha];
    }
    return "###";
}

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> raw_msg;
        raw_msg = " " + raw_msg;
        for (ll j = 1; j <= Len / 2; j++) {
            swap(raw_msg[j], raw_msg[Len - j + 1]);
        }
        string msg;
        if (JudgeSimOrCom(raw_msg) == Complex) {
            if (ComSender(raw_msg) == Before) {
                // cout << "ok1" << endl;
                ll tmp = GetNumber(raw_msg, 2, 13);
                msg = msg + FindName(tmp, 12);
                msg = msg + " ";
                tmp = GetNumber(raw_msg, 14, 71);
                string known = DecodeLong(tmp);
                msg = msg + known;
                Guess12[Encode(known, 12)] = known;
                Guess25[Encode(known, 25)] = known;
            } else {
                // cout << "ok2" << endl;
                ll tmp = GetNumber(raw_msg, 14, 71);
                string known = DecodeLong(tmp);
                msg = msg + known;
                msg = msg + " ";
                tmp = GetNumber(raw_msg, 2, 13);
                msg = msg + FindName(tmp, 12);
                Guess12[Encode(known, 12)] = known;
                Guess25[Encode(known, 25)] = known;
            }
        } else {
            // cout << "ok3" << endl;
            ll tmp = GetNumber(raw_msg, 44, 71);
            vector<string> known;
            if (tmp >= (1ll << 25)) {
                known.push_back(DecodeShort(tmp - (1ll << 25)));
                msg = msg + known.back();
                msg = msg + " ";
            } else {
                msg = msg + FindName(tmp, 25);
                msg = msg + " ";
            }
            tmp = GetNumber(raw_msg, 16, 43);
            if (tmp >= (1ll << 25)) {
                known.push_back(DecodeShort(tmp - (1ll << 25)));
                msg = msg + known.back();
                msg = msg + " ";
            } else {
                msg = msg + FindName(tmp, 25);
                msg = msg + " ";
            }
            tmp = GetNumber(raw_msg, 1, 15);

            if (tmp) {
                msg = msg + to_string(tmp);
            }

            if (!known.empty()) {
                for (auto j = known.begin(); j != known.end(); ++j) {
                    // cout << "!!" << endl;
                    Guess12[Encode(*j, 12)] = *j;
                    Guess25[Encode(*j, 25)] = *j;
                }
            }
        }
        cout << msg << endl;
    }
}

void init() {
    LongDe[0] = ' ';
    LongEn[' '] = 0;
    for (ll i = 1; i <= 10; i++) {
        LongDe[i] = '0' - 1 + i;
        LongEn['0' - 1 + i] = i;
    }
    for (ll i = 11; i <= 36; i++) {
        LongDe[i] = 'A' - 11 + i;
        LongEn['A' - 11 + i] = i;
    }
    LongDe[37] = '_';
    LongEn['_'] = 37;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    init();
    while (T--) {
        solve();
    }
    return 0;
}
/*
7
100111111001001101000001000100101001010001000000011011110000011100011010
000000111011010010001111000110010000110101101010001111011000000001111011
100111111001001101000001000100101001010001000001001000111000011101101000
110010110001000111010011000010110001101000100110000001111000011110010101
100111111001001101000001000100101001010001000001001000111000011101101000
100111111001001101000001000100101001010001000001110110000000011101101000
100111111001001101000001000100101001010001000001110110000000011101101000


### ABCD200_3
#ABCD200_3 A0BCD 123
#ABCD200_3 ABCD200_4
PY4XMCHJZTN ###
#PY4XMCHJZTN ABCD200_4
#ABCD200_4 ABCD200_5
#ABCD200_5 ABCD200_5

*/