#include <iostream>
#include <bitset>
#include <cassert>

using namespace std;

const int MAX_N = 1e9 + 10;
bitset<MAX_N * MAX_N> board;

void mark(int n, int m, int dx, int dy) {
    int nx = n + dx;
    int ny = m + dy;
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
        board[(nx - 1) * m + (ny - 1)] = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    for (const auto& [x, y] : pieces) {
        board[(x - 1) * n + (y - 1)] = true;
        mark(n, m, 2, 1);
        mark(n, m, 1, 2);
        mark(n, m, -1, 2);
        mark(n, m, -2, 1);
        mark(n, m, -2, -1);
        mark(n, m, -1, -2);
        mark(n, m, 1, -2);
        mark(n, m, 2, -1);
    }

    uint64_t empty_squares = n * m - board.count();
    cout << empty_squares << endl;

    return 0;
}