#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> existing_pieces;
    set<pair<long long, long long>> unsafe_squares;
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing_pieces.insert({a, b});
        
        // All 8 possible knight moves
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                if (existing_pieces.find({x, y}) == existing_pieces.end()) {
                    unsafe_squares.insert({x, y});
                }
            }
        }
    }
    
    long long total_squares = N * N;
    long long occupied = existing_pieces.size();
    long long unsafe = unsafe_squares.size();
    
    // Safe squares are total squares minus occupied squares minus unsafe squares not already occupied
    long long safe_squares = total_squares - occupied - unsafe;
    
    cout << safe_squares << endl;
    
    return 0;
}