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
        a--; b--;
        pieces.insert({a, b});
        for (auto move : moves) {
            long long new_a = a + move.first;
            long long new_b = b + move.second;
            if (0 <= new_a && new_a < N && 0 <= new_b && new_b < N) {
                attacked.insert({new_a, new_b});
            }
        }
    }
    
    long long total_squares = N * N;
    long long unsafe_squares = attacked.size();
    long long occupied_squares = M;
    
    // The safe squares are total_squares - (unsafe_squares + occupied_squares - overlap)
    // But since pieces can't be in attacked set (no piece captures another), overlap is zero.
    long long safe_squares = total_squares - unsafe_squares - occupied_squares;
    
    cout << safe_squares << endl;
    
    return 0;
}