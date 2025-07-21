#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;
using i128 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i128 N, M;
    cin >> N >> M;

    set<pair<i128, i128>> occupied;
    unordered_set<i128> attacked;

    for (i128 i = 0; i < M; ++i) {
        i128 a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        attacked.insert((a - 1) * N + (b - 1));

        // Check all 8 possible attack positions
        if (a + 2 <= N && b + 1 <= N) attacked.insert((a + 1) * N + (b));
        if (a + 1 <= N && b + 2 <= N) attacked.insert((a) * N + (b + 1));
        if (a - 1 >= 1 && b + 2 <= N) attacked.insert((a - 2) * N + (b + 1));
        if (a - 2 >= 1 && b + 1 <= N) attacked.insert((a - 3) * N + (b));
        if (a - 2 >= 1 && b - 1 >= 1) attacked.insert((a - 3) * N + (b - 2));
        if (a - 1 >= 1 && b - 2 >= 1) attacked.insert((a - 2) * N + (b - 3));
        if (a + 1 <= N && b - 2 >= 1) attacked.insert((a) * N + (b - 3));
        if (a + 2 <= N && b - 1 >= 1) attacked.insert((a + 1) * N + (b - 2));
    }

    i128 total_squares = N * N;
    i128 safe_squares = total_squares - attacked.size() - occupied.size() + M;

    cout << safe_squares << endl;

    return 0;
}