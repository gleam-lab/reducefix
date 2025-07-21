#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    long long M;
    cin >> N >> M;

    set<pair<long long, long long>> anti_dup;
    set<pair<long long, long long>> reachable;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        
        anti_dup.insert({a, b});

        if (a + 2 <= N && b + 1 <= N) reachable.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) reachable.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) reachable.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) reachable.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) reachable.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) reachable.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) reachable.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) reachable.insert({a + 2, b - 1});
    }

    // Remove overlapping positions
    for (auto& pos : anti_dup) {
        reachable.erase(pos);
    }

    long long result = N * N - anti_dup.size();
    cout << result << endl;

    return 0;
}