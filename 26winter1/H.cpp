#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 200 + 10, mod = 1000000007;
struct Matrix {
    ll M[N][N], n;
    Matrix(ll type, ll s) {
        memset(M, 0, sizeof(M));
        n = s;
        if (type)
            for (ll i = 0; i <= n; i++)
                M[i][i] = 1;
    }
    void print() {
        for (ll i = 0; i <= n; i++) {
            for (ll j = 0; j <= n; j++)
                printf("%lld ", M[i][j]);
            printf("\n");
        }
        return;
    }
    Matrix operator*(const Matrix &N) {
        Matrix ret(0, n);
        for (ll i = 0; i <= n; i++)
            for (ll j = 0; j <= n; j++)
                for (ll k = 0; k <= n; k++)
                    ret.M[i][j] = (ret.M[i][j] + this->M[i][k] * N.M[k][j] % mod) % mod;
        return ret;
    }
    Matrix operator^(ll k) {
        Matrix ret(1, n), tmp = *this;
        while (k) {
            if (k % 2)
                ret = ret * tmp;
            tmp = tmp * tmp;
            k /= 2;
        }
        return ret;
    }
};

void solve() {
    ll n, b, k, x;
    cin >> n >> b >> k >> x;
    ll a[n + 10], cnt[10] = {};
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    Matrix M(0, x);
    for (ll i = 0; i <= x - 1; i++) {
        for (ll j = 1; j <= 9; j++) {
            M.M[i][(i * 10 + j) % x] += cnt[j];
            M.M[i][(i * 10 + j) % x] %= mod;
        }
    }
    // M.print();
    M = M ^ b;
    // M.print();
    cout << M.M[0][k] << endl;
    return;
}

int main() {
    solve();
    return 0;
}
/*
2 6
1 2
3 4
*/
