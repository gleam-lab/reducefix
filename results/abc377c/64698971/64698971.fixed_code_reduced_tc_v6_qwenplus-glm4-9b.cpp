#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAXN 1000000000
int N, M;
vector<pair<int, int>> captures[4][8];

// Define capturing patterns for each type of move
void define_moves() {
    for (int dir = 0; dir < 4; ++dir) {
        for (int move = 0; move < 8; ++move) {
            int dx = (dir + move % 2 - 1) * 2;
            int dy = (move >= 4) * 2 - (move < 4) * 2;
            captures[dir][move] = {dx, dy};
        }
    }
}

int main() {
    define_moves();
    
    cin >> N >> M;
    
    vector<pair<int, int>> occupied;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied.push_back({a - 1, b - 1});
    }
    
    // Create a grid with all cells initially available
    vector<vector<bool>> available(N, vector<bool>(N, true));
    
    // Mark the cells that cannot be occupied due to existing pieces
    for (auto& p : occupied) {
        int x = p.first, y = p.second;
        for (int dir = 0; dir < 4; ++dir) {
            for (int move = 0; move < 8; ++move) {
                int nx = x + captures[dir][move].first;
                int ny = y + captures[dir][move].second;
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    available[nx][ny] = false;
                }
            }
        }
    }
    
    // Calculate the number of available cells
    long long count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (available[i][j]) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}