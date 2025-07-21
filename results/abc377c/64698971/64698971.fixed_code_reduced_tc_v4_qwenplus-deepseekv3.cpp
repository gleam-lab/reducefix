#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> dangerous;
    set<pair<long long, long long>> pieces;
    
    vector<pair<long long, long long>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        a--; b--;
        pieces.insert({a, b});
        
        for (auto move : moves) {
            long long new_a = a + move.first;
            long long new_b = b + move.second;
            if (new_a >= 0 && new_a < N && new_b >= 0 && new_b < N) {
                dangerous.insert({new_a, new_b});
            }
        }
    }
    
    long long total_squares = N * N;
    long long dangerous_and_occupied = dangerous.size() + pieces.size();
    
    // To avoid double-counting squares that are both occupied and dangerous
    for (auto piece : pieces) {
        if (dangerous.count(piece)) {
            dangerous_and_occupied--;
        }
    }
    
    long long safe_squares = total_squares - dangerous_and_occupied;
    cout << safe_squares << endl;
    
    return 0;
}