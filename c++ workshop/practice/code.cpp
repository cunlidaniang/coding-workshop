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
#define abs(x) ((x) > 0 ? (x) : (-x) )
#define rll register long long
#define Mod 998244353
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

template<typename Ta>
void sum(Ta a, Ta b){
	cout<< typeid(Ta).name() << endl;
}

template<> void sum(double , double)
{
	cout<<"!!"<<endl;
}

void aa(int , int ){
	cout << "aaa"<< endl;
}
void (&bb)(int, int) = aa;

void cc(int , int){

}

struct point{
	int x;
	point operator + (const point & o){
		point ans;
		ans.x = this->x + o.x;
		return ans;
	}
};

void print(int size, char c = '*'){
	For(i, 1, size){
		For(j, 1, size){
			cout<< c;
		}
		cout<< endl;
	}
}

void vabs(int * p, int n){
	For(i, 0, n - 1){
		*(p + i) = abs(*(p + i) );
	}
}

void vabs(float * p, int n){
	For(i, 0, n - 1){
		*(p + i) = abs(*(p + i) );
	}
}

void vabs(double * p, int n){
	For(i, 0, n - 1){
		*(p + i) = abs(*(p + i) );
	}
}

template <typename T>
T minimum(T a , T b){
	return a> b? b: a;
}

int main()
{
	cout<< bb<< endl;
	cout<< aa<< endl;
	cout<< &aa<< endl;
	cout<< cc << endl;
	cout<< "----------------------"<< endl;
	print(5, '#');
	print(4);
	cout<< "----------------------"<< endl;
	int a[10] = {0, -1, -2};
	vabs(a , 3);
	For(i, 0, 2){
		cout<< a[i]<< endl;
	}

	float b[10] = {0, -1, -2};
	vabs(b , 3);
	For(i, 0, 2){
		cout<< b[i]<< endl;
	}

	double c[10] = {0, -1, -2};
	vabs(c , 3);
	For(i, 0, 2){
		cout<< c[i]<< endl;
	}

	cout<< "------------------------"<< endl;
	int i1 = 2, i2 = 1;
	cout<< minimum<int>(i1, i2)<< endl;

	float f1 = 2, f2 = 1.2;
	cout<< minimum<float>(f1, f2)<< endl;

	double d1 = 2, d2 = 1.3;
	cout<< minimum<double>(d1, d2)<< endl;
}

/*

*/
