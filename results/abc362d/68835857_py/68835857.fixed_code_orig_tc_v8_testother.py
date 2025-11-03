import heapq

N, M = map(int, input().split())
A = list(map(int, input().split()))

# Build adjacency list: (neighbor, edge_weight)
G = [[] for _ in range(N)]
for _ in range(M):
    u, v, b = map(int, input().split())
    u -= 1
    v -= 1
    G[u].append((v, b))
    G[v].append((u, b))

INF = float('inf')
dist = [INF] * N
dist[0] = A[0]  # Start at vertex 1 (index 0), include its vertex weight

pq = [(A[0], 0)]  # (distance, vertex)

while pq:
    d, u = heapq.heappop(pq)
    
    if d > dist[u]:
        continue
        
    for v, edge_weight in G[u]:
        # Total cost to reach v via u: current distance + edge weight + vertex weight of v
        new_dist = d + edge_weight + A[v]
        if new_dist < dist[v]:
            dist[v] = new_dist
            heapq.heappush(pq, (new_dist, v))

# Output distances for vertices 2 to N (indices 1 to N-1)
print(*dist[1:])