#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
queue<ll> q;
ll step[MAXN];
bool vis[MAXN];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        ll u, v;
        scanf("%lld %lld", &u, &v);
        vec[u].push_back(v);
    }
    
    memset(step, 0, sizeof(step));  // Initialize step array to 0
    memset(vis, false, sizeof(vis)); // Initialize vis array to false
    q.push(1);
    step[1] = 0;
    vis[1] = true;

    while(!q.empty()){
        ll top = q.front();
        q.pop();
        for(ll i = 0; i < vec[top].size(); i++){
            ll to = vec[top][i];
            if(!vis[to]){
                vis[to] = true;
                step[to] = step[top] + 1;
                q.push(to);
            }
            if(to == 1){
                printf("%lld", step[to]);
                return 0;
            }
        }
    }
    printf("-1");
    return 0;
}