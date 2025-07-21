#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define fora(i,a,b) for(int i=a;i<b;i++)
#define trav(a,x) for(auto&a:x)
#define sz(x) (int)(x).size()
#define lb lower_bound
#define ub upper_bound

const int MAXN = 2 * 1e5 + 10;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef set<int> si;
typedef map<int, int> mii;

vi adj[MAXN];
mii rankv;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int parent[MAXN];

int find(int x){
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(rankv[x] > rankv[y]){
        rankv[x] += rankv[y];
        parent[y] = x;
        pq.push({rankv[x],x});
    }else{
        rankv[y] += rankv[x];
        parent[x] = y;
        pq.push({rankv[y],y});
    }
}

int getKthLargest(int node, int k){
    priority_queue<int,vector<int>, greater<int>> temp;
    for(int child : adj[node]){
        temp.push(child);
        if(temp.size() > k) temp.pop();
    }
    return temp.top();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    forn(i,n) parent[i] = i, rankv[i] = 1;
    
    forn(i,q){
        int type, u, v;
        cin >> type >> u >> v;
        if(type == 1){
            merge(u, v);
        }else{
            int root = find(u);
            auto it = pq.lower_bound({k,root});
            if(it != pq.end()){
                cout << it->second << endl;
            }else{
                cout << "-1" << endl;
            }
        }
    }
    return 0;
}