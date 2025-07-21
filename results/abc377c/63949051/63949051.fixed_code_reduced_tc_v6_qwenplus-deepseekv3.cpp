#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> unsafe_squares;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        unsafe_squares.insert({a, b});

        // Check all 8 possible attack positions
        if (a + 2 <= N && b + 1 <= N) {
            unsafe_squares.insert({a + 2, b + 1});
        }
        if (a + 1 <= N && b + 2 <= N) {
            unsafe_squares.insert({a + 1, b + 2});
        }
        if (a - 1 >= 1 && b + 2 <= N) {
            unsafe_squares.insert({a - 1, b + 2});
        }
        if (a - 2 >= 1 && b + 1 <= N) {
            unsafe_squares.insert({a - 2, b + 1});
        }
        if (a - 2 >= 1 && b - 1 >= 1) {
            unsafe_squares.insert({a - 2, b - 1});
        }
        if (a - 1 >= 1 && b - 2 >= 1) {
            unsafe_squares.insert({a - 1, b - 2});
        }
        if (a + 1 <= N && b - 2 >= 1) {
            unsafe_squares.insert({a + 1, b - 2});
        }
        if (a + 2 <= N && b - 1 >= 1) {
            unsafe_squares.insert({a + 2, b - 1});
        }
    }

    long long total_squares = N * N;
    long long unsafe_count = unsafe_squares.size();
    long long safe_squares = total_squares - unsafe_count;

    cout << safe_squares << endl;

    return 0;
}