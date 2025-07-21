#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e9 + 10;
const int DIRS[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    unordered_set<long long> blocked;
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        long long idx = (a - 1) * n + b;
        
        // Check all directions
        for (int d = 0; d < 8; ++d) {
            int dx = DIRS[d][0], dy = DIRS[d][1];
            long long x = a + dx, y = b + dy;
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                blocked.insert((x - 1) * n + y);
            }
        }
    }

    // Calculate the number of unblocked positions
    long long total_squares = n * n;
    long long unblocked_squares = total_squares - blocked.size();

    cout << unblocked_squares << endl;

    return 0;
}