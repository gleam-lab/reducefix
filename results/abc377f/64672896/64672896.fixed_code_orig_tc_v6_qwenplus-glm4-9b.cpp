#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> unique_lines;
    
    for (long long i = 0; i < M; ++i) {
        long long r, c;
        cin >> r >> c;
        // Capture lines for rows and columns
        unique_lines.insert({r, 42}); // Placeholder value, row line
        unique_lines.insert({42, c}); // Placeholder value, column line
        // Capture lines for main diagonals (r = c)
        unique_lines.insert({r, c});
        // Capture lines for anti-diagonals (r - c = constant)
        unique_lines.insert({r, c - 1});
    }
    
    long long safe_squares = N * N;
    
    // Eliminate squares on captured lines
    for (const auto& line : unique_lines) {
        long long r = line.first, c = line.second;
        if (r != 42 && c != 42) { // Skip placeholder values
            if (r == 42) c = 0; // This is a row line
            if (c == 42) r = 0; // This is a column line
            
            // Count squares on the line
            long long min_dim = min(N, r);
            safe_squares -= min_dim;
        }
    }
    
    cout << safe_squares << endl;
    return 0;
}