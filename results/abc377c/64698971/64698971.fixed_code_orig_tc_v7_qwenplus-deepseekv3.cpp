#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> unsafe;
    set<pair<long long, long long>> pieces;
    
    vector<pair<long long, long long>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        a--; b--; // converting to 0-based index
        pieces.insert({a, b});
        
        for (auto [dx, dy] : moves) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                if (pieces.find({x, y}) == pieces.end()) {
                    unsafe.insert({x, y});
                }
            }
        }
    }
    
    long long total = N * N;
    long long occupied = pieces.size();
    long long unsafe_count = unsafe.size();
    
    cout << total - occupied - unsafe_count << endl;
    
    return 0;
}