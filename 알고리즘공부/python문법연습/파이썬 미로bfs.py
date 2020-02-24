


					
for tc in range(1,11):
	n = input()
	arr = []
	check = []
	answer = int(0)
	posx = list(map(int,[1,0,-1,0]))
	posy = list(map(int,[0,1,0,-1]))
	
	for _ in range(16) :
		tmp = input()
		arr.append(list(map(int,tmp)))
		check.append([0] * 16)


	def solve(aa,bb) :
		a = int(aa)
		b = int(bb)
		#print(a , "  " , b)
		global answer
		for i in range(4) :
			
			if arr[a+posx[i]][b+posy[i]] == int(3):
				#print("good")
				answer = 1
				return
			
			if check[a+posx[i]][b+posy[i]] == 0 and arr[a+posx[i]][b+posy[i]] == 0 :
				check[a+posx[i]][b+posy[i]] = 1
				solve(a+posx[i],b+posy[i])
					
	check[1][1] = 1
	solve(1,1)
	print("#", end="")
	print(tc,end=" ")
	print(answer)
