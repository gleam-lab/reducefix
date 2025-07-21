#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<pair<i64, i64>> unsafe;
    set<pair<i64, i64>> existing;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        existing.insert({a, b});
        unsafe.insert({a, b});

        // Check all 8 possible attack positions
        i64 dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        i64 dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            i64 x = a + dx[k];
            i64 y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe.insert({x, y});
            }
        }
    }

    i64 total_squares = N * N;
    i64 unsafe_squares = unsafe.size();
    i64 safe_squares = total_squares - unsafe_squares;

    cout << safe_squares << '\n';

    return 0;
}