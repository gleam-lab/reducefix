#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef pair<int,int> PII;
typedef pair<int,PII> TIII;
using ll = long long;

struct Query{
    int x,y,t;
};

bool cmp(Query &a,Query &b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,q;cin>>n>>m>>q;
    vector<vector<bool>> grid(n,vector<bool>(m,false));
    vector<Query> qs;
    rep(i,q){
        int x,y;cin>>x>>y;x--,y--;
        qs.push_back({x,y,i});
    }
    sort(qs.begin(),qs.end(),cmp);
    set<int> xs,ys;
    multiset<TIII> ms;
    vector<int> ans(q,-1);
    rep(i,q){
        int x=qs[i].x,y=qs[i].y,t=qs[i].t;
        while(!xs.empty()&&*xs.rbegin()<x){
            ys.erase(ys.find(*xs.rbegin()));
            xs.erase(xs.find(*xs.rbegin()));
        }
        while(!ys.empty()&&*ys.rbegin()<y){
            ms.erase(ms.find(TIII{-1,{*ys.rbegin(),x}}));
            ys.erase(ys.find(*ys.rbegin()));
        }
        if(grid[x][y]){
            ans[t]=n*m-(xs.size()+ys.size());
        }else{
            bool up=true,down=true,left=true,right=true;
            auto it=ms.lower_bound(TIII{-1,{x+1,y}});
            if(it!=ms.end()&&it->second.second==y)up=false;
            it=ms.lower_bound(TIII{-1,{x-1,y}});
            if(it!=ms.begin()){
                it--;
                if(it->second.second==y)down=false;
            }
            it=ms.lower_bound(TIII{-1,{x,y+1}});
            if(it!=ms.end()&&it->second.first==y)right=false;
            it=ms.lower_bound(TIII{-1,{x,y-1}});
            if(it!=ms.begin()){
                it--;
                if(it->second.first==y)left=false;
            }
            if(up&&!ys.count(x)){
                ys.insert(x);
                xs.insert(x);
            }
            if(down&&!ys.count(x)){
                ys.insert(x);
                xs.insert(x);
            }
            if(right&&!xs.count(y)){
                ms.insert(TIII{1,{y,x}});
                xs.insert(y);
            }
            if(left&&!xs.count(y)){
                ms.insert(TIII{1,{y,x}});
                xs.insert(y);
            }
            ans[t]=n*m-(xs.size()+ys.size());
        }
        grid[x][y]=true;
    }
    rep(i,q)cout<<ans[i]<<'\n';
    return 0;
}