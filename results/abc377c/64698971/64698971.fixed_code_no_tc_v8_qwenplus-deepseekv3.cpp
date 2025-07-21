#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    
    set<pair<int, int>> attacked;
    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    set<pair<int, int>> existing_pieces;
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        existing_pieces.insert({a, b});
        
        for (const auto& move : moves) {
            int new_a = a + move.first;
            int new_b = b + move.second;
            if (new_a >= 0 && new_a < N && new_b >= 0 && new_b < N) {
                attacked.insert({new_a, new_b});
            }
        }
    }
    
    ll total_squares = (ll)N * N;
    ll unsafe_squares = attacked.size() + existing_pieces.size();
    
    // Subtract squares that are both occupied and under attack (if any)
    // But since existing_pieces are separate, the total unsafe is attacked + existing
    cout << total_squares - unsafe_squares << endl;
    
    return 0;
}