import heapq

N, M = map(int, input().split())
A = list(map(int, input().split()))

# Build graph: each edge stores (neighbor, edge_weight)
G = [[] for _ in range(N)]
for _ in range(M):
    u, v, b = map(int, input().split())
    u -= 1
    v -= 1
    G[u].append((v, b))
    G[v].append((u, b))

INF = 10**18
dist = [INF] * N
dist[0] = A[0]  # Start at vertex 0 (vertex 1), include its weight

pq = [(A[0], 0)]  # (distance, node)

while pq:
    d, u = heapq.heappop(pq)
    if d > dist[u]:
        continue
    for v, edge_weight in G[u]:
        # Total cost to go from u to v: current distance + edge weight + vertex weight of v
        new_cost = d + edge_weight + A[v]
        if new_cost < dist[v]:
            dist[v] = new_cost
            heapq.heappush(pq, (new_cost, v))

# Output distances for vertices 2 to N (indices 1 to N-1)
print(*dist[1:])