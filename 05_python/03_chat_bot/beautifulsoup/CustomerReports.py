from bs4 import BeautifulSoup
import requests



url = "https://www.consumerreports.org/cro/a-to-z-index/products/index.htm"

response = requests.get(url)
data = response.text


soup=BeautifulSoup(data,'html.parser')
# print(soup)

# tags = soup.find_all('a')

tags = soup.find_all(class_='products-a-z__results__item')
# id를 뽑을때는 id="asdadsad" 이런식으로

#<a> 태그의 href 속성 값에서 url정보 추출
for tag in tags:
    # print(tag.get("href"))
    print(tag.text + "     ///link : " +  tag.get("href"))



