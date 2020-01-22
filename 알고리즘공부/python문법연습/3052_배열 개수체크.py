list1 = []
list2 = []

for i in range(10) :
    a = int(input())
    list1.append(a)
    
    if a % 42 in list2 :
        pass
    else : 
        list2.append(a%42)

print(len(list2))