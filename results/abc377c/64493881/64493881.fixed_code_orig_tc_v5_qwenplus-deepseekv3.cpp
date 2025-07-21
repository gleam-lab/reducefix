#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, M;
    cin >> N >> M;
    
    set<pair<int, int>> pieces;
    set<pair<int, int>> attacked;
    
    for (int k = 0; k < M; ++k) {
        int a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        
        // All 8 possible attack positions
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        for (int i = 0; i < 8; ++i) {
            int new_a = a + dx[i];
            int new_b = b + dy[i];
            if (new_a >= 1 && new_a <= N && new_b >= 1 && new_b <= N) {
                attacked.insert({new_a, new_b});
            }
        }
    }
    
    // Total safe positions = total cells - (occupied cells + attacked cells not occupied)
    long long total = N * N;
    long long occupied = pieces.size();
    long long attack_count = 0;
    
    for (const auto& pos : attacked) {
        if (pieces.find(pos) == pieces.end()) {
            attack_count++;
        }
    }
    
    long long safe = total - occupied - attack_count;
    cout << safe << '\n';

    return 0;
}