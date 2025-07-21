#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> pieces(m);
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    // Maps to store the positions and their capturing reach
    map<long long, long long> rows, cols, diag1, diag2;

    // Populate the maps
    for (auto& p : pieces) {
        rows[p.first]++;
        cols[p.second]++;
        diag1[p.first + p.second]++;
        diag2[p.first - p.second]++;
    }

    long long total_empty_squares = n * n;
    long long captured_squares = 0;

    // Calculate captured squares
    for (auto& p : pieces) {
        // Rows and columns
        captured_squares += rows[p.first] - 1;
        captured_squares += cols[p.second] - 1;
        // Diagonals
        captured_squares += diag1[p.first + p.second] - 1;
        captured_squares += diag2[p.first - p.second] - 1;
    }

    // Subtract the captured squares from total squares
    captured_squares /= 2; // Each square is counted twice in the above calculation
    captured_squares = min(max(0LL, captured_squares), total_empty_squares);

    // Calculate the number of empty squares where you can place your piece
    cout << total_empty_squares - captured_squares << endl;

    return 0;
}