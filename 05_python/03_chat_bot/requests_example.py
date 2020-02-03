import requests

response = requests.get('https://www.google.com')

print(response.content)

print(response.status_code)

print(response.headers)

for key, value in response.headers.items():
    print(key,'',value)