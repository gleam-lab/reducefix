#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> attacked;
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        attacked.insert({a, b});

        // Check all 8 possible knight moves
        if (a + 2 <= N && b + 1 <= N) attacked.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) attacked.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) attacked.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) attacked.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) attacked.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) attacked.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) attacked.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) attacked.insert({a + 2, b - 1});
    }

    cout << N * N - attacked.size() << '\n';

    return 0;
}