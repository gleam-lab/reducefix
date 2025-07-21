#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(m);
    for (auto& p : pieces) {
        cin >> p.first >> p.second;
    }

    // Sort pieces by their coordinates
    sort(pieces.begin(), pieces.end());

    // Remove duplicates
    auto last = unique(pieces.begin(), pieces.end());
    pieces.erase(last, pieces.end());

    // Count the number of unique positions
    int unique_positions = pieces.size();

    // Calculate the total number of squares
    long long total_squares = 1LL * n * n;

    // Calculate the number of squares that cannot be used
    long long unusable_squares = 0;

    // For each piece, calculate the number of squares it covers
    for (const auto& p : pieces) {
        int row = p.first;
        int col = p.second;

        // Squares in the same row
        unusable_squares += n;

        // Squares in the same column
        unusable_squares += n;

        // Squares on the same diagonal (top-left to bottom-right)
        unusable_squares += min(n, row + col);

        // Squares on the same anti-diagonal (top-right to bottom-left)
        unusable_squares += min(n, n - row + col);

        // Subtract the piece itself
        unusable_squares--;
    }

    // The number of usable squares is the total minus the unusable
    long long usable_squares = total_squares - unusable_squares;

    cout << usable_squares << endl;

    return 0;
}