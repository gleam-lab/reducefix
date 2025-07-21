#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    unordered_set<long long> dangerous;
    unordered_set<long long> occupied;

    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert(a * (N + 1) + b); // Using a unique key for each (a, b)

        for (int k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                dangerous.insert(x * (N + 1) + y);
            }
        }
    }

    long long total = N * N;
    long long unsafe = 0;

    for (long long pos : dangerous) {
        if (occupied.find(pos) == occupied.end()) {
            unsafe++;
        }
    }

    unsafe += occupied.size(); // All occupied squares are also unsafe
    long long safe = total - unsafe;

    cout << safe << endl;
    return 0;
}