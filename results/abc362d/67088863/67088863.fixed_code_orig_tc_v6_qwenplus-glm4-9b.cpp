void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> val(n);
    for (ll& i : val) cin >> i;
    
    vector<vector<pair<int, ll>>> adj(n);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        adj[a].push_back({b, w}); // Removed the addition of the vertex weight
        adj[b].push_back({a, w}); // Removed the addition of the vertex weight
    }
    vector<ll> dist(n, INF);

    dist[0] = 0;
    vector<bool> vis(n, 0);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // Set the initial distance to vertex 1 as 0

    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();
        if (vis[v]) continue;
        vis[v] = 1;

        for (auto [u, ww] : adj[v]) {
            if (ww + dist[v] < dist[u]) {
                dist[u] = ww + dist[v];
                pq.push({dist[u], u});
            }
        }
    }

    for (int i = 1; i < n; i++) cout << dist[i] + val[i] << " ";
    cout << endl;
}