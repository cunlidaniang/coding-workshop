#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <stack>
#include <deque>
#include <cmath>
#include <set>
#include <bitset>
using namespace std;

typedef long long ll;
#define ri register int
#define rc register char
#define rll register ll
#define rd register double
#define For(i, a, b) for(ri i= a;i<= b;i++)
#define Ford(i, a, b) for(ri i= a;i>= b;i--)
#define max(a, b) (a> b? a: b)
#define min(a, b) (a> b? b: a)
#define lowbit(x) (x& -x)
#define INF (2147483647)

inline ll read(){
	rll s= 0;
	bool b= 0;
	rc c= getchar();
	while(!isdigit(c) ) b= c== '-', c= getchar();
	while(isdigit(c) ) s= (s<< 3)+ (s<< 1)+ c- '0', c= getchar();
	return b? ~s+ 1: s;
}

#define ls(x) (spl[x].ch[0])
#define rs(x) (spl[x].ch[1])
#define ident(x, f) (rs(f)== x)
#define connect(x, f, k) (spl[f].ch[k]= x, spl[x].fa= f)

const int N= 3e5+ 5;
int n, m, root, cnt;
int c;

struct Spl{
	int ch[2], size, cnt, val, fa;
	int lb, rb, o, io;
}spl[N];

inline void move(int & lb, int & rb, int & o1, int o2){
	int l = lb + o1, r = rb + o1;
	if(l + o2 > c){
		o2 = c - l;
	}else if(r + o2 < 0){
		o2 = -r;
	}
	l += o2, r += o2;
	if(l < 0){
		l = 0;
	}else if(r > c){
		r = c;
	}
	lb = l - o2 - o1;
	rb = r - o2 - o1;
	o1 = o1 + o2;
}

inline void updata(int now){
	spl[now].size= spl[ls(now)].size+ spl[rs(now)].size+ spl[now].cnt;
	int l = 0, r = c, o = 0;
	if(ls(now) != 0){
		l = spl[ls(now)].lb, r = spl[ls(now)].rb, o = spl[ls(now)].o;
	}
	move(l, r, o, spl[now].io);
	if(rs(now) != 0){
		int l2 = spl[rs(now)].lb, r2 = spl[rs(now)].rb, o2 = spl[rs(now)].o;
		int x = max(l + o, l2), y = min(r + o, r2);
		if(x <= y){
			l = x - o, r = y - o;
			o += o2;
		}else{
			if(l + o < l2){
				l = l2 + o2, r = l2 + o2;
				o = 0;
			}else{
				l = r2 + o2, r = r2 + o2;
				o = 0;
			}
		}
	}
	spl[now].lb = l, spl[now].rb = r, spl[now].o = o;
}

inline void rotate(ri x){
	ri f= spl[x].fa, ff= spl[f].fa, k= ident(x, f);
	connect(spl[x].ch[k^ 1], f, k);
	connect(x, ff, ident(f, ff) );
	connect(f, x, k^ 1);
	updata(f), updata(x);
	return;
}

inline void splaying(ri x, ri top){
	if(top== 0) root= x;
	while(spl[x].fa!= top){
		ri f= spl[x].fa, ff= spl[f].fa;
		if(ff!= top) ident(x, f)^ ident(f, ff)? rotate(x): rotate(f);
		rotate(x);
	}
	return;
}

inline void ins(ri o, ri p, ri &now= root, ri fa= 0){
	if(now== 0){
		now = ++cnt;
		spl[now].io = o;
		spl[now].size= spl[now].cnt= 1, spl[now].fa= fa;
		splaying(now, 0);
		return;
	}
	if(p <= spl[ls(now)].size + 1) ins(o, p, ls(now), now);
	else ins(o, p - spl[ls(now)].size - 1, rs(now), now);
	return;
}

inline int fn(ri rank){
	ri now= root;
	while(now){
		ri a= spl[ls(now)].size, b= spl[now].cnt;
		if(rank<= a) now= ls(now);
		else if(rank<= a+ b){
			splaying(now, 0);
			break;
		}
		else now= rs(now), rank-= a+ b;
	}
	return now;
}

void ask(int x){
	int l = spl[root].lb, r = spl[root].rb, o = spl[root].o;
	if(x < l){
		x = l;
	}else if(x > r){
		x = r;
	}
	x += o;
	printf("%d\n", x);
}

inline void del(ri rank){
	ri x= fn(rank);
	splaying(x, 0);
	spl[x].cnt--, spl[x].size--;
	if(spl[x].cnt> 0) return;
	ri pre= ls(x);
	if(pre== 0){
		root= rs(x), spl[root].fa= 0;
		return;
	}
	else{
		while(rs(pre) ) pre= rs(pre);
		splaying(pre, x);
		connect(rs(x), pre, 1);
		root= pre, spl[root].fa= 0;
		updata(pre);
		return;
	}
	return;
}

int main(){
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	
	c = read();
	n = read();
	For(i, 1, n){
		int o = read();
		ins(o, i);
	}
	m = read();
	For(i, 1, m){
		char s[5];
		scanf("%s", s);
		if(s[0] == 'a'){
			int p = read();
			ask(p);
		}else if(s[0] == 'r'){
			int p = read();
			del(p);
		}else if(s[0] == 'i'){
			int p = read();
			int o = read();
			ins(o, p);
		}
	}
	// cout << root << endl;
	// For(i, 1, cnt){
	// 	cout<< i << " :: " << spl[i].size << " !!" << spl[i].io << ":: " << spl[i].ch[0] << " " << spl[i].ch[1] << endl;
	// 	cout<< spl[i].lb <<  " "<< spl[i].rb <<  " "<< spl[i].o <<  " "<< endl;
	// }
	
	return 0;
}