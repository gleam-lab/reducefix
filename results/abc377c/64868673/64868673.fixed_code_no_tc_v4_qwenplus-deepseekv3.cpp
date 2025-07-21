#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> existing_pieces;
    unordered_set<long long> unsafe_positions;
    vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
                                         {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing_pieces.insert((a - 1) * N + b - 1);
        
        for (auto [dx, dy] : directions) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe_positions.insert((x - 1) * N + y - 1);
            }
        }
    }
    
    long long total_unsafe = unsafe_positions.size();
    for (auto pos : existing_pieces) {
        if (unsafe_positions.count(pos)) {
            total_unsafe--;
        }
    }
    
    cout << N * N - existing_pieces.size() - total_unsafe << endl;
    
    return 0;
}