#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long N;
    int M;
    cin >> N >> M;
    
    set<pair<long long, long long>> occupied;
    set<pair<long long, long long>> capturable;
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        
        // Generate all 8 possible capturable positions
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
        
        for (auto &move : moves) {
            long long x = move.first;
            long long y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                if (occupied.find({x, y}) == occupied.end()) {
                    capturable.insert({x, y});
                }
            }
        }
    }
    
    long long total_squares = N * N;
    long long occupied_or_capturable = occupied.size() + capturable.size();
    long long safe_squares = total_squares - occupied_or_capturable;
    
    cout << safe_squares << endl;
    
    return 0;
}