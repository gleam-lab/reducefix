#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> existing;
    set<pair<long long, long long>> attacked;
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing.emplace(a, b);
        
        // Generate all 8 possible knight moves
        vector<pair<long long, long long>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };
        
        for (const auto& move : moves) {
            long long x = move.first, y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.emplace(x, y);
            }
        }
    }
    
    // The safe squares are N² minus existing squares minus attacked squares (not existing)
    long long total_squares = N * N;
    long long unsafe_squares = existing.size() + attacked.size();
    
    // But some attacked squares might already be existing, so we need to find the union
    set<pair<long long, long long>> unsafe;
    unsafe.insert(existing.begin(), existing.end());
    unsafe.insert(attacked.begin(), attacked.end());
    
    long long safe_squares = total_squares - unsafe.size();
    cout << safe_squares << '\n';
    
    return 0;
}