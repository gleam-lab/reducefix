#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N, M;
    cin >> N >> M;
    
    set<pair<int, int>> existing_pieces;
    set<pair<int, int>> under_attack;
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        existing_pieces.insert({a, b});
        
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        for (int j = 0; j < 8; ++j) {
            int x = a + dx[j];
            int y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                under_attack.insert({x, y});
            }
        }
    }
    
    long long total_squares = N * N;
    long long occupied = existing_pieces.size();
    
    for (const auto& pos : existing_pieces) {
        under_attack.erase(pos);
    }
    
    long long unsafe = under_attack.size() + occupied;
    long long safe = total_squares - unsafe;
    
    cout << safe << '\n';
    
    return 0;
}