//calculateExpertSystem can consult
#ifndef _CALCULATEEXPERTSYSTEM_HPP
#define _CALCULATEEXPERTSYSTEM_HPP

#include"head.hpp"
#include<map>
#include"BigNum.hpp"
#include"stringFunctions.hpp"
#include<vector>
#include<stack>

struct Node{        //a container to store the elements of suffix expression
	int type;
	BigNum x;
	char op;

	Node(){}
	Node(BigNum x){
        type = 1;
        this->x = x;
    }
	Node(char c){
        type = 0;
        this->op = c;
    }
};

struct calculateExpertSystem{
    map< string , BigNum > vMap;  //variableMap
    map< string , int >    fMap;  //functionMap ; int represents the parameters number of funciton
    vector<Node > v;              //vector to store suffix expression

    calculateExpertSystem(){   //initial fMap
        addFunction("sqrt" , 1);
        addFunction("pow" , 2);
        addFunction("abs" , 1);
    }
    
    bool processToSuffix(string s){ //nifix expression into postfix expression
        stack<char > op;             //vector to store operation like '+' '-' '*' '/'
        s = removePreSufSpace(s);
        int len = s.length();
        if(len == 0){
            printf("the is no expression inputed into  processToSuffix(string s)\n");
            return false;
        }
        For(i, 0, len){
            s = removePreSufSpace(s);
            if(s.length() == 0){
                return true;
            }
            pair<bool , string> p;
            BigNum x;
            p = takeOffBigNumFromString(s , &x);
            if(p.first == true){
                s = p.second;
                v.push_back(Node(x));
                continue;
            }
            p = takeOffFunctionFromString(s , &x);
            if(p.first == true){
                s = p.second;
                v.push_back(Node(x));
                continue;
            }
            p = takeOffVariableFromString(s , &x);
            if(p.first == true){
                s = p.second;
                v.push_back(Node(x));
                continue;
            }

            if(s.at(0) == '(') op.push(s.at(0));
            else if(s.at(0) == ')') {
                while(op.top() != '(') {
                    v.push_back(Node(char(op.top())));
                    op.pop();
                }
                op.pop();
            }
            else {
                while(!op.empty() && priority(op.top()) >= priority(s.at(0))) {
                    v.push_back(Node(char(op.top())));
                    op.pop();
                }
                op.push(s.at(0));
		    }
            s = s.substr(1, s.length() -  1);
	    }

        if(s.length() > 0){
            v.clear();
            return false;
        }

        while(!op.empty()) {
            v.push_back(Node(char(op.top())));
            op.pop();
        }
        
        return true;
    }

    bool handleVariableDeclaration(string s){ ///handle the  input statement which declare a variable
        int len = s.length();
        int pos = s.find("=");
        if(pos > len - 1 || pos < 0){  //if '=' is not found
            return false;
        }
        string s1 , s2;
        s1 = s.substr(0, pos);
        s2 = s.substr(pos + 1, len - pos);
        s1 = removePreSufSpace(s1);
        s2 = removePreSufSpace(s2);

        if(!isValidVariable(s1) ){  //if wrong format
            return false;
        }

        pair<bool , BigNum> p = ValueOfExpression(s2);
        if(p.first == false){
            return false;
        }

        addVariable(s1 , p.second);
        return true;
    }

    pair<bool , BigNum> ValueOfExpression(string s){ //return True and the value of expression s; if expression invalid return False;
        v.clear();
        if(processToSuffix('(' + s + ')') == false ){
            printf("wrong expression format to turn into suffix!\n");
            return (pair<bool , BigNum>) make_pair(false, BigNum() );
        };
        pair<bool , BigNum> p = calc();
        if(p.first == false){
            printf("wrong expression format to calculate the suffix expression!\n");
            return (pair<bool , BigNum>) make_pair(false, BigNum() );
        }
        return (pair<bool , BigNum>) make_pair(true, p.second );
    }

    void handleStatement(string s){ //handle the  input statement like calculate or declare a variable
        if(handleVariableDeclaration(s) == true ){
            return;
        }
        pair<bool , BigNum> p = ValueOfExpression(s);
        if(p.first == true){
            // p.second.approximate(ApproximationPrecision);
            p.second.print();
            cout<< endl;
            return;
        }
    }

