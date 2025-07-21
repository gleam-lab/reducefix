#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define pii pair<ll,ll>
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()

class Solution {
public:
    ll solve() {
        ll N, M;
        cin >> N >> M;
        
        unordered_set<pii> board;
        for(ll i = 0; i < M; ++i){
            ll a, b;
            cin >> a >> b;
            board.insert(mp(a, b));
        }
        
        ll total_empty = N*N;
        for(auto &it : board){
            ll a = it.first, b = it.second;
            
            // Check all possible moves
            if(a >= 2 && b >= 1 && !board.count(mp(a-2, b-1))) total_empty--;
            if(a >= 1 && b >= 2 && !board.count(mp(a-1, b-2))) total_empty--;
            if(a >= 1 && b <= N-2 && !board.count(mp(a-1, b+2))) total_empty--;
            if(a >= 2 && b <= N-1 && !board.count(mp(a-2, b+1))) total_empty--;
            if(a <= N-2 && b >= 2 && !board.count(mp(a+2, b-1))) total_empty--;
            if(a <= N-1 && b >= 1 && !board.count(mp(a+1, b-2))) total_empty--;
            if(a <= N-1 && b <= N-2 && !board.count(mp(a+1, b+2))) total_empty--;
            if(a <= N-2 && b <= N-1 && !board.count(mp(a+2, b+1))) total_empty--;
        }
        
        return total_empty;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Solution sol;
    cout << sol.solve() << endl;
    
    return 0;
}