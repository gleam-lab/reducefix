dis[i.first] = dis[now.id] + i.second + a[now.id];
   ```
   This correctly adds the edge weight and the source vertex weight.
2. However, at the end you do:
   ```cpp
   printf("%lld ",dis[i]+a[i]);
   ```
   This is correct because we have not included A[i] in the distance calculation — it's added once at the end.

But there was one major bug:
- In the initial setup, `dis[1] = 0;` — but this omits `A[1]`, which should be included because the path starts at vertex 1.
  - So, `dis[1]` should actually be initialized as `A[1]`.

### Fixed Code