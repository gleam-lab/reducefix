#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    
    vector<pair<i64, i64>> pieces(M);
    for(i64 i = 0; i < M; ++i){
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    set<pair<i64, i64>> lines;
    for(auto &p : pieces){
        lines.insert({p.first, p.second});
        lines.insert({p.first + p.second, 0});
        lines.insert({p.first - p.second, 0});
        lines.insert({0, p.second});
    }
    
    i64 total_empty_squares = N*N - M;
    
    for(auto &p : pieces){
        auto it1 = lines.lower_bound({p.first + p.second, 0});
        auto it2 = lines.upper_bound({p.first + p.second, INT_MAX});
        if(it1 != it2 && (*it1).first == p.first + p.second){
            --total_empty_squares;
        }
        
        it1 = lines.lower_bound({p.first - p.second, 0});
        it2 = lines.upper_bound({p.first - p.second, INT_MAX});
        if(it1 != it2 && (*it1).first == p.first - p.second){
            --total_empty_squares;
        }
        
        it1 = lines.lower_bound({p.first, 0});
        it2 = lines.upper_bound({p.first, INT_MAX});
        if(it1 != it2 && (*it1).first == p.first){
            --total_empty_squares;
        }
        
        it1 = lines.lower_bound({0, p.second});
        it2 = lines.upper_bound({INT_MAX, p.second});
        if(it1 != it2 && (*it1).second == p.second){
            --total_empty_squares;
        }
    }
    
    cout << total_empty_squares << endl;
    
    return 0;
}