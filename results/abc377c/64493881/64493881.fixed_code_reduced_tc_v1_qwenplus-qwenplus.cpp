#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    int M;
    cin >> N >> M;
    
    unordered_set<long long> attacked;
    auto hash = [N](int x, int y) {
        return (x - 1LL) * N + (y - 1LL);
    };
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        
        // Add current piece position to attacked set (we can't place there)
        attacked.insert(hash(a, b));
        
        vector<pair<int, int>> attack_offsets = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };
        
        for (const auto& [dx, dy] : attack_offsets) {
            int na = a + dx;
            int nb = b + dy;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                attacked.insert(hash(na, nb));
            }
        }
    }
    
    // Total squares minus attacked squares
    cout << (N * N - static_cast<long long>(attacked.size())) << endl;
    
    return 0;
}