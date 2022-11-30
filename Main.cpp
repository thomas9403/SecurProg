#include "Money.hpp"






int main(void){
    Money m1(1, 50);
    m1.operator+(m1);
    cout << m1 << endl;
}