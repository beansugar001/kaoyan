#include <bits/stdc++.h>
#include <queue>
#include <stack>
using namespace std;
int a[5];

int main()
{
    queue<int> q;
    stack<int> s;
    for(int i = 0; i < 5; i ++) {
        int a;
        cin >> a;
        s.push(a);
    }
    for(int i = 0; i < 5; i ++) {
        q.push(s.top());
        s.pop();
    }
    
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}