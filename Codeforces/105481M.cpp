#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 1e5 + 10;

ll nInit, mType, kNum, tLuck;
ll kSeq[N];
ll game33[5][5] = {}, gamePos33[5][5];
ll *game9[20];
ll curNum = 0, oweNum = 0, curPos = 0;
ll ans[N] = {};

void init() {
    game9[1] = &game33[2][2];
    game9[2] = &game33[1][1];
    game9[3] = &game33[1][2];
    game9[4] = &game33[1][3];
    game9[5] = &game33[2][1];
    game9[6] = &game33[2][3];
    game9[7] = &game33[3][1];
    game9[8] = &game33[3][2];
    game9[9] = &game33[3][3];
    gamePos33[2][2] = 1;
    gamePos33[1][1] = 2;
    gamePos33[1][2] = 3;
    gamePos33[1][3] = 4;
    gamePos33[2][1] = 5;
    gamePos33[2][3] = 6;
    gamePos33[3][1] = 7;
    gamePos33[3][2] = 8;
    gamePos33[3][3] = 9;
    curNum = nInit;
}

ll check1(ll st) {
    for (ll i = st; i <= 9; i++) {
        if (*game9[i] == 0) {
            if (curPos < curNum) {
                return i;
            }
        }
    }
    return 0;
}

ll check2() {
    set<ll> s;
    for (ll i = 1; i <= 9; i++) {
        if (*game9[i] != 0) {
            s.insert(*game9[i]);
        }
    }
    if (s.size() == 9)
        return 1;
    return 0;
}

vector<ll> check3() {
    vector<vector<ll> > ret;
    for (ll i = 1; i <= 3; i++) {
        if (game33[i][1] == game33[i][2] && game33[i][1] == game33[i][3] && game33[i][1] != 0) {
            vector tmp = {gamePos33[i][1], gamePos33[i][2], gamePos33[i][3]};
            sort(tmp.begin(), tmp.end());
            ret.push_back(tmp);
        }
    }
    for (ll i = 1; i <= 3; i++) {
        if (game33[1][i] == game33[2][i] && game33[1][i] == game33[3][i] && game33[1][i] != 0) {
            vector tmp = {gamePos33[1][i], gamePos33[2][i], gamePos33[3][i]};
            sort(tmp.begin(), tmp.end());
            ret.push_back(tmp);
        }
    }
    if (game33[1][1] == game33[2][2] && game33[1][1] == game33[3][3] && game33[1][1] != 0) {
        vector tmp = {gamePos33[1][1], gamePos33[2][2], gamePos33[3][3]};
        sort(tmp.begin(), tmp.end());
        ret.push_back(tmp);
    }
    if (game33[1][3] == game33[2][2] && game33[1][3] == game33[3][1] && game33[3][1] != 0) {
        vector tmp = {gamePos33[1][3], gamePos33[2][2], gamePos33[3][1]};
        sort(tmp.begin(), tmp.end());
        ret.push_back(tmp);
    }
    auto cmp = [](vector<ll> a, vector<ll> b)-> bool {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    };
    if (ret.empty())
        return {0, 0, 0};
    sort(ret.begin(), ret.end(), cmp);
    return ret[0];
}

PII check4() {
    PII ret[100];
    ll retNum = 0;
    for (ll i = 1; i <= 9; i++) {
        for (ll j = 1; j <= 9; j++) {
            if (i == j)
                continue;
            if (*game9[i] == 0 || *game9[j] == 0)
                continue;
            if (*game9[i] != *game9[j])
                continue;
            ret[++retNum] = {i, j};
            ret[++retNum] = {j, i};
        }
    }
    auto cmp = [](PII a,PII b)-> bool {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    };
    if (retNum == 0)
        return {0, 0};
    sort(ret + 1, ret + 1 + retNum, cmp);
    return ret[1];
}

