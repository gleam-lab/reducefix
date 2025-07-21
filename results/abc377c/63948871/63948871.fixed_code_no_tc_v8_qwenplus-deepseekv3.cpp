#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

#define i128 long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i128 N, M;
    cin >> N >> M;

    set<pair<i128, i128>> knights;
    set<pair<i128, i128>> attacked;

    for (i128 i = 0; i < M; ++i) {
        i128 a, b;
        cin >> a >> b;
        knights.insert({a, b});

        // Check all 8 possible attack positions
        if (a + 2 <= N && b + 1 <= N) attacked.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) attacked.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) attacked.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) attacked.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) attacked.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) attacked.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) attacked.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) attacked.insert({a + 2, b - 1});
    }

    // The safe positions are total positions minus occupied and attacked positions
    // But attacked positions already include occupied positions, so we need to subtract them
    i128 total = N * N;
    i128 occupied_and_attacked = M;
    for (const auto& pos : attacked) {
        if (knights.find(pos) == knights.end()) {
            occupied_and_attacked++;
        }
    }

    i128 ans = total - occupied_and_attacked;
    cout << ans << endl;

    return 0;
}