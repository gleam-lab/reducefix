#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> attacked;
    set<pair<long long, long long>> pieces;
    
    vector<pair<long long, long long>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        for (auto move : moves) {
            long long x = a + move.first;
            long long y = b + move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }
    
    long long total = N * N;
    long long unsafe = pieces.size() + attacked.size();
    for (auto piece : pieces) {
        if (attacked.find(piece) != attacked.end()) {
            unsafe--;
        }
    }
    
    cout << total - unsafe << endl;
    
    return 0;
}