void curNumPlus(ll x) {
    curNum += x;
    if (curNum > kNum) {
        oweNum += curNum - kNum;
        curNum = kNum;
    }
}

void debug() {
    /*for (ll i = 1; i <= 3; i++) {
        for (ll j = 1; j <= 3; j++) {
            cout << game33[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/
}

void solve() {
    cin >> nInit >> mType >> kNum >> tLuck;
    for (ll i = 1; i <= kNum; i++) {
        cin >> kSeq[i];
    }
    init();
    while (1) {
        ll check6 = 0;
        ll ck1 = check1(1);
        if (ck1 != 0) {
            //cout << "Type 1" << endl;
            check6 = 1;
            ll curSt = 1, flagCon = 0;
            while (1) {
                ll ck12 = check1(curSt);
                if (ck12 == 0) {
                    debug();
                    break;
                }
                curPos++;
                *game9[ck12] = kSeq[curPos];
                curSt = ck12;
                if (kSeq[curPos] == tLuck) {
                    curNumPlus(1);
                }
                if (kSeq[curPos] == 0) {
                    curNumPlus(1);
                    ans[0]++;
                    flagCon = 1;
                    debug();
                    break;
                }
            }
            if (flagCon) {
                continue;
            }
        }

        ll ck2 = check2();
        if (ck2 == 1) {
            //cout << "Type 2" << endl;
            check6 = 1;
            ans[*game9[1]]++;
            *game9[1] = 0;
            debug();
            continue;
        }

        ll check5 = 0;
        vector<ll> ck3 = check3();
        if (ck3[0] != 0) {
            //cout << "Type 3" << endl;
            check6 = 1;
            while (1) {
                vector<ll> ck3t = check3();
                if (ck3t[0] == 0) {
                    debug();
                    break;
                }
                for (auto i: ck3t) {
                    if (i != 1) {
                        ans[*game9[i]]++;
                        *game9[i] = 0;
                    }
                    if (i == 1) {
                        check5 = 1;
                    }
                }
                curNumPlus(5);
            }
        }

        PII ck4 = check4();
        if (ck4.first != 0) {
            //cout << "Type 4" << endl;
            check6 = 1;
            while (1) {
                PII ck4t = check4();
                if (ck4t.first == 0) {
                    debug();
                    break;
                }
                if (ck4t.first != 1) {
                    ans[*game9[ck4t.first]]++;
                    *game9[ck4t.first] = 0;
                }
                if (ck4t.first == 1) {
                    check5 = 1;
                }
                if (ck4t.second != 1) {
                    ans[*game9[ck4t.second]]++;
                    *game9[ck4t.second] = 0;
                }
                if (ck4t.second == 1) {
                    check5 = 1;
                }
                curNumPlus(1);
            }
        }

        ll ck5 = check5;
        if (ck5) {
            //cout << "Type 5" << endl;
            check6 = 1;
            ans[*game9[1]]++;
            *game9[1] = 0;
            debug();
        }

        ll ck6 = check6;
        if (ck6 == 0) {
            //cout << "Type end" << endl;
            for (ll i = 1; i <= 9; i++) {
                if (*game9[i] != 0) {
                    ans[*game9[i]]++;
                    *game9[i] = 0;
                }
            }
            debug();
            break;
        } else {
            ll ck62 = 0;
            for (ll i = 1; i <= 9; i++) {
                if (*game9[i] != 0) {
                    ck62 = 1;
                }
            }
            if (ck62 == 0) {
                //cout << "Type 6" << endl;
                debug();
                curNumPlus(10);
            }
        }
    }
    for (ll i = 0; i <= mType; i++)
        cout << ans[i] << " ";
    cout << endl;
    if (oweNum >= 1) {
        cout << "Unhappy! " << oweNum << endl;
    }
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
8 9 16 2
 1 0 1 1 2 3 4 5 1 6 1 7 8 9 1 1

2 9 2 1
 1 2
 */
