#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef struct node * nodeptr;
typedef struct node {
    int x;
    int y;
    int n;
    nodeptr left,right;
} node;
node arr[10001];

int cnt;

void insert(int a, int b, int c, nodeptr ptr) {

	if (ptr->x > b) { // x값이 더 작으면
		if (ptr->left == NULL) {
			arr[cnt].y = a;
			arr[cnt].x = b;
			arr[cnt].n = c;
			ptr->left = &arr[cnt];
			cnt++;
			return;
		}
		else insert(a, b, c, ptr->left);
		
	}
	else if (ptr->x < b) { // x값이 더 크면
		if (ptr->right == NULL) { // 오른쪽이 비어있으면
			arr[cnt].y = a;
			arr[cnt].x = b;
			arr[cnt].n = c;
			ptr->right = &arr[cnt];
			cnt++;
			return;
		}
		else insert(a, b, c, ptr->right);
	}

}
vector<int> v;
void preorder(nodeptr ptr) {
    if(ptr) {
       // cout << ptr->n << endl;
        v.push_back(ptr->n);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(nodeptr ptr) {
    if(ptr) {
        postorder(ptr->left);
        postorder(ptr->right);
        v.push_back(ptr->n);
    }
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    priority_queue<pair<pair<int,int>,int>>q; //first = y, second = -x;

   for (int i = 0; i < nodeinfo.size(); i++) {
		q.push({ {nodeinfo[i][1],-nodeinfo[i][0]},i + 1 });
		arr[i].x = 0;
		arr[i].y = 0;
		arr[i].n = 0;
		arr[i].left = NULL;
		arr[i].right = NULL;
	}
	cnt = 1;
	arr[0].y = q.top().first.first;
	arr[0].x = -q.top().first.second;
	arr[0].n = q.top().second;
	q.pop();
	while (!q.empty()) {
		int a = q.top().first.first; // y값 . 높이
		int b = -q.top().first.second; // x값
		int c = q.top().second;
		q.pop();
		insert(a, b, c,&arr[0]);
	}
    v.clear();
	preorder(&arr[0]);
    answer.push_back(v);
    v.clear();
	postorder(&arr[0]);
    answer.push_back(v);
    return answer;
}