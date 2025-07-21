#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long N, M;
    cin >> N >> M;
    
    set<pair<int, int>> unsafe;
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        unsafe.insert({a, b});
        
        // All 8 possible knight moves
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        for (int j = 0; j < 8; ++j) {
            int new_a = a + dx[j];
            int new_b = b + dy[j];
            if (1 <= new_a && new_a <= N && 1 <= new_b && new_b <= N) {
                unsafe.insert({new_a, new_b});
            }
        }
    }
    
    cout << N * N - unsafe.size() << '\n';
    
    return 0;
}