#include<iostream>
#include<cstring>
#include<algorithm>
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

void qSort(ll a[], int l, int r){
	int mid= a[(l+ r)>> 1];
	int i= l, j= r;
	do{
		while(a[i] > mid){
			i++;
		}
		while(a[j] < mid){
			j--;
		}
		if(i<= j){
			ll tmp= a[i];
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

const int N = 1e5;
ll a[N + 5];
ll pre[N + 5];
ll suf[N + 5];
int n;
bool ans1, ans2, ans3;

void process(){
	n =  read();
	ans1 = true;
	For(i, 1, n){
		a[i] = read();
		if(a[i] < 0){
			ans1 = false;
			return;
		}
	}

	qSort(a, 1, n);

	For(i, 1, n){
		pre[i] = pre[i - 1] + a[i];
	}
	Ford(i, n, 1){
		suf[i] = suf[i + 1] + a[i];
	}

	// For(i, 1, n){
	// 	cout<< suf[i] << endl;
	// }

	if(pre[n] % 2 == 1){
		ans1 = false;
		return;
	}

	ans2 = true;

	int pos = n + 1;

	For(i, 1, n){
		ll tmp = (ll)i * (ll)(i - 1);
		while(a[pos - 1] < i && pos - 1 > i){
			pos--;
		}
		if(pos <= i){
			pos = i + 1;
		}
		tmp += suf[pos] + (ll)i * (ll)(pos - i - 1);
		if(pre[i] > tmp){
			ans2 = false;
			return;
		}
	}

	ans3 = true;

	if(n != 1){
		For(i, 1, n){
			if(a[i] == 0){
				ans3 = false;
				return;
			}
		}
	}

	if(pre[n] != 2 * (n - 1LL) ){
		ans3 = false;
		return;
	}
	
}

int main()
{
	ans1 = ans2 = ans3 = false;
	process();

	if(ans1){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	if(ans2){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	if(ans3){
		printf("YES\n");
	}else{
		printf("NO\n");
	}


	return 0;
}

/*
3
4 4 4
28
3 3 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
*/
