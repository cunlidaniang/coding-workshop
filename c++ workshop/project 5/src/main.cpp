#include"head.hpp"
#include"Matrix.hpp"

int main(){
    Matrix<int> m(2, 3);
    Matrix<int> n(2, 3);
    
    for(int i = 1;i<= 2;i++){
        for(int j = 1;j<= 3;j++){
            m.set(i, j , i);
            n.set(i, j, j);
        }
    }

    m.print();
    n.print();
    m = m + n;
    m.print();

    // shared_ptr<int[]> p1(new int[2] );
    // shared_ptr<int[]> p2;
    // p2 = p1;
    // cout<< p1.use_count() << endl;
    // cout<< p2.use_count() << endl;
    // p2 = make_shared<int[]>();
    // cout<< p1.use_count() << endl;
    // cout<< p2.use_count() << endl;
    // p2 = p1;
    // cout<< p1.use_count() << endl;
    // cout<< p2.use_count() << endl;
    // p1 = nullptr;
    // cout<< p1.use_count() << endl;
    // cout<< p2.use_count() << endl;
}