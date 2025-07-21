#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long h, w, q;
    cin >> h >> w >> q;

    vector<vector<set<long long>>> row(h, vector<set<long long>>(w));
    vector<vector<set<long long>>> col(w, vector<set<long long>>(h));
    long long initialWalls = h * w;

    for (long long i = 0; i < h; i++) {
        for (long long j = 0; j < w; j++) {
            row[i][j] = {j};
            col[j][i] = {i};
        }
    }

    for (long long i = 0; i < q; i++) {
        long long r, c;
        cin >> r >> c;
        r--; c--;

        if (row[r][c].size() > 0) {
            // A wall exists at (r, c)
            row[r][c].erase(c);
            col[c][r].erase(r);
        } else {
            // No wall at (r, c), need to remove contiguous walls
            set<long long> left({c - 1});
            set<long long> right({c + 1});
            set<long long> up({r - 1});
            set<long long> down({r + 1});

            // Erase walls from left
            while (!left.empty()) {
                long long x = *left.begin();
                if (row[r][x].size() > 0) {
                    row[r][x].erase(x);
                    col[x][r].erase(r);
                    left = row[r][x];
                } else {
                    left.erase(left.begin());
                }
            }

            // Erase walls from right
            while (!right.empty()) {
                long long x = *right.begin();
                if (row[r][x].size() > 0) {
                    row[r][x].erase(x);
                    col[x][r].erase(r);
                    right = row[r][x];
                } else {
                    right.erase(right.begin());
                }
            }

            // Erase walls from up
            while (!up.empty()) {
                long long x = *up.begin();
                if (col[c][x].size() > 0) {
                    col[c][x].erase(x);
                    row[x][c].erase(c);
                    up = col[c][x];
                } else {
                    up.erase(up.begin());
                }
            }

            // Erase walls from down
            while (!down.empty()) {
                long long x = *down.begin();
                if (col[c][x].size() > 0) {
                    col[c][x].erase(x);
                    row[x][c].erase(c);
                    down = col[c][x];
                } else {
                    down.erase(down.begin());
                }
            }
        }
    }

    // Count remaining walls
    long long remainingWalls = 0;
    for (long long i = 0; i < h; i++) {
        for (long long j = 0; j < w; j++) {
            remainingWalls += row[i][j].size();
        }
    }

    cout << remainingWalls << endl;

    return 0;
}