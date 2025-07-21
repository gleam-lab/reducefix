#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> positions(M);
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        a--; b--;
        positions[i] = {a, b};
    }

    // Sort positions by rows and then by columns
    sort(positions.begin(), positions.end());

    // Set to store already occupied lines
    set<long long> occupied_lines;

    // Check each position and mark the lines it occupies
    for (const auto& pos : positions) {
        // Horizontal line
        occupied_lines.insert(pos.first);
        // Vertical line
        occupied_lines.insert(pos.second);
        // Diagonal lines
        occupied_lines.insert(pos.first + pos.second);
        occupied_lines.insert(pos.first - pos.second);
    }

    // The total number of empty squares is N^2
    // Subtract the number of occupied lines from N^(2)
    long long empty_squares = N * N;
    for (const auto& line : occupied_lines) {
        // Calculate how many squares are on this line
        // It can be a row, column, diagonal going from 1 to N
        long long squares_on_line = min(N, line) - max(0LL, line + 1 - N) + 1;
        empty_squares -= squares_on_line;
    }

    cout << empty_squares << endl;

    return 0;
}