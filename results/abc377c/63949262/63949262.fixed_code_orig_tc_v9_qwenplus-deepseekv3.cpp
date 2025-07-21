#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> occupied;
    set<pair<long long, long long>> unsafe;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        unsafe.insert({a, b});

        // Check all 8 possible knight moves
        const long long dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const long long dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (long long j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe.insert({x, y});
            }
        }
    }

    long long total = N * N;
    long long unsafe_count = unsafe.size();
    long long safe = total - unsafe_count;

    cout << safe << endl;

    return 0;
}