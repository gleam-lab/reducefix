#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M;
    cin >> N >> M;
    
    vector<pair<ll, ll>> pieces(M);
    set<pair<ll, ll>> occupied;
    set<ll> rows, cols, diagonals, anti_diagonals;
    
    for (ll i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        --pieces[i].first; --pieces[i].second;
        
        occupied.insert(pieces[i]);
        rows.insert(pieces[i].first);
        cols.insert(pieces[i].second);
        diagonals.insert(pieces[i].first + pieces[i].second);
        anti_diagonals.insert(pieces[i].first - pieces[i].second);
    }
    
    ll total_empty_squares = N * N;
    
    for (const auto& [r, c] : pieces) {
        total_empty_squares -= rows.count(r);
        total_empty_squares -= cols.count(c);
        total_empty_squares -= diagonals.count(r + c);
        total_empty_squares -= anti_diagonals.count(r - c);
        
        if (rows.count(r)) total_empty_squares++;
        if (cols.count(c)) total_empty_squares++;
        if (diagonals.count(r + c)) total_empty_squares++;
        if (anti_diagonals.count(r - c)) total_empty_squares++;
        
        total_empty_squares += 4;
    }
    
    cout << total_empty_squares << '\n';
    
    return 0;
}