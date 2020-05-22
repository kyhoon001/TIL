def solution(arr):
    answer = []
    # [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    print('Hello Python')
    
    check = arr[0]
    answer.append(check)
    for i in arr :
        if i != check :
            check = i
            answer.append(i)
    
    
    
    return answer