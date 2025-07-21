#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1009;

int N, M;
vector<pair<int, int>> pieces;

vector<int> occupied_rows, occupied_cols, occupied_diags_pos, occupied_diags_neg;

bool is_safe(int r, int c) {
    // Check if the row or column is occupied
    if (find(occupied_rows.begin(), occupied_rows.end(), r) != occupied_rows.end()) return false;
    if (find(occupied_cols.begin(), occupied_cols.end(), c) != occupied_cols.end()) return false;

    // Check if any diagonal is occupied
    int diag1 = r + c;
    int diag2 = r - c + N - 1;
    if (find(occupied_diags_pos.begin(), occupied_diags_pos.end(), diag1) != occupied_diags_pos.end()) return false;
    if (find(occupied_diags_neg.begin(), occupied_diags_neg.end(), diag2) != occupied_diags_neg.end()) return false;

    return true;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int r, c;
        cin >> r >> c;
        r++, c++; // Convert to 1-based index
        pieces.push_back({r, c});

        // Mark row and column as occupied
        occupied_rows.push_back(r);
        occupied_cols.push_back(c);

        // Mark diagonals as occupied
        occupied_diags_pos.push_back(r + c);
        occupied_diags_neg.push_back(r - c + N - 1);

        // Sort and remove duplicates
        sort(occupied_rows.begin(), occupied_rows.end());
        sort(occupied_cols.begin(), occupied_cols.end());
        sort(occupied_diags_pos.begin(), occupied_diags_pos.end());
        sort(occupied_diags_neg.begin(), occupied_diags_neg.end());

        occupied_rows.erase(unique(occupied_rows.begin(), occupied_rows.end()), occupied_rows.end());
        occupied_cols.erase(unique(occupied_cols.begin(), occupied_cols.end()), occupied_cols.end());
        occupied_diags_pos.erase(unique(occupied_diags_pos.begin(), occupied_diags_pos.end()), occupied_diags_pos.end());
        occupied_diags_neg.erase(unique(occupied_diags_neg.begin(), occupied_diags_neg.end()), occupied_diags_neg.end());
    }

    int safe_squares = 0;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (is_safe(r, c)) safe_squares++;
        }
    }

    cout << safe_squares << endl;
    return 0;
}