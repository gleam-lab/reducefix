#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Position {
    int row, col;
};

int main() {
    long long n, m;
    cin >> n >> m;

    vector<Position> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].row >> pieces[i].col;
    }

    // Using a long long variable `ans` to handle large values of N^2 - M^2
    long long ans = n * n;

    // Arrays to track the positions occupied by pieces on rows, columns, and diagonals
    vector<bool> occupied_rows(n + 1, false);
    vector<bool> occupied_cols(n + 1, false);
    vector<bool> occupied Ð³Ð»Ð°Ð²Ð½Ð¾Ð³Ð¾_Ð´Ð¸Ð°Ð³Ð¾Ð½Ð°Ð»Ñ(n + 1, false);
    vector<bool> occupied_Ð¿ÑÑÐ¼Ð¾Ð¼Ñ_Ð´Ð¸Ð°Ð³Ð¾Ð½Ð°Ð»Ñ(n + 1, false);

    // Mark the occupied positions by pieces
    for (const auto &piece : pieces) {
        occupied_rows[piece.row]++;
        occupied_cols[piece.col]++;
        occupied_Ð³Ð»Ð°Ð²Ð½Ð¾Ð¼Ñ_Ð´Ð¸Ð°Ð³Ð¾Ð½Ð°Ð»Ñ[piece.row + piece.col]++;
        occupied_Ð¿ÑÑÐ¼Ð¾Ð¼Ñ_Ð´Ð¸Ð°Ð³Ð¾Ð½Ð°Ð»Ñ[piece.row - piece.col]++;
    }

    // Calculate the number of safe positions
    for (int i = 1; i <= n; ++i) {
        ans -= occupied_rows[i];
        ans -= occupied_cols[i];
        ans -= occupied_Ð³Ð»Ð°Ð²Ð½Ð¾Ð¼Ñ_Ð´Ð¸Ð°Ð³Ð¾Ð½Ð°Ð»Ñ[i];
        ans -= occupied_Ð¿ÑÑÐ¼Ð¾Ð¼Ñ_Ð´Ð¸Ð°Ð³Ð¾Ð½Ð°Ð»Ñ[i];
    }

    cout << ans << endl;
    return 0;
}