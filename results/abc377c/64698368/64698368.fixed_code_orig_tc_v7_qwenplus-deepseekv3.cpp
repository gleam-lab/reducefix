#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<long long, long long>> unsafe;
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        a--; b--;
        unsafe.insert({a, b});
        for (const auto& dir : directions) {
            long long new_a = a + dir.first;
            long long new_b = b + dir.second;
            if (new_a >= 0 && new_a < N && new_b >= 0 && new_b < N) {
                unsafe.insert({new_a, new_b});
            }
        }
    }

    long long total = N * N;
    long long unsafe_count = unsafe.size();
    cout << total - unsafe_count << endl;
    return 0;
}