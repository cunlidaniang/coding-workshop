#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int > pii;
#define ri register int
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

const int N = 2e5;
const int M = 1e5;

struct Node{
	int size;
	int h;
	ll mn, mx, sum;
    ll io;
	int l, r;
};

Node node[N + M + 5];
int cnt;
int root;
ll c;
int n;
int m;


inline void newNode(int & now, int o){
	node[now = ++cnt].mx = o;
    node[now].mn = o;
    node[now].sum = o;
    node[now].io = o;
	node[now].size = 1;
}

inline int diff(int & now){
	return node[node[now].l].h - node[node[now].r].h;
}

inline void update(int now){
	node[now].size = node[node[now].l].size + node[node[now].r].size + 1;
	node[now].h = std::max(node[node[now].l].h, node[node[now].r].h) + 1;
    node[now].sum = node[node[now].l].sum + node[node[now].r].sum + node[now].io;
    node[now].mx = std::max(node[node[now].l].mx, node[node[now].r].mx + node[node[now].l].sum + node[now].io);
    node[now].mx = std::max(node[now].mx, node[node[now].l].sum + node[now].io);
    node[now].mn = std::min(node[node[now].l].mn, node[node[now].r].mn + node[node[now].l].sum + node[now].io);
    node[now].mn = std::min(node[now].mn, node[node[now].l].sum + node[now].io);
}

inline void lr(int & now){
	int r = node[now].r;
	node[now].r = node[r].l;
	node[r].l = now;
	now = r;
	update(node[now].l);
	update(now);
}

inline void rr(int & now){
	int l = node[now].l;
	node[now].l = node[l].r;
	node[l].r = now;
	now = l;
	update(node[now].r);
	update(now);
}

inline void check(int & now){
	int nd = diff(now);
	if(nd > 1){
		int ld = diff(node[now].l);
		if(ld > 0){
			rr(now);
		}else{
			lr(node[now].l);
			rr(now);
		}
	}
	if(nd < -1){
		int rd = diff(node[now].r);
		if(rd < 0){
			lr(now);
		}else{
			rr(node[now].r);
			lr(now);
		}
	}
	else if(now){
		update(now);
	}
}

void ins(int & now, int p, int o){
	if(now == 0){
		newNode(now, o);
	}else if(p <= node[node[now].l].size + 1){
		ins(node[now].l, p, o);
	}else{
		ins(node[now].r, p - node[node[now].l].size - 1, o);
	}
	check(now);
}

ll ask(int x, int now = root){
    if(!node[now].l && !node[now].r){
        return std::max(0ll, std::min(x + node[now].io, c) );
    }
    int l = node[now].l, r = node[now].r;
    if(node[r].mx - node[r].mn < c){
        ll tmp = ask(x, l);
        tmp = std::max(0ll, std::min(tmp + node[now].io, c) );
        return node[r].sum + std::max(-node[r].mn, std::min( tmp , c- node[r].mx) );
    }
    return ask(0, r);
}

int find(int & now, int fa){
	int ans;
	if(!node[now].l){
		ans = now;
		node[fa].l = node[now].r;
	}else{
		ans = find(node[now].l, now);
		check(now);
	}
	return ans;
}

void rem(int & now, int p){
	if(node[node[now].l].size + 1 == p){
		int l = node[now].l , r = node[now].r;
		if(!l || !r){
			now = l + r;
		}else{
			now = find(r, r);
			if(now != r){
				node[now].r = r;
			}
			node[now].l = l;
		}
	}else if(node[node[now].l].size >= p){
		rem(node[now].l, p);
	}else{
		rem(node[now].r, p - node[node[now].l].size - 1);
	}
	check(now);
}

int main()
{
	c = read();
	n = read();
	For(i, 1, n){
		int o = read();
		ins(root, i, o);
	}
	m = read();
	For(i, 1, m){
		char s[5];
		scanf("%s", s);
		if(s[0] == 'a'){
			int p = read();
			printf("%lld\n", ask(p) );
		}else if(s[0] == 'r'){
			int p = read();
			rem(root, p);
		}else if(s[0] == 'i'){
			int p = read();
			int o = read();
			ins(root, p, o);
		}
	}
	// cout << root << endl;
	// For(i, 0, cnt){
	// 	cout<< i << " :: " << node[i].size << " !!" << node[i].h<< " !!" << node[i].io << ":: " << node[i].l << " " << node[i].r << endl;
	// 	cout<< node[i].mx <<  " "<< node[i].mn <<  " "<< node[i].sum <<  " "<< endl;
	// }

	return 0;
}

/*
10 3
4 -5 2
5
ask 7
rem 1
ask 7
ins 2 -3
ask 7

0 3
1 1 1
5
ask 7
ask 7
ins 2 -10
ask 7

10 3
1 2 3
10
ins 4 -1
ins 5 -2
ins 6 -6
ins 7 -10
ins 8 6
rem 2
rem 3
rem 4
rem 2
rem 1

10 3
1 2 3
5
ins 4 -1
ins 5 -2
ins 6 -6
ins 7 -10
ins 8 6
*/
