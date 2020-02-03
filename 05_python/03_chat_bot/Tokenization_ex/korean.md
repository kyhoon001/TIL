# 한글 Tokenization

- KoNLPy 라는 파이썬 패키지를 사용
- mecab이 괜찮음. 자소분리나 오탈자에 대해서도 고려하려면 KOMORAN



```python
from konlpy.tag import Mecab
mecab = Mecab()
text = "자연어는 처리가 필요합니다. 전처리가 중요하지요. 철수가 전처리를 합니다."
print(mecab.morphs(text))
print(mecab.pos(text))
print(mecab.nouns(text))
```



## 텍스트 정제 및 정규화

- 실제 자연어 처리 전 데이터의 복잡도를 낮추기 위해 정제 및 정규화 실행
  - 정제(cleaning) : 갖고 있는 Corpus로부터 노이즈 데이터를 제거
  - 정규화(Nomalization) : 단어들을 통합시켜서 같은 단어로 만듦.



- Stop Word 제거 Corpus에서 큰 의미가 없는 단어 토큰을 제거하는 작업

  ```python
  import nltk
  from nltk.corpus import stopwords
  from nltk.tokenize import word_tokenize
  
  text = "개발 중 혹은 배포된 소프트웨어에서 이미 발견한 버그의 상태 변화 과정을 추적하기 위한 소프트웨어다. 버그가 수정되었는지 여부, 수정중이라면 현재 진행상황을 알 수 있고, 이미 알려진 버그의 누락을 막을 수 있으며, 버그 수정과 관련된 불필요한 커뮤니케이션 비용을 줄일 수 있다."
  stop_words = "혹은 이미 위한 있다 있으며"
  
  stop_words=stop_words.split("")
  tokens = word_tokenize(text)
  result=[]
  for w in tokens:
  	if w not in stop_words:
  		result.append(w)
  
  print(tokens)
  print(result)
  
  # stop word 사전을 db에 구축, 여러 문장을 bulk로 처리하는 백엔드 기능 개발하여 사용
  # https://www.ranks.nl/stopwords/korean
  ```

  

단어 분산처리 2/126

자연어 처리 기술 (텍스트 분류, 개체명 인식, 문장 생성)

예제 : https://data.seoul.go.kr/

Konlpy를 이용한 Tokenization 수행

Word Cloud 및 차원 축소를 통한 시각화 