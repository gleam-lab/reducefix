#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<pair<ll, ll>> positions(M);
    for(ll i = 0; i < M; ++i){
        cin >> positions[i].first >> positions[i].second;
    }

    set<ll> rows, cols, diag1, diag2;
    for(auto &pos : positions){
        rows.insert(pos.first);
        cols.insert(pos.second);
        diag1.insert(pos.first + pos.second);
        diag2.insert(pos.first - pos.second);
    }

    ll total_empty_squares = N*N;
    total_empty_squares -= rows.size();
    total_empty_squares -= cols.size();
    total_empty_squares -= diag1.size();
    total_empty_squares -= diag2.size();

    // Adjust for overcounting intersections
    for(auto &pos : positions){
        if(rows.find(pos.first) != rows.end()) --total_empty_squares;
        if(cols.find(pos.second) != cols.end()) --total_empty_squares;
        if(diag1.find(pos.first + pos.second) != diag1.end()) --total_empty_squares;
        if(diag2.find(pos.first - pos.second) != diag2.end()) --total_empty_squares;
    }

    cout << total_empty_squares << endl;

    return 0;
}