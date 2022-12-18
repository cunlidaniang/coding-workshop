#include<iostream>
#include<assert.h>
using namespace std;

class OutofRangeException{
    public:
    int s1, s2, s3, s4;
};

float calculateAverage(int s1, int s2, int s3, int s4){
    OutofRangeException s;
    s.s1 = s1;
    s.s2 = s2;
    s.s3 = s3;
    s.s4 = s4;
    // if(s1 < 0 || s1 > 100){
    //     throw s;
    // }
    // if(s2 < 0 || s2 > 100){
    //     throw s;
    // }
    // if(s3 < 0 || s3 > 100){
    //     throw s;
    // }
    // if(s4 < 0 || s4 > 100){
    //     throw s;
    // }
    return (float)(s1 + s2 + s3 + s4)/4;
}

int main(){
    while(true){
        cout<< " Please enter four :" << endl;
        int s1, s2, s3, s4;
        cin>> s1 >> s2 >> s3 >> s4;
        assert(s1 >= 0 && s1 <= 100);
        assert(s2 >= 0 && s2 <= 100);
        assert(s3 >= 0 && s3 <= 100);
        assert(s4 >= 0 && s4 <= 100);
        // try{
            float ans = calculateAverage(s1, s2, s3, s4);
            cout<< "success " << ans << endl;
        // }catch(OutofRangeException s){
        //     if(s.s1 < 0 || s.s1 > 100){
        //         cout<< " error : number 1 is " << s.s1 << endl;
        //     }
        //     if(s.s2 < 0 || s.s2 > 100){
        //         cout<< " error : number 2 is " << s.s2 << endl;
        //     }
        //     if(s.s3 < 0 || s.s3 > 100){
        //         cout<< " error : number 3 is " << s.s3 << endl;
        //     }
        //     if(s.s4 < 0 || s.s4 > 100){
        //         cout<< " error : number 4 is " << s.s4 << endl;
        //     }
        // }
        cout<< "try again? (y/n)" << endl;
        char c;
        cin >> c;
        if(c != 'y'){
            break;
        }
    }
}