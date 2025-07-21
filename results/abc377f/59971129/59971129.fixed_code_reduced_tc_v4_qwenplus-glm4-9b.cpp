#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

long long n, m;
vector<pair<int, int>> pieces;
set<int> row captures, col captures, diag1 captures, diag2 captures;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b; // Convert to 0-based index
        pieces.push_back({a, b});
        row captures.insert(a);
        col captures.insert(b);
        diag1 captures.insert(a + b);
        diag2 captures.insert(a - b);
    }

    long long total = n * n;
    long long invalid = 0;

    // Count invalid positions in rows and columns
    for (int row : row captures) {
        if (row + 1 <= n) {
            for (int col = 0; col < n; ++col) {
                if (col + 1 <= n) {
                    invalid++;
                }
                if (row + col + 1 <= n) {
                    invalid++;
                }
                if (row - col + 1 <= n) {
                    invalid++;
                }
            }
        }
    }
    for (int col : col captures) {
        if (col + 1 <= n) {
            for (int row = 0; row < n; ++row) {
                if (row + 1 <= n) {
                    invalid++;
                }
                if (row + col + 1 <= n) {
                    invalid++;
                }
                if (row - col + 1 <= n) {
                    invalid++;
                }
            }
        }
    }

    // Count invalid positions in diagonals
    for (int diag : diag1 captures) {
        if (diag + 1 <= n) {
            for (int row = diag + 1, col = 0; row < n && col < n; ++row, ++col) {
                invalid++;
            }
            for (int row = 0, col = diag + 1; row < n && col < n; ++row, ++col) {
                invalid++;
            }
        }
    }
    for (int diag : diag2 captures) {
        if (diag + 1 <= n) {
            for (int row = diag + 1, col = n - 1; row < n && col >= 0; ++row, --col) {
                invalid++;
            }
            for (int row = 0, col = diag + 1; row < n && col >= 0; ++row, --col) {
                invalid++;
            }
        }
    }

    cout << total - invalid << endl;
    return 0;
}