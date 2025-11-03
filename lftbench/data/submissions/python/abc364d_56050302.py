import bisect
n, q = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
queries = [list(map(int, input().split())) for _ in range(q)]
results = []
for x in range(q):
    target = queries[x][0]
    k = queries[x][1] - 1  
    pos = bisect.bisect_left(a, target)
    diffs = []
    if pos < n:
        diffs.append(abs(a[pos] - target))
    if pos > 0:
        diffs.append(abs(a[pos - 1] - target))
    diffs.sort()
    if k < len(diffs):
        results.append(diffs[k])
    else:
        results.append(-1)
for result in results:
    print(result)
