#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <cassert>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    long long M;
    cin >> N >> M;

    set<pair<long long, long long>> pieces;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});

        if (a + 2 <= N && b + 1 <= N) pieces.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) pieces.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) pieces.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) pieces.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) pieces.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) pieces.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) pieces.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) pieces.insert({a + 2, b - 1});
    }

    long long total_empty_squares = N * N;
    long long blocked_squares = pieces.size();

    cout << total_empty_squares - blocked_squares << endl;

    return 0;
}