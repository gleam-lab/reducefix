#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> positions(M);
    for(int i = 0; i < M; ++i) {
        cin >> positions[i].first >> positions[i].second;
    }

    set<pair<int, int>> attacked_positions;
    
    for(const auto& pos : positions) {
        int x = pos.first, y = pos.second;
        
        // Check all possible moves of a knight
        vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        
        for(const auto& move : moves) {
            int nx = x + move.first, ny = y + move.second;
            if(nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                attacked_positions.insert({nx, ny});
            }
        }
    }

    cout << (N * N) - attacked_positions.size() << endl;

    return 0;
}