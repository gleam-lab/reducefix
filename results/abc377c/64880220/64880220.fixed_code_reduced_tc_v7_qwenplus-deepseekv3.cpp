#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> existing;
    unordered_set<long long> threatened;
    
    const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    const int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing.insert(a * (N + 1) + b);
        
        for (int k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
            
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                if (existing.find(x * (N + 1) + y) == existing.end()) {
                    threatened.insert(x * (N + 1) + y);
                }
            }
        }
    }
    
    long long ans = N * N - existing.size() - threatened.size();
    cout << ans << endl;
    
    return 0;
}