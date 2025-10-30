from collections import deque

def main():
    n, m = map(int, input().split())
    
    # Build adjacency list
    graph = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a-1].append(b-1)  # Convert to 0-indexed
    
    # BFS from vertex 0 (vertex 1) to find shortest cycle containing it
    # We want the shortest path from 0 back to 0
    dist = [-1] * n
    q = deque()
    
    # Start from vertex 0
    dist[0] = 0
    q.append(0)
    
    while q:
        u = q.popleft()
        for v in graph[u]:
            if dist[v] == -1:  # Not visited
                dist[v] = dist[u] + 1
                q.append(v)
            elif v == 0:  # Found a back edge to start vertex
                # This creates a cycle of length dist[u] + 1
                print(dist[u] + 1)
                return
    
    # If we never found a cycle containing vertex 0
    print(-1)

if __name__ == "__main__":
    main()