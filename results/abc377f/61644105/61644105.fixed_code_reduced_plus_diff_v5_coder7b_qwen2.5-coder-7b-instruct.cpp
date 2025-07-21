#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 1005;

ll n, m;
vector<ll> rows[MAXN], cols[MAXN], diags[2 * MAXN], anti_diags[2 * MAXN];

bool isValid(ll x, ll y) {
    return find(rows[x].begin(), rows[x].end(), y) == rows[x].end() &&
           find(cols[y].begin(), cols[y].end(), x) == cols[y].end() &&
           find(diags[x + y].begin(), diags[x + y].end(), x) == diags[x + y].end() &&
           find(anti_diags[x - y + n].begin(), anti_diags[x - y + n].end(), x) == anti_diags[x - y + n].end();
}

int main() {
    cin >> n >> m;
    
    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        --x, --y; // Convert to zero-based index
        
        rows[x].push_back(y);
        cols[y].push_back(x);
        diags[x + y].push_back(x);
        anti_diags[x - y + n].push_back(x);
        
        sort(rows[x].begin(), rows[x].end());
        sort(cols[y].begin(), cols[y].end());
        sort(diags[x + y].begin(), diags[x + y].end());
        sort(anti_diags[x - y + n].begin(), anti_diags[x - y + n].end());
    }
    
    ll result = 0;
    for (ll x = 0; x < n; ++x) {
        for (ll y = 0; y < n; ++y) {
            if (isValid(x, y)) {
                ++result;
            }
        }
    }
    
    cout << result << endl;
    return 0;
}