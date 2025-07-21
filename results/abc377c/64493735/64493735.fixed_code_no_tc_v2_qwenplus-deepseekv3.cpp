#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long N;
    int M;
    cin >> N >> M;
    
    set<pair<int, int>> forbidden;
    
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        forbidden.insert({a, b});
        
        for (int k = 0; k < 8; k++) {
            int ni = a + dx[k];
            int nj = b + dy[k];
            if (1 <= ni && ni <= N && 1 <= nj && nj <= N) {
                forbidden.insert({ni, nj});
            }
        }
    }
    
    cout << N*N - forbidden.size() << '\n';
    
    return 0;
}