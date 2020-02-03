from bs4 import BeautifulSoup
import requests

url ="http://example.com/"

# 서버의 response 정보를 이용해 response 객체 생성
response = requests.get(url)
# response 객체에서 html 코드에 해당 부분 추출
data = response.text
#bs4를 이용하여 html 코드를 soup 객체로 파싱
soup=BeautifulSoup(data,'html.parser')
# 문서 내에 모든 <a> 태그 정보를 찾아 list로 반환
tags = soup.find_all('a')

#<a> 태그의 href 속성 값에서 url정보 추출
for tag in tags:
    print(tag.get("href"))