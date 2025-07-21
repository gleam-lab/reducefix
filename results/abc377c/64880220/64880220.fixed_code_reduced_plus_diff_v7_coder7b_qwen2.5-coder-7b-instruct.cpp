#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

bool isValidMove(int n, int m, int x, int y, unordered_set<int>& occupied) {
    return x >= 1 && x <= n && y >= 1 && y <= m && !occupied.count((x-1)*m + y);
}

int countValidPositions(int n, int m, int k, vector<vector<int>>& positions) {
    unordered_set<int> occupied;
    for(auto& pos : positions) {
        occupied.insert((pos[0]-1)*m + pos[1]);
    }

    int validCount = 0;
    for(auto& pos : positions) {
        int x = pos[0], y = pos[1];
        vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        bool canPlace = true;
        for(auto& move : moves) {
            int newX = x + move.first;
            int newY = y + move.second;
            if(isValidMove(n, m, newX, newY, occupied)) {
                canPlace = false;
                break;
            }
        }
        if(canPlace) {
            validCount++;
        }
    }

    return validCount;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> positions(k, vector<int>(2));
    for(int i = 0; i < k; ++i) {
        cin >> positions[i][0] >> positions[i][1];
    }
    
    cout << countValidPositions(n, m, k, positions) << endl;
    return 0;
}