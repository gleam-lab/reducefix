#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> threats;

    for (long long k = 0; k < M; ++k) {
        long long a, b;
        cin >> a >> b;

        // Check all 8 directions for threatening squares
        threats.insert({a + 2, b + 1});
        threats.insert({a + 1, b + 2});
        threats.insert({a - 1, b + 2});
        threats.insert({a - 2, b + 1});
        threats.insert({a - 2, b - 1});
        threats.insert({a - 1, b - 2});
        threats.insert({a + 1, b - 2});
        threats.insert({a + 2, b - 1});

        // Ensure indices remain within bounds
        threats.erase(threats.find({a + 2, b + 1}));
        threats.erase(threats.find({a + 1, b + 2}));
        threats.erase(threats.find({a - 1, b + 2}));
        threats.erase(threats.find({a - 2, b + 1}));
        threats.erase(threats.find({a - 2, b - 1}));
        threats.erase(threats.find({a - 1, b - 2}));
        threats.erase(threats.find({a + 1, b - 2}));
        threats.erase(threats.find({a + 2, b - 1}));

        if (a + 2 <= N && b + 1 <= N) threats.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) threats.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) threats.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) threats.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) threats.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) threats.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) threats.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) threats.insert({a + 2, b - 1});
    }

    cout << N * N - threats.size() << endl;

    return 0;
}