#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;

typedef long long ll;

const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

ll solve(ll n, vector<pair<ll, ll>>& pieces) {
    unordered_set<string> occupied;
    for (auto& p : pieces) {
        occupied.insert(to_string(p.first) + "," + to_string(p.second));
    }

    ll count = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            bool canPlace = true;
            for (int d = 0; d < 8; ++d) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (isValid(ni, nj, n) && occupied.count(to_string(ni) + "," + to_string(nj))) {
                    canPlace = false;
                    break;
                }
            }
            if (canPlace) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);
    for (auto& p : pieces) {
        cin >> p.first >> p.second;
    }

    cout << solve(n, pieces) << endl;

    return 0;
}