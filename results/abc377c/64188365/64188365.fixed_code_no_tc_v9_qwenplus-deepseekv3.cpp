#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    set<pair<ll, ll>> c;
    set<pair<ll, ll>> forbidden;
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        c.emplace(a, b);
        // Check all 8 possible knight moves
        for (int dx : {-2, -1, 1, 2}) {
            for (int dy : {-2, -1, 1, 2}) {
                if (abs(dx) + abs(dy) == 3) {
                    ll nx = a + dx;
                    ll ny = b + dy;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        forbidden.emplace(nx, ny);
                    }
                }
            }
        }
    }
    // The answer is total squares minus occupied squares minus forbidden squares
    // But forbidden squares can include occupied squares, so subtract the size of the union
    set<pair<ll, ll>> union_set;
    for (auto p : c) {
        union_set.insert(p);
    }
    for (auto p : forbidden) {
        union_set.insert(p);
    }
    cout << n * n - union_set.size() << endl;
}