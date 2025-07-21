#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> occupied;
    set<pair<long long, long long>> threatened;
    
    vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        
        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                if (occupied.find({x, y}) == occupied.end()) {
                    threatened.insert({x, y});
                }
            }
        }
    }
    
    long long total_occupied_or_threatened = occupied.size() + threatened.size();
    long long ans = N * N - total_occupied_or_threatened;
    
    cout << ans << endl;
    
    return 0;
}