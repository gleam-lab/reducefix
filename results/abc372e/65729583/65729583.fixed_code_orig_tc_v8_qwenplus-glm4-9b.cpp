// ...ä»£ç ...

void Union(int u, int v) {
    u = Find(u); v = Find(v);
    if (u != v) {
        U[v] = u;
        // ä¿è¯ u æ¯æ ¹èç¹
        if (V[v].size() > V[u].size()) swap(V[u], V[v]);
        // åå¹¶éå
        for (auto num : V[v]) {
            auto it = V[u].lower_bound(num);
            if (it != V[u].end() && *it == num) continue; // é¿éå¤
            V[u].insert(it, num);
        }
    }
}

// ...ä»£ç ...