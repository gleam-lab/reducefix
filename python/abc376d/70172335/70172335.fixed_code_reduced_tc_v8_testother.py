from collections import deque
import sys

def main():
    data = sys.stdin.read().split()
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
    
    # We want the shortest cycle containing vertex 0 (which is vertex 1 originally)
    # Use BFS from vertex 0, but we need to detect when we can return to 0
    # We cannot use simple visited array because we want to allow coming back to 0
    
    # dist[v] = shortest distance from 0 to v
    INF = float('inf')
    dist = [INF] * n
    dist[0] = 0
    q = deque([0])
    
    while q:
        u = q.popleft()
        for v in graph[u]:
            if dist[v] == INF:
                dist[v] = dist[u] + 1
                q.append(v)
    
    # Now check all edges that point back to vertex 0
    # If there's an edge from some vertex u to 0, then we have a cycle of length dist[u] + 1
    min_cycle = INF
    for u in range(n):
        if dist[u] != INF:  # reachable from 0
            for v in graph[u]:
                if v == 0:  # edge from u to 0
                    min_cycle = min(min_cycle, dist[u] + 1)
    
    print(min_cycle if min_cycle != INF else -1)

if __name__ == "__main__":
    main()