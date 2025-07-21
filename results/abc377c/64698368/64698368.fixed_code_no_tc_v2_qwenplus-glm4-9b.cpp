#include <iostream>
#include <vector>
#include <set>
#include <cmath>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define rrepi(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); i--)
#define ALL(a) (a).begin(), (a).end()
#define ALL_(a) (a), (a) + (int)(a).size()

using namespace std;

int N, M;
set<pair<int, int>> occupied;

// Function to check if a cell is occupied
bool is_occupied(int r, int c) {
    return occupied.count({r, c});
}

// Function to check if a cell can be occupied
bool can_occupy(int r, int c) {
    if (is_occupied(r, c)) return false;
    for (int dr = -2; dr <= 2; dr++) {
        for (int dc = -2; dc <= 2; dc++) {
            if (abs(dr) + abs(dc) > 1) {
                if (r + dr >= 0 && r + dr < N && c + dc >= 0 && c + dc < N) {
                    if (is_occupied(r + dr, c + dc)) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);

    rep(i, M) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a - 1, b - 1};
        occupied.insert(pieces[i]);
    }

    // Calculate the total number of cells
    long long total_cells = N * N;

    // Calculate the number of cells that can be occupied
    long long can_occupy_cells = 0;
    repi(r, 0, N) {
        repi(c, 0, N) {
            if (can_occupy(r, c)) {
                can_occupy_cells++;
            }
        }
    }

    // Output the number of cells that can be occupied
    cout << can_occupy_cells << endl;

    return 0;
}