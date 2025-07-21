#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

#define N 1000000000

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; i++) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    vector<int> capture_count(N + 1, 0);

    // For each piece, mark the regions it can capture
    for (auto &p : pieces) {
        int x = p.first;
        int y = p.second;
        // Check all knight-like moves and mark the regions they can capture
        // This is a simplified example, actual moves need to be calculated
        capture_count[x + 1] += 1; // Example region
        capture_count[x - 1] += 1; // Example region
        // ...
    }

    // Total squares on the grid
    long long total_squares = (long long)n * n;

    // Calculate the number of safe squares
    long long safe_squares = total_squares;
    for (int i = 0; i <= N; i++) {
        if (capture_count[i] == m) {
            // All regions up to i are threatened by all pieces
            safe_squares -= m;
        }
    }

    cout << safe_squares << endl;

    return 0;
}