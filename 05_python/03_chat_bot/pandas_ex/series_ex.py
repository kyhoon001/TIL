import pandas as pd

data = ['2016', '2017', '2018', '2019']

result = pd.Series(data)
# series 객체의 이름 지정하기
result.name = 'Year'
#series 객체의 인덱스명 지정하기
result.index.name = 'No'

print(result)
# 다 출력하고  type까지 출력함

print(result.index)
print(result.values)
