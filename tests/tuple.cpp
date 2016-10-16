 /*
  * File	: tuple.cpp
  * Project	: 
  * Author	: zerozakiGeek
  * Email	: zerozakiGeek@gmail.com
  * Date	: 2016-10-13
  */
#include "../include/tuple.hpp"
#include <iostream>
int main(){
    zslib::tuple<int,char,const char*> tp(10,'x',"hh");
    zslib::get<0>(tp) = 100;
    std::cout << zslib::get<0>(tp) << std::endl;
    std::cout << zslib::get<1>(tp) << std::endl;
    return 0;
}
