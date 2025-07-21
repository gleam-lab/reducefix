#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<long long, long long>> st;
    vector<pair<long long, long long>> pieces(M);

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        st.insert({a, b});
    }

    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (auto &p : pieces) {
        long long a = p.first;
        long long b = p.second;
        for (int k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                st.insert({x, y});
            }
        }
    }

    long long total = N * N;
    long long unsafe = st.size();
    long long safe = total - unsafe;

    cout << safe << endl;

    return 0;
}