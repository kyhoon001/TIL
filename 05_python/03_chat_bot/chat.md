# 챗봇만들기 관련

1. 크롤링 관련 부분은 beautifulsoup 폴더에 있는 예제들 참조.
    - customerreports 에 예시 있음.

2. 데이터 분석 관련은 pandas_ex 폴더에 있는 문서들 참조. 



## 자연어 전처리
- Tokenization
- 정제 및 정규화
- Stop word 제거

- 환경 설정으로는 python, java, pycharm, NLTK, KoNLPy 등을 설치하여 준비
- - NLTK 설치
```
python -m pip install --upgrade pip
pip install numpy
pip install nltk

```
- python 실행 후
```python
import nltk
nltk.download('puckt')
nltk.download('stopwords')

```
- 자바 환경설정 : 변수 이름을 JAVA_HOME으로 준다.
- 변수 값 :  C:\Program Files\Java|jdk1.8.0_181\jre\bin\server
- 시스템 변수 Path에 %JAVA_HOME\bin 추가



- - KoNLPy 설치
```python
pip install JPype1-0.6.3-cp37-cp37m-win32.whl
pip install konlpy
```





- Tokenization

  ```
  Corpus를 토큰 단위로 나누는 작업
  의미 있는 단위로 토큰을 정의
  ToKenization을 위한 다양한 라이브러리가 존재함
  
  토큰 단위를 단어로 하는 경우, Workd Tokenization
  가장 쉬운 방법은 띄어쓰기로 구분하는 것
  
  구두점이나 특수문자를 단순히 제외해서는 안 된다.
  영어의 경우 줄임말과 단어 내에 띄어쓰기가 있는 경우 하나의 단어로 보아야 한다.
  ```

  

  ```python
  import nltk
  from nltk.tokenize import sent_tokenize
  
  text = "Droxford railway station was a small station on the Meon Valley Railway,"
  "built to a design by T. P. Figgis and opened in 1903. It served the villages"
  "of Droxford, Soberton and Hambledon in Hampshire, England.[A] The railway served"
  "a relatively lightly populated area, but was built to main line specifications in "
  "anticipation of it becoming a major route to Gosport. Consequently, although the" 
  "station was built in an area with only five houses, it was designed with the" 
  "capacity to handle 10-carriage trains. It initially proved successful both for the" 
  "transport of goods and passengers, but services were reduced during the First" 
  "World War and the subsequent recession, and the route suffered owing to" 
  "competition from road transport."
  print(text)
  print(sent_tokenize(text))
  ```

  

