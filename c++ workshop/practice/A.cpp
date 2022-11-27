#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
typedef pair<long long, int > pii;
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

const int N = 5e5;
int cnt;
pii bh[2 * N + 5];
bool visited[N + 5];
int ln[N + 5];
int rn[N + 5];
long long val[N + 5];

void push(pii val){
	bh[++cnt] = val;
	int tmp = cnt;
	while(tmp != 1){
		if(bh[tmp] < bh[tmp >> 1]){
			swap(bh[tmp] , bh[tmp >> 1]);
		}
		tmp = tmp >> 1;
	}
}

pii top(){
	return bh[1];
}

void pop(){
	bh[1] = bh[cnt];
	cnt--;
	int tmp = 1;
	while(true){
		int l = tmp << 1, r = tmp << 1 | 1;
		if(l > cnt){
			break;
		}
		if(r > cnt){
			if(bh[l] < bh[tmp]){
				swap(bh[l] , bh[tmp]);
				tmp = l;
				continue;
			}
			break;
		}else{
			if(bh[l] < bh[tmp] && bh[l] <= bh[r]){
				swap(bh[l] , bh[tmp]);
				tmp = l;
				continue;
			}
			if(bh[r] < bh[tmp] && bh[r] <= bh[l]){
				swap(bh[r] , bh[tmp]);
				tmp = r;
				continue;
			}
			break;
		}
	}
}

int main()
{
	int n = read();
	For(i, 1, n){
		int v = read();
		val[i] = v;
		push(make_pair(v , i) );
	}
	For(i, 2, n){
		ln[i] = i - 1;
	}
	For(i, 1, n - 1){
		rn[i] = i + 1;
	}
	int lastAns;
	while(cnt > 0){
		// For(i, 1, n){
		// 	cout<< visited[i] << " ";
		// }
		// cout<< endl;
		// For(i, 1, n){
		// 	cout<< val[i] << " ";
		// }
		// cout<< "!!";
		pii x = top();
		// cout<< x.first << " " << x.second << endl;
		pop();
		int p = x.second;
		if(visited[p] == true){
			continue;
		}
		lastAns = x.first;
		int lp = ln[p];
		int rp = rn[p];
		if(lp == 0 && rp == 0){
			break;
		}
		if(lp == 0 || (lp != 0 && rp != 0 && (val[rp] ^ val[p]) + 1 > (val[lp] ^ val[p]) + 1 ) ){
			val[p] = (val[rp] ^ val[p]) + 1;
			rn[p] = rn[rp];
			if(rn[rp] != 0){
				ln[rn[rp]] = p;
			}
			visited[rp] = true;
			push(make_pair(val[p] , p) );
		}else{
			val[p] = (val[lp] ^ val[p]) + 1;
			ln[p] = ln[lp];
			if(ln[lp] != 0){
				rn[ln[lp]] = p;
			}
			visited[lp] = true;
			push(make_pair(val[p] , p) );
		}
	}
	cout<< lastAns << endl;
}

/*
5
3 6 6 7 1 
6
1 2 3 2 1 3
*/
