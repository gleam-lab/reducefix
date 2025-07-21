#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;

bool isValidMove(const unordered_set<pair<int, int>>& pieces, int x, int y, int N) {
    static const vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    for (auto& move : moves) {
        int nx = x + move.first;
        int ny = y + move.second;
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && pieces.count({nx, ny})) {
            return false;
        }
    }
    return true;
}

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<pair<int, int>> pieces;
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        --a, --b; // Convert to zero-based index
        pieces.insert({a, b});
    }
    
    long long emptyCount = 0;
    for (long long i = 0; i < N; ++i) {
        for (long long j = 0; j < N; ++j) {
            if (!pieces.count({i, j}) && isValidMove(pieces, i, j, N)) {
                ++emptyCount;
            }
        }
    }
    
    cout << emptyCount << endl;
    return 0;
}