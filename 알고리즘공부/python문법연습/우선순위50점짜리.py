for tc in range(1,11) :
	
	n, v = input().split()

	arr = list() #간선에 대한 정보가 저장될 리스트
	checklist = list() # 몇 개의 임계점이 있는지를 저장함.
	visit = list()
	
	for _ in range(int(n)+1) :
		arr.append([])
		checklist.append(int(0))
		visit.append(False)
	
	inputarr = list(map(int,input().split()))
	for _ in range(int(v)) :
		#a, b = input().split()
		a = inputarr[0]
		inputarr.pop(0)
		b = inputarr[0]
		inputarr.pop(0)
		arr[int(a)].append(b)
		checklist[int(b)] +=  int(1)
	
	#print(arr)
	q = list()
	
	def bfs() :
		while q :
			a = q[0]
			q.pop(0)
			if visit[a] == False :
				print(a, end=" ")
				visit[a] = True
			#print(a,"의 값 : ", checklist[int(a)])
			if checklist[int(a)] <= 1 :
				
				for i in range(len(arr[a])) :
					if visit[int(arr[a][i])] == False:
						q.append(int(arr[a][i]))
						#print(q)
						visit[a] = True
						
						#print("전 : ",checklist[int(arr[a][i])])
						if checklist[int(arr[a][i])] == 0 :
							continue
						checklist[int(arr[a][i])] -= 1
						#print("후 : ",checklist[int(arr[a][i])])
						
						#임계지점 2의 값이 안 깎이는 문제 발생중	
				
				
				
				
	for i in range(int(n)+1) :
		if checklist[int(i)] == 0 and i != 0 :
			q.append(i)
	#print(q)
	print("#",end='')
	print(tc, end=" ")
	bfs()
	print()
	
	
	
	
	
