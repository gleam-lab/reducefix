#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<long long, long long>> st;

    vector<pair<long long, long long>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        st.insert({a, b});
        for (auto [dx, dy] : moves) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                st.insert({x, y});
            }
        }
    }

    long long total = N * N;
    long long unsafe = st.size();
    cout << total - unsafe << endl;

    return 0;
}