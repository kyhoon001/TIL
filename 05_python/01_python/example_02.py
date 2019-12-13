import webbrowser

# webbrowser.open('www.google.co.kr')

import requests
# res = requests.get("http://naver.com")
# print(res.text)


from bs4 import BeautifulSoup


url = 'https://finance.naver.com/sise/'
response = requests.get(url).text
soup = BeautifulSoup(response, 'html.parser')
kospi = soup.select_one('#KOSPI_now')
print(kospi.text)