#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
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
#define len(x) x.size()

#define FOR_U(r, b, e, s) for (i64 r = (i64)b; r < (i64)e; r += (i64)s)
#define FOR_L(r, b, e, s) for (i64 r = (i64)b; r > (i64)e; r -= (i64)s)
#define FOR_R(r, b) for (auto r : b)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    set<pair<i32, i32>> captured_squares; // Use a set for fast lookup
    pair<i32, i32> p;

    FOR_U(i, 0, M, 1) {
        cin >> p.fi >> p.se;
        captured_squares.insert(p);

        // Check and add attack positions
        if (p.fi + 2 <= N && p.se + 1 <= N) captured_squares.insert({p.fi + 2, p.se + 1}); // (i+2, j+1)
        if (p.fi + 1 <= N && p.se + 2 <= N) captured_squares.insert({p.fi + 1, p.se + 2}); // (i+1, j+2)
        if (p.fi - 1 >= 1 && p.se + 2 <= N) captured_squares.insert({p.fi - 1, p.se + 2}); // (i-1, j+2)
        if (p.fi - 2 >= 1 && p.se + 1 <= N) captured_squares.insert({p.fi - 2, p.se + 1}); // (i-2, j+1)
        if (p.fi - 2 >= 1 && p.se - 1 >= 1) captured_squares.insert({p.fi - 2, p.se - 1}); // (i-2, j-1)
        if (p.fi - 1 >= 1 && p.se - 2 >= 1) captured_squares.insert({p.fi - 1, p.se - 2}); // (i-1, j-2)
        if (p.fi + 1 <= N && p.se - 2 >= 1) captured_squares.insert({p.fi + 1, p.se - 2}); // (i+1, j-2)
        if (p.fi + 2 <= N && p.se - 1 >= 1) captured_squares.insert({p.fi + 2, p.se - 1}); // (i+2, j-1)
    }

    // Calculate the number of valid squares
    i64 valid_squares = N * N - len(captured_squares);
    out(valid_squares);

    return 0;
}