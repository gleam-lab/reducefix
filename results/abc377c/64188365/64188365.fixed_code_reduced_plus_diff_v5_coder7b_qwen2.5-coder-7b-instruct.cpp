#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidMove(int x, int y, int N) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> threats;
    
    for(long long i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        --x, --y; // Convert to zero-based index
        
        vector<pair<int, int>> moves = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };
        
        for(auto& move : moves) {
            int nx = x + move.first;
            int ny = y + move.second;
            
            if(isValidMove(nx, ny, N)) {
                threats.insert({nx, ny});
            }
        }
    }

    long long totalSquares = N * N;
    long long safeSquares = totalSquares - threats.size();
    
    cout << safeSquares << endl;
    return 0;
}