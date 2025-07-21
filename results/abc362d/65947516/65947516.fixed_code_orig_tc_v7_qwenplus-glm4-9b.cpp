void heap_dijkstra()
{
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
        dis[i] = LLONG_MAX;
    dis[1] = 0; // Initialize the distance to the start vertex (vertex 1) to 0
    priority_queue<node> q;
    q.push({1, 0});
    while (!q.empty())
    {
        node now = q.top();
        q.pop();
        if (vis[now.id]) continue;
        vis[now.id] = true;
        for (auto i : g[now.id])
        {
            // Update the distance only by adding the weight of the edge, not the vertex weight twice
            if (dis[i.first] > dis[now.id] + i.second)
            {
                dis[i.first] = dis[now.id] + i.second;
                if (!vis[i.first]) q.push({i.first, dis[i.first]});
            }
        }
    }
}