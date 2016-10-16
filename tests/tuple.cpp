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
    //std::cout << std::is_same<zslib::get_tuple_type<0,1,int,char,const char*>::type,char>::value << std::endl;
    std::cout << zslib::get<1>(tp) << std::endl;
        
    return 0;
}
