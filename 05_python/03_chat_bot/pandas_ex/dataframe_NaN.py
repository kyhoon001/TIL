import pandas as pd
import numpy as np

df = pd.DataFrame(np.arange(18).reshape(6,3),
index=['a','b','c','d','e','f'], columns=['x','y','z'])

df['data1'] = pd.Series([1.7,1.2,2.4], index=['a','e','c'])

print(df)

df['date'] = pd.date_range('20190717',periods=6)
print(df)
#pd.dropna
# 행 데이터를 기준으로 NaN 값이 포함된 데이터를 제거한 후 나머지를
# DataFrame으로 반환함 
df.dropna(how='all') # 행 데이터의 모든 값이 NaN인 행 데이터를 제거한다
# print(df)  => 변화 없음 모든 값이 NaN은 아니기 때문.

df.dropna(how='any') # 행 데이터 중 하나라도 NaN이면 해당 행만 제거함
# 원본 데이터는 바뀌지 않음. 바꾸고 싶으면 inplace=True를 추가해야함.
df['data2'] = np.nan # 예제 데이터 생성

###########################################
# NaN인 데이터 찾기.

#pd.isnull()
print(df.isnull()) # DataFrame 내 NaN 데이터를 찾아 true,false로 반환


## pd.fillna(value='...') NaN 데이터를 찾아 지정된 value로 변환하여 반환
print(df.fillna(value='not null')) # 똑같이 원본 바꾸려면 inplace=True

## df.sort_index() index 이름 기준으로 오름차순 정렬
## df.sort_index(ascending=False) 내림차순
## df.sort_index(axis=1) column명 기준으로 오름차순
## df.sort_index(ascending=False) 내림차순
## df.sort_values(by='...') 특정 열 데이터 정렬시 by 옵션에 컬럼명 지정



########################################################################
#여기까지 데이터 분석 끝.