#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> dangerous;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        dangerous.insert({a, b});

        // Check all 8 possible attack positions
        if (a + 2 <= N && b + 1 <= N) {
            dangerous.insert({a + 2, b + 1});
        }
        if (a + 1 <= N && b + 2 <= N) {
            dangerous.insert({a + 1, b + 2});
        }
        if (a - 1 >= 1 && b + 2 <= N) {
            dangerous.insert({a - 1, b + 2});
        }
        if (a - 2 >= 1 && b + 1 <= N) {
            dangerous.insert({a - 2, b + 1});
        }
        if (a - 2 >= 1 && b - 1 >= 1) {
            dangerous.insert({a - 2, b - 1});
        }
        if (a - 1 >= 1 && b - 2 >= 1) {
            dangerous.insert({a - 1, b - 2});
        }
        if (a + 1 <= N && b - 2 >= 1) {
            dangerous.insert({a + 1, b - 2});
        }
        if (a + 2 <= N && b - 1 >= 1) {
            dangerous.insert({a + 2, b - 1});
        }
    }

    long long total_squares = N * N;
    long long dangerous_count = dangerous.size();
    long long safe_squares = total_squares - dangerous_count;

    cout << safe_squares << '\n';

    return 0;
}