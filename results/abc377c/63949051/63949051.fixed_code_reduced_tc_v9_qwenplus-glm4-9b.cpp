#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
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

#define FOR_U(r, b, e, s) for (i64 r = b; r < e; r += s)
#define FOR_L(r, b, e, s) for (i64 r = b; r > e; r -= s)
#define FOR_R(r, b) for (auto r : b)

#define in let

int main()
{
    i64 N, M;
    in >> N >> M;

    vector<pair<i64, i64>> pieces(M);
    for (i64 i = 0; i < M; ++i) {
        in >> pieces[i].fi >> pieces[i].se;
    }

    set<pair<i64, i64>> used_cells;
    for (const auto& piece : pieces) {
        used_cells.insert(piece);
        for (i64 di = -2; di <= 2; ++di) {
            for (i64 dj = -2; dj <= 2; ++dj) {
                if (di == 0 && dj == 0) continue;
                i64 ni = piece.fi + di, nj = piece.se + dj;
                if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                    used_cells.insert({ni, nj});
                }
            }
        }
    }

    cout << (N * N - len(used_cells)) << endl;

    return 0;
}