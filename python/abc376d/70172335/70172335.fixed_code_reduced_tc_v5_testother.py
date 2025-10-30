from collections import deque

def main():
    n, m = map(int, input().split())
    graph = [[] for _ in range(n)]
    
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a-1].append(b-1)
    
    # We want the shortest cycle containing vertex 0 (vertex 1 originally)
    # Use BFS from vertex 0, but we cannot revisit nodes freely because that would create incorrect cycles
    # Instead, we do: for each neighbor of 0, run BFS from that neighbor and see if we can return to 0
    
    if n == 0:
        print(-1)
        return
        
    min_cycle = float('inf')
    
    # For each direct successor of vertex 0, try to find shortest path back to 0
    for neighbor in graph[0]:
        dist = [-1] * n
        q = deque()
        q.append(neighbor)
        dist[neighbor] = 1  # one edge from 0 to neighbor
        
        found = False
        while q and not found:
            u = q.popleft()
            for v in graph[u]:
                if dist[v] == -1:  # not visited
                    dist[v] = dist[u] + 1
                    if v == 0:
                        min_cycle = min(min_cycle, dist[u] + 1)
                        found = True
                        break
                    q.append(v)
            if found:
                break
    
    print(min_cycle if min_cycle != float('inf') else -1)

if __name__ == "__main__":
    main()