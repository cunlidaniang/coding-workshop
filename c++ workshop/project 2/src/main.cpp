#include"head.hpp"
#include"BigNum.hpp"
#include"stringFunctions.hpp"
#include"BigNumFunctions.hpp"
#include"helps.hpp"
#include"calculateExpertSystem.hpp"

int main(int argc, char* argv[]) 
{	

	calculateExpertSystem ces;
	string s;
	printHelpList();
	while(getline(cin , s) ){
		if(s == "exit"){
			return 0;
		}
		if(s == "help"){
			printHelpList();
			continue;
		}
		ces.handleStatement(s);
	}

    return 0;
}

/*  some sample input

2 + 3
5 + 2 * 3
3 * ( (1 + 1) / 3) + 1 - 2
help
exit

*/
