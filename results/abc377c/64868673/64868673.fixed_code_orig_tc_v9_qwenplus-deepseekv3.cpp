#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> existing_pieces;
    set<pair<long long, long long>> unsafe_squares;

    vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing_pieces.insert({a, b});

        for (int k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe_squares.insert({x, y});
            }
        }
    }

    // The safe squares are N*N minus the existing pieces and unsafe squares
    long long total_squares = N * N;
    long long existing_count = existing_pieces.size();
    
    // Count unsafe squares that are not already existing pieces
    for (auto p : existing_pieces) {
        unsafe_squares.erase(p);
    }
    
    long long unsafe_count = unsafe_squares.size();
    long long safe_count = total_squares - existing_count - unsafe_count;

    cout << safe_count << endl;

    return 0;
}