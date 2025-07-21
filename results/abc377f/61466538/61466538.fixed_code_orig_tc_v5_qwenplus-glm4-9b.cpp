int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    int threatened = 0;
    set<int> rows, cols, diag1, diag2, anti_diag1, anti_diag2;
    for (auto &piece : pieces) {
        int r = piece.first, c = piece.second;
        rows.insert(r);
        cols.insert(c);
        diag1.insert(r + c);
        diag2.insert(r - c);
        anti_diag1.insert(c - r + n);
        anti_diag2.insert(c + r);
    }

    // Total number of squares minus the number of threatened squares
    int total_squares = n * n;
    int threatened_rows = rows.size();
    int threatened_cols = cols.size();
    int threatened_diag1 = diag1.size();
    int threatened_diag2 = diag2.size();
    int threatened_anti_diag1 = anti_diag1.size();
    int threatened_anti_diag2 = anti_diag2.size();

    // Subtract threatened squares
    int safe_squares = total_squares - threatened_rows * n - threatened_cols * n;
    safe_squares += threatened_diag1 * (n - 1) + threatened_diag2 * (n - 1);
    safe_squares += threatened_anti_diag1 * (n - 1) + threatened_anti_diag2 * (n - 1);

    cout << safe_squares << endl;
    return 0;
}