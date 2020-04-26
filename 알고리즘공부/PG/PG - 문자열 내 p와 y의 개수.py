def solution(s):
    answer = True
    
    # [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    if s.lower().count('p') != s.lower().count('y') or (s.lower().count('p') == 0 and s.lower().count('y') == 0) :
        return False
    print('Hello Python')

    return True