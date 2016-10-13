 /*
  * File	: utility.cpp
  * Project	: 
  * Author	: zerozakiGeek
  * Email	: zerozakiGeek@gmail.com
  * Date	: 2016-10-10
  */
#include "../include/utility.hpp"
#include <iostream>
int Test(int &&x){
    std::cout << "int Test(int&&): " << x << std::endl;
    return 0;
}
int Test(const int& x){
    std::cout << "int Test(const int&): " << x << std::endl;
    return 0;
}
void Test1(){
    Test(static_cast<const int&>(10));
}
int main(){
    auto c = zslib::Function::bind(Test1);
    c();
    return 0;
}
