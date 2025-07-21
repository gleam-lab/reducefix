#include <bits/stdc++.h>
using namespace std;

struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return p.first * 1000000001LL + p.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    unordered_set<pair<int, int>, PairHash> unsafe;
    
    for (int k = 0; k < M; ++k) {
        int a, b;
        cin >> a >> b;
        unsafe.insert({a, b});
        
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        for (int i = 0; i < 8; ++i) {
            int x = a + dx[i];
            int y = b + dy[i];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe.insert({x, y});
            }
        }
    }
    
    cout << (1LL * N * N - unsafe.size()) << '\n';
    
    return 0;
}