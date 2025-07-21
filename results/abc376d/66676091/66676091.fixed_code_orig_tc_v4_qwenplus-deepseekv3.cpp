#include<bits/stdc++.h>
using namespace std;

template<typename T> bool chmax(T &m, const T q) {
    if (m < q) {m = q; return true;} else return false; }

template<typename T> bool chmin(T &m,const T q){
    if(m>q){m=q;return true;}else return false;
}

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
using pqgi=priority_queue<int,vector<int>,greater<int>>;
using pqi=priority_queue<int>;
using pii=pair<int,int>;
using ll=long long;
using vs=vector<string>;
using vi=vector<int>;
using vb=vector<bool>;
using vl=vector<long long>;
using vc=vector<char>;
using vvi=vector<vector<int>>;
using vvl=vector<vector<long long>>;
using vvc=vector<vector<char>>;
using vvb=vector<vector<bool>>;
using vvpii=vector<vector<pii>>;
using vpii=vector<pair<int,int>>;
using vtiii=vector<tuple<int,int,int>>;
using vvs=vector<vector<string>>;
const long long INF=1e18;
const int mod=1e9+7;
const int MAX=1e5+10;
const int MIN=-1e9;

int main(){
    int N, M;
    cin >> N >> M;
    vvi G(N);
    
    rep(i, 0, M) {
        int s, v;
        cin >> s >> v;
        s--; v--;
        G[s].pb(v);
    }
    
    int min_cycle = INT_MAX;
    
    // We need to find the shortest cycle that starts and ends at 0
    // Perform BFS from each neighbor of 0 to find paths back to 0
    for (int u : G[0]) {
        if (u == 0) {
            // Direct self-loop
            min_cycle = 1;
            continue;
        }
        
        vi dist(N, -1);
        queue<int> q;
        q.push(u);
        dist[u] = 1;
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            for (int to : G[v]) {
                if (to == 0) {
                    chmin(min_cycle, dist[v] + 1);
                    continue;
                }
                if (dist[to] == -1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
    }
    
    if (min_cycle != INT_MAX) {
        cout << min_cycle << el;
    } else {
        cout << -1 << el;
    }
}