#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n,q;
int a,x,y,z;

#define AI 100000

int main(){
    cin >> n >> q;
    unordered_map<int, unordered_map<int, int>> mp;
    for(int i = 1; i <= q; i ++) {
        cin >> a;
        if(a == 1){
            int z;
            cin >> x >> y >> z;
            mp[x][y] = z;
        }else if(a == 2){
            cin >> x >> y;
            if(mp[x][y]){
                cout << mp[x][y] << endl;
            }else{
                cout << 0 << endl;
            }
        }
    }
    return 0;
}