 /*
  * File	: tuple.cpp
  * Project	: 
  * Author	: zerozakiGeek
  * Email	: zerozakiGeek@gmail.com
  * Date	: 2016-10-13
  */
#include "tuple.hpp"
#include <iostream>
int main(){
    zslib::tuple<int,char,const char*> tp(10,'x',"hh");
    zslib::tuple_type_at<1,0,int,char,const char*>::value_type k = 500;
    std::cout << zslib::tuple_value_at<0,0,int>::tuple_value(tp) << std::endl;
    std::cout << tp.child_tuple.child_tuple.value << std::endl;
    return 0;
}
