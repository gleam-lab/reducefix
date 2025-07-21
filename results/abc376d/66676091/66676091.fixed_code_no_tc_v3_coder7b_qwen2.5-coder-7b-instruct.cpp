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
  int N,M,len=INF;
  cin>>N>>M;
  vvi G(N);
  vb vis(N,false);
  rep(i,0,M){
    int s,v;
    cin>>s>>v;
    s--;v--;
    G[s].pb(v);
  }
  function<void(int,int)> dfs=[&](int pos,int d){
    if(vis[pos])return;
    vis[pos]=true;
    for(auto to:G[pos]){
      dfs(to,d+1);
    }
    if(pos==0){
      chmin(len,d);
    }
    vis[pos]=false;
  };
  dfs(0,0);
  if(len==INF)cout<<-1<<el;
  else cout<<len<<endl;
}