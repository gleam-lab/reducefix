#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    for (i64 i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // We need to find all unique lines (x+y, x-y, row, column)
    set<pair<i64, i64>> lines;
    for (const auto& p : pieces) {
        lines.insert({p.first + p.second, 0});  // x+y
        lines.insert({p.first - p.second, 1});  // x-y
        lines.insert({p.first, 2});             // row
        lines.insert({p.second, 3});            // column
    }

    i64 ans = N * N; // Start with all empty squares

    // Remove squares covered by any existing piece
    for (const auto& l : lines) {
        i64 x = l.first;
        i64 type = l.second;
        i64 start, end, step;
        if (type == 0) { // x+y
            start = max(1LL, -x);
            end = min(N, N - x);
            step = 1;
        } else if (type == 1) { // x-y
            start = max(1LL, x);
            end = min(N, N + x);
            step = 1;
        } else if (type == 2) { // row
            start = max(1LL, x - N + 1);
            end = min(N, x);
            step = -1;
        } else { // column
            start = max(1LL, x - N + 1);
            end = min(N, x);
            step = -1;
        }
        for (i64 i = start; step > 0 ? i <= end : i >= end; i += step) {
            ans--;
        }
    }

    cout << ans << "\n";

    return 0;
}