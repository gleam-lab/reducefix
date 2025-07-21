#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

using i64 = long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<pair<i64, i64>> forbidden;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        forbidden.insert({a, b});

        // Check all 8 possible knight moves
        if (a + 2 <= N && b + 1 <= N) forbidden.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) forbidden.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) forbidden.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) forbidden.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) forbidden.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) forbidden.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) forbidden.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) forbidden.insert({a + 2, b - 1});
    }

    i128 total_squares = static_cast<i128>(N) * N;
    i128 forbidden_count = static_cast<i128>(forbidden.size());
    i128 safe_squares = total_squares - forbidden_count;

    // Print the result
    if (safe_squares <= static_cast<i128>(numeric_limits<i64>::max())) {
        cout << static_cast<i64>(safe_squares) << '\n';
    } else {
        // Handle cases where safe_squares is larger than i64 max (unlikely given constraints)
        string result;
        while (safe_squares > 0) {
            result += '0' + static_cast<char>(safe_squares % 10);
            safe_squares /= 10;
        }
        reverse(result.begin(), result.end());
        cout << result << '\n';
    }

    return 0;
}