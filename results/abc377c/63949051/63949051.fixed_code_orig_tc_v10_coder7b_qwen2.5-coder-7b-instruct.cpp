#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

#define LL long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, m;
    cin >> n >> m;

    set<pair<LL, LL>> pieces;
    for (LL i = 0; i < m; ++i) {
        LL a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        
        auto it = pieces.find({a, b});
        if (it != pieces.end()) {
            pieces.erase(it);
        }
        
        for (LL dx = -2; dx <= 2; ++dx) {
            for (LL dy = -2; dy <= 2; ++dy) {
                if (abs(dx) == abs(dy)) continue;
                LL nx = a + dx, ny = b + dy;
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                    pieces.insert({nx, ny});
                }
            }
        }
    }

    LL total_empty = n * n - pieces.size();
    cout << total_empty << endl;

    return 0;
}