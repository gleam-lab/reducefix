#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long N;
    int M;
    cin >> N >> M;
    
    set<pair<long long, long long>> occupied;
    set<pair<long long, long long>> threatened;
    
    for (int i = 0; i < M; i++) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        
        // All 8 possible moves
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        for (int k = 0; k < 8; k++) {
            long long ni = a + dx[k];
            long long nj = b + dy[k];
            if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                threatened.insert({ni, nj});
            }
        }
    }
    
    // Total safe squares = total squares - occupied squares - threatened squares + squares that are both occupied and threatened
    // But since occupied squares are already empty, we just need to avoid threatened squares that are not occupied
    long long total_threatened = threatened.size();
    for (auto p : occupied) {
        if (threatened.count(p)) {
            total_threatened--;
        }
    }
    
    long long safe = N * N - M - total_threatened;
    cout << safe << '\n';
    
    return 0;
}