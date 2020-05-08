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

## 중복은 set로 하자.