import heapq

N, M = map(int, input().split(" "))
A = [-int(_) for _ in input().split(" ")]

heapq.heapify(A)

for i in range(M):
    heapq.heappush(A, -(-heapq.heappop(A) // 2))

print(-sum(A))
