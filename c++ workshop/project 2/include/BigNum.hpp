#ifndef _BIGNUM_HPP
#define _BIGNUM_HPP

#include "head.hpp"
#include "stringFunctions.hpp"

struct BigNum{    //a struct to store big num
	int size;     //size of a[N]
	bool pos;     //if the value is positive
	int a[N];     //store value bit by bit like 0 1 2 3 equal to 3210 ; index from 0
	ll e;         //store the number of e

	BigNum operator / (BigNum o){//define / operation
		BigNum zero;              //justify the o not zero
		zero.read("0");
		if(o == zero){
			printf("Warning! divide zero!!\n");
			return zero;
		}

		BigNum l , r;

		// pos
		l.pos = r.pos = true;
		// e
		l.e = (this->e + this-> size - 1) - (o.e + o.size - 1) - 1;
		r.e = (this->e + this-> size - 1) - (o.e + o.size - 1) + 1;
		// size
		l.size = 1;
		r.size = 1;
		// a[n]
		l.a[0] = 1;
		r.a[0] = 9;

		//divsion search
		BigNum p;             //precision
		p.pos = true;
		p.e = DivisionPrecision;
		p.size = 1;
		p.a[0] = 1;

		BigNum doubleDivid;
		doubleDivid.read("5e-1");
		while((r - l) > p){
			BigNum mid = (l + r) * doubleDivid;
			if((mid * o).absCompare(this) ){
				r = mid;
			}else{
				l = mid;
			}
		}

		l.pos = this->pos == o.pos;

		return l;
	}

	BigNum operator - (BigNum o){//define - operation
		o.pos = !o.pos;
		return (*this + o);
	}

	bool operator >= (BigNum o){//define >= operation
		return !(o > *this);
	}

	bool operator == (BigNum o){ //define == operation
		return !(o > *this) && !(*this > o);
	}

	bool operator > (BigNum o){ //define > operation
		if(pos^ o.pos){   //if two BigNum are of different sign
			return pos;
		}
		if(pos){          //if two BigNum are of same sign
			return this->absCompare(&o);
		}else{
			return o.absCompare(this);
		}
	}

	BigNum operator + (BigNum o){ //define + operation
		BigNum ans;
		BigNum bn1, bn2; //abs(pbn1)>= abs(pbn2)

		if(this->absCompare(&o) ){       //select pbn1 and pbn2
			bn1 = *this;
			bn2 = o;
		}else{
			bn1 = o;
			bn2 = *this;
		}

		bn1.addSufZerofromE(bn1.e - bn2.e);
		bn2.addSufZerofromE(bn2.e - bn1.e);

		// ans.pos
		if(bn1.pos == bn2.pos){
			ans.pos = bn1.pos;
		}else{
			ans.pos = bn1.pos;
		}
		//ans.size
		ans.size = bn1.size + 1;
		//ans.e
		ans.e = bn1.e;

		//ans.a[n]
		For(i , 0 , bn1.size - 1){
			ans.a[i] = bn1.a[i];
		}
		ans.a[ans.size - 1] = 0;

		For(i , 0 , bn2.size - 1){
			if(bn1.pos == bn2.pos){
				ans.a[i] = ans.a[i] + bn2.a[i];
			}else{
				ans.a[i] = ans.a[i] - bn2.a[i];
			}
		}

		For(i , 0 , ans.size - 2){
			ans.a[i + 1] += (ans.a[i] + 10) / 10 - 1;
			ans.a[i] = (ans.a[i] + 10) % 10;
		}

		ans.optimizeZeros();

		return ans;
	}

	BigNum operator * (const BigNum o){  //define * operation
		BigNum ans;
		ans.size= size+ o.size;
		ans.pos= !(pos^ o.pos);
		ans.e= e+ o.e;
		For(i, 0, ans.size- 1){
			ans.a[i]= 0;
		}
		For(i, 0, size- 1){
			For(j, 0, o.size- 1){
				ans.a[i+ j]+= a[i]* o.a[j];
			}
		}
		For(i, 1, ans.size- 1){
			ans.a[i]+= ans.a[i- 1]/ 10;
			ans.a[i- 1]%= 10;
		}
		ans.optimizeZeros();
		return ans;
	}

	void sqrt(){//define sqrt operation
		if(this-> pos == false){
			printf("Warning! sqrt(negative number)!!\n");
			BigNum zero;
			zero.read("0");
			*this = zero;
		}

		BigNum l , r;

		// pos
		l.pos = r.pos = true;
		// e
		l.e = (this->e + this-> size - 1) / 2 - 1;
		r.e = (this->e + this-> size - 1) / 2 + 1;
		// size
		l.size = 1;
		r.size = 1;
		// a[n]
		l.a[0] = 1;
		r.a[0] = 9;

		//divsion search
		BigNum p;             //precision
		p.pos = true;
		p.e = SqrtPrecision;
		p.size = 1;
		p.a[0] = 1;

		BigNum doubleDivid;
		doubleDivid.read("5e-1");
		while((r - l) > p){
			BigNum mid = (l + r) * doubleDivid;
			if((mid * mid).absCompare(this) ){
				r = mid;
			}else{
				l = mid;
			}
		}

		*this = l;
	}

