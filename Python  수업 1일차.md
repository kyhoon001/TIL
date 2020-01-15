# Python  수업 1일차



- 간단한 환경설정 및 명령어에 대한 수업을 진행하였음.

  -  파이썬 파일 ( ex -> first.py)을   콘솔 환경에서 python first.py라고 입력하여 실행하였음

  ``` 
   import os
   print(os.name)
   결과 : nt
   
   import sys
   sys.platform
   결과 : win32
   
   import platform
   platform.system()
   결과 : Windows
  ```

  

- pip  명령어는 파이썬이 아닌 콘솔 환경에서 실행해야 함

  - 해당 환경에서는 beautifulsoup4를 설치해주었음

    ```
    pip install beautifulsoup4
    pip freeze > requirements.txt (필요한 패키지들을 해당 파일에 저장. )
    pip install -r requirements.txt 를 통해 해당 파일의 패키지들을 설치 가능
    
    python -m pip install --upgrade pip
    ```

    > pip를 통해 설치한 파일의 경로는 다음과 같다.
    >
    > Unix = prefix/lib/pythonx.y/site-packages (/usr/local/lib/pythonx.y/site-packages)
    >
    > Windows = prefix\lib\site-packages (c:\pythonxy\lib\site-packages)



## 관련 설정

- venv 모듈을 사용해 가상환경을 만들어줌

  ```
  python -m venv firstenv => 해당 디렉토리에 firstenv라는 폴더를 만듬
  cd firstenv/scripts  => 디렉토리 이동
  activate.bat => 가상환경 실행
  deactivate.bat => 가상환경 종료
  
  ```

- pycharm 환경에서는 setting 프로젝트에서 가상환경의 인터프리터를 추가해주었음.