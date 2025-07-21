#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> unavailable;
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        unavailable.emplace(a, b);
        
        // All 8 possible moves
        const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unavailable.emplace(x, y);
            }
        }
    }
    
    cout << N * N - unavailable.size() << endl;
    
    return 0;
}