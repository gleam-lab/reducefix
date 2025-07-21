#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> attacked;
    set<pair<long long, long long>> pieces;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        attacked.insert({a, b});

        // Check all 8 possible moves
        if (a + 2 <= N && b + 1 <= N) attacked.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) attacked.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) attacked.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) attacked.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) attacked.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) attacked.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) attacked.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) attacked.insert({a + 2, b - 1});
    }

    long long total_squares = N * N;
    long long invalid_squares = attacked.size();
    long long answer = total_squares - invalid_squares;

    cout << answer << "\n";

    return 0;
}