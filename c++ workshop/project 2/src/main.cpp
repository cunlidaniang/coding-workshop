#include"head.hpp"
#include"BigNum.hpp"
#include"stringFunctions.hpp"
#include"BigNumFunctions.hpp"

int main(int argc, char* argv[]) 
{	
	string s1, s2;
	if(argc< 3){
		cout<< "please input two string!"<< endl;
		return 0;
	}
	s1= argv[1];
	s2= argv[2];
	if(!isvalid(s1)|| !isvalid(s2) ){  //determine if it is valid num
		cout<< "The input cannot be interpret as numbers!"<< endl;
		return 0;
	}
	BigNum bn1, bn2, bn3;
	bn1.read(s1);
	bn2.read(s2);
	bn3 = bn1 * bn2;
	bn1.print();
	cout<< " * ";
	bn2.print();
	cout<< " = ";
	bn3.print();
	cout<< endl;

	bn3= bn1+ bn2;
	cout<< endl;
	bn1.print();
	cout<< " + ";
	bn2.print();
	cout<< " = ";
	bn3.print();
	cout<< endl;

	bn3= bn1- bn2;
	cout<< endl;
	bn1.print();
	cout<< " - ";
	bn2.print();
	cout<< " = ";
	bn3.print();
	cout<< endl;

	bn3= bn1/ bn2;
	cout<< endl;
	bn1.print();
	cout<< " / ";
	bn2.print();
	cout<< " = ";
	bn3.print();
	cout<< endl;
	bn3.approximate(-4);
	bn3.print();
	cout<< endl;

	cout<< "sqrt (";
	bn1.print();
	cout<< ") = ";
	bn1 = sqrt(bn1);
	bn1.print();
	cout<< endl;


    return 0;
}

/*

./mul 2 3
./mul 232 -231
./mul 0 -123

./mul 3.1416 2
./mul 3.1415 2.0e-2
./mul 2e123211 3.123e-123211
./mul 0002e0000000 00.03e123

./mul a 2
./mul 12e 2
./mul -11-2e-1 2
./mul -1.e1 2
./mul 1.-1e1 2
./mul 1.1.1e1 2
./mul 1e1.1 2

./mul 1234567890 1234567890
./mul 12300000000000 234000000000000000

./mul 1.0e200 1.0e200
./mul 2e123211 3.123e-123211
./mul 0002e0000000 00.03e123

*/
