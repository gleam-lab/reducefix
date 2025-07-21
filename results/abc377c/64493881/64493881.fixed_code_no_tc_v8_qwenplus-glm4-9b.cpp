#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int MAX_N = 1000000000;
const int capture_directions[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; i++) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    // To keep track of all the positions that can be captured by any piece
    set<pair<int, int>> captured_positions;
    
    for (const auto& piece : pieces) {
        int a = piece.first, b = piece.second;
        for (int i = 0; i < 8; i++) {
            int new_a = a + capture_directions[i][0], new_b = b + capture_directions[i][1];
            if (new_a >= 1 && new_a <= N && new_b >= 1 && new_b <= N) {
                captured_positions.insert({new_a, new_b});
            }
        }
    }
    
    // Calculate the number of empty squares
    int total_squares = N * N;
    int captured_count = captured_positions.size();
    cout << total_squares - captured_count << endl;
    
    return 0;
}