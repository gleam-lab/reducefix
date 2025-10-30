q = int(input())
l = 0
for i in range(q):
  query = [int(a) for a in input().split()]
  
  if query[0] == 1:
    l += 1
  elif query[0] == 2:
    l -= 1
  else:
    print(l)