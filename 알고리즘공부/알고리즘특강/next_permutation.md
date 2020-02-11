# next_permutation

- vector와 함께 사용.
- 정렬을 하고 돌리삼

```c++
vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(3);
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	v.push_back(8);
	do {
		// 출력
		
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}

		cout << endl;

	} while (next_permutation(v.begin(), v.end()));
```

- 이런 식으로 사용