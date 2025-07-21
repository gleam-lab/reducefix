#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long n, m;
    cin >> n >> m;
    
    set<pair<long long, long long>> occupied;
    for(long long i = 0; i < m; ++i){
        long long a, b;
        cin >> a >> b;
        --a, --b;
        
        // Mark all reachable positions as occupied
        for(auto [dx, dy] : vector<pair<long long, long long>>{
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, 
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        }){
            long long nx = a + dx, ny = b + dy;
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                occupied.insert({nx, ny});
            }
        }
        
        // Also mark the current position as occupied
        occupied.insert({a, b});
    }

    // The number of available cells is total cells minus occupied cells
    cout << n * n - occupied.size() << '\n';

    return 0;
}