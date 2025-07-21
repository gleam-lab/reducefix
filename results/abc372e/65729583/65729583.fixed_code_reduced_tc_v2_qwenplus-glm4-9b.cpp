void Union(int u, int v) {
    u = Find(u); v = Find(v);
    if(u != v) {
        U[v] = u;

        // Ensure the set of v is the smaller one
        if(V[v].size() > V[u].size() || V[v].size() == V[u].size() && *V[v].rbegin() < *V[u].rbegin()) {
            swap(V[u], V[v]);
        }

        // Merge the sets
        for(int num : V[v]) {
            V[u].insert(num);
        }
    }
}