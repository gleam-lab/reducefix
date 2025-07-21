#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e3;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(n * m);
    for (int i = 0; i < n * m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    sort(pieces.begin(), pieces.end());

    set<int> rows, cols, ups, downs;

    for (const auto& p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        ups.insert(p.first - p.second);
        downs.insert(p.first + p.second);
    }

    int num_rows = rows.size();
    int num_cols = cols.size();
    int num_ups = ups.size();
    int num_downs = downs.size();

    long long total_empty_squares = static_cast<long long>(n) * n;
    total_empty_squares -= static_cast<long long>(num_rows) * n + num_cols * n;
    total_empty_squares += static_cast<long long>(num_rows) * num_cols;

    cout << total_empty_squares << endl;

    return 0;
}