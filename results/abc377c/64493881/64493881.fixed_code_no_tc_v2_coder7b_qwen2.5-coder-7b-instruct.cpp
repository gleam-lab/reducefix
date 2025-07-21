#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int countSafeSquares(int N, int M, vector<vector<int>>& pieces) {
        unordered_set<ll> occupied;
        
        // Mark all occupied squares
        for(auto &piece : pieces) {
            int x = piece[0], y = piece[1];
            occupied.insert(((ll)x << 32) | y);
        }
        
        // Directions for knight moves
        vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        
        // Count safe squares
        ll safeCount = 0;
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                bool isSafe = true;
                for(auto &dir : directions) {
                    int nx = i + dir.first, ny = j + dir.second;
                    if(nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                        if(occupied.count(((ll)nx << 32) | ny)) {
                            isSafe = false;
                            break;
                        }
                    }
                }
                if(isSafe) {
                    safeCount++;
                }
            }
        }
        return safeCount;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> pieces(M, vector<int>(2));
    for(int i = 0; i < M; ++i) {
        cin >> pieces[i][0] >> pieces[i][1];
    }

    Solution sol;
    cout << sol.countSafeSquares(N, M, pieces) << endl;

    return 0;
}