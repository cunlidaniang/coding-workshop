#include<iostream>
#include<cmath>

using namespace std;

typedef int myint;

typedef unsigned char vec3b[3];

typedef struct _rgb_struct{//name _rgb_struct can be omit
    unsigned char r;
    unsigned char g;
    unsigned char b;
} rgb_struct;


int ff(int i){
	if (i== 0){
		return 1;
	}
	return i* ff(i- 1);
}

int main(){
	double ans= 0;
	for(int i= 0;i<= 5;i++){
		ans+= (double)pow(5, i) * (double)exp(-5)/ (double)(ff(i));
	}
	
	cout<< ans<< endl;
	cout<< pow(5, 3)<< endl;
}


