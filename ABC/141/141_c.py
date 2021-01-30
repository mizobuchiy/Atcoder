n, k, q = map(int, input().split())
p = [k - q] * n
for _ in range(q):
    p[int(input()) - 1] += 1

for x in p:
    print("Yes" if x > 0 else "No")
