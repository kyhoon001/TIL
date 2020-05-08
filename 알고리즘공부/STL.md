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