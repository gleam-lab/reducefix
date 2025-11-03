n = int(input())
n3 = 3 ** n
b = "#"
w = "."

for i in range(1, n3 + 1):
    ans = ""
    for j in range(1, n3 + 1):
        if i % 3 == 2 and j % 3 == 2:
            ans += w
        # 長いので分割
        elif ((n3 // 3) < i <= (n3 // 3 * 2)) and ((n3 // 3) < j <= (n3 // 3 * 2)):
            ans += w
        else:
            ans += b
    print(ans)
