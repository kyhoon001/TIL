n = int(input())

q = []
arr = []


def bfs(start) :
	

	check = [0] * n
	while q :
		a = q.pop(0)
		for i in range(n) :
			if arr[a][i] == 1 and check[i] == 0:
				q.append(i)
				arr[start][i] = 1
				check[i] =1
	return

for _ in range(n):
	arr.append(list(map(int,input().split())))
		
		

#print(arr[2][2])
for i in range(n) :
	q.append(i)
	bfs(i)


for i in range(n):
	for j in range(n):
		print(arr[i][j], end= " ")
	print()
	