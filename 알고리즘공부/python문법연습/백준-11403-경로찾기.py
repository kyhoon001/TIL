n = int(input())
arr = []
check = []
def solve(start, a) :
		
		for i in range(n) :
			if arr[a][i] == 1 : #간선이 있다면
			
				if check[a][i] == False : #만약 탐색이 안 되었으면
					check[a][i] = True #탐색을 하고
					arr[start][i] =1 # 처음 시작한 데서 목적지까지  경로가 있음
					
					solve(start,i)
												

for i in range(n) :
	arr.append(list(map(int,input().split())))
	check.append([False] * n)

for i in range(n) :
	
	solve(i,i)
	for j in range(n) :
		for t in range(n) :
			check[j][t] = False
	
for i in range(n) :	
	for j in range(n) :
		print(arr[i][j], end=" ")
	print()	

	
				
