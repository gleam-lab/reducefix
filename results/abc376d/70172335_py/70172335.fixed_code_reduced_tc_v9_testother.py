from collections import defaultdict, deque

def main():
    n, m = map(int, input().split())
    graph = defaultdict(list)
    
    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        graph[a].append(b)
    
    # Use BFS to find shortest cycle containing vertex 0 (originally vertex 1)
    # We need to track distance from start and detect when we return to start
    dist = [-1] * n
    q = deque()
    
    # Start from vertex 0
    dist[0] = 0
    q.append(0)
    
    while q:
        u = q.popleft()
        for v in graph[u]:
            if v == 0:
                # We found a cycle back to vertex 1 (0-indexed)
                print(dist[u] + 1)
                return
            if dist[v] == -1:  # Not visited
                dist[v] = dist[u] + 1
                q.append(v)
    
    # If we never returned to vertex 0
    print(-1)

if __name__ == "__main__":
    main()