#ifndef TAPE_HH
#define TAPE_HH

/* Defines */

/* Includes */
// TODO: Justify instantiation of the integer class
//#include "integer.h"
#include <initializer_list>

namespace quart
{
    template<typename T>
    class tape
    {
        
        protected:
            /* VARIABLES */
            T * data;
            size_t size;

        public:
            /* CONSTRUCTORS */
            tape();
            tape(size_t size);
            tape(std::initializer_list<T> list);
            tape(tape<T> & other_tape);
            
            /* DESTRUCTORS */
            ~tape();

            /* OPERATORS */
            inline T & operator[](size_t reference);
            inline tape<T> & operator=(tape<T> & other_tape);
            inline tape<T> & operator=(std::initializer_list<T> list);
            
            /* FUNCTIONS */
            constexpr size_t size();
            T & at(size_t reference);
            tape<T> & copy(std::initializer_list<T> list);
            tape<T> & copy(tape<T> & other_tape);
            void resize(size_t new_size);
            void clear();


            tape<T> & clone(tape<T> & other_tape);

            /* FRIEND */
            friend tape<T> & duplicate(tape<T> & other_tape);

    };
    


}







#endif