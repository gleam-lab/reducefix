from collections import defaultdict as dic, deque
def main():
    n, m = map(int, input().split())
    edge = dic(set)
    for _ in range(m):
        a, b = map(lambda x : int(x) - 1, input().split())
        edge[a].add(b)
    #bfs
    INF = float("inf")
    ans = INF
    q = deque()
    q.append((0, -1, 0)) #頂点と経由した辺の数
    cnt = [INF] * n
    cnt[0] = 0
    while q:
        (u, before, c) = q.popleft()
        for v in edge[u]:
            if v == before:
                continue
            if v == 0:
                ans = min(ans, c + 1)
            elif c + 1 > cnt[v]:
                #一度通過した頂点同士を連結
                ans = min(ans, c + cnt[v] + 1)
            else:
                cnt[v] = c + 1
                q.append((v, u, c + 1))
    print(ans if ans != INF else -1)

if __name__ == "__main__":
    main()