#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<int> vec[MAXN];
queue<int> q;
int step[MAXN];
bool vis[MAXN];
int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        vec[u].push_back(v);
    }
    q.push(1);
    while(!q.empty()){
        int top=q.front();
        vis[top]=true;
        q.pop();
        for(int i=0;i<vec[top].size();i++){
            int to=vec[top][i];
            if(to==1){
                printf("%d\n",step[top]+1);
                return 0;
            }
            if(!vis[to]){
                step[to]=step[top]+1;
                q.push(to);
            }
        }
    }
    printf("-1\n");
    return 0;
}