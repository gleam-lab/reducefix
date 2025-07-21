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

    set<pair<long long, long long>> attacked_or_occupied;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        attacked_or_occupied.insert({a, b});

        // Check all 8 possible attack positions
        if (a + 2 <= N && b + 1 <= N) attacked_or_occupied.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) attacked_or_occupied.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) attacked_or_occupied.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) attacked_or_occupied.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) attacked_or_occupied.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) attacked_or_occupied.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) attacked_or_occupied.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) attacked_or_occupied.insert({a + 2, b - 1});
    }

    long long total_squares = N * N;
    long long unsafe_squares = attacked_or_occupied.size();
    long long safe_squares = total_squares - unsafe_squares;

    cout << safe_squares << endl;

    return 0;
}