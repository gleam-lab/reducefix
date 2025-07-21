#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> unsafe;
    vector<pair<long long, long long>> knights(M);

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        knights[i] = {a, b};
        unsafe.insert({a, b});
    }

    const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (const auto& knight : knights) {
        long long a = knight.first;
        long long b = knight.second;
        for (int k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
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