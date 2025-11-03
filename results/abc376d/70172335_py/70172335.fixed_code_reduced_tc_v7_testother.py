from collections import defaultdict, deque

def main():
    n, m = map(int, input().split())
    graph = defaultdict(list)
    
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
    
    # We want the shortest cycle containing vertex 1
    # Use BFS from vertex 1, and when we can return to 1, that's a cycle
    
    # dist[i] = shortest distance from vertex 1 to vertex i
    dist = [-1] * (n + 1)
    q = deque()
    
    # Start from vertex 1
    dist[1] = 0
    q.append(1)
    
    min_cycle = float('inf')
    
    while q:
        u = q.popleft()
        
        for v in graph[u]:
            if v == 1:
                # We found a path back to 1
                min_cycle = min(min_cycle, dist[u] + 1)
            elif dist[v] == -1:  # Not visited yet
                dist[v] = dist[u] + 1
                q.append(v)
    
    print(min_cycle if min_cycle != float('inf') else -1)

if __name__ == "__main__":
    main()