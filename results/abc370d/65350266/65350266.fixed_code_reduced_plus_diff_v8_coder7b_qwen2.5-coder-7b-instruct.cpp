#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

struct Query{
    int type;
    int x,y;
};

vector<Query> que;
vector<vector<bool>> field;

void init(const int h,const int w){
    que.clear();
    field.assign(h,vector<bool>(w,true));
}

void solve(){
    const int n=que.size();
    int ans=h*w;
    for(int i=0;i<n;++i){
        const Query &q=que[i];
        const int x=q.x-1,y=q.y-1;
        if(field[x][y]){
            --ans;
            field[x][y]=false;
        }else{
            for(int dx=-1;dx<=1;++dx){
                for(int dy=-1;dy<=1;++dy){
                    if(dx==0&&dy==0){ continue;}
                    const int nx=x+dx,ny=y+dy;
                    if(nx>=0&&nx<h&&ny>=0&&ny<w&&!field[nx][ny]){
                        field[nx][ny]=true;
                        ++ans;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
}

int main(){
    int h,w,q;
    scanf("%d%d%d",&h,&w,&q);
    init(h,w);
    rep(i,q){
        char s[2];
        scanf("%s",s);
        if(s[0]=='B'){
            int x,y;
            scanf("%d%d",&x,&y);
            que.emplace_back(Query{1,x,y});
        }else{
            assert(false);
        }
    }
    solve();
    return 0;
}