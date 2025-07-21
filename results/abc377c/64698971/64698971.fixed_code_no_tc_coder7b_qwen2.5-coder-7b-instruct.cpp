#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    set<pair<int, int>> st;
    
    vector<pair<int, int>> dirs = {
        {2,1}, {1,2}, {-1,2}, {-2,1},
        {-2,-1}, {-1,-2}, {1,-2}, {2,-1}
    };
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        for (auto d : dirs) {
            int x = a + d.first;
            int y = b + d.second;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                st.insert({x, y});
            }
        }
    }
    
    long long total = (long long)N * N;
    cout << total - (long long)st.size() - M << endl;
}