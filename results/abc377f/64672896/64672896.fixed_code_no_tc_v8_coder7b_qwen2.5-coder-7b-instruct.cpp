#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<pair<i64, i64>> occupied;
    unordered_set<i64> rows, cols, diags1, diags2;

    for (const auto& [r, c] : pieces) {
        occupied.insert({r, c});
        rows.insert(r);
        cols.insert(c);
        diags1.insert(r + c);
        diags2.insert(r - c);
    }

    i64 empty_squares = N * N - M;

    for (i64 r = 1; r <= N; ++r) {
        if (!rows.count(r)) {
            empty_squares += N;
        }
    }

    for (i64 c = 1; c <= N; ++c) {
        if (!cols.count(c)) {
            empty_squares += N;
        }
    }

    for (i64 d1 = -N + 1; d1 <= N - 1; ++d1) {
        if (!diags1.count(d1)) {
            empty_squares += N;
        }
    }

    for (i64 d2 = -N + 1; d2 <= N - 1; ++d2) {
        if (!diags2.count(d2)) {
            empty_squares += N;
        }
    }

    cout << empty_squares << '\n';

    return 0;
}