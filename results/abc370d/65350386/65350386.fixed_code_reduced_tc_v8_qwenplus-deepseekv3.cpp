#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    rep(i,h) rep(j,w) {
        tate[j].insert(i);
        yoko[i].insert(j);
    }
    int remaining = h * w;
    rep(qi,q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (tate[c].count(r)) {
            tate[c].erase(r);
            yoko[r].erase(c);
            remaining--;
        } else {
            // Up
            auto it_up = tate[c].lower_bound(r);
            if (it_up != tate[c].begin()) {
                int pos = *prev(it_up);
                tate[c].erase(pos);
                yoko[pos].erase(c);
                remaining--;
            }
            // Down
            auto it_down = tate[c].lower_bound(r);
            if (it_down != tate[c].end()) {
                int pos = *it_down;
                tate[c].erase(pos);
                yoko[pos].erase(c);
                remaining--;
            }
            // Left
            auto it_left = yoko[r].lower_bound(c);
            if (it_left != yoko[r].begin()) {
                int pos = *prev(it_left);
                yoko[r].erase(pos);
                tate[pos].erase(r);
                remaining--;
            }
            // Right
            auto it_right = yoko[r].lower_bound(c);
            if (it_right != yoko[r].end()) {
                int pos = *it_right;
                yoko[r].erase(pos);
                tate[pos].erase(r);
                remaining--;
            }
        }
    }
    cout << remaining << "\n";
    return 0;
}