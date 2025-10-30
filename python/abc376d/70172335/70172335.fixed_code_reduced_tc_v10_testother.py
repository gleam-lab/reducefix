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
    # We'll track the distance from vertex 0 to each vertex
    dist = [-1] * n
    dist[0] = 0
    queue = deque([0])
    
    while queue:
        u = queue.popleft()
        for v in graph[u]:
            if v == 0:
                # We found a cycle back to vertex 0
                print(dist[u] + 1)
                return
            if dist[v] == -1:  # Not visited yet
                dist[v] = dist[u] + 1
                queue.append(v)
    
    # If we never returned above, no cycle containing vertex 0 was found
    print(-1)

if __name__ == "__main__":
    main()