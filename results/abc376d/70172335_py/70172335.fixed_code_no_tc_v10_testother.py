from collections import deque
import sys

def main():
    n, m = map(int, input().split())
    
    # Build adjacency list
    graph = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a-1].append(b-1)  # Convert to 0-indexed
    
    # We want the shortest cycle containing vertex 0 (vertex 1 originally)
    # Use BFS from vertex 0, and when we can return to 0, that forms a cycle
    
    # dist[i] = shortest distance from vertex 0 to vertex i
    dist = [-1] * n
    dist[0] = 0
    q = deque()
    q.append(0)
    
    min_cycle = float('inf')
    
    while q:
        u = q.popleft()
        
        for v in graph[u]:
            if v == 0:
                # We can go back to start -> cycle of length dist[u] + 1
                min_cycle = min(min_cycle, dist[u] + 1)
            elif dist[v] == -1:
                # First time visiting v
                dist[v] = dist[u] + 1
                q.append(v)
            # If we've seen v before, we don't update, but we don't need to do anything
            # because we're looking for shortest path to each node
    
    print(min_cycle if min_cycle != float('inf') else -1)

if __name__ == "__main__":
    main()