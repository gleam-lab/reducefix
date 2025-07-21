#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64, 2>> pieces(M);
    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        --a; --b; // Convert to 0-based index
        pieces[i] = {a, b};
    }
    
    // This will store the number of pieces that can attack each point on the grid
    vector<vector<i64>> attack_map(N, vector<i64>(N, 0));
    for (auto &piece : pieces) {
        i64 x = piece[0];
        i64 y = piece[1];
        // Rows and columns
        for (i64 i = 0; i < N; ++i) {
            attack_map[x][i]++;
            attack_map[i][y]++;
        }
        // Diagonals x+y and x-y
        for (i64 i = 0; i < N; ++i) {
            for (i64 j = 0; j < N; ++j) {
                if (x + y == i + j || x - y == i - j) {
                    attack_map[i][j]++;
                }
            }
        }
    }
    
    // Calculate the number of safe squares
    i64 safe_squares = 0;
    for (i64 i = 0; i < N; ++i) {
        for (i64 j = 0; j < N; ++j) {
            safe_squares += (attack_map[i][j] == 0);
        }
    }
    cout << safe_squares << "\n";
    
    return 0;
}