#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    // To track cells that can be captured
    set<pair<int, int>> captured;
    
    for (auto& piece : pieces) {
        int i = piece.first;
        int j = piece.second;
        
        // Add the cells that can be captured by this piece
        captured.insert({i, j});
        if (i + 2 <= N) captured.insert({i + 2, j + 1});
        if (i + 1 <= N) captured.insert({i + 1, j + 2});
        if (i - 1 >= 1) captured.insert({i - 1, j + 2});
        if (i - 2 >= 1) captured.insert({i - 2, j + 1});
        if (i - 2 >= 1) captured.insert({i - 2, j - 1});
        if (i - 1 >= 1) captured.insert({i - 1, j - 2});
        if (i + 1 <= N) captured.insert({i + 1, j - 2});
        if (i + 2 <= N) captured.insert({i + 2, j - 1});
    }
    
    // Calculate the number of empty cells
    long long empty_cells = N * N - captured.size();
    cout << empty_cells << endl;
    
    return 0;
}