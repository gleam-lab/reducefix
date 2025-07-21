#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define INF 1000000000

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

#define FOR_U(r, b, e, s) for (i64 r = (i64)b; r < (i64)e; r += (i64)s)
#define FOR_L(r, b, e, s) for (i64 r = (i64)b; r > (i64)e; r -= (i64)s)
#define FOR_R(r, b) for (auto r : b)

#define out(out_data) cout << out_data << '\n'
#define outvec(out_data, sep) cout << sep.join(out_data) << '\n'

int main() {
    i64 N, M;
    cin >> N >> M;

    set<pair<i64, i64>> captured_cells;

    pair<i64, i64> coordinates[M];
    FOR_U(i, 0, M, 1) {
        cin >> coordinates[i].fi >> coordinates[i].se;
    }

    FOR_U(i, 0, M, 1) {
        auto &c = coordinates[i];
        if (c.fi + 2 <= N && c.se + 1 <= N) captured_cells.insert({c.fi + 2, c.se + 1});
        if (c.fi + 1 <= N && c.se + 2 <= N) captured_cells.insert({c.fi + 1, c.se + 2});
        if (c.fi - 1 >= 1 && c.se + 2 <= N) captured_cells.insert({c.fi - 1, c.se + 2});
        if (c.fi - 2 >= 1 && c.se + 1 <= N) captured_cells.insert({c.fi - 2, c.se + 1});
        if (c.fi - 2 >= 1 && c.se - 1 >= 1) captured_cells.insert({c.fi - 2, c.se - 1});
        if (c.fi - 1 >= 1 && c.se - 2 >= 1) captured_cells.insert({c.fi - 1, c.se - 2});
        if (c.fi + 1 <= N && c.se - 2 >= 1) captured_cells.insert({c.fi + 1, c.se - 2});
        if (c.fi + 2 <= N && c.se - 1 >= 1) captured_cells.insert({c.fi + 2, c.se - 1});
    }

    out(N * N - captured_cells.size());
}