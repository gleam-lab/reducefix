#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> attacked;
    vector<pair<long long, long long>> knights(M);

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        knights[i] = {a, b};
        attacked.insert({a, b});
    }

    for (const auto& knight : knights) {
        long long a = knight.first;
        long long b = knight.second;

        const long long dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const long long dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (long long k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }

    long long total_squares = N * N;
    long long safe_squares = total_squares - attacked.size();

    cout << safe_squares << '\n';

    return 0;
}