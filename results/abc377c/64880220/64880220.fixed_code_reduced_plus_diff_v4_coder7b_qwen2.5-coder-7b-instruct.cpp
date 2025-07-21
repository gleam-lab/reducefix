#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    
    set<pair<long long, long long>> occupied;
    for(long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
    }

    auto isValidMove = [&](long long x, long long y) -> bool {
        return x >= 1 && x <= n && y >= 1 && y <= n;
    };

    long long result = 0;
    for(long long i = 1; i <= n; ++i) {
        for(long long j = 1; j <= n; ++j) {
            if(occupied.find({i, j}) != occupied.end()) continue;
            
            bool canPlace = true;
            vector<pair<long long, long long>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
            for(auto& [dx, dy] : directions) {
                long long nx = i + dx, ny = j + dy;
                if(isValidMove(nx, ny) && occupied.find({nx, ny}) != occupied.end()) {
                    canPlace = false;
                    break;
                }
            }
            
            if(canPlace) ++result;
        }
    }
    
    cout << result << '\n';
    return 0;
}