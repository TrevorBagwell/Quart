#ifndef ARRAY_HH
#define ARRAY_HH

/* Includes */
#include "tape.h"
#include "reference.h"
#include <initialize_list>

namespace quart
{
    template<typename T> class array
    {
        
        //TODO: Figure out how to implement

        private:
        // TODO: private functions go here




        protected:
        // TODO: protected functions go here
            tape<T> data;
            tape<size_t> dimensions;




        public:
        
            static size_t undefined = (size_t) -1;
        
        
        // TODO: public functions go here
            array();
            template< typename ...Args>
            array(Args... args);
            array(std::initialize_list<int> argsList);
            array(array<T> & other_array);

            ~array();
            /* OPERATORS */
            array<T> & operator[](size_t index);
            array<T> & operator=(array<T> & other_array);

            /* FUNCTIONS */
            template< typename ...Args>
            bool reshape(Args... args);
            bool reshape(std::initialize_list<int> argsList);

            
            template< typename ...Args>
            T & directAt(size_t index);
            array<T> & at(Args... args);
            array<T> & at(std::initialize_list<int> argsList);
            
            size_t index(Args... args);
            size_t index(std::initialize_list<int> argsList);

            tape<size_t> & shape();
            constexpr size_t size();

            array<T> & copy(array<T> & other_array);
            void clear();

            



    
    };





}


#endif