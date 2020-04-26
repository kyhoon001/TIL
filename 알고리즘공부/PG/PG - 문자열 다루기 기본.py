def solution(s):
    if 4 != len(s) and len(s) != 6 : return False
    # return s.isdigit() and len(s) in (4,6)
    return s.isdigit()