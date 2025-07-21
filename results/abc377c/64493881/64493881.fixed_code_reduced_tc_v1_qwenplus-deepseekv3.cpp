#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long N, M;
    cin >> N >> M;
    
    set<pair<int, int>> attacked;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        attacked.insert({a, b});
        
        // All possible moves a knight can make from (a, b)
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        for (int k = 0; k < 8; ++k) {
            int x = a + dx[k];
            int y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }
    
    cout << N * N - attacked.size() << '\n';
    
    return 0;
}