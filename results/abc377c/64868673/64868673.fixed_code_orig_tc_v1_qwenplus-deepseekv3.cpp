#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> occupied;
    set<pair<long long, long long>> attacked;
    
    vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        
        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }
    
    set<pair<long long, long long>> all_invalid;
    for (auto p : occupied) {
        all_invalid.insert(p);
    }
    for (auto p : attacked) {
        all_invalid.insert(p);
    }
    
    long long invalid_count = all_invalid.size();
    long long total_squares = N * N;
    long long answer = total_squares - invalid_count;
    
    cout << answer << endl;
    
    return 0;
}