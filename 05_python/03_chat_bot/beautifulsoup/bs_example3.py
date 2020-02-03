from bs4 import BeautifulSoup

def read_file(fileName):
    file = open(fileName)
    data=file.read()
    file.close()
    return data

html_file = read_file('intro_to_soup_html.html')

soup = BeautifulSoup(html_file,'lxml')

# 태그 객체의 .string 멤버 변수로 Navigable strings값 조회
title = soup.title
print(title.string)

#태그 객체의 .replace_with("") 함수로 Navigable strings 값 변경
title.string.replace_with("title has been changed")
print(title.string)

#이름을 이용한 태그 객체 접근
p = soup.p
print(p)
#원래 정보 <p class = "title">In second div</p>
#출력 정보 <p>In first div</p>
#중복된 이름을 가진 tag에는 접근 불가 -> 가장 처음 태그의 정보만 출력


print('\n\n\n')
body = soup.body
print(type(body.children))
## 결과 : <class 'list_iterator'>

for child in body.children:
    print(child if child is not None else'', end = '\n\n\n\n')