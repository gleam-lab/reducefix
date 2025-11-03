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
    q.append(0)
    dist[0] = 0
    
    while q:
        u = q.popleft()
        for v in graph[u]:
            if dist[v] == -1:  # Not visited
                dist[v] = dist[u] + 1
                q.append(v)
                # Don't stop here, we need to potentially reach 0 again
            elif v == 0:  # Found a way back to start
                # This handles the case where we're coming back to 0
                # But we need to make sure this is part of a valid cycle
                pass
    
    # Actually, we need to find shortest path from neighbors of 0 back to 0
    # Then add 1 for the edge from 0 to that neighbor
    
    # Special case: if there's a direct edge from some node back to 0,
    # and we can reach that node from 0, then we have a cycle
    
    # Let's do: BFS from 0, and when we encounter 0 again (except at start), we have a cycle
    # But we can't visit 0 twice in standard BFS
    
    # Alternative approach:
    # Remove all outgoing edges from 0 temporarily
    # For each neighbor of 0, compute shortest path from that neighbor back to 0
    # The answer is 1 + min(shortest path from neighbor to 0)
    
    if n == 1:
        # Check if there's a self-loop on vertex 1
        for neighbor in graph[0]:
            if neighbor == 0:
                print(1)
                return
        print(-1)
        return
    
    # Get neighbors of 0
    neighbors = graph[0]
    if not neighbors:
        print(-1)
        return
    
    # For each neighbor, find shortest path back to 0
    # Use BFS from 0 but don't immediately visit neighbors
    # Instead, we'll do BFS starting from all neighbors simultaneously
    
    dist = [-1] * n
    q = deque()
    
    # Initialize: all neighbors of 0 are at distance 1 (edge 0->neighbor)
    # But for returning, we want shortest path from neighbor to 0
    # So initialize with neighbors at distance 0 for the reverse path
    for neighbor in neighbors:
        if neighbor == 0:  # Self-loop
            print(1)
            return
        dist[neighbor] = 1  # This represents the full cycle length would be this + 0?
        q.append(neighbor)
    
    # If 0 has no neighbors except possibly itself, handled above
    if not q:
        print(-1)
        return
    
    # Mark 0 as unvisited initially, we want to reach it
    if dist[0] == -1:
        dist[0] = -1
    
    ans = -1
    while q and ans == -1:
        u = q.popleft()
        for v in graph[u]:
            if dist[v] == -1:  # Not visited
                dist[v] = dist[u] + 1
                if v == 0:
                    ans = dist[u] + 1
                    break
                q.append(v)
    
    print(ans)

if __name__ == "__main__":
    main()