#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<int, int>> captured;

    // Read all pieces and update the captured squares
    for (long long i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        // Convert 1-based to 0-based index
        captured.insert({x - 1, y - 1});
        // Add rows and columns
        for (int d = 0; d <= 2 * N - 2; ++d) {
            captured.insert({x - 1, (y - 1 + d) % N});
            captured.insert({(x - 1 + d) % N, y - 1});
        }
    }

    // Calculate the number of empty squares
    long long totalSquares = N * N;
    long long capturedSquares = captured.size();
    long long result = totalSquares - capturedSquares;

    cout << result << endl;

    return 0;
}