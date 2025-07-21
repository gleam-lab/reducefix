#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

class List {
public:
    Node* head;
    List() : head(new Node(-1)) {}

    bool has(int v) {
        Node* p = head->next;
        while(p) {
            if(p->val == v) return true;
            p = p->next;
        }
        return false;
    }

    void insert(int v) {
        if(!has(v)) {
            Node* p = new Node(v);
            p->next = head->next;
            head->next = p;
        }
    }

    void erase(int v) {
        Node* p = head;
        while(p->next && p->next->val != v) p = p->next;
        if(p->next) {
            Node* temp = p->next;
            p->next = p->next->next;
            delete temp;
        }
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;
    List tate[w], yoko[h];
    rep(i,w) tate[i].insert(i);
    rep(i,h) yoko[i].insert(i);

    rep(qi,q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if(tate[c].has(r)) {
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            auto it = tate[c].begin();
            while(it != tate[c].end() && *it < r) ++it;
            if(it != tate[c].end()) tate[c].erase(it);

            it = yoko[r].begin();
            while(it != yoko[r].end() && *it < c) ++it;
            if(it != yoko[r].end()) yoko[r].erase(it);
        }
    }

    int ans = 0;
    rep(i,w) ans += tate[i].size();
    rep(i,h) ans += yoko[i].size();

    cout << ans / 2 << '\n';

    return 0;
}