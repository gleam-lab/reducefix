#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int n, q;

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int findKthLargest(vector<int>& vec, int k) {
    sort(vec.begin(), vec.end());
    if (vec.size() < k) return -1;
    return vec[k-1];
}

int main() {
    cin >> q >> n;
    while(q--) {
        int op, ix, iy;
        cin >> op >> ix >> iy;
        if (op == 1) {
            addEdge(ix, iy);
        } else {
            vector<int> neighbors = adj[ix];
            cout << findKthLargest(neighbors, iy) << endl;
        }
    }
    return 0;
}