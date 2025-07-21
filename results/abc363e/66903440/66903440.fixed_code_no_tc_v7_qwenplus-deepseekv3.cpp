#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int H,W,Y;
    cin>>H>>W>>Y;
    vector<vector<int>>A(H,vector<int>(W));
    int max_A = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>A[i][j];
            max_A = max(max_A, A[i][j]);
        }
    }
    
    int ans=H*W;
    vector<vector<bool>>sunk(H,vector<bool>(W,false));
    vector<queue<pair<int,int>>>Q(max_A + 2);
    
    // Process border cells first
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(i==0 || i==H-1 || j==0 || j==W-1){
                sunk[i][j] = true;
                Q[A[i][j]].push({i,j});
                ans--;
            }
        }
    }
    
    for(int y=1;y<=Y;y++){
        while(!Q[y].empty()){
            auto [i,j]=Q[y].front();
            Q[y].pop();
            
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni>=0 && ni<H && nj>=0 && nj<W){
                    if(!sunk[ni][nj]){
                        sunk[ni][nj] = true;
                        if(A[ni][nj] <= y){
                            Q[y].push({ni,nj});
                        }else{
                            Q[A[ni][nj]].push({ni,nj});
                        }
                        ans--;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
}