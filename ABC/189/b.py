n = int(input())
x = int(input())
v = []
p = []
for i in range(n):
    v.append(int(input()))
    p.append(int(input()))

sum = 0
for i in range(n):
    sum += v[i] * p[i] / 100
    if sum > x:
        print(i + 1)
