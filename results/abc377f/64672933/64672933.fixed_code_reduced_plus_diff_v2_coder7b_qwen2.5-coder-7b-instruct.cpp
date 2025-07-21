#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M;
    cin >> N >> M;
    
    vector<pair<ll, ll>> pieces(M);
    for(int i = 0; i < M; ++i){
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    set<ll> rows, cols, diag1, diag2;
    for(auto [r, c] : pieces){
        rows.insert(r);
        cols.insert(c);
        diag1.insert(r + c);
        diag2.insert(r - c);
    }
    
    ll total_empty_squares = N * N;
    total_empty_squares -= rows.size();
    total_empty_squares -= cols.size();
    total_empty_squares -= diag1.size();
    total_empty_squares -= diag2.size();
    
    for(auto [r, c] : pieces){
        if(rows.find(r) != rows.end()) --total_empty_squares;
        if(cols.find(c) != cols.end()) --total_empty_squares;
        if(diag1.find(r + c) != diag1.end()) --total_empty_squares;
        if(diag2.find(r - c) != diag2.end()) --total_empty_squares;
    }
    
    cout << total_empty_squares << '\n';
    
    return 0;
}