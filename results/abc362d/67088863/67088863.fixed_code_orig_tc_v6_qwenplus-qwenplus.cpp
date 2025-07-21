adj[a].push_back({b, 1ll * w + val[a]});
  adj[b].push_back({a, 1ll * w + val[b]});
  ```

This effectively includes the vertex weight `val[a]` or `val[b]` every time a node is reached through an edge, which leads to **double-counting** of vertex weights in paths longer than one step.

For example, in a path `1 -> u -> v`, the total cost becomes: