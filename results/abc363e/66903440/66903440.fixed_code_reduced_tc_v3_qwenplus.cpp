#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
using ll=int64_t;
using ld=long double;
int inf=1000000001;
ll INF=1e18;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define sz(x) (ll)x.size()
template<typename T>bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<typename T>bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int H,W,Y;
    cin>>H>>W>>Y;
    vector<vector<int>>A(H,vector<int>(W));
    rep(i,H)rep(j,W)cin>>A[i][j];
    
    // Priority queue to process cells by elevation (lowest first)
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    vector<vector<bool>>sunk(H,vector<bool>(W,false));
    int remaining = H*W;
    
    // Add all boundary cells to the priority queue
    rep(i,H){
        rep(j,W){
            if(i==0||i==H-1||j==0||j==W-1){
                pq.push({A[i][j],{i,j}});
                sunk[i][j] = true;
                remaining--;
            }
        }
    }
    
    // Process each year
    for(int year=1; year<=Y; year++){
        // Process all cells that sink at this sea level
        while(!pq.empty() && pq.top().first <= year){
            auto [elevation, pos] = pq.top();
            pq.pop();
            int i = pos.first, j = pos.second;
            
            // Check all 4 adjacent cells
            rep(k,4){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni>=0 && ni<H && nj>=0 && nj<W && !sunk[ni][nj]){
                    sunk[ni][nj] = true;
                    pq.push({A[ni][nj], {ni,nj}});
                    remaining--;
                }
            }
        }
        cout << remaining << endl;
    }
}