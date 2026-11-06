#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y) : x(x), y(y) {}

    Point operator+(const Point &other) const {
        return Point(x + other.x, y + other.y);
    }
    Point operator-(const Point &other) const {
        return Point(x - other.x, y - other.y);
    }
    ll operator*(const Point &other) const { return x * other.x + y * other.y; }
    ll operator^(const Point &other) const { return x * other.y - y * other.x; }
    bool operator<(const Point &other) const {
        if (x == other.x)
            return y < other.y;
        return x < other.x;
    }
};

vector<Point> Convex_Hull(vector<Point> p) {
    sort(p.begin(), p.end());
    vector<Point> ch;
    for (int i = 0; i < p.size(); i++) {
        while (ch.size() > 1 && ((ch[ch.size() - 1] - ch[ch.size() - 2]) ^
                                 (p[i] - ch[ch.size() - 1])) <= 0) {
            ch.pop_back();
        }
        ch.push_back(p[i]);
    }
    int tmp = ch.size();
    for (int i = p.size() - 2; i >= 0; i--) {
        while (ch.size() > tmp && ((ch[ch.size() - 1] - ch[ch.size() - 2]) ^
                                   (p[i] - ch[ch.size() - 1])) <= 0) {
            ch.pop_back();
        }
        ch.push_back(p[i]);
    }
    return ch;
}

int in_Convex_Hull(Point p, const vector<Point> &ch) { p = p - ch[0]; }

vector<Point> p;

void solve() {
    int n;
    for (int i = 1; i <= n; i++) {
        ll x, y;
        cin >> x >> y;
        p.push_back(Point(x, y));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
