#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 13, inf = 1e17, mod = 998244353;

ll n, m;
vector<ll> a;

struct Matrix // 方阵
{
    ll M[N][N], n;
    Matrix(ll type, ll s) // 若 type 不为 0，构造一个单位矩阵
    {
        memset(M, 0, sizeof(M));
        n = s;
        if (type)
            for (ll i = 1; i <= N - 1; i++)
                M[i][i] = 1;
    }
    Matrix operator*(const Matrix &N) // 矩阵乘法
    {
        Matrix ret(0, n);
        for (ll i = 1; i <= n; i++)
            for (ll k = 1; k <= n; k++)
                for (ll j = 1; j <= n; j++) // j,k 互换可能会更快
                    ret.M[i][j] =
                        (ret.M[i][j] + M[i][k] * N.M[k][j] % mod) % mod;
        return ret;
    }
    Matrix operator^(ll k) // 矩阵快速幂
    {
        Matrix ret(1, n), tmp = *this;
        while (k) {
            if (k % 2)
                ret = ret * tmp;
            tmp = tmp * tmp;
            k /= 2;
        }
        return ret;
    }
} f(0, 12), m1(0, 12), m2(0, 12);

ll mat1[12][12] = {
    {25, 25, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // 0
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},       // 1
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},       // 2
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},       // 3 (保持全0)
    {0, 0, 1, 0, 25, 24, 24, 24, 24, 24, 0, 0}, // 4
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},       // 5
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},       // 6
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},       // 7
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},       // 8
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},       // 9
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},       // 10 (保持全0)
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 26}       // 11
};

ll mat2[12][12] = {
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 3
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0}, // 4
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 6
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 7
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 8
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 10
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}  // 11
};

void solve() {
    cin >> n >> m;
    ll lsta = 0, cura;
    for (ll i = 1; i <= m; i++) {
        cin >> cura;
        a.push_back(cura - lsta - 1);
        lsta = cura;
    }
    cura = n + 1;
    a.push_back(cura - lsta - 1);
    for (ll i = 1; i <= 12; i++) {
        for (ll j = 1; j <= 12; j++) {
            m1.M[i][j] = mat1[j - 1][i - 1];
            m2.M[i][j] = mat2[j - 1][i - 1];
        }
    }
    f.M[1][1] = 1;
    ll len = a.size();
    for (ll i = 0; i <= len - 1; i++) {
        f = f * (m1 ^ a[i]);
        if (i != len - 1) {
            f = f * m2;
        }
        // cout << a[i] << endl;
    }
    cout << f.M[1][12] << endl;
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
