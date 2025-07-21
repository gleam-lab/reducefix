#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> forbidden;
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        forbidden.insert({a, b});

        // Check all 8 possible capture positions
        if (a + 2 <= N && b + 1 <= N) forbidden.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) forbidden.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) forbidden.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) forbidden.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) forbidden.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) forbidden.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) forbidden.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) forbidden.insert({a + 2, b - 1});
    }

    cout << N * N - forbidden.size() << '\n';

    return 0;
}