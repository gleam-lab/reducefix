#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(h), yoko(w);
    vector<vector<int>> status(h, vector<int>(w, 1)); // 1 means wall exists, 0 means wall destroyed

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            tate[i].insert(j);
        }
    }

    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (status[r][c] == 1) {
            // Wall exists
            status[r][c] = 0;
            tate[r].erase(c);
            if (tate[r].empty()) {
                for (int j = 0; j < w; j++) {
                    yoko[j].erase(r);
                }
            }
        } else {
            // Wall doesn't exist, destroy vertical walls
            bool vertical_destroyed = false;
            for (int i = 0; i < h; i++) {
                if (status[i][c] == 1) {
                    status[i][c] = 0;
                    tate[i].erase(c);
                    if (tate[i].empty()) {
                        for (int j = 0; j < w; j++) {
                            yoko[j].erase(i);
                        }
                    }
                    vertical_destroyed = true;
                    break;
                }
            }
            // If no vertical wall was destroyed, destroy horizontal walls
            if (!vertical_destroyed) {
                for (int i = 0; i < w; i++) {
                    if (status[r][i] == 1) {
                        status[r][i] = 0;
                        yoko[i].erase(r);
                        break;
                    }
                }
            }
        }
    }

    ll remaining_walls = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            remaining_walls += status[i][j];
        }
    }

    cout << remaining_walls << "\n";
    return 0;
}