from collections import defaultdict, deque

def main():
    n, m = map(int, input().split())
    graph = defaultdict(list)
    
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
    
    # BFS from vertex 1 to find shortest cycle containing vertex 1
    INF = float('inf')
    dist = [INF] * (n + 1)  # distance from vertex 1
    dist[1] = 0
    
    q = deque([1])
    
    while q:
        u = q.popleft()
        for v in graph[u]:
            if dist[v] == INF:  # not visited yet
                dist[v] = dist[u] + 1
                q.append(v)
    
    # Check if there's any edge from a vertex back to vertex 1
    min_cycle = INF
    for u in range(1, n + 1):
        if dist[u] != INF and 1 in graph[u]:
            min_cycle = min(min_cycle, dist[u] + 1)
    
    print(min_cycle if min_cycle != INF else -1)

if __name__ == "__main__":
    main()