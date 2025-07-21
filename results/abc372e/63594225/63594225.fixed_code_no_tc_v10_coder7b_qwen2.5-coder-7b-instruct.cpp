#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector<vector<int>> adj(N);

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int findKthLargest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    if(k > arr.size()) return -1;
    return arr[k - 1];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            addEdge(a, b);
        } else {
            vector<int> connectedVertices;
            for(auto& neighbor : adj[a]) {
                connectedVertices.push_back(neighbor);
            }
            cout << findKthLargest(connectedVertices, b) << '\n';
        }
    }

    return 0;
}