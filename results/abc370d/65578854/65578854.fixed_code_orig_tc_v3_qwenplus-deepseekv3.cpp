#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row(H + 1), col(W + 1);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    
    ll remaining = (ll)H * W;
    
    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        
        if (row[R].count(C)) {
            row[R].erase(C);
            col[C].erase(R);
            remaining--;
        } else {
            // Check up
            auto it = col[C].lower_bound(R);
            if (it != col[C].begin()) {
                --it;
                int r = *it;
                if (row[r].count(C)) {
                    row[r].erase(C);
                    col[C].erase(r);
                    remaining--;
                }
            }
            
            // Check down
            it = col[C].lower_bound(R);
            if (it != col[C].end()) {
                int r = *it;
                if (row[r].count(C)) {
                    row[r].erase(C);
                    col[C].erase(r);
                    remaining--;
                }
            }
            
            // Check left
            it = row[R].lower_bound(C);
            if (it != row[R].begin()) {
                --it;
                int c = *it;
                if (col[c].count(R)) {
                    col[c].erase(R);
                    row[R].erase(c);
                    remaining--;
                }
            }
            
            // Check right
            it = row[R].lower_bound(C);
            if (it != row[R].end()) {
                int c = *it;
                if (col[c].count(R)) {
                    col[c].erase(R);
                    row[R].erase(c);
                    remaining--;
                }
            }
        }
    }
    
    cout << remaining << endl;
    
    return 0;
}