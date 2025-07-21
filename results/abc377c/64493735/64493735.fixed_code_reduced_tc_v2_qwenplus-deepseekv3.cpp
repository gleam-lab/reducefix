#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    int M;
    cin >> N >> M;
    
    set<pair<int, int>> unsafe;
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        unsafe.insert({a, b});
        
        // All 8 possible attack positions
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        for (int j = 0; j < 8; ++j) {
            int x = a + dx[j];
            int y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe.insert({x, y});
            }
        }
    }
    
    long long total = N * N;
    long long unsafe_count = unsafe.size();
    long long safe = total - unsafe_count;
    
    cout << safe << '\n';
    
    return 0;
}