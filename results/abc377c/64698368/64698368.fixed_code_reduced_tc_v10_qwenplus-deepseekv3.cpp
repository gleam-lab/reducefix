#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;
set<pair<int, int>> st;

void insert(int a, int b) {
    if (1 <= a && a <= N && 1 <= b && b <= N) {
        st.insert({a, b});
    }
}

int main() {
    cin >> N >> M;

    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        st.insert({a, b});
        for (auto [dx, dy] : moves) {
            insert(a + dx, b + dy);
        }
    }

    ll total = N * 1LL * N;
    ll forbidden = st.size();
    cout << total - forbidden << endl;

    return 0;
}