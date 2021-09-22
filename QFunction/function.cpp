#include "function.h"





template <typename ReturnType,typename InputType>
quart::function<ReturnType,InputType>::function() {}

template <typename ReturnType,typename InputType>
quart::function<ReturnType,InputType>::~function() {}


template <typename ReturnType,typename InputType>
inline ReturnType & quart::function<ReturnType,InputType>::operator()(InputType & input) 
{ 
    return operate(input); 
}

template <typename ReturnType,typename InputType>
inline ReturnType & quart::function<ReturnType,InputType>::operator()(InputType && input) 
{ 
    return operate(input); 
}