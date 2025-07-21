#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> under_attack;
    set<pair<long long, long long>> pieces;

    for (long long _ = 0; _ < M; ++_) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        under_attack.insert({a, b});

        // Check all 8 possible attack positions
        if (a + 2 <= N && b + 1 <= N) under_attack.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) under_attack.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) under_attack.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) under_attack.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) under_attack.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) under_attack.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) under_attack.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) under_attack.insert({a + 2, b - 1});
    }

    long long total_squares = N * N;
    long long unsafe_squares = under_attack.size();
    long long safe_squares = total_squares - unsafe_squares;

    cout << safe_squares << '\n';

    return 0;
}