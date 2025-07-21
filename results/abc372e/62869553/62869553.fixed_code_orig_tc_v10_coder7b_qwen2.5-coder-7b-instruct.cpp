#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int deg[200005];

void add_edge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
}

int find_kth_largest(vector<int>& arr, int k){
    sort(arr.begin(), arr.end());
    if(k > arr.size()) return -1;
    return arr[arr.size() - k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    while(q--){
        int type, u, v, k;
        cin >> type;

        if(type == 1){
            cin >> u >> v;
            add_edge(u, v);
        } else {
            cin >> u >> k;
            vector<int> neighbors;
            for(auto &v : adj[u]){
                neighbors.push_back(v);
            }
            cout << find_kth_largest(neighbors, k) << "\n";
        }
    }

    return 0;
}