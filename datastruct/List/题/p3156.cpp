#include<stdio.h>
#include<stdlib.h>

#define NMAX (1000000 + 2)
#define MMAX (1000000 + 2)

int s[NMAX];
int q[MMAX];

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i<=n; i++) {
        scanf("%d", &s[i]);
    }
    for(int i = 1; i<= m; i++) {
        scanf("%d", &q[i]);
    }
    for(int i = 1; i <= m; i++) { 
        printf("%d\n", s[q[i]]);
    }
    return 0;
}