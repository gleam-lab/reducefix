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
    
    # BFS from vertex 0 (vertex 1 in 1-indexing) to find shortest cycle containing it
    # We want the shortest path from 0 back to 0 with at least one edge
    dist = [-1] * n
    dist[0] = 0
    q = deque([0])
    
    min_cycle_length = float('inf')
    
    while q:
        u = q.popleft()
        
        for v in graph[u]:
            if v == 0:
                # Found a path back to vertex 0
                min_cycle_length = min(min_cycle_length, dist[u] + 1)
            elif dist[v] == -1:  # Not visited yet
                dist[v] = dist[u] + 1
                q.append(v)
    
    print(min_cycle_length if min_cycle_length != float('inf') else -1)

if __name__ == "__main__":
    main()