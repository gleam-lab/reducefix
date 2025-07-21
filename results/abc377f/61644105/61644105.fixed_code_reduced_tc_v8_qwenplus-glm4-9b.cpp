#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }
    
    // Sort pieces to process them in order
    sort(pieces.begin(), pieces.end());
    
    // Sets to track captured squares
    set<ll> captured_rows, captured_cols;
    set<pair<ll, ll>, greater<pair<ll, ll>>> captured_diagonals[2]; // (sum, diff) sort by sum descending
    
    ll answer = n * n;
    
    for (ll i = 0; i < m; i++) {
        ll r = pieces[i].first;
        ll c = pieces[i].second;
        
        // Check if current piece can capture any previously placed pieces
        if (!captured_rows.count(r) && !captured_cols.count(c)) {
            // This piece will capture all pieces in the same row and column
            captured_rows.insert(r);
            captured_cols.insert(c);
            
            // Check for diagonal captures
            for (ll j = 0; j < i; j++) {
                ll r2 = pieces[j].first;
                ll c2 = pieces[j].second;
                ll sum = r + c;
                ll diff = r - c;
                
                if (r != r2 && c != c2) {
                    if (sum == r2 + c2 || diff == r2 - c2) {
                        if (captured_diagonals[sum % 2].count({sum, diff})) {
                            captured_diagonals[sum % 2].erase({sum, diff});
                        }
                        captured_diagonals[sum % 2].insert({sum, diff});
                    }
                }
            }
        }
        
        // Decrease the answer by the number of captured squares
        answer -= captured_rows.size() + captured_cols.size();
        for (auto diag : captured_diagonals[r % 2]) {
            if (diag.first == r + c && diag.second == r - c) {
                answer -= 1;
            }
        }
        for (auto diag : captured_diagonals[c % 2]) {
            if (diag.first == r + c && diag.second == r - c) {
                answer -= 1;
            }
        }
    }
    
    cout << answer << endl;
    return 0;
}