#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    vector<vector<int>> captured(n + 1, vector<int>(n + 1, 0));

    // Read the positions of the existing pieces and update the captured grid accordingly
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        captured[a][b] = 1;
        
        // Update the captured grid based on the piece's capture range
        for (int j = 1; j <= 2 && a + j <= n; ++j) { // i+2,j+1
            captured[a + j][b] = 1;
        }
        for (int j = 1; j <= 2 && b + j <= n; ++j) { // i+1,j+2
            captured[a][b + j] = 1;
        }
        for (int j = 1; j <= 2 && a - j >= 1; ++j) { // i-2,j+1
            captured[a - j][b] = 1;
        }
        for (int j = 1; j <= 2 && b - j >= 1; ++j) { // i+2,j-1
            captured[a][b - j] = 1;
        }
        for (int j = 1; j <= 2 && a + j <= n; ++j) { // i+1,j-2
            captured[a][b - j] = 1;
        }
        for (int j = 1; j <= 2 && a - j >= 1; ++j) { // i-1,j-2
            captured[a - j][b] = 1;
        }
    }

    // Calculate the number of empty squares not captured by any piece
    long long empty_squares = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (captured[i][j] == 0) {
                empty_squares++;
            }
        }
    }

    cout << empty_squares << endl;

    return 0;
}