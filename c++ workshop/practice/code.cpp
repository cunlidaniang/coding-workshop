#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int > pii;
#define ri register int
#define rc register char
#define rd register double
#define For(i, a, b) for(ri i= (a);i<= (b);i++)
#define Ford(i, a, b) for(ri i= (a);i>= (b);i--)
#define Max(a, b) ((a)> (b)? (a): (b))
#define Min(a, b) ((a)< (b)? (a): (b))
#define abs(x) ((x) > 0 ? (x) : (-x) )
#define rll register long long
#define Mod1 1000000007
#define Mod2 998244353
#define Redix1 31
#define Redix2 37
#define M_PI 3.14159265358979323846
 
ll read(){
    ll n= 0, b= 1;
    char c= getchar();
    while(!isdigit(c) ){
        if(c== '-') b= -1;
        c= getchar();
    }
    while(isdigit(c) ){
        n= n* 10;
        n+= c- 48;
        c= getchar();
    }
    return n* b;
}
 
void qSort(int a[], int l, int r){
    int mid= a[(l+ r)>> 1];
    int i= l, j= r;
    do{
        while(a[i] < mid){
            i++;
        }
        while(a[j] > mid){
            j--;
        }
        if(i<= j){
            int tmp= a[i];
            a[i]= a[j];
            a[j]= tmp;
            i++;
            j--;
        }
    }while(i<= j);
    if(l< j){
        qSort(a, l, j);
    }
    if(r> i){
        qSort(a, i, r);
    }
}
 
const int N = 2e5;
const int M = 4e5;
int head[N + 5];
int fa[N + 5];
int val[N + 5];
int nxt[2 * N + 5];
int to[2 * N + 5];
int n, m;
int tmp;
 
void addEdge(int x, int y){
    tmp++;
    to[tmp] = y;
    nxt[tmp] = head[x];
    head[x] = tmp;
}
 
void dfspre(int x){
    for(int i = head[x];i != 0; i = nxt[i]){
        int y = to[i];
        if(y == fa[x]){
            continue;
        }
        fa[y] = x;
        dfspre(y);
    }
}
 
int main()
{
    n = read();
    For(i, 2, n){
        int u = read(), v = read();
        addEdge(u, v);
        addEdge(v, u);
    }
    For(i, 1, n){
        val[i] = read();
    }
    std::shared_ptr<int>
 
    return 0;
}
 
/*
7
1 2
1 3
2 4
2 5
3 6
3 7
2
1 2 3
1 3 3
*/