greeting = "안녕하세요"

print(greeting)

menus = ['순남시래기','양자강','타코벨']

phone_book =  {'순남시래기':'02-1234-5678','양자강':'02-4321-8765','타코벨':'02-7897-1235'}

print(phone_book['타코벨'])





n = 0
dust = 190

if dust >150 :
    print("매우나쁨")
elif 80<dust<=150 :
    print("나쁨")
elif 30<dust<=80:
    print("보통")
else :
    print("좋음")

import random
numbers = random.sample(range(1,46),6)
print(numbers)