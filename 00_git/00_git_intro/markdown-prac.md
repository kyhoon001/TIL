# Git



## Git 개념

> git은 컴퓨터 파일의 변경사항을 추적하고 여러 명의 사용자들 간에 해당 파일들의 작업을 조율하기 위한 분산 버전 관리 시스템이다.



## Git 설정

> 전역 영역에서 commit 기록의 주인을 등록
>
> ```bash
> $ git config --global user.name "username"
> $ git config --global user.email "edu@hphk.kr"
> ```



## Git 기본

> **git init** 해당 디렉토리를 `Git`이 관리하도록 초기화
>
> add 파일명 커밋할 목록에 추가
>
> `commit -m` "커밋 메시지"(히스토리의 한 단위) 만들기
>
> `git push origin master` 현재까지의 역사(commits)가 기록되어 있는 곳에 새로 생성한 커밋 반영



## Git 저장소

> -  로컬(working directory) - staging area - remote repository(github, bitbucket, gitlab)
>
> - 로컬 컴퓨터 저장소 해당 버전의 스냅샷(기록), 원격저장소



## Git branch

> 1. 같은 작업물을 기반으로 동시에 다양한 작업을 할 수 있게 만들어 주는 기능
>
> 2. 독립적은 작업 영역 안에서 마음대로 소스코드를 변경할 수 있다. 분리된 작업 영역에서 변경된 내용은 추후에 기존 버전과 비교해서 새로운 하나의 버전을 만들어 낼 수 있다.





