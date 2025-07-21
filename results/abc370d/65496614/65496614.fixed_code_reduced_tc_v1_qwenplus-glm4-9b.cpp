#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n) ; ++i)
#define rep1(i,n) for(int i = 1; i < (int)(n) ; ++i)
#define rrep(i,n) for(int i = (int)n-1; i >= 0 ; --i)
#define rrep1(i,n) for(int i = (int)n-1; i >= 1 ; --i)

using ll = long long;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;

using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;

using vs = vector<string>;

string filename = __FILE__;

//===============================================
//ãããã°ç¨åºåé¢æ°===============================
//===============================================

template<typename T>
void dbg(const T &i, bool linebreak = true){
    cout << i;
    if(linebreak) cout << "\n";
    else cout << " ";
}

template<typename T>
void dbg(const vector<T> &vec, bool linebreak = true){
    for(const auto &val: vec) dbg(val, is_container<T>::value);
    cout << endl;
}

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vvb grid(h + 1, vb(w + 1, true));

    rep1(i, h) rep1(j, w) {
        if (i == 1 || j == 1 || i == h || j == w) {
            grid[i][j] = false; // Wall exists on the boundary
        }
    }

    bool queryProcessed = false;
    while (q--) {
        int r, c;
        cin >> r >> c;
        if (!grid[r][c]) {
            // Bomb placed in a cell without a wall, need to remove walls
            queryProcessed = true;

            // Remove walls above the cell
            rep1(i, r) {
                if (grid[i][c]) {
                    grid[i][c] = false;
                    queryProcessed = true;
                }
            }

            // Remove walls below the cell
            rep1(i, h - r) {
                if (grid[r + i][c]) {
                    grid[r + i][c] = false;
                    queryProcessed = true;
                }
            }

            // Remove walls to the left of the cell
            rep1(j, c) {
                if (grid[r][j]) {
                    grid[r][j] = false;
                    queryProcessed = true;
                }
            }

            // Remove walls to the right of the cell
            rep1(j, w - c) {
                if (grid[r][c + j]) {
                    grid[r][c + j] = false;
                    queryProcessed = true;
                }
            }
        } else {
            // Bomb placed in a cell with a wall, just remove the wall
            grid[r][c] = false;
            queryProcessed = true;
        }
    }

    if (!queryProcessed) {
        // If there were no queries, output the initial number of walls
        cout << (h * w) << endl;
    } else {
        // Count the remaining walls
        int remainingWalls = 0;
        rep1(i, h) rep1(j, w) {
            remainingWalls += grid[i][j];
        }
        cout << remainingWalls << endl;
    }

    return 0;
}