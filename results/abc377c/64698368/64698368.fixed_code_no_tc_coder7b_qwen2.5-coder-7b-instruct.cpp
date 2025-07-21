#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    set<pair<int, int>> st;
    vector<pair<int, int>> pieces;

    vector<pair<int, int>> vc = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        pieces.emplace_back(a, b);
        for (auto& x : vc) {
            int na = a + x.first;
            int nb = b + x.second;
            if (na >= 0 && na < N && nb >= 0 && nb < N) {
                st.insert({na, nb});
            }
        }
    }

    int cnt = 0;
    for (auto p : pieces) {
        if (st.count(p)) cnt++;
    }

    long long total = (long long)N * N;
    long long ans = total - M - (st.size() - cnt);
    cout << ans << endl;
}