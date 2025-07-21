#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long N;
    int M;
    cin >> N >> M;
    
    set<pair<int, int>> forbidden;
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        forbidden.emplace(a, b);
        
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        for (int k = 0; k < 8; ++k) {
            int na = a + dx[k];
            int nb = b + dy[k];
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                forbidden.emplace(na, nb);
            }
        }
    }
    
    cout << N * N - forbidden.size() << '\n';
    
    return 0;
}