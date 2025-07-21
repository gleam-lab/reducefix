#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    set<pair<int, int>> st;
    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, 
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        for (auto move : moves) {
            int x = a + move.first;
            int y = b + move.second;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                st.insert({x, y});
            }
        }
    }
    
    long long total = (long long)N * N;
    long long forbidden = st.size() + M;
    long long answer = total - forbidden;
    
    cout << answer << endl;
    
    return 0;
}