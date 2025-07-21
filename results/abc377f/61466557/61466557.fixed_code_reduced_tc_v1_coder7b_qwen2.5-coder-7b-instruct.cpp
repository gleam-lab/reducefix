#include <iostream>
#include <set>
#include <vector>

using namespace std;

// Function to check if a point is within bounds
bool inBounds(int x, int y, int n) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

// Main function to solve the problem
void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    set<int> rows, cols, diags1, diags2;
    
    for (const auto &piece : pieces) {
        rows.insert(piece.first);
        cols.insert(piece.second);
        diags1.insert(piece.first - piece.second);
        diags2.insert(piece.first + piece.second);
    }
    
    int total_squares = n * n;
    int occupied_by_rows = rows.size() * n;
    int occupied_by_cols = cols.size() * n;
    int occupied_by_diags1 = diags1.size() * n;
    int occupied_by_diags2 = diags2.size() * n;
    
    // Over-counting correction
    for (const auto &piece : pieces) {
        int diag1_index = piece.first - piece.second;
        int diag2_index = piece.first + piece.second;
        
        if (rows.count(piece.first) > 1) {
            occupied_by_rows--;
        }
        if (cols.count(piece.second) > 1) {
            occupied_by_cols--;
        }
        if (diags1.count(diag1_index) > 1) {
            occupied_by_diags1--;
        }
        if (diags2.count(diag2_index) > 1) {
            occupied_by_diags2--;
        }
    }
    
    int result = total_squares - (occupied_by_rows + occupied_by_cols + occupied_by_diags1 + occupied_by_diags2);
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}