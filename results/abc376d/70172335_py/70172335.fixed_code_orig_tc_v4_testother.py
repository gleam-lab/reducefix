from collections import defaultdict, deque

def main():
    n, m = map(int, input().split())
    graph = defaultdict(list)
    
    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        graph[a].append(b)
    
    # BFS to find shortest cycle containing vertex 0 (originally vertex 1)
    INF = float('inf')
    dist = [INF] * n
    dist[0] = 0
    queue = deque([0])
    
    min_cycle_length = INF
    
    while queue:
        u = queue.popleft()
        
        for v in graph[u]:
            if v == 0:
                # Found a cycle back to vertex 0
                min_cycle_length = min(min_cycle_length, dist[u] + 1)
            elif dist[v] == INF:
                # First time visiting this vertex
                dist[v] = dist[u] + 1
                queue.append(v)
    
    print(min_cycle_length if min_cycle_length != INF else -1)

if __name__ == "__main__":
    main()