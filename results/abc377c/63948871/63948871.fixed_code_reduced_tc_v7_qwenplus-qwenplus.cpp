#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

using i32 = int;
using i64 = long long;
using u64 = unsigned long long;
using pII = pair<i32, i32>;

const i64 INF = 1e18;

i64 N;
i32 M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    set<pII> attacked_cells;
    vector<pII> pieces(M);

    for (int m = 0; m < M; ++m) {
        i32 a, b;
        cin >> a >> b;
        pieces[m] = {a, b};

        // Add current piece position to attacked cells
        attacked_cells.insert({a, b});

        // Define all 8 possible knight-like moves that could attack this cell
        const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            int na = a + dx[k];
            int nb = b + dy[k];
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                attacked_cells.insert({na, nb});
            }
        }
    }

    // Calculate total number of safe cells
    i64 total_cells = N * N;
    i64 attacked_count = attacked_cells.size();
    i64 result = total_cells - attacked_count;

    cout << result << endl;

    return 0;
}