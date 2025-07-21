if (dis[u] + w < dis[v]) {
      dis[v] = dis[u] + w;
      q.push({dis[v], v});
  }
  ```

This ensures that each node’s weight is only included once in the total path cost, and edges contribute their weights properly.

---

Here's the corrected and efficient C++ implementation: