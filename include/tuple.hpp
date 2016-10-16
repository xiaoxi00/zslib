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
        struct get_tuple_type{
            typedef typename get_tuple_type<index + 1,max,Args...>::type type;
        };
    template <size_t max,typename T,typename ...Args>
        struct get_tuple_type<max,max,T,Args...>{
            typedef T type;
        };
    template <size_t index,size_t max,typename T,typename ...Args>
        struct  get_tuple_value{
            static typename get_tuple_type<0,max,Args...>::type& get_value(zslib::tuple<Args...>& Tp){
                return get_tuple_value<index + 1,max,Args...>::get_value(Tp.child_tuple);
            }
        };
    template <size_t max,typename T,typename ...Args>
        struct get_tuple_value<max,max,T,Args...>{
            static typename get_tuple_type<0,max,Args...>::type& get_value(zslib::tuple<Args...>& Tp){
                return Tp.value;
            }
        };
    template <size_t index,typename ...Args>
        typename get_tuple_type<0,index,Args...>::type get(zslib::tuple<Args...>& Tp){
            return get_tuple_value<0,index,int,Args...>::get_value(Tp);
        }

}
#endif
