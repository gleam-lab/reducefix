#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define i64 long long
#define i128 __int128_t

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N;
    int M;
    cin >> N >> M;

    set<pair<i64, i64>> attacked;
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        attacked.insert({a, b});

        // Check all 8 possible attack positions
        if (a + 2 <= N && b + 1 <= N) attacked.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) attacked.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) attacked.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) attacked.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) attacked.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) attacked.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) attacked.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) attacked.insert({a + 2, b - 1});
    }

    i128 total_squares = (i128)N * N;
    i128 unsafe_squares = attacked.size();
    i128 safe_squares = total_squares - unsafe_squares;

    // Print the result, handling the large number properly
    if (safe_squares <= (i128)1e18) {
        cout << (i64)safe_squares << '\n';
    } else {
        // For very large numbers, we can print them directly as strings if needed,
        // but the problem constraints ensure that the output fits within a 64-bit integer.
        cout << (i64)safe_squares << '\n';
    }

    return 0;
}