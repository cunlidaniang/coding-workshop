#include<bits/stdc++.h>
#define ratio 4
using namespace std;
inline int read() {
	register int tmp=0;register char c=getchar(); while(c<'0'||c>'9')	c=getchar();
	while(c>='0'&&c<='9')	tmp=(tmp<<1)+(tmp<<3)+(c^48),c=getchar(); return tmp;
}
inline void print(int x) { if(x>9)	print(x/10); putchar(x%10+'0'); }

const int N=70010;
int n,m,a[N],ans;
vector <int> q,ttt;
int root;
int Tot=0;
struct ST {
	int l,r,s;
	ST(int L,int R,int S):l(L),r(R),s(S) {}
	ST() {}
};ST tr[20000010]; int Sta[20000010],Top=0;
int tot=0;
struct P {
	int l,r,val,rt,sz;
	P(int L,int R,int V,int Rt,int S):l(L),r(R),val(V),rt(Rt),sz(S) {}
	P() {}
};P t[N];
int sta[N],top=0;
//sgt_...：替罪羊树所属函数
//st_...：权值线段树所属函数

inline int Min(const int x,const int y) { return x<y?	x:y; }
inline int Max(const int x,const int y) { return x>y?	x:y; }
inline int st_node() {
	if(!Top) return ++Tot; --Top; return Sta[Top+1];
}
void clean(int &u) {
	if(tr[u].l)	clean(tr[u].l); if(tr[u].r)	clean(tr[u].r);
	Sta[++Top]=u,tr[u]=ST(0,0,0),u=0;
}
void st_insert(int &u,int l,int r,int x,int w) {
	if(!u)	u=st_node(); tr[u].s+=w;
	if(l>=r) { if(!tr[u].s)	clean(u); return ; }
	int mid=(l+r)>>1;
	x<=mid?	st_insert(tr[u].l,l,mid,x,w):
			st_insert(tr[u].r,mid+1,r,x,w);
	if(!tr[u].s)	clean(u);
}
void debug(int u,int Tab) {
	if(t[u].l)	debug(t[u].l,Tab+1);
	for(int i=1;i<Tab;i++)	printf("     |");
	printf(" %d\n",t[u].val);
	if(t[u].r)	debug(t[u].r,Tab+1);
}
inline bool Bad(int u) {
	return (double)t[t[u].l].sz>ratio*(double)t[t[u].r].sz||
	       (double)t[t[u].r].sz>ratio*(double)t[t[u].l].sz;
}
inline int sgt_node(int l,int r,int v,int sz) {
	t[sta[top]]=P(l,r,v,0,sz),--top; return sta[top+1];
}
void sgt_init(int &u,int l,int r) {
	int mid=(l+r)>>1; u=sgt_node(0,0,a[mid],r-l+1);
	for(int i=l;i<=r;i++)	st_insert(t[u].rt,0,70000,a[i],1);//瓶颈
	if(l<mid)	sgt_init(t[u].l,l,mid-1);
	if(mid<r)	sgt_init(t[u].r,mid+1,r);
}
void ask(int u,int l,int r,int L,int R) {//类似线段树的方法预处理出要询问的块
	if(L>R||l>r)	return ;
	if(l==L&&r==R) { q.push_back(u);return ; }
	int mid=t[t[u].l].sz+l;
	if(L<=mid&&mid<=R)	ttt.push_back(t[u].val);
	if(R<mid)	ask(t[u].l,l,mid-1,L,R);
	else if(L>mid)	ask(t[u].r,mid+1,r,L,R);
	else	ask(t[u].l,l,mid-1,L,mid-1),ask(t[u].r,mid+1,r,mid+1,R);
}
int solve(int l,int r,int k) {
	ask(root,1,t[root].sz,l,r); int L=0,R=70000,mid,sum;
	for(int i=0;i<q.size();i++)	q[i]=t[q[i]].rt;
//	printf("ASK : ");
//	for(int i=0;i<q.size();i++)	printf(" %d",tr[q[i]].s);printf("\n");
//	for(int i=0;i<ttt.size();i++)	printf(" 1",ttt[i]);printf("\n");
	while(L<R) {
		mid=(L+R)>>1,sum=0;
		for(int i=0;i<q.size();i++)	sum+=tr[tr[q[i]].l].s;
		for(int i=0;i<ttt.size();i++)	if(ttt[i]<=mid)	++sum;
//		printf("MWHAKIOI : %d %d\n",mid,sum);
		if(sum>=k) {
			R=mid; for(int i=0;i<q.size();i++)	q[i]=tr[q[i]].l;
		}
		else {
			k-=sum,L=mid+1;
			for(int i=0;i<q.size();i++)	q[i]=tr[q[i]].r;
			for(int i=0;i<ttt.size();i++)
				if(ttt[i]<=mid)	ttt[i]=70010;
		}
	}
	q.clear(),ttt.clear(); return R;
}
int sgt_find(int u,int k) {
	if(t[t[u].l].sz+1==k)	return t[u].val;
	if(k<=t[t[u].l].sz)	return sgt_find(t[u].l,k);
	return sgt_find(t[u].r,k-t[t[u].l].sz-1);
}
void sgt_mdy(int u,int k,int Old,int New) {
	st_insert(t[u].rt,0,70000,Old,-1),
	st_insert(t[u].rt,0,70000,New,1);
	if(t[t[u].l].sz+1==k) { t[u].val=New;return ; }
	k<=t[t[u].l].sz?	sgt_mdy(t[u].l,k,Old,New):
	sgt_mdy(t[u].r,k-t[t[u].l].sz-1,Old,New);
}
void dfs(int &u) {
	if(t[u].l)	dfs(t[u].l);
	a[++n]=t[u].val,clean(t[u].rt),sta[++top]=u;
	if(t[u].r)	dfs(t[u].r);
	u=0;
}
void rebuild(int &u) { n=0,dfs(u),sgt_init(u,1,n); }
void sgt_insert(int &u,int x,int w) {
	if(!u) {
		u=sgt_node(0,0,w,1),st_insert(t[u].rt,0,70000,w,1);
		return ;
	}
	st_insert(t[u].rt,0,70000,w,1),++t[u].sz;
	if(x<=t[t[u].l].sz)	sgt_insert(t[u].l,x,w);
	else	sgt_insert(t[u].r,x-t[t[u].l].sz-1,w);
	if(!Bad(u)) {
		if(Bad(t[u].l))	rebuild(t[u].l);
		if(Bad(t[u].r))	rebuild(t[u].r);
	}
}
int main() {
	n=read();
	for(register int i=1;i<=n;++i)	a[i]=read(); m=read();
	for(register int i=1;i<N;++i)	sta[++top]=i;
	sgt_init(root,1,n);
//	printf("Array : \n"),debug(root,1),printf("\n");
	for(;m;--m) {
		register char opt=getchar();
		while(opt<'A'||opt>'Z')	opt=getchar();
		if(opt=='Q') {
			register int l=read()^ans,r=read()^ans,k=read()^ans;
			ans=solve(l,r,k),print(ans),putchar(10);
		}
		else if(opt=='M') {
			register int x=read()^ans,y=read()^ans,z;
			z=sgt_find(root,x),sgt_mdy(root,x,z,y);
		}
		else {
			register int x=read()^ans,y=read()^ans;
			sgt_insert(root,x-1,y); if(Bad(root))	rebuild(root);
		}
//		printf("Array : \n"),debug(root,1),printf("\n");
	}
	return 0;
}