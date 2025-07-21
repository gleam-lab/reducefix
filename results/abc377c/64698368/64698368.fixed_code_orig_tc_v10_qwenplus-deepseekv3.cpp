#include <bits/stdc++.h>
using namespace std;

int N, M;
set<pair<int, int>> unsafe;

void mark_unsafe(int a, int b) {
    // Check all 8 possible attack positions
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int i = 0; i < 8; ++i) {
        int x = a + dx[i];
        int y = b + dy[i];
        if (x >= 1 && x <= N && y >= 1 && y <= N) {
            unsafe.insert({x, y});
        }
    }
}

int main() {
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        mark_unsafe(a, b);
    }

    // The total safe squares are N^2 minus the unsafe squares (including occupied ones)
    // But the occupied squares are already in 'unsafe', so no need to subtract M separately
    long long total_squares = 1LL * N * N;
    long long unsafe_squares = unsafe.size() + M; // M pieces are already in 'unsafe' if they can attack each other
    // But actually, the 'unsafe' set includes squares that can be attacked, and the M pieces themselves are not available for placement
    // So the correct unsafe count is the size of 'unsafe' plus M (since original pieces are not in 'unsafe' but are occupied)
    // Wait, no: the original pieces are not in 'unsafe' unless they can attack each other
    // So the correct unsafe count is the size of 'unsafe' (which includes squares attacked by any piece) plus M (the original pieces)
    // But we must subtract any overlaps where original pieces are in 'unsafe' (i.e., if a piece can attack another piece)
    // To avoid double-counting, we can just add all original pieces to 'unsafe' first
    for (auto [a, b] : pieces) {
        unsafe.insert({a, b});
    }
    unsafe_squares = unsafe.size();
    long long safe_squares = total_squares - unsafe_squares;
    cout << safe_squares << endl;
    return 0;
}