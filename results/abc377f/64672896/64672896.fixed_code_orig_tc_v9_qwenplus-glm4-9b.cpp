#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> pieces(M);
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    // Set to store all captured lines
    set<long long> captured_lines;

    // Collect all captured lines by existing pieces
    for (auto& p : pieces) {
        long long a = p.first, b = p.second;
        captured_lines.insert(a); // Captures row a
        captured_lines.insert(b); // Captures column b
        captured_lines.insert(a + b); // Captures diagonal a+b
        captured_lines.insert(a - b); // Captures diagonal a-b
    }

    long long free_cells = 0;

    // Count free cells in the upper triangle
    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j < i; ++j) {
            long long capture_condition = i + j;
            if (captured_lines.find(capture_condition) == captured_lines.end()) {
                free_cells++;
            }
        }
    }

    cout << free_cells * 2 << '\n'; // Each pair of upper and lower triangle cells can be filled

    return 0;
}