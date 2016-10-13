 /*
  * File	: utility.hpp
  * Project	: 
  * Author	: zerozakiGeek
  * Email	: zerozakiGeek@gmail.com
  * Date	: 2016-10-04
  */
#ifndef __ZSLIB__UTILITY__HPP
#define __ZSLIB__UTILITY__HPP
#include <stddef.h>
#include <tuple>
namespace zslib{
    namespace type_traits{
        struct true_type{
            static constexpr bool value = true;
            bool operator()();
            operator bool();
        };
        bool true_type::operator()(){
            return true;
        }
        true_type::operator bool(){
            return true;
        }
        struct false_type{
            static constexpr bool value = false;
            bool operator()();
            operator bool();
        };
        bool false_type::operator()(){
            return false;
        }
        false_type::operator bool(){
            return false;
        }
        template <typename T,size_t size>
        struct array_info{
            typedef T type;
            static constexpr size_t value = size;
        };
        template <typename T,size_t u>
            struct __function__info{
                typedef T result_type;
                static constexpr size_t Args_count = u;
            };
        template <typename,typename>
            struct is_same : public false_type{ };
        template <typename T>
            struct is_same<T,T> : public true_type{ };
        template <typename>
            struct extent;
        template <typename T,size_t u>
            struct extent<T[u]> : public array_info<T,u>{ };
        template <typename,typename...>
            struct function_info;
        template <typename T,typename ...Args>
            struct function_info<T(Args...)> : public __function__info<T,sizeof...(Args)>{ };
        template <typename>
            struct remove_extent;
        template <typename T,size_t u>
            struct remove_extent<T[u]>{
                typedef T type;
            };
        template <typename T>
            struct remove_all_extents{
                typedef T type;
            };
        template <typename T,size_t u>
            struct remove_all_extents<T[u]>{
                typedef typename remove_all_extents<T>::type type;
            };
        template <typename T,typename ...Args>
            struct result_type;
        template <typename T,typename ...Args>
            struct result_type<T(Args...)>{
                typedef T type;
            };
    }
    namespace Function{
        //TupleType:存放参数包的tuple的类型
        //return_type:绑定的函数的返回值类型
        //T:绑定的函数的类型
        //index:当前参数的索引
        //max:参数的个数
        template <typename TupleType,typename return_type,typename T,size_t index,size_t max>
            struct __Call{
                template <typename ...Args>
                static return_type call(T &f,TupleType& Tp,Args ...__Args){
                    //递归往__Args中添加参数
                    //当index和max相等时，说明已经添加到了最后一个参数
                    return __Call<TupleType,return_type,T,index + 1,max>::call(f,Tp,std::forward<Args>(__Args)...,std::forward<decltype(std::get<index>(Tp))>(std::get<index>(Tp)));
                }
            };
        template <typename TupleType,typename return_type,typename T,size_t max>
            struct __Call<TupleType,return_type,T,max,max>{
                template <typename ...Args>
                static return_type call(T &f,TupleType& Tp,Args ...__Args){
                    //直接调用f所指的函数
                    return f(__Args...);
                }
            };
        template <typename T,typename ...Args>
        struct Bind_t{
            typedef T function_type;
            typedef std::tuple<Args...> ArgsTpType;
            typedef typename type_traits::result_type<T>::type return_type;
            ArgsTpType ArgsPack;
            function_type &fun;
            Bind_t(T &function,Args ...__Args):ArgsPack(std::tuple<Args...>(__Args...)),fun(function){ }
            return_type operator()(){
                    return __Call<ArgsTpType,return_type,T,0,sizeof...(Args)>::call(fun,ArgsPack);
            }
        };
        template <typename T,typename ...Args>
        Bind_t<T,Args...> bind(T &fun,Args... __Args){
        return Bind_t<T,Args...>(fun,std::forward<Args>(__Args)...);
        }
    }
}
#endif //__UTILITY__HPP
