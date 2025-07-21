#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=2e5+7;
bool mp[N][N];
int h,w,q,r,c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>h>>w>>q;
    memset(mp,true,sizeof mp);
    for(int i=1;i<=q;++i){
        cin>>r>>c;
        if(!mp[r][c]){
            mp[r][c]=true;
            continue;
        }
        mp[r][c]=false;
        for(int j=r-1;j>=1&&mp[j][c];--j)mp[j][c]=false;
        for(int j=r+1;j<=h&&mp[j][c];++j)mp[j][c]=false;
        for(int j=c-1;j>=1&&mp[r][j];--j)mp[r][j]=false;
        for(int j=c+1;j<=w&&mp[r][j];++j)mp[r][j]=false;
    }
    LL res=0;
    for(int i=1;i<=h;++i)for(int j=1;j<=w;++j)if(mp[i][j])res++;
    cout<<res<<"\n";
    return 0;
}