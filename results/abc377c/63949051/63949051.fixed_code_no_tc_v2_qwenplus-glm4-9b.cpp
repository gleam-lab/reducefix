#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define INF 1000000000

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> available;
    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j <= N; ++j) {
            available.insert({i, j});
        }
    }

    for (long long k = 0; k < M; ++k) {
        long long a, b;
        cin >> a >> b;
        // Remove the positions that the piece can attack
        available.erase({a, b}); // Remove the piece itself
        if (a + 2 <= N && b + 1 <= N) available.erase({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) available.erase({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) available.erase({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) available.erase({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) available.erase({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) available.erase({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) available.erase({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) available.erase({a + 2, b - 1});
    }

    cout << available.size() << endl;

    return 0;
}