from collections import defaultdict, deque

def main():
    n, m = map(int, input().split())
    graph = defaultdict(list)
    
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
    
    # We want the shortest cycle containing vertex 1
    # Use BFS from vertex 1, and when we come back to 1, we have a cycle
    
    INF = float('inf')
    dist = [INF] * (n + 1)  # 1-indexed
    dist[1] = 0
    q = deque()
    q.append(1)
    
    min_cycle = INF
    
    while q:
        u = q.popleft()
        for v in graph[u]:
            if v == 1:
                # We found a cycle back to vertex 1
                min_cycle = min(min_cycle, dist[u] + 1)
            elif dist[v] == INF:
                dist[v] = dist[u] + 1
                q.append(v)
    
    print(min_cycle if min_cycle != INF else -1)

if __name__ == "__main__":
    main()