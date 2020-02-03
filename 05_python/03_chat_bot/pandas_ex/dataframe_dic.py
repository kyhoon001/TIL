import pandas as pd

data = {'name':['Lee','Hwang','Kim','Choi'],
        'score':[100,95,90,85],'grade':['A','A','B','B']}


df = pd.DataFrame(data) # 행과 열을 가진 데이터 구조를 생성
df.index.name = 'NO'
df.columns.name = 'Info'

print(df)


# 각 column을 지정하여 DataFrame 객체를 생성하는 것

c = ['name','grade','score','etc']
df2 = pd.DataFrame(data, columns=c)
print(df2)


# 인덱싱을 통해 객체의 열 또는 행 데이터 가져오기
print(df2['name'])
print(df2.name,df2.grade)
#모두 같은 기능

#이런 식으로 DataFrame의 데이터를 각각 지정하여 변경할 수 있다.
df2['etc'] = [11,22,33,44]
print(df2)
#df2['etc'] = 0 으로 모든 값을 0으로 바꿀 수도 있음.

#연산을 통해 열 데이터를 추가할 수 있다.
df2['high_score'] = df2['score'] > 90
print(df2)

#행 데이터를 추가하려면 loc()함수를 이용한다
df2.loc[5,:] = ['Su','C',70,0.0,False]
print(df2)

#drop을 통해 행 데이터를 삭제할 수도 있다.
#하지만 해당 데이터가 삭제되는 것이 아니라
#해당 데이터가 제외된 새로운 객체를 생성한다.
# df2.drop(5) 요렇게 삭제해도
# print(df2) 요렇게 찍어보면 데이터 안 바뀌고 그대로임
# 기존 객체의 데이터를 삭제하려면 df2.drop(5,inplace=True)라고 해야함

new_obj = df2.drop(5)
print(new_obj)

#index 바꾸기
df2.set_index('name',inplace=True)
# index 이름을 기존의 숫자에서 name 칼럼으로 바꿈

#loc[행 조건식, [열 조건식]]
print(df2.loc['Lee'])

print(df2.loc['Kim':'Choi',['grade','high_score']])


#iloc은  위치 번호를 기준으로 데이터를 가져옴.
# df2.iloc[0:3] 이런식