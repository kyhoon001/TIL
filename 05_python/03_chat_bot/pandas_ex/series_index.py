import pandas as pd

data = ['2016', '2017', '2018', '2019']

result = pd.Series(data,index=['a','b','c','d'])

print(result)
print(result.index)



#dictionary 또한 리스트와 같은 방식으로 작동한다./