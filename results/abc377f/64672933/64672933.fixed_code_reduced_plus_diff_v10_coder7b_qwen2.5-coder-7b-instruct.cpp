#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    
    vector<pair<i64, i64>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    set<pair<i64, i64>> occupied;
    set<i64> rows, cols, diagonals1, diagonals2;
    
    for (const auto& [r, c] : pieces) {
        occupied.insert({r, c});
        rows.insert(r);
        cols.insert(c);
        diagonals1.insert(r + c);
        diagonals2.insert(r - c);
    }
    
    i64 count = 0;
    
    for (i64 r = 1; r <= N; ++r) {
        for (i64 c = 1; c <= N; ++c) {
            if (occupied.count({r, c})) continue;
            
            bool safe = true;
            for (i64 rr : rows) {
                if (rr == r) {
                    safe = false;
                    break;
                }
            }
            for (i64 cc : cols) {
                if (cc == c) {
                    safe = false;
                    break;
                }
            }
            for (i64 dd1 : diagonals1) {
                if (dd1 == r + c) {
                    safe = false;
                    break;
                }
            }
            for (i64 dd2 : diagonals2) {
                if (dd2 == r - c) {
                    safe = false;
                    break;
                }
            }
            
            if (safe) {
                count++;
            }
        }
    }
    
    cout << count << "\n";
    
    return 0;
}