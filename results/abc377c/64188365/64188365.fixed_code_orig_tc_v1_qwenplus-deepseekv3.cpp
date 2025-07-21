#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    set<pair<ll, ll>> occupied;
    set<pair<ll, ll>> unsafe;

    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--; // converting to 0-based for easier handling
        occupied.insert({a, b});
        // Mark all 8 possible knight moves as unsafe
        for (int da : {-2, -1, 1, 2}) {
            for (int db : {-2, -1, 1, 2}) {
                if (abs(da) + abs(db) == 3) { // ensures L-shaped move
                    ll ni = a + da - 1; // adjusting back to 1-based for boundary check
                    ll nj = b + db - 1;
                    if (ni >= 0 && nj >= 0 && ni < n && nj < n) {
                        unsafe.insert({a + da - 1, b + db - 1});
                    }
                }
            }
        }
    }

    // The total unsafe squares are those in 'unsafe' plus the squares with pieces
    // But 'unsafe' already includes the squares with pieces (since they can capture those)
    // So total unsafe is unsafe.size()
    // But we need to subtract the squares that are both occupied and unsafe (but they are already counted in unsafe)
    // So the safe squares are n*n - (unsafe.size() + occupied.size() - intersection)
    // But since occupied squares are already in unsafe, the total unsafe is unsafe.size()

    // However, some occupied squares might not be in unsafe if they can't be captured by any piece
    // But according to the problem, any empty square that can be captured by any piece is unsafe
    // So the total unsafe squares are the union of:
    // 1. All squares that can be captured by any piece (i.e., unsafe)
    // 2. All squares that are already occupied

    // Therefore, total unsafe is the size of the union of 'unsafe' and 'occupied'
    set<pair<ll, ll>> total_unsafe;
    for (auto p : unsafe) {
        total_unsafe.insert(p);
    }
    for (auto p : occupied) {
        total_unsafe.insert(p);
    }

    ll safe_squares = n * n - total_unsafe.size();
    cout << safe_squares << endl;
}