#ifndef QDOT_HH
#define QDOT_HH

template <typename T>
class dot 
{
    dot();
    ~dot();

    inline T operator()(T t1, T t2);
    virtual T operate(T t1, T t2) = 0;
};


#endif