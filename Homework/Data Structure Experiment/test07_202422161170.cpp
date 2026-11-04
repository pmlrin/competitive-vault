#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100;

enum PrintType { PREV, MIDD };

template <class T> struct Heap {
    T h[N] = {}, n = 0;

    ll up(ll u) {
        while (u > 1 && h[u] > h[u / 2]) {
            swap(h[u], h[u / 2]);
            u = u / 2;
        }
        return u;
    }

    ll down(ll u) {
        while (u * 2 <= n) {
            ll temp = u * 2;
            if (u * 2 + 1 <= n && h[u * 2 + 1] > h[u * 2])
                temp = u * 2 + 1;
            if (h[temp] <= h[u])
                break;
            swap(h[u], h[temp]);
            u = temp;
        }
        return u;
    }

    Heap(ll siz = 0, T *a = nullptr) {
        n = siz;
        for (ll i = 1; i <= n; i++)
            h[i] = a[i];
        for (ll i = n; i >= 1; i--)
            down(i);
    }

    T top() { return h[1]; }

    ll push(T val) {
        h[++n] = val;
        return up(n);
    }

    void pop(ll key = 1) {
        swap(h[key], h[n]);
        n--;
        down(1);
    }
};

template <class T> ostream &operator<<(ostream &os, Heap<T> &q) {
    for (ll i = 1; i <= q.n; i++) {
        os << q.h[i];
        if (i != q.n) {
            os << ",";
        }
    }
    return os;
}

template <class T> struct BST {
    struct Node {
        T val;
        ll cnt;
        Node *lson, *rson;
        Node(T val = NULL, ll cnt = 0, Node *lson = nullptr,
             Node *rson = nullptr)
            : val(val), cnt(cnt), lson(lson), rson(rson) {}
    };
    Node *root;
    bool __printFlag;

    BST() : root(nullptr), __printFlag(false) {}

    Node *__insert(Node *&root, T val) {
        if (root == nullptr) {
            Node *ins = new Node{val, 1ll, nullptr, nullptr};
            root = ins;
            return root;
        }
        if (root->val == val) {
            root->cnt++;
            return root;
        } else if (root->val > val) {
            return __insert(root->lson, val);
        } else {
            return __insert(root->rson, val);
        }
    }
    Node *insert(T val) { return __insert(root, val); }

    void __print(Node *root, PrintType type) {
        if (root == nullptr) {
            return;
        }
        if (type == PREV) {
            if (__printFlag == true) {
                cout << ",";
            }
            __printFlag = true;
            cout << root->val;
        }
        __print(root->lson, type);
        if (type == MIDD) {
            if (__printFlag == true) {
                cout << ",";
            }
            __printFlag = true;
            cout << root->val;
        }
        __print(root->rson, type);
    }

    void print(PrintType type) {
        __printFlag = false;
        __print(root, type);
    }
};

int main() {
    cout << "Ver1\n";
    cout << "input\n";
    ll n, a[N], b[N];
    for (ll i = 1; cin >> a[i]; i++) {
        if (a[i] == 0) {
            break;
        }
        n = i;
    }
    cout << "output\n";
    Heap<ll> q(n, a);
    cout << q << "\n";
    for (ll i = n; i >= 1; i--) {
        b[i] = q.top();
        q.pop();
    }
    for (ll i = 1; i <= n; i++) {
        cout << b[i] << ",\n"[i == n];
    }
    BST<ll> t;
    for (ll i = 1; i <= n; i++) {
        t.insert(a[i]);
    }
    t.print(PREV);
    cout << "\n";
    t.print(MIDD);
    cout << "\n";
    cout << "end\n";
    system("pause");
    return 0;
}