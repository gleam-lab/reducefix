from collections import deque

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    m = int(data[1])
    
    # Build adjacency list
    graph = [[] for _ in range(n)]
    index = 2
    for _ in range(m):
        a = int(data[index]) - 1
        b = int(data[index + 1]) - 1
        index += 2
        graph[a].append(b)
    
    # BFS from vertex 0 (vertex 1 in 1-indexed) to find shortest cycle containing it
    # We want the shortest path from 0 back to 0 with at least one edge
    dist = [-1] * n
    dist[0] = 0
    q = deque([0])
    
    min_cycle = float('inf')
    
    while q:
        u = q.popleft()
        for v in graph[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
            elif v == 0:
                # Found a path back to start
                min_cycle = min(min_cycle, dist[u] + 1)
    
    # Check if we found a cycle containing vertex 0 (vertex 1)
    print(min_cycle if min_cycle != float('inf') else -1)

if __name__ == "__main__":
    main()