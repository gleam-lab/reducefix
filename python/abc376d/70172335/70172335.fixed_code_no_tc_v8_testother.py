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
    
    # BFS from vertex 0 (vertex 1) to find shortest cycle containing it
    # We want the shortest path from 0 back to 0 with at least one edge
    dist = [-1] * n
    dist[0] = 0
    q = deque([0])
    
    while q:
        u = q.popleft()
        for v in graph[u]:
            if dist[v] == -1:  # Not visited
                dist[v] = dist[u] + 1
                q.append(v)
            elif v == 0:  # Found a cycle back to vertex 0
                # This handles the case where we complete a cycle back to start
                # But we need to make sure it's not just checking self-loop incorrectly
                pass
    
    # Actually, we need to find shortest cycle containing vertex 0
    # Better approach: For each neighbor of 0, do BFS to find shortest path back to 0
    
    if n == 1:
        # Check if there's a self-loop on vertex 0
        if 0 in graph[0]:
            print(1)
        else:
            print(-1)
        return
    
    # Look for shortest cycle through vertex 0
    # Start from all direct neighbors of 0, then find shortest path back to 0
    ans = float('inf')
    
    for neighbor in graph[0]:
        # BFS from neighbor to reach back to 0
        dist = [-1] * n
        q = deque()
        dist[neighbor] = 1  # One edge from 0 to neighbor
        q.append(neighbor)
        
        found = False
        while q and not found:
            u = q.popleft()
            for v in graph[u]:
                if dist[v] == -1:
                    dist[v] = dist[u] + 1
                    if v == 0:
                        ans = min(ans, dist[v])
                        found = True
                        break
                    q.append(v)
            if found:
                break
    
    print(ans if ans != float('inf') else -1)

if __name__ == "__main__":
    main()