#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

ll pown(int b, int e) {
    ll res = 1;
    while (e > 0) {
        if (e & 1) res = res * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    vector<set<int>> rows(n + 1), cols(n + 1);
    vector<pair<set<int>, set<int>>> diagonals(2 * n + 1); // For (i+j) and (i-j)

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows[a].insert(b);
        cols[b].insert(a);
        diagonals[a - b + n].insert(i);
    }

    ll total = (ll)n * n - (ll)m;
    set<int> all_cols, all_rows;
    for (int i = 1; i <= n; ++i) {
        all_rows.insert(i);
        all_cols.insert(i);
    }

    for (int i = 1; i <= n; ++i) {
        total -= (ll)all_cols.size() - rows[i].size() * rows[i].size(); // Captures at each row
        all_cols.erase(all_cols.find(i));
        all_rows.erase(all_rows.find(i));
    }

    for (int i = 1; i <= n; ++i) {
        total -= (ll)all_rows.size() - cols[i].size() * cols[i].size(); // Captures at each column
        all_cols.insert(i);
        all_rows.erase(all_rows.find(i));
    }

    for (int i = 1; i <= 2 * n; ++i) {
        set<int> lines; // To store unique pairs (i+j, i-j)
        for (auto idx : diagonals[i]) {
            int a = pieces[idx].first;
            int b = pieces[idx].second;
            lines.insert(a + b);
            lines.insert(a - b);
        }

        for (auto line : lines) {
            total -= (ll)all_rows.size() - all_cols.size(); // Captures on each line
            all_rows.insert((line + 1) / 2);
            all_cols.insert((line - 1) / 2);
        }

        all_rows.erase(all_rows.find((i + 1) / 2));
        all_cols.erase(all_cols.find((i - 1) / 2));
    }

    cout << total << endl;
    return 0;
}