#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row(H + 2), col(W + 2);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    
    long long ans = (long long)H * W;
    int cnt = 0;
    
    auto erase = [&](int r, int c) {
        if (row[r].count(c)) {
            cnt++;
            row[r].erase(c);
            col[c].erase(r);
        }
    };
    
    while (Q--) {
        int R, C;
        cin >> R >> C;
        
        if (row[R].count(C)) {
            erase(R, C);
            continue;
        }
        
        auto it = col[C].lower_bound(R);
        if (it != col[C].begin()) {
            it--;
            erase(*it, C);
        }
        
        it = col[C].lower_bound(R);
        if (it != col[C].end()) {
            erase(*it, C);
        }
        
        it = row[R].lower_bound(C);
        if (it != row[R].begin()) {
            it--;
            erase(R, *it);
        }
        
        it = row[R].lower_bound(C);
        if (it != row[R].end()) {
            erase(R, *it);
        }
    }
    
    cout << ans - cnt << '\n';
    return 0;
}