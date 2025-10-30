from collections import defaultdict, deque

def main():
    n, m = map(int, input().split())
    edge = defaultdict(list)
    
    for _ in range(m):
        a, b = map(lambda x: int(x) - 1, input().split())
        edge[a].append(b)
    
    # BFS to find shortest cycle containing vertex 0 (vertex 1 originally)
    INF = float("inf")
    dist_from_start = [INF] * n
    dist_from_start[0] = 0
    
    q = deque()
    q.append(0)
    
    min_cycle_length = INF
    
    while q:
        u = q.popleft()
        
        for v in edge[u]:
            if v == 0:
                # Found a cycle back to vertex 0
                min_cycle_length = min(min_cycle_length, dist_from_start[u] + 1)
            elif dist_from_start[v] == INF:
                # First time visiting this vertex
                dist_from_start[v] = dist_from_start[u] + 1
                q.append(v)
    
    print(min_cycle_length if min_cycle_length != INF else -1)

if __name__ == "__main__":
    main()