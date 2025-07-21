#include <iostream>
#include <vector>
#include <iostream>

#define N 1000000000

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(n * n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        pieces[i] = {x - 1, y - 1};
    }

    vector<vector<bool>> can_be_taken(n, vector<bool>(n, true));

    for (auto& p : pieces) {
        int x = p.first;
        int y = p.second;
        // Check all 8 possible moves
        can_be_taken[x + 2][y + 1] = false;
        can_be_taken[x + 1][y + 2] = false;
        can_be_taken[x - 1][y + 2] = false;
        can_be_taken[x - 2][y + 1] = false;
        can_be_taken[x - 2][y - 1] = false;
        can_be_taken[x - 1][y - 2] = false;
        can_be_taken[x + 1][y - 2] = false;
        can_be_taken[x + 2][y - 1] = false;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (can_be_taken[i][j]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}