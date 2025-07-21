#include <iostream>
#include <vector>
#include <set>

using namespace std;

long long solve(long long N, long long M, vector<pair<long long, long long>>& pieces) {
    set<pair<long long, long long>> anti_dup;
    
    for(auto& p : pieces){
        anti_dup.insert(p);
        
        if(p.first + 2 <= N && p.second + 1 <= N) anti_dup.insert({p.first + 2, p.second + 1});
        if(p.first + 1 <= N && p.second + 2 <= N) anti_dup.insert({p.first + 1, p.second + 2});
        if(p.first - 1 >= 1 && p.second + 2 <= N) anti_dup.insert({p.first - 1, p.second + 2});
        if(p.first - 2 >= 1 && p.second + 1 <= N) anti_dup.insert({p.first - 2, p.second + 1});
        if(p.first - 2 >= 1 && p.second - 1 >= 1) anti_dup.insert({p.first - 2, p.second - 1});
        if(p.first - 1 >= 1 && p.second - 2 >= 1) anti_dup.insert({p.first - 1, p.second - 2});
        if(p.first + 1 <= N && p.second - 2 >= 1) anti_dup.insert({p.first + 1, p.second - 2});
        if(p.first + 2 <= N && p.second - 1 >= 1) anti_dup.insert({p.first + 2, p.second - 1});
    }
    
    return N * N - anti_dup.size();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> pieces(M);
    for(auto& [x, y] : pieces) cin >> x >> y;
    
    cout << solve(N, M, pieces) << '\n';
    return 0;
}