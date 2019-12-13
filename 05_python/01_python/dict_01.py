my_dict = {'한국어':'안녕', '영어':'hi', '독일어':'Geten tag'}
my_dict2 = {}
my_dict2['한국어']='안녕'
my_dict2['영어']='hi'
my_dict2['독일어']='Geten tag'

my_dict3 = dict(한국어='안녕',영어='hi',독일어='Geten tag')

print(my_dict)
print(my_dict2)
print(my_dict3)

area_code={'서울':'02'}
area_code['경기도']='031'
print(area_code)

for key in area_code:
    print(key)
    print(area_code[key])

for key, value in area_code.items():
    print(key,value)

for key in area_code.values():
    print(value)

score = {
    '수학': 80,
    '국어': 90,
    '음악': 100
}

scores = {
    'a': {
        '수학': 84,
        '국어': 90,
        '음악': 92
    },
    'b': {
        '수학': 83,
        '국어': 91,
        '음악': 77
    }
}

print(sum(score.values())/len(score.items()))