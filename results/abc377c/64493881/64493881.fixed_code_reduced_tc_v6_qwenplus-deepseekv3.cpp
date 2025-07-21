#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> threatened;
    set<pair<long long, long long>> occupied;
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        
        // All 8 possible knight moves
        vector<pair<long long, long long>> moves = {
            {a + 2, b + 1},
            {a + 1, b + 2},
            {a - 1, b + 2},
            {a - 2, b + 1},
            {a - 2, b - 1},
            {a - 1, b - 2},
            {a + 1, b - 2},
            {a + 2, b - 1}
        };
        
        for (auto move : moves) {
            long long x = move.first, y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                threatened.insert({x, y});
            }
        }
    }
    
    // The total safe squares are N^2 minus occupied squares minus threatened squares not already occupied
    long long total = N * N;
    long long unsafe = occupied.size();
    for (auto square : threatened) {
        if (occupied.find(square) == occupied.end()) {
            unsafe++;
        }
    }
    
    cout << (total - unsafe) << '\n';
    
    return 0;
}