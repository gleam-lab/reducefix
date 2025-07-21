#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long i64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<pair<i64, i64>> forbidden;

    for (i64 k = 0; k < M; ++k) {
        i64 a, b;
        cin >> a >> b;
        forbidden.insert({a, b});

        // Check all 8 possible attack positions and add them to forbidden if within bounds
        if (a + 2 <= N && b + 1 <= N) forbidden.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) forbidden.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) forbidden.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) forbidden.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) forbidden.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) forbidden.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) forbidden.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) forbidden.insert({a + 2, b - 1});
    }

    i64 total = N * N;
    i64 safe = total - forbidden.size();

    cout << safe << endl;

    return 0;
}