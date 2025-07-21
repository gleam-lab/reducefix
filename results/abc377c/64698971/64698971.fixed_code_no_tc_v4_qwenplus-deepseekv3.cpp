#include <bits/stdc++.h>
using namespace std;

int N, M;
set<pair<int, int>> st;

void set_insert(int a, int b) {
    if (a >= 0 && a < N && b >= 0 && b < N) {
        st.insert({a, b});
    }
}

int main() {
    cin >> N >> M;
    vector<pair<int, int>> vc = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        for (auto x : vc) {
            set_insert(a + x.first, b + x.second);
        }
    }
    
    long long total = (long long)N * N;
    long long unsafe = st.size();
    long long occupied = M;
    long long safe = total - unsafe - occupied;
    cout << safe << endl;
    
    return 0;
}