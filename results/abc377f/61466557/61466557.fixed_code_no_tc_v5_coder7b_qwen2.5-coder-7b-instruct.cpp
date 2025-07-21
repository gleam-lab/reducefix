#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Function to check if the position is within bounds
bool isValid(ll x, ll y, ll n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

// Main function
int main(){
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> positions(m);
    for(ll i=0;i<m;++i){
        cin >> positions[i].first >> positions[i].second;
    }
    
    unordered_set<ll> rows, cols, diag1, diag2;
    
    // Inserting the occupied positions into respective sets
    for(auto pos : positions){
        rows.insert(pos.first);
        cols.insert(pos.second);
        diag1.insert(pos.first - pos.second);
        diag2.insert(pos.first + pos.second);
    }
    
    ll totalPositions = n*n;
    ll takenByRows = rows.size() * n;
    ll takenByCols = cols.size() * n;
    ll takenByDiag1 = diag1.size() * n;
    ll takenByDiag2 = diag2.size() * n;
    ll takenByBothRowAndCol = rows.size() * cols.size();
    
    // Applying inclusion-exclusion principle
    ll takenPositions = takenByRows + takenByCols + takenByDiag1 + takenByDiag2 - 
                        takenByBothRowAndCol - 
                        ((rows.size() + cols.size() + diag1.size() + diag2.size()) - 
                         (takenByBothRowAndCol * 2));
                        
    // The remaining positions will not be attacked
    ll safePositions = totalPositions - takenPositions;
    
    cout << safePositions << '\n';
    return 0;
}