#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> existing_pieces;
    set<pair<long long, long long>> unsafe_squares;
    
    vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing_pieces.insert({a, b});
        
        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe_squares.insert({x, y});
            }
        }
    }
    
    long long total_safe = N * N - existing_pieces.size() - unsafe_squares.size();
    for (const auto& piece : existing_pieces) {
        if (unsafe_squares.count(piece)) {
            total_safe++;
        }
    }
    
    cout << max(0LL, total_safe) << endl;
    
    return 0;
}