#include <bits/stdc++.h>
using namespace std;

// Custom hash for pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    unordered_set<pair<int, int>, pair_hash> attacked;

    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        attacked.insert({a, b});

        for (auto [dx, dy] : directions) {
            int na = a + dx;
            int nb = b + dy;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                attacked.insert({na, nb});
            }
        }
    }

    cout << (N * NLL - static_cast<long long>(attacked.size())) << '\n';
    return 0;
}