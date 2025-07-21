#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    unordered_set<pair<int, int>> captured;
    
    for (auto &p : pieces) {
        int a = p.first, b = p.second;
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                if (dx == 0 && dy == 0) continue;
                int x = a + dx, y = b + dy;
                if (x > 0 && x <= n && y > 0 && y <= n) {
                    captured.insert({x, y});
                }
            }
        }
    }
    
    cout << n * n - captured.size() << endl;
    return 0;
}