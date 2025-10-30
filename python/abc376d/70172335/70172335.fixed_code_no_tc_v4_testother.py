from collections import deque

def main():
    n, m = map(int, input().split())
    
    # Build adjacency list
    graph = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        graph[a].append(b)
    
    # Use BFS to find shortest cycle containing vertex 0 (originally vertex 1)
    # We track the shortest distance from vertex 0 to each vertex
    dist = [-1] * n
    dist[0] = 0
    q = deque([0])
    
    min_cycle_length = float('inf')
    
    while q:
        u = q.popleft()
        
        for v in graph[u]:
            if v == 0:
                # Found a cycle back to vertex 0
                min_cycle_length = min(min_cycle_length, dist[u] + 1)
            elif dist[v] == -1:
                # First time visiting this vertex
                dist[v] = dist[u] + 1
                q.append(v)
    
    print(min_cycle_length if min_cycle_length != float('inf') else -1)

if __name__ == "__main__":
    main()