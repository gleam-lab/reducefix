#include <bits/stdc++.h>
using namespace std;

int N, M;
set<pair<int, int>> st;

void set_insert(int a, int b) {
    if (0 <= a && a < N && 0 <= b && b < N) {
        st.insert({a, b});
    }
}

int main() {
    cin >> N >> M;

    vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        for (auto move : moves) {
            set_insert(a + move.first, b + move.second);
        }
    }

    long long total_squares = (long long)N * N;
    long long unsafe_squares = st.size();
    long long occupied_squares = M;
    long long safe_squares = total_squares - unsafe_squares - occupied_squares;

    cout << safe_squares << endl;
    return 0;
}