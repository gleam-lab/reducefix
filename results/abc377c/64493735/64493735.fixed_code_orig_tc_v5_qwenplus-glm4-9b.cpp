#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.push_back({a, b});
    }

    vector<pair<int, int>> capturedSquares;

    // Check all pieces to determine the capture squares
    for (const auto& p : pieces) {
        int x = p.first;
        int y = p.second;
        if (x + 2 <= N && y + 1 <= N) capturedSquares.push_back({x + 2, y + 1});
        if (x + 1 <= N && y + 2 <= N) capturedSquares.push_back({x + 1, y + 2});
        if (x - 1 <= N && y + 2 <= N) capturedSquares.push_back({x - 1, y + 2});
        if (x - 2 <= N && y + 1 <= N) capturedSquares.push_back({x - 2, y + 1});
        if (x - 2 <= N && y - 1 <= N) capturedSquares.push_back({x - 2, y - 1});
        if (x - 1 <= N && y - 2 <= N) capturedSquares.push_back({x - 1, y - 2});
        if (x + 1 <= N && y - 2 <= N) capturedSquares.push_back({x + 1, y - 2});
        if (x + 2 <= N && y - 1 <= N) capturedSquares.push_back({x + 2, y - 1});
    }

    // Remove duplicates
    sort(capturedSquares.begin(), capturedSquares.end());
    auto last = unique(capturedSquares.begin(), capturedSquares.end());
    capturedSquares.erase(last, capturedSquares.end());

    // Calculate the number of safe squares
    cout << N * N - capturedSquares.size() << endl;

    return 0;
}