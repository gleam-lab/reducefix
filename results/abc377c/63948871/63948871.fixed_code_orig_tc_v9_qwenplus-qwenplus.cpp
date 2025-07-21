#include <iostream>
#include <unordered_set>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    // To store occupied positions
    unordered_multiset<pair<long long, long long>, 
        function<size_t(pair<long long, long long>)>> occupied(2 * M, [](const pair<long long, long long>& p) {
            return (p.first << 32) ^ p.second;
        });

    // To store attacked positions
    unordered_multiset<pair<long long, long long>,
        function<size_t(pair<long long, long long>)>> attacked(8 * M, [](const pair<long long, long long>& p) {
            return (p.first << 32) ^ p.second;
        });

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        // All 8 knight moves
        const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int j = 0; j < 8; ++j) {
            long long na = a + dx[j];
            long long nb = b + dy[j];
            if (na >= 1 && na <= N && nb >= 1 && nb <= N) {
                attacked.insert({na, nb});
            }
        }
    }

    // Count unique invalid positions: occupied + attacked
    unordered_multiset<pair<long long, long long>, 
        function<size_t(pair<long long, long long>)>> invalid_positions(occupied.size() + attacked.size(), [](const pair<long long, long long>& p) {
            return (p.first << 32) ^ p.second;
        });

    for (auto& p : occupied) invalid_positions.insert(p);
    for (auto& p : attacked) invalid_positions.insert(p);

    // Total positions = N^2
    // Valid positions = N*N - number of distinct invalid positions
    unsigned __int128 total = (__int128)N * N;
    unsigned __int128 ans = total - invalid_positions.size();

    cout << ans << "\n";

    return 0;
}