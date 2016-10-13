 /*
  * File	: tuple.hpp
  * Project	: 
  * Author	: zerozakiGeek
  * Email	: zerozakiGeek@gmail.com
  * Date	: 2016-10-13
  */
#ifndef __ZSLIB__TUPLE__HPP
#define __ZSLIB__TUPLE__HPP
#include <utility>
using std::size_t;
namespace zslib{
    template <typename T,typename ...Args>
        struct tuple{
            typedef T value_type;
            tuple(T &val,Args... __Args):value(val),child_tuple(__Args...){ }
            tuple(T &&val,Args&&... __Args):value(std::move(val)),child_tuple(std::forward<Args>(__Args)...){ }
            tuple(const T& val,const Args&... __Args):value(std::forward<T>(val)),child_tuple(std::forward<Args>(__Args)...){ }
            tuple<Args...> child_tuple;
            T value;
        };
    template <typename T>
        struct tuple<T>{
            typedef T value_type;
            tuple(T &val):value(val){ }
            tuple(T &&val):value(std::move(val)){ }
            tuple(const T& val):value(std::forward<T>(val)){ }
            T value;
        };
    template <size_t index,size_t max,typename T,typename ...Args>
        struct tuple_type_at{
            typedef typename tuple_type_at<index +1,max,Args...>::value_type value_type;
        };
    template <size_t index,typename T,typename ...Args>
        struct tuple_type_at<index,0,T,Args...>{
            typedef T value_type;
        };
    template <size_t max,typename T,typename ...Args>
        struct tuple_type_at<max,max,T,Args...>{
            typedef T value_type;
        };
    template <size_t index,size_t max,typename T,typename ...Args>
        struct tuple_value_at{
            static typename tuple_type_at<index,max,T,Args...>::value_type tuple_value(zslib::tuple<Args...>& Tp){
                return tuple_value_at<index + 1,max,Args...>::tuple_value(Tp.child_tuple);
            }
        };
    template <size_t max,typename T,typename ...Args>
        struct tuple_value_at<max,max,T,Args...>{
            static typename tuple_type_at<max,max,Args...>::value_type tuple_value(zslib::tuple<Args...>& Tp){
                return Tp.value;
            }
        };
    //template <typename T,typename ...Args>
    template <const size_t index,typename ...Args>
        tuple_type_at<0,index,Args...> tuple_get(zslib::tuple<Args...>& Tp){
            //return index?Tp.value:
        }      

}
#endif
