#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
bool visited[MAXN];
ll step[MAXN];

int main(){
    ll n, m, u, v;
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= m; i++){
        scanf("%lld %lld", &u, &v);
        vec[u].push_back(v);
    }
    queue<ll> q;
    q.push(1);
    step[1] = 0;
    visited[1] = true;

    while(!q.empty()){
        ll top = q.front();
        q.pop();

        for(ll i = 0; i < vec[top].size(); i++){
            ll to = vec[top][i];
            if(to == 1){
                printf("%lld\n", step[top] + 1);
                return 0;
            }
            if(!visited[to]){
                step[to] = step[top] + 1;
                visited[to] = true;
                q.push(to);
            }
        }
    }

    printf("-1\n");
    return 0;
}