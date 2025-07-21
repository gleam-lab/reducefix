#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define INF 1000000000
#define LINF 1000000000000000000

#define fi first
#define se second

#define i32 int
#define i64 long long

#define u32 unsigned int
#define u64 unsigned long long

#define f32 float
#define f64 double

#define str string
#define vec vector
#define cc const char *

#define all(x) x.begin(), x.end()
#define len(x) x.size()
#define elif else if

#define FOR_U(r, b, e, s) for (i64 r = (i64)b; r < (i64)e; r += (i64)s)
#define FOR_L(r, b, e, s) for (i64 r = (i64)b; r > (i64)e; r -= (i64)s)
#define FOR_R(r, b) for (auto r : b)

#define pow2(x) (1LL << (x))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N;
    cin >> N;
    i64 M;
    cin >> M;

    vector<vector<int>> grid(N + 1, vector<int>(N + 1, 0));
    set<pair<i64, i64>> pieces;

    FOR_L(i, 1, M + 1) {
        i64 x, y;
        cin >> x >> y;
        grid[x][y]++;
        pieces.insert({x, y});
    }

    vector<pair<i64, i64>> directions = {
        {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1},
        {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}
    };

    i64 unprotected = 0;
    FOR_U(i, 1, N + 1) {
        FOR_U(j, 1, N + 1) {
            bool protected_by_piece = false;
            for (auto dir : directions) {
                i64 ni = i + dir.first, nj = j + dir.second;
                if (ni > 0 && ni <= N && nj > 0 && nj <= N && grid[ni][nj] > 0) {
                    protected_by_piece = true;
                    break;
                }
            }
            if (!protected_by_piece) {
                unprotected++;
                for (auto dir : directions) {
                    i64 ni = i + dir.first, nj = j + dir.second;
                    if (ni > 0 && ni <= N && nj > 0 && nj <= N) {
                        grid[ni][nj]--;
                    }
                }
            }
        }
    }

    cout << unprotected << "\n";

    return 0;
}