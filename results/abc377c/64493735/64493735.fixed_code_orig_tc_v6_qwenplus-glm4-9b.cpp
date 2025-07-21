#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define v(type) vector<type>
#define p(ate,bte) pair<ate,bte>
#define m(ate,bte) map<ate,bte>
#define s(type) set<type>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    // Maximum number of cells that can be captured by one piece
    int max_capturable_cells = 8;

    // Array to track the number of pieces that can capture each cell
    int capturable[max_capturable_cells][N][N] = {0};

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based index

        // For each direction a piece can move, check if it's within bounds and increase the count
        capturable[0][a][b]++; // a+2, b+1
        capturable[1][a][b]++; // a+1, b+2
        capturable[2][a][b]++; // a-1, b+2
        capturable[3][a][b]++; // a-2, b+1
        capturable[4][a][b]++; // a-2, b-1
        capturable[5][a][b]++; // a-1, b-2
        capturable[6][a][b]++; // a+1, b-2
        capturable[7][a][b]++; // a+2, b-1
    }

    // Set to track cells that can potentially capture a new piece
    s<p<int, int>> capture_cells;
    for (int i = 0; i < max_capturable_cells; ++i) {
        for (int a = 0; a < N; ++a) {
            for (int b = 0; b < N; ++b) {
                if (capturable[i][a][b] > 0) {
                    capture_cells.emplace(a, b);
                }
            }
        }
    }

    // Calculate the number of free cells
    long long free_cells = N * N - capture_cells.size();

    cout << free_cells << '\n';

    return 0;
}