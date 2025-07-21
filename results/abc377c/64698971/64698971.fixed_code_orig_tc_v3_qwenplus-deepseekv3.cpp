#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> attacked;
    set<pair<long long, long long>> knights;
    
    vector<pair<long long, long long>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        a--; b--;
        knights.insert({a, b});
        
        for (auto [dx, dy] : moves) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                attacked.insert({x, y});
            }
        }
    }
    
    long long total = N * N;
    long long attacked_count = attacked.size();
    long long knights_count = knights.size();
    
    // Squares under attack or already occupied
    set<pair<long long, long long>> all;
    for (auto pos : attacked) {
        all.insert(pos);
    }
    for (auto pos : knights) {
        all.insert(pos);
    }
    long long safe = total - all.size();
    
    cout << safe << endl;
    
    return 0;
}