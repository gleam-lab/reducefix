#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);

    // Initialize the sets with all positions
    rep(i, h) rep(j, w) {
        tate[j].insert(i);
        yoko[i].insert(j);
    }

    // Process each query
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to zero-based index

        if (!tate[c].empty() && *tate[c].begin() == r) { // Check if there is a wall above
            tate[c].erase(tate[c].begin());
            yoko[r].erase(c);
        } else if (!tate[c].empty() && *tate[c].rbegin() == r) { // Check if there is a wall below
            tate[c].erase(prev(tate[c].end()));
            yoko[r].erase(c);
        } else if (!yoko[r].empty() && *yoko[r].begin() == c) { // Check if there is a wall to the left
            yoko[r].erase(yoko[r].begin());
            tate[c].erase(r);
        } else if (!yoko[r].empty() && *yoko[r].rbegin() == c) { // Check if there is a wall to the right
            yoko[r].erase(prev(yoko[r].end()));
            tate[c].erase(r);
        }
    }

    // Calculate the number of remaining walls
    int ans = 0;
    rep(i, w) {
        ans += tate[i].size();
    }
    cout << ans << "\n";

    return 0;
}