#ifndef QFUNCTION_HH
#define QFUNCTION_HH




namespace quart
{
    
template <typename ReturnType, typename InputType>
struct function
{
    ReturnType returner;
        
    function();
    ~function();
        
    inline ReturnType & operator()(InputType & input);
    inline ReturnType & operator()(InputType && input);

    virtual ReturnType & operate(InputType & input) = 0;
    virtual ReturnType & operate(InputType && input) = 0;
};  

}
#endif