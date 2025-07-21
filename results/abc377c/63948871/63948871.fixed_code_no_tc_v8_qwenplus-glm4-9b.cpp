#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        pieces[i].first--; // Convert to 0-indexed
        pieces[i].second--;
    }
    
    // Store the positions that can be captured by each piece
    set<pair<int, int>> captured_positions;
    
    for (auto &piece : pieces) {
        int x = piece.first;
        int y = piece.second;
        
        // Add possible positions that can be captured based on the given moves
        captured_positions.insert({x + 2, y + 1});
        captured_positions.insert({x + 1, y + 2});
        captured_positions.insert({x - 1, y + 2});
        captured_positions.insert({x - 2, y + 1});
        captured_positions.insert({x - 2, y - 1});
        captured_positions.insert({x - 1, y - 2});
        captured_positions.insert({x + 1, y - 2});
        captured_positions.insert({x + 2, y - 1});
    }
    
    // Calculate the number of squares that are not captured by any piece
    long long total_squares = N * N;
    long long captured_count = captured_positions.size();
    
    // The number of safe squares is the total squares minus the number of captured positions, 
    // but we need to ensure that we do not count any position more than once
    long long safe_squares = total_squares - captured_count;
    
    // Output the result
    cout << safe_squares << endl;
    
    return 0;
}