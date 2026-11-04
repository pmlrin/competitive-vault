#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100;

template <class T> struct LinkedList {
    struct Node {
        T val;
        Node *pre, *nxt;
    };
    Node *head;
    LinkedList() { head = nullptr; }
    bool empty() { return head == nullptr; }
    Node *insertByOrder(T val) {
        Node *cur = head;
        Node *pre = nullptr;
        while (cur != nullptr && !(cur->val > val)) {
            pre = cur;
            cur = cur->nxt;
        }
        Node *ins = new Node{val, pre, cur};
        if (pre != nullptr) {
            pre->nxt = ins;
        } else {
            head = ins;
        }
        if (cur != nullptr) {
            cur->pre = ins;
        }
        return ins;
    }
    pair<Node *, ll> find(T val) {
        Node *cur = head;
        ll index = 1;
        while (cur != nullptr) {
            if (cur->val == val) {
                return {cur, index};
            }
            cur = cur->nxt;
            index++;
        }
        return {nullptr, 0};
    }
    void erase(Node *pos) {
        if (pos == nullptr) {
            return;
        }
        if (pos->pre != nullptr) {
            pos->pre->nxt = pos->nxt;
        } else {
            head = pos->nxt;
        }
        if (pos->nxt != nullptr) {
            pos->nxt->pre = pos->pre;
        }
        delete pos;
        return;
    }
    Node *merge(LinkedList<T>::Node *a, LinkedList<T>::Node *b) {
        if (a == nullptr)
            return b;
        if (b == nullptr)
            return a;
        if (a->val < b->val) {
            a->nxt = merge(a->nxt, b);
            if (a->nxt != nullptr) {
                a->nxt->pre = a;
            }
            return a;
        } else {
            b->nxt = merge(a, b->nxt);
            if (b->nxt != nullptr) {
                b->nxt->pre = b;
            }
            return b;
        }
    }
};

template <class T> ostream &operator<<(ostream &os, LinkedList<T> &L) {
    typename LinkedList<T>::Node *cur = L.head;
    if (cur == nullptr) {
        os << "(nul)";
        return os;
    }
    while (cur != nullptr) {
        os << cur->val << ",\0"[cur->nxt == nullptr];
        cur = cur->nxt;
    }
    return os;
}

int main() {
    cout << "Ver1\n";
    LinkedList<ll> L1, L2;

    cout << "input1\n";
    for (ll a; cin >> a;) {
        if (a == 0) {
            break;
        }
        L1.insertByOrder(a);
    }
    cout << "output1\n";
    cout << L1 << "\n";

    cout << "input2\n";
    for (ll a; cin >> a;) {
        if (a == 0) {
            break;
        }
        L2.insertByOrder(a);
    }
    cout << "output2\n";
    cout << L2 << "\n";

    cout << "mergence\n";
    L1.head = L1.merge(L1.head, L2.head);
    cout << L1 << "\n";

    cout << "insert\n";
    ll a;
    cin >> a;
    L1.insertByOrder(a);
    cout << "insertion\n";
    cout << L1 << "\n";

    cout << "delete\n";
    cin >> a;
    auto [pos, index] = L1.find(a);
    if (pos != nullptr) {
        L1.erase(pos);
    }
    cout << "deletion\n";
    cout << L1 << "\n";

    cout << "find\n";
    cin >> a;
    auto [pos2, index2] = L1.find(a);
    cout << "position\n";
    cout << index2 << "\n";

    cout << "end\n";
    system("pause");
    return 0;
}