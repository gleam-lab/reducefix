#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

const vector<pair<int, int>> directions = {
    {2, 1}, {1, 2}, {1, -2}, {2, -1},
    {-2, 1}, {-1, 2}, {-1, -2}, {-2, -1}
};

int main() {
    ll n, m;
    cin >> n >> m;
    
    vector<vector<bool>> can_capture(n, vector<bool>(n, false));
    
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        
        for (const auto& dir : directions) {
            ll nx = a + dir.first, ny = b + dir.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                can_capture[nx][ny] = true;
            }
        }
    }
    
    ll empty_squares = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (!can_capture[i][j]) {
                empty_squares++;
            }
        }
    }
    
    cout << empty_squares << endl;
}