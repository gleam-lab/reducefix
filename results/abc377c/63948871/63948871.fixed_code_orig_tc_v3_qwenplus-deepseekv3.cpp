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

    set<pair<long long, long long>> occupied_or_attacked;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied_or_attacked.insert({a, b});

        // All 8 possible attack positions
        if (a + 2 <= N && b + 1 <= N) occupied_or_attacked.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) occupied_or_attacked.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) occupied_or_attacked.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) occupied_or_attacked.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) occupied_or_attacked.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) occupied_or_attacked.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) occupied_or_attacked.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) occupied_or_attacked.insert({a + 2, b - 1});
    }

    long long total_squares = N * N;
    long long unsafe_squares = occupied_or_attacked.size();
    long long safe_squares = total_squares - unsafe_squares;

    cout << safe_squares << endl;

    return 0;
}