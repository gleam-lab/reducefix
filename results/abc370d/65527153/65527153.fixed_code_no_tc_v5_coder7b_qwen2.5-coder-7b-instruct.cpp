#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4e5 + 7;

vector<int> row[MAXN], col[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w, q;
    cin >> h >> w >> q;

    // Initialize the grids with all cells containing a wall
    for(int i = 1; i <= h; ++i) row[i] = {j for j in range(1, w+1)};
    for(int j = 1; j <= w; ++j) col[j] = {i for i in range(1, h+1)};

    for(int qi = 0; qi < q; ++qi) {
        int ri, ci;
        cin >> ri >> ci;
        // If there is already no wall, skip this query
        if(!row[ri].empty() && !col[ci].empty()) {
            // Remove the wall from both row and column sets
            row[ri].erase(find(row[ri].begin(), row[ri].end(), ci));
            col[ci].erase(find(col[ci].begin(), col[ci].end(), ri));

            // Adjust the rest of the row and column sets
            if(!row[ri].empty()) {
                auto it = lower_bound(row[ri].begin(), row[ri].end(), ci);
                if(it != row[ri].end()) {
                    int next = *it;
                    col[next].erase(find(col[next].begin(), col[next].end(), ri));
                } else {
                    int prev = row[ri].back();
                    col[prev].erase(find(col[prev].begin(), col[prev].end(), ri));
                }
            }

            if(!col[ci].empty()) {
                auto it = lower_bound(col[ci].begin(), col[ci].end(), ri);
                if(it != col[ci].end()) {
                    int next = *it;
                    row[next].erase(find(row[next].begin(), row[next].end(), ci));
                } else {
                    int prev = col[ci].back();
                    row[prev].erase(find(row[prev].begin(), row[prev].end(), ci));
                }
            }
        }
    }

    // Count the remaining walls
    int count = 0;
    for(int i = 1; i <= h; ++i) count += row[i].size();
    for(int j = 1; j <= w; ++j) count += col[j].size();

    // Since each wall is counted twice, we divide by 2
    cout << count / 2 << '\n';

    return 0;
}