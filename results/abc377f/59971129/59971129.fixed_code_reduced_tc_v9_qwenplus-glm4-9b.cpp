#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);
    vector<set<ll>> rows(n+1), cols(n+1), diag_p(n+1), anti_diag_p(n+1);
    
    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        ++rows[x].count();
        ++cols[y].count();
        ++diag_p[x + y].count();
        ++anti_diag_p[x - y + n].count();
        pieces[i] = {x, y};
    }
    
    ll free_rows = 0, free_cols = 0, free_diag = 0, free_anti_diag = 0;
    
    for (ll i = 1; i <= n; ++i) {
        free_rows += n - rows[i].size();
        free_cols += n - cols[i].size();
        free_diag += n - diag_p[i].size();
        free_anti_diag += n - anti_diag_p[i].size();
    }
    
    ll total_free = free_rows * free_cols;
    
    // Subtract the intersections of rows and columns, diagonals, and anti-diagonals
    for (ll i = 0; i < m; ++i) {
        ll x = pieces[i].first;
        ll y = pieces[i].second;
        total_free -= rows[x].size() * cols[y].size();
        ll diag = x + y;
        ll anti_diag = x - y + n;
        total_free -= rows[x].size() * diag_p[diag].size();
        total_free -= cols[y].size() * diag_p[diag].size();
        total_free -= rows[x].size() * anti_diag_p[anti_diag].size();
        total_free -= cols[y].size() * anti_diag_p[anti_diag].size();
    }
    
    cout << total_free << endl;
    return 0;
}