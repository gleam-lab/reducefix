#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

using LL = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    set<int> rows, cols, diag1, diag2;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Calculate the number of empty squares
    LL total_empty = n * n;
    total_empty -= rows.size() * n; // Subtract rows
    total_empty -= cols.size() * n; // Subtract columns
    total_empty -= diag1.size();    // Subtract anti-diagonal
    total_empty -= diag2.size();    // Subtract diagonal
    total_empty -= m;               // Subtract placed pieces

    // Subtract overlaps
    for (auto& p : pieces) {
        int r = p.first, c = p.second;
        // Subtract rows and columns intersecting with the piece
        total_empty -= rows.count(r) + cols.count(c) - 1;
        // Subtract diagonals intersecting with the piece
        total_empty -= diag1.count(r + c) + diag2.count(r - c) - 1;
    }

    cout << total_empty << endl;
    return 0;
}