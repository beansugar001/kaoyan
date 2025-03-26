#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int s1,s2,s3,n,k;
string str;

int main(){
    cin >> str;
    n = str.length();
    k = 0;
    for(int i = 0; i < n; i ++) {
        if(str[i] <= '9' && str[i] >= '0'){
            k = k * 10 + (str[i] - '0');
        }else if(str[i] == '.') {
            s.push(k);
            k = 0;
        }else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            s1 = s.top();s.pop();
            s2 = s.top();s.pop();
            if (str[i] == '+') s3 = s2 + s1;
            else if (str[i] == '-') s3 = s2 - s1;
            else if (str[i] == '*') s3 = s2 * s1;
            else if (str[i] == '/') s3 = s2 / s1;
            s.push(s3);
        }else if(str[i] == '@'){
            break;
        }
    }
    cout << s.top();
    return 0;
}