#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAX_N = 1000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> rows, cols, ups, downs;
    set<pair<int, int>> positions;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.push_back(b);
        cols.push_back(a);
        ups.push_back(b - a);
        downs.push_back(a + b);
        positions.insert({a, b});
    }

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());
    sort(ups.begin(), ups.end());
    sort(downs.begin(), downs.end());

    int unique_rows = unique(rows.begin(), rows.end()) - rows.begin();
    int unique_cols = unique(cols.begin(), cols.end()) - cols.begin();
    int unique_ups = unique(ups.begin(), ups.end()) - ups.begin();
    int unique_downs = unique(downs.begin(), downs.end()) - downs.begin();

    long long total_squares = (long long)N * N;
    long long occupied_squares = (long long)M;

    // Subtract squares captured by rows and columns
    occupied_squares += (unique_rows * (N - unique_rows)) + (unique_cols * (N - unique_cols));

    // Subtract squares captured by diagonals
    for (int i = 0; i < unique_ups; ++i) {
        int count = upper_bound(ups.begin(), ups.end(), ups[i] + N - 1) - lower_bound(ups.begin(), ups.end(), ups[i]);
        occupied_squares += count;
    }
    for (int i = 0; i < unique_downs; ++i) {
        int count = upper_bound(downs.begin(), downs.end(), downs[i] + N - 1) - lower_bound(downs.begin(), downs.end(), downs[i]);
        occupied_squares += count;
    }

    // Add back over-counted squares (intersection of rows/columns and diagonals)
    for (int i = 0; i < unique_rows; ++i) {
        for (int j = 0; j < unique_cols; ++j) {
            int a = cols[j], b = rows[i];
            if (positions.count({a, b})) continue;
            if (positions.count({a, b + 1}) || positions.count({a, b - 1}))
                occupied_squares--;
            if (positions.count({a + 1, b}) || positions.count({a - 1, b}))
                occupied_squares--;
        }
    }
    for (int i = 0; i < unique_ups; ++i) {
        for (int j = 0; j < unique_downs; ++j) {
            int a = downs[j] / 2, b = ups[i] / 2;
            if (positions.count({a, b})) continue;
            if (positions.count({a, b + 1}) || positions.count({a, b - 1}))
                occupied_squares--;
            if (positions.count({a + 1, b}) || positions.count({a - 1, b}))
                occupied_squares--;
        }
    }

    cout << total_squares - occupied_squares << endl;

    return 0;
}