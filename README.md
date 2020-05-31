
## TIL 목표
**감 떨어지지 않게 쉬운문제라도 꾸준히 풀어보자.**

## 알고리즘
```
문제를 잘못 읽어서 디버깅에서 시간 버리는 경우가 많았음.
!!!꼭 문제 정확하게 읽고, 설계한 다음에 구현하자!!!


1. N값이 10~20이면 DFS, 50 이상이면 BFS, 10000 이상이면 이분탐색을 염두에 두고 접근하자.
2. 예제 데이터를 몇 개 손으로 시뮬레이션 해보자.
3. 함수를 짜고 나면 해당 함수가 의도한대로 작동하는지 확인해서 디버깅 시간을 줄이자.

```


## 디버깅 관련
```
빠르게 디버깅할 수 있게 단축키 외우고 연습하자
런타임 에러 발생시 F5로 디버깅 모드로 진입하여 자세한 에러 코드를 보자.

F9 : breaking point를 찍음.
F11 : 함수 안으로 진입
ctrl + F10 : 커서 있는 곳 실행.

```


## Git 기본 로직
### Git 초기 설정
```
$ git config --global --list
$ git config --global user.name "kyhoon001"
$ git config --global user.email "kyhoon001@naver.com"
```


### git -github 연결


### git add, commit, push
```
$ git add.
$ git commit -m "commit message"
$ git push origin master
```


### git 명령어 관련 
#### log
- git log
- git log --pretty=oneline
- git log --oneline
- git log --oneline --graph

#### 폴더
- git init =>초기화를 의미하며 앞으로 이 폴더를 git이 관리한다는 의미


#### remote
$ git remote add origin https://github.com/kyhoon001/TIL.git(이건 github에서 확인)
$ git remote -v => 이름 확인
$ git remote rename origin(원래이름) change(바꿀 이름)
$ git remote rm origin(삭제 대상)
git remote ==>연결되어있는거 확인(EX-> origin이라고 뜸)



git bash에서 실행
$ git clone https://github.com/nanayunn/endgame.git(github에서 확인)
$ code .


add에 올렸던거 떨구는 법
$ git reset HEAD
$ git rm --cached 




branch


$ git branch (feature/test 이건 예시임) -> branch 생성
$ git checkout (feature/test) -> 이동
$ git branch --d (feature/test) -> 삭제
$ git checkout -b (feature/test) -> 생성하고 해당 branch로 이동
$ git branch -D (feature/test) -> 강제로 삭제

$ git merge (feature/test) -> 해당 작업공간에서 작업한 것을 merge해서 옴


stash

$ git add . 하고 나서
$ git stash -> 저장함
$ git stash list -> 리스트 보기
$ git stash apply -> 다시 데려옴 다시 데려와도 add상태는 유지됨.
$ git stash drop -> apply로 꺼내고 난 뒤에는 남아있는거 지워야함.
$ git stash pop -> apply와 drop을 한번에 해줌.


$ git reset --hard 해쉬태그(e00a06f405ab9e9860f1e930d8f6874abc71ff3f)
해당 커밋으로 돌아감 해당 파일의 내용도 변경시킴. 태그는
$ git --pretty=oneline으로 볼 수 있음
$ git reset --soft 해쉬태그 ==> 커밋은 돌리지만 해당 파일의 내용을 변경시키지는 않음.
$ git reset --mixed 해쉬태그

$ git reset HEAD~2 => head를 기준으로 2단계 전으로 복귀
$ git revert 해쉬태그(2fe609020e1acb0b460d4addcf2e5981cb97f6d2 )


git credential reject
protocol=https
host=github.com


