#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    int M;
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
                if (occupied.find({x, y}) == occupied.end()) {
                    attacked.insert({x, y});
                }
            }
        }
    }
    
    long long total = N * N;
    long long unsafe = occupied.size() + attacked.size();
    long long safe = total - unsafe;
    
    cout << safe << endl;
    
    return 0;
}