#include <iostream>
#include <set>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    set<pair<int, int>> pieces;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.insert({a, b});
    }

    long long total_empty = n * n - m;
    long long threatened = 0;

    // Horizontal and vertical threat
    for (auto p : pieces) {
        int r = p.first;
        int c = p.second;
        threatened += min(n - r, n - c);  // Subtract the number of empty cells in the row and column
    }

    // Diagonal threat
    for (auto p : pieces) {
        int r = p.first;
        int c = p.second;
        // Primary diagonal (r + c)
        int d = r + c;
        int max_d = n;  // Maximum possible value of r + c
        threatened += min(max_d - d, m - pieces.count({d - c, c}));  // Subtract the number of empty cells on each diagonal

        // Secondary diagonal (r - c)
        d = r - c;
        int max_d2 = n;  // Maximum possible value of r - c
        threatened += min(max_d2 - d, m - pieces.count({d + c, c}));  // Subtract the number of empty cells on each diagonal
    }

    cout << total_empty - threatened << endl;

    return 0;
}