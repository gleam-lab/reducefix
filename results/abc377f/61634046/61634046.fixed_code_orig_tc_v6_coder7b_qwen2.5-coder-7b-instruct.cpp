#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> rows(n+1), cols(n+1);
    vector<vector<int>> up(2, vector<int>(n+1)), down(2, vector<int>(n+1));

    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y; // Convert to 0-based indexing
        rows[x] = 1;
        cols[y] = 1;
        up[(x+y)&1][x-y+n] = 1;
        down[(x+y)&1][x+y] = 1;
    }

    ll res = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(!rows[i] && !cols[j] && !up[0][i-j+n] && !up[1][i+j] && !down[0][i-j+n] && !down[1][i+j]) {
                ++res;
            }
        }
    }

    cout << res << endl;
    
    return 0;
}