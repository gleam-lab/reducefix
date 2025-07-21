#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    for(int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<int> rows, cols, diag1, diag2;
    for(auto& [r, c] : pieces) {
        rows.insert(r);
        cols.insert(c);
        diag1.insert(r - c);
        diag2.insert(r + c);
    }

    ll total_empty_squares = (ll)n * n;
    ll occupied_by_rows = rows.size();
    ll occupied_by_cols = cols.size();
    ll occupied_by_diag1 = diag1.size();
    ll occupied_by_diag2 = diag2.size();

    ll result = total_empty_squares - 
                 (occupied_by_rows + occupied_by_cols - 1) -
                 (occupied_by_diag1 + occupied_by_diag2 - 1) +
                 (rows.size() + cols.size() + diag1.size() + diag2.size()) / 2;

    cout << result << endl;
    return 0;
}