	void carryBits(){  // carry the bits
		this->size += 1;
		this->a[this->size - 1] = 0;
		For(i , 0 , this->size - 2){
			this->a[i + 1] += (this->a[i] + 10) / 10 - 1;
			this->a[i] = (this->a[i] + 10) % 10;
		}
		this->optimizeZeros();
		return;
	}

	void approximate(ll n){ //approximate this BigNum into E(n)
		if(this->e >= n){
			return;
		}
		
		if(n - this->e <= this->size - 1){
			this->a[n - this->e] += this->a[n - this->e - 1] >= 5 ? 1 : 0;
		}

		For(i, 0, n - this->e - 1){
			if(i >= this->size){
				break;
			}
			this->a[i] = 0;
		}

		this->carryBits();
		this->optimizeZeros();
		return;
	}

	bool absCompare(BigNum * po){ //return abs(this) > abs(o)
		this->optimizeZeros(); //delete pre and suf zeros
		po->optimizeZeros();

		if(this->e+ this->size != po->e+ po->size){
			return (this->e+ this->size) > (po->e + po->size);
		}

		ll minSize = min(this->size , po->size);

		For(i, 1, minSize){
			int x = this->a[this->size - i];
			int y = po->a[po->size - i];
			if(x != y){
				return x > y;
			}
		}

		return this->size > po->size;
	}

	void addSufZerofromE(ll n){ //pick n zeros from e, append n zeros to a[];
		if(n<= 0){   //valid operation IIF n > 0
			return ;
		}

		e -= n;
		size += n;

		Ford(i, size- 1, n){  //left move a[]
			a[i]= a[i- n];
		}

		Ford(i, n- 1, 0){     //add n zeros
			a[i]= 0;
		}

		return;
	}
	
	void optimizeZeros(){ //adjust size and a[n] to delete the pre and suf zeros
		while(a[size- 1]== 0){
			size--;
			if(size== 0){
				break;
			}
		}
		int num= 0;
		while(a[num]== 0&& num< size){
			num++;
		}
		For(i, num, size- 1){
			a[i- num]= a[i];
		}
		e+= num;
		size-= num;
		
		if(size== 0){   //avoid there is null in a[n]
			pos= 1;
			a[size++]= 0;
			e= 0;
		}
	}
	
	void read(string s){  //intialize BigNum with string s (input must be valid)
		//find the length of s
		int len= s.length();
		//find the 'e''s position
		int ePos= -1;
		int n= s.length();
		For(i, 0, n- 1){
			if(s[i]== 'e'){
				ePos= i;
			}
		}
		//find if it is positive or not
		pos= s[0]!= '-';
		//determine e from give string's suffix if having
		if(ePos== -1){
			e= 0;
		}else {
			e= readString(s.substr(ePos+ 1, len- ePos- 1) );
		}
		//dertermine size a[n], adjust e form string's prefix
		len= (ePos== -1)? len: ePos; //omit the exxx part
		size= 0;
		int dotPos= -1;
		For(i, 0, len- 1){
			if(s[i]== '-'){
				continue;
			}
			if(s[i]== '.'){
				dotPos= i;
				continue;
			}
			a[size++]= (s[i]- '0');
		}
		if(dotPos!= -1){//update e
			e-= len- 1- dotPos;
		}
		For(i, 1, size/ 2){ //reverse a[n]
			swap(a[i- 1], a[size- i]);
		}
		
		optimizeZeros();//delete pre and suf zero
	}
	
	void print(){ //print the value
		if(!pos){
			cout<< '-';
		}
		
		if(e>= 0&& e<= 5){           //like 123000
			Ford(i, size- 1, 0){
				cout<< a[i];
			}
			For(i, 1, e){
				cout<< 0;
			}
		}else{
			if(-e>= size&& -e<= size+ 5){ //like 0.0123
				cout<< "0.";
				For(i, 1, -e- size){
					cout<< 0;
				}
				Ford(i, size- 1, 0){
					cout<< a[i];
				}
			}else if(-e< size&& -e> 0){ //like 1.23
				Ford(i, size- 1, -e){
					cout<< a[i];
				}
				cout<< '.';
				Ford(i, -e- 1, 0){
					cout<< a[i];
				}
			}else{                     //like 123e123
				Ford(i, size- 1, 0){
					cout<< a[i];
				}
				cout<< 'e'<< e;
			}
		}
	}
};

#endif