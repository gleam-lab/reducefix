#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
queue<ll> q;
ll step[MAXN];
bool vis[MAXN];

struct Node {
    ll dist;
    ll vertex;
    bool operator>(const Node& other) const {
        return dist < other.dist; // Min-heap by distance
    }
};

int main(){
    ll n, m, u, v;
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= m; i++) {
        scanf("%lld %lld", &u, &v);
        vec[u].push_back(v);
    }
    priority_queue<Node, vector<Node>, greater<Node>> pq; // Min-heap
    pq.push({0, 1}); // Push starting node with distance 0
    step[1] = 0;
    while(!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        ll top = current.vertex;
        if(vis[top]) continue;
        vis[top] = true;
        for(ll adj : vec[top]) {
            if(adj == 1) {
                printf("%lld\n", step[top] + 1);
                return 0;
            }
            if(!vis[adj]) {
                step[adj] = step[top] + 1;
                pq.push({step[adj], adj});
            }
        }
    }
    printf("-1\n");
    return 0;
}