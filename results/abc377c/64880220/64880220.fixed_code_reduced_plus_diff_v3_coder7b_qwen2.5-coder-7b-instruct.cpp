#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    long long n, m;
    cin >> n >> m;

    unordered_set<long long> occupied;
    vector<vector<bool>> board(n + 1, vector<bool>(n + 1, false));

    for(long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert((a - 1) * n + b);
        board[a][b] = true;
    }

    long long count = 0;
    for(long long i = 1; i <= n; ++i) {
        for(long long j = 1; j <= n; ++j) {
            bool canPlace = true;
            vector<pair<long long, long long>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
            for(auto [di, dj] : directions) {
                long long ni = i + di, nj = j + dj;
                if(ni >= 1 && ni <= n && nj >= 1 && nj <= n && !board[ni][nj]) {
                    long long idx = (ni - 1) * n + nj;
                    if(occupied.find(idx) != occupied.end()) {
                        canPlace = false;
                        break;
                    }
                }
            }
            if(canPlace) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}