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
    
    // Create a list of all boundary cells (initially exposed to sea)
    vector<tuple<int,int,int>> events; // (elevation, i, j)
    
    // Add all border cells
    rep(i,H){
        rep(j,W){
            if(i==0||i==H-1||j==0||j==W-1){
                events.emplace_back(A[i][j], i, j);
            }
        }
    }
    
    // Sort by elevation (lowest first)
    sort(all(events));
    
    vector<vector<bool>> submerged(H,vector<bool>(W,false));
    int remaining = H*W;
    
    int event_idx = 0;
    queue<pair<int,int>> q;
    
    for(int year=1; year<=Y; year++){
        // Add all cells with elevation <= year that haven't been processed
        while(event_idx < events.size() && get<0>(events[event_idx]) <= year){
            auto [elev, i, j] = events[event_idx];
            if(!submerged[i][j]){
                submerged[i][j] = true;
                q.push({i,j});
                remaining--;
            }
            event_idx++;
        }
        
        // Flood fill from newly submerged cells
        while(!q.empty()){
            auto [i,j] = q.front(); q.pop();
            
            rep(k,4){
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if(ni>=0 && ni<H && nj>=0 && nj<W && !submerged[ni][nj]){
                    if(A[ni][nj] <= year){
                        submerged[ni][nj] = true;
                        q.push({ni,nj});
                        remaining--;
                    }
                }
            }
        }
        
        cout << remaining << '\n';
    }
}