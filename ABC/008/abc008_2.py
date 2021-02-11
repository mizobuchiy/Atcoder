from collections import Counter

N = int(input())
S = []

for _ in range(N):
    S.append(input())

c = Counter(S)

print(c.most_common()[0][0])
