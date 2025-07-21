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

    for (auto knight : knights) {
        long long x = knight.first;
        long long y = knight.second;
        for (int i = 0; i < 8; ++i) {
            long long nx = x + dx[i];
            long long ny = y + dy[i];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                unsafe.insert({nx, ny});
            }
        }
    }

    long long total_squares = N * N;
    long long unsafe_squares = unsafe.size();
    long long safe_squares = total_squares - unsafe_squares;

    cout << safe_squares << "\n";

    return 0;
}