#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);(r)>i;i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
#define spa " "
#define Yes cout << "Yes" << el
#define No cout << "No" << el
#define YES cout << "YES" << el
#define NO cout << "NO" << el
#define cou(i) cout<<i<<endl;
#define rrep(i,l,r) for(int i=(r);i>=(l);i--)
#define pb push_back
using ll=long long;
using vi=vector<int>;
using vvi=vector<vector<int>>;
const int INF=1e9;

int main(){
    int N, M;
    cin >> N >> M;
    vvi G(N);
    rep(i,0,M){
        int s, v;
        cin >> s >> v;
        s--; v--;
        G[s].pb(v);
    }
    
    int min_cycle = INF;
    queue<pair<int, int>> que;
    que.push({0, 0});
    vi dist(N, INF);
    dist[0] = 0;
    
    while(!que.empty()){
        auto [pos, d] = que.front();
        que.pop();
        if(d > dist[pos]) continue;
        
        for(auto to : G[pos]){
            if(to == 0){
                min_cycle = min(min_cycle, d + 1);
            }
            if(dist[to] > d + 1){
                dist[to] = d + 1;
                que.push({to, d + 1});
            }
        }
    }
    
    if(min_cycle != INF) cout << min_cycle << el;
    else cout << -1 << el;
}