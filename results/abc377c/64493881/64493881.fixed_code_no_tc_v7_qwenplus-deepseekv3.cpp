#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long N;
    int M;
    cin >> N >> M;
    
    set<pair<int, int>> forbidden;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        forbidden.insert({a, b});
        
        // Check all 8 possible knight moves
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        for (int j = 0; j < 8; j++) {
            int x = a + dx[j];
            int y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                forbidden.insert({x, y});
            }
        }
    }
    
    cout << N * N - forbidden.size() << '\n';
    
    return 0;
}