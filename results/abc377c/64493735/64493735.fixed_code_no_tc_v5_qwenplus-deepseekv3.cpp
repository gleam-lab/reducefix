#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int64_t N, M;
    cin >> N >> M;
    
    set<pair<int64_t, int64_t>> attacked;
    set<pair<int64_t, int64_t>> original;
    
    for (int i = 0; i < M; i++) {
        int64_t a, b;
        cin >> a >> b;
        original.emplace(a, b);
        
        int64_t dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int64_t dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        for (int j = 0; j < 8; j++) {
            int64_t x = a + dx[j];
            int64_t y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.emplace(x, y);
            }
        }
    }
    
    for (auto &p : original) {
        attacked.erase(p);
    }
    
    int64_t total = N * N - original.size() - attacked.size();
    cout << total << '\n';
    
    return 0;
}