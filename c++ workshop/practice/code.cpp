#include<iostream>
#include<queue>
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
#define rll register long long
#define Mod 998244353
#define M_PI 3.14159265358979323846

ll abs(rll x){
	return x> 0? x: -x;
}

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

const int N= 1e5;

int a[N+ 5];

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

int main()
{
	

    return 0;
}

/*

5
1 3 4 3 6
2
1 20

*/
