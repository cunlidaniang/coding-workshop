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

void qSort(int a[], int l, int r){
	int mid= a[(l+ r)>> 1];
	int i= l, j= r;
	do{
		while(a[i]< mid){
			i++;
		}
		while(a[j]> mid){
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

struct Node{
	ll c;
	ll e;
	Node *next;
};

Node* merge(Node* phead1, Node* phead2){
	Node* phead= NULL;
	Node* ppre= NULL;
	Node* tmp;
	
	while(phead1!= NULL|| phead2!= NULL){
		tmp= new Node;
		if(phead1!= NULL&& phead2!= NULL){
			if(phead1->e== phead2->e){
				tmp->c= phead1->c+ phead2->c;
				tmp->e= phead1->e;
				phead1= phead1->next;
				phead2= phead2->next;
			}else if(phead1->e< phead2->e){
				tmp->c= phead1->c;
				tmp->e= phead1->e;
				phead1= phead1->next;
			}else if(phead1->e> phead2->e){
				tmp->c= phead2->c;
				tmp->e= phead2->e;
				phead2= phead2->next;
			}
		}else if(phead1!= NULL){
			tmp->c= phead1->c;
			tmp->e= phead1->e;
			phead1= phead1->next;
		}else if(phead2!= NULL){
			tmp->c= phead2->c;
			tmp->e= phead2->e;
			phead2= phead2->next;
		}
		
		tmp->next= NULL;
		
		if(phead== NULL){
			phead= tmp;
			ppre=  tmp;
		}else{
			ppre->next= tmp;
			ppre= ppre->next;
		}
	}
	
	return phead;
}

int main()
{
	int n= read(), m= read();
	Node head1;
	head1.c= read();
	head1.e= read();
	head1.next= NULL;
	Node *tmp= &head1;
	Node *x;
	For(i, 2, n){
		x= new Node;
		x->c= read();
		x->e= read();
		x->next= NULL;
		(*tmp).next= x;
		tmp= x;
	}
	
	Node head2;
	head2.c= read();
	head2.e= read();
	head2.next= NULL;
	tmp= &head2;
	For(i, 2, m){
		x= new Node;
		x->c= read();
		x->e= read();
		x->next= NULL;
		(*tmp).next= x;
		tmp= x;
	}
	
	Node* phead= merge(&head1, &head2);
	Node* ttt= phead;
	ll sum= 0;
	while(phead!= NULL){
		if(phead->c== 0){
			phead= phead->next;
			continue;
		}
		sum+= 1;
		phead= phead->next;
	}
	phead= ttt;
	printf("%d\n", sum);
	while(phead!= NULL){
		if(phead->c== 0){
			phead= phead->next;
			continue;
		}
		printf("%d %d\n", phead->c, phead->e);
		phead= phead->next;
	}

    return 0;
}

/*

5 3
2 1
1 3
2 4
2 5
6 6
1 2
2 3
1 4


*/
