#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

long long count_capture(const vector<pair<int, int>>& pieces, int row, int col) {
    long long captured = 0;

    // Capture by row or column
    captured += (pieces.end() == find_if(pieces.begin(), pieces.end(), 
        [row](const pair<int, int>& p) { return p.first == row; }));
    captured += (pieces.end() == find_if(pieces.begin(), pieces.end(), 
        [col](const pair<int, int>& p) { return p.second == col; }));

    // Capture by diagonal (i+j)
    auto pos = find_if(pieces.begin(), pieces.end(), 
        [row, col](const pair<int, int>& p) { return row + col == p.first + p.second; });
    if (pos != pieces.end()) {
        captured += (pos + 1 == find_if(pos + 1, pieces.end(), 
            [row, col](const pair<int, int>& p) { return row + col == p.first + p.second; }));
    }

    // Capture by anti-diagonal (i-j)
    pos = find_if(pieces.begin(), pieces.end(), 
        [row, col](const pair<int, int>& p) { return row - col == p.first - p.second; });
    if (pos != pieces.end()) {
        captured += (pos + 1 == find_if(pos + 1, pieces.end(), 
            [row, col](const pair<int, int>& p) { return row - col == p.first - p.second; }));
    }

    return captured;
}

int main() {
    long long N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Count empty squares not captured by any piece
    long long count = 0;
    for (int row = 1; row <= N; ++row) {
        for (int col = 1; col <= N; ++col) {
            if (count_capture(pieces, row, col) == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}