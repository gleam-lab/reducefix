#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int countValidCells(int N, vector<vector<int>>& pieces) {
        // Directions for capturing pieces
        vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        
        // Set to keep track of all cells that can be captured
        unordered_set<ll> capturedCells;
        
        // Iterate through each piece and mark cells that can be captured
        for (auto &piece : pieces) {
            int x = piece[0];
            int y = piece[1];
            for (auto &dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                    capturedCells.insert(((ll)(nx - 1) << 32) | (ny - 1));
                }
            }
        }
        
        // Total number of valid cells is total cells minus captured cells
        return N * N - capturedCells.size();
    }

    int solve() {
        int N, M;
        cin >> N >> M;
        
        vector<vector<int>> pieces(M, vector<int>(2));
        for (int i = 0; i < M; ++i) {
            cin >> pieces[i][0] >> pieces[i][1];
        }
        
        cout << countValidCells(N, pieces) << endl;
        
        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution sol;
    sol.solve();
    return 0;
}