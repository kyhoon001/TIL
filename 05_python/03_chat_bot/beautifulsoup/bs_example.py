from bs4 import BeautifulSoup

def read_file(fileName):
    file = open(fileName)
    data=file.read()
    file.close()
    return data

html_file = read_file('intro_to_soup_html.html')

soup = BeautifulSoup(html_file,'lxml')

meta = soup.meta
print(meta)
# <meta charset="utf-8>"
print(meta.name)
#<meta>

print(soup.prettify())
# => 결과는 intro_to_soup_html.html의 모든 코드를 긁어옴.
print(meta.get(charset))

body = soup.bodyprint(body['style'])