#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> forbidden;
    set<pair<long long, long long>> pieces;
    
    for (int i = 0; i < M; i++) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        
        // Check all 8 possible knight moves
        vector<pair<long long, long long>> moves = {
            {a+2, b+1}, {a+1, b+2}, {a-1, b+2}, {a-2, b+1},
            {a-2, b-1}, {a-1, b-2}, {a+1, b-2}, {a+2, b-1}
        };
        
        for (auto [x, y] : moves) {
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                forbidden.insert({x, y});
            }
        }
    }
    
    // Total squares minus squares with pieces minus forbidden squares (but not counted twice)
    long long total = N * N;
    long long occupied = pieces.size();
    long long forbidden_count = forbidden.size();
    
    // Need to subtract the intersection of pieces and forbidden squares
    long long overlap = 0;
    for (auto p : pieces) {
        if (forbidden.count(p)) {
            overlap++;
        }
    }
    
    long long safe = total - occupied - (forbidden_count - overlap);
    cout << safe << '\n';
    
    return 0;
}