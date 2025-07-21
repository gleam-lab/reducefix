#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<int> vec[MAXN];
queue<int> q;
bool visited[MAXN];
int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        vec[u].push_back(v);
    }
    q.push(1);
    visited[1] = true;
    int min_edges = INF; // Initialize with infinity
    bool found_cycle = false;

    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int i=0;i<vec[top].size();i++){
            int to = vec[top][i];
            if(to == 1){
                min_edges = 1; // Cycle length is 1 when it goes back to itself
                found_cycle = true;
                break;
            }
            if(!visited[to]){
                visited[to] = true;
                q.push(to);
            } else {
                // If we encounter a node that's already visited, calculate the cycle length
                int current = to;
                int count = 1;
                while(current != top){
                    current = vec[current][0]; // Assuming each node has only one outgoing edge to simplify
                    count++;
                }
                min_edges = min(min_edges, count); // Update the minimum cycle length
                found_cycle = true;
                break;
            }
        }
        if(found_cycle) break; // Once a cycle is found, exit the loop
    }

    if(found_cycle){
        printf("%d\n", min_edges);
    } else {
        printf("-1\n");
    }
    return 0;
}