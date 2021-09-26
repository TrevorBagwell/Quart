#ifndef QSHAPE_HH
#define QSHAPE_HH

#include <vector>




namespace quart 
{
// This shape will hold the first type of n-square shape
// Don't know how to handle this but I will

template <typename T=int>
class shape
{
    private:
        
        std::vector<T> axes;
        size_t reference_size;
    public:
        shape();
        ~shape();

        /* Modifier Functions */
        void copy(shape<T> & old_shape);
        void addAxis(T & value);
        void addAxis(T && value);
        void addAxes(std::vector<T> value_vec);
        void clear();

        template <typename ...Args>
        size_t index(Args ... args);

        
};


}
#endif