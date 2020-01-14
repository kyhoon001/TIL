
## TIL 목표
**1주일에 3가지 이상의 알고리즘을 다루는 것을 목표로 공부한다.**


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


