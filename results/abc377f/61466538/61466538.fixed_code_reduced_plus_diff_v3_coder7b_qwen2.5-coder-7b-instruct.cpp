#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

// Function to check if a position is within bounds
bool in_bounds(int x, int y, int n) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

// Main function to solve the problem
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> pieces(m);
    for(int i = 0; i < m; i++) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Sets to store positions attacked by rows, columns, diagonals
    set<int> row_attacked, col_attacked, diag1_attacked, diag2_attacked;

    // Populate the sets based on the pieces' positions
    for(const auto &piece : pieces) {
        row_attacked.insert(piece.first);
        col_attacked.insert(piece.second);
        diag1_attacked.insert(piece.first - piece.second);
        diag2_attacked.insert(piece.first + piece.second);
    }

    // Calculate the total number of empty squares
    ll total_empty_squares = (ll)n * n;

    // Subtract squares attacked by rows, columns, and diagonals
    total_empty_squares -= row_attacked.size() * (ll)n;
    total_empty_squares -= col_attacked.size() * (ll)n;
    total_empty_squares += row_attacked.size() * col_attacked.size();

    // Adjust for over-subtraction of squares attacked by diagonals
    for(const auto &diag1 : diag1_attacked) {
        int count = 0;
        for(int i = 1; i <= n; i++) {
            if(diag1 == i - i) {
                count++;
            }
        }
        total_empty_squares += count - 1;
    }

    for(const auto &diag2 : diag2_attacked) {
        int count = 0;
        for(int i = 1; i <= n; i++) {
            if(diag2 == i + i) {
                count++;
            }
        }
        total_empty_squares += count - 1;
    }

    // Output the result
    cout << total_empty_squares << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}