    pair<bool , string> takeOffFunctionFromString(string s , BigNum * bn){ //take of the first Function from string ; return true and change the string IFF success; bn is the value of the takenoff Function
        s = removePreSufSpace(s);
        int len = s.length();
        int pos = 0;
        For(i, 0, len - 1){
                char ch = s.at(i);
            if(ch == '('){
                pos = i;
                break;
            }
        }

        string FunctionName = s.substr(0, pos - 0);
        FunctionName = removePreSufSpace(FunctionName);

        pair<bool , string> ans;
        if(!existFunction(FunctionName) ){    //if FunctionName not valid
            ans.first = false;
            ans.second = s;
            return ans;
        }

        int pos2 = pos;
        int cnt = 0;
        For(i, pos, len - 1){
            char ch = s.at(i);
            if(ch == '('){
                cnt++;
            }
            if(ch == ')'){
                cnt--;
                if(cnt == 0){
                    pos2 = i;
                    break;
                }
            }
        }
        if(pos2 == pos){
            ans.first = false;
            ans.second = s;
            return ans;
        }
        string parameterString = s.substr(pos + 1, pos2 - pos - 1);
        int parameterNumber = parameterNumberOfFunction(FunctionName);
        BigNum * parameters = new BigNum[4];
        For(i, 1, parameterNumber){
            parameterString = removePreSufSpace(parameterString);
            if(s.length() == 0){
                return (pair<bool , string>)make_pair(false, s);
            }

            if(i != 1&& parameterString.at(0) == ',' ){
                parameterString = parameterString.substr(1 , parameterString.length() - 1);
            }
            parameterString = removePreSufSpace(parameterString);
            BigNum x;
            pair<bool , string> p = takeOffBigNumFromString(parameterString, &x);
            if(p.first == false){
                p = takeOffVariableFromString(parameterString, &x);
                if(p.first == false){
                    p = takeOffFunctionFromString(parameterString, &x);
                    if(p.first == false){
                        return (pair<bool , string>)make_pair(false, s);
                    }
                }
            }
            parameterString = p.second;
            parameters[i] = x;
        }

        if(parameterString.length() > 0){
            return (pair<bool , string>)make_pair(false, s);
        }
        if(FunctionName == "sqrt"){
            *bn = sqrt(parameters[1]);
            bn->approximate(ApproximationPrecision);
        }else if(FunctionName == "pow"){
            *bn = pow(parameters[1], parameters[2].toLongLong() );
        }else if(FunctionName == "abs"){
            *bn = abs(parameters[1] );
        }else{
            *bn = BigNum();
            printf("unnamed function! in takeOffFunctionFromString(string s , BigNum * bn)\n");
        }
        delete parameters;
        return (pair<bool , string>)make_pair(true, s.substr(pos2 + 1, len - pos2) );
    }

    pair<bool , string> takeOffVariableFromString(string s , BigNum * bn){ //take of the first Variable from string ; return true and change the string IFF success; bn is the value of the takenoff Variable
        s = removePreSufSpace(s);
        int len = s.length();
        int pos = len;
        For(i, 0, len - 1){
                char ch = s.at(i);
            if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == ','){
                pos = i;
                break;
            }
        }
        string variableName = s.substr(0, pos - 0);
        variableName = removePreSufSpace(variableName);

        pair<bool , string> ans;

        if(!existVariable(variableName) ){    //if variableName not valid
            ans.first = false;
            ans.second = s;
            return ans;
        }

        ans.first = true;
        ans.second = s.substr(pos, len- pos);
        *bn = VariableValue(variableName);
        return ans;
    }

    int priority(char c) {  //return the priority
        if(c == '*' || c == '/') return 2;
        if(c == '+' || c == '-') return 1;
        if(c == '(' || c == ')') return 0;
        throw "WA! Unexpected operator";
    }

    pair<bool , BigNum> calc() {       //calculate the suffix expression ; if success return ture
        stack<BigNum> s;             //vector to store BigNum in suffix expression order
        int sz = v.size();
        For(i, 0, sz-1) {
            if(v[i].type) s.push(v[i].x);
            else {
                BigNum a, b; char _;
                if(s.empty() ){
                    return (pair<bool , BigNum>) make_pair(false , BigNum() );
                }
                b = s.top(); s.pop();
                if(s.empty() ){
                    return (pair<bool , BigNum>) make_pair(false , BigNum() );
                }
                a = s.top(); s.pop();
                _ = v[i].op;
                if(_ == '+') s.push( a+b );
                else if(_ == '-') s.push( a-b );
                else if(_ == '*') s.push( a*b );
                else if(_ == '/') s.push( a/b );
            }
        }
        if(s.size()!= 1){
            return (pair<bool , BigNum>) make_pair(false , BigNum() );
        }
        return (pair<bool , BigNum>) make_pair(true , s.top() );
    }

    void addVariable(string variableName , string value ){  //add variable into variableMap
        vMap[variableName] = BigNum(value);
    }

    void addVariable(string variableName , BigNum bn ){  //add variable into variableMap
        vMap[variableName] = bn;
    }

    bool existVariable(string variableName){ //check if variable exists
        return (bool) vMap.count(variableName);
    }

    BigNum VariableValue(string variableName){//return the value of variable
        map<string, BigNum>::iterator it_find;
        it_find = vMap.find(variableName);
        return it_find->second;
    }

    void addFunction(string functionName , int parameterNum ){ //add function into functionMap
        fMap[functionName] = parameterNum;
    }

    bool existFunction(string functionName){ //check if function exists
        return (bool) fMap.count(functionName);
    }

    int parameterNumberOfFunction(string functionName){ //return the parameter number of a funciton
        map<string, int>::iterator it_find;
        it_find = fMap.find(functionName);
        return it_find->second;
    }
};

#endif