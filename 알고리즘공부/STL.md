# 자주 쓰는 stl

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
## vector 내림차순 정렬 :
```
sort(v.rbegin(),v.rend());
```

## map으로 hash :
```


    map<string,string> hash;
    hash["key"] = value 이런식으로 접근
    map<strring,string>::iterator iter = hash.begin();
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



## 반복문 인덱스를 이용한 값 처리를 할 수 없는 것 같음.
```
vector<int> v;
v = {1, 2, 5, 2};
for (auto i: v)
    cout << i << ' ';
cout << '\n';
// prints "1 2 5 2"


deque<vector<pair<int, int>>> d;
d = {{{3, 4}, {5, 6}}, {{1, 2}, {3, 4}}};
for (auto i: d) {
    for (auto j: i)
        cout << j.first << ' ' << j.second << '\n';
    cout << "-\n";
}



값을 바꿔줘야할때는 다음과 같이 함.
vector<int> v = {8, 2, 3, 1};
for (auto &it: v)
    it *= 2;
for (auto it: v)
    cout << it << ' ';
// prints "16 4 6 2"
```

## STL은 아니지만 최대공약수
```

ll gcd(ll a, ll b)
{
	ll tmp;
	while (b != 0) {
		tmp = a % b;
		if (tmp == 0) return b;
		else {
			a = b;
			b = tmp;
		}
	}
}
```

## 소수점 자리 설정
```

	// 소수점 자리수 수정
	cout << fixed;
	cout.precision(4);
	/////////////////////
```

## 입력 개수가 주어지지 않았을 때 입력받기
```
	while (getline(cin, s)) {
		if (s == "") break;
        //할거 하기
	}
```