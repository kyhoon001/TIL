#자주 쓰는 stl

## 최솟값 :
```
최솟값 : *max_element(v.begin(),v.end());
최솟값 index : *max_element(v.begin(),v.end()) - v.begin();
```

## 개수 :
```
count(v.begin(),v.end(), 기준);
```

## vector에서 중복값 제거 :
```
sort를 하고 해주어야함
vector.erase(unique(s.begin(),s.end()),s.end())

sort된 vector에서 unique(vector.begin(),vector.end()) ==>
 중복된 값들을 뒤로 보낸 뒤 중복된 숫자가 시작되는 주소를 반환함.
 따라서 erase를 사용해서 해당 값부터 끝까지 지워주면 중복이 삭제됨.
```


## map으로 hash :
```


    map<string,string> hash;
    hash["key"] = value 이런식으로 접근

    모두 탐색 :
    for (it = map.begin(); it != map.end(); ++it)
        cout << "(" << (*it).first << "," << (*it).second << ")" << " ";
    cout << endl;
```
## find
```
    string s = "dfsfdafacaasd"
    s.find("caa"); // 시작 주소를 반환함.
	cout << s.substr(s.find(c), c.length()) << endl; // 아렇게 하면 뽑을 수 있음.



    숫자를 찾을 때는
    
	값 : cout <<  *find(v.begin(), v.end(), 20) << endl;
    index : cout << find(v.begin(), v.end(), 20) - v.begin() << endl;

    못 찾았을 떄 : if(find(v.begin(), v.end(), 60) == v.end()) 

```
## 중복은 set로 하자.