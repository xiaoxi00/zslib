 /*
  * File	: utility.cpp
  * Project	: 
  * Author	: zerozakiGeek
  * Email	: zerozakiGeek@gmail.com
  * Date	: 2016-10-10
  */
#include "../include/utility.hpp"
#include <iostream>
void Test1(){
    std::cout << "void Test1()" << std::endl;
}
int Test(int x){
    std::cout << "int Test(int): " << x << std::endl;
    return 0;
}
int main(){
    auto c = util::Function::bind(Test1);
    auto c1 = util::Function::bind(Test,100);
    c();
    c1();
    return 0;
}
