#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    unordered_set<long long> unsafe;
    vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        unsafe.insert((a - 1) * N + (b - 1)); // Using 0-based index for easier calculation

        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe.insert((x - 1) * N + (y - 1));
            }
        }
    }

    cout << N * N - unsafe.size() << endl;
    return 0;
}