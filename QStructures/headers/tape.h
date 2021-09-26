#ifndef QTAPE_HH
#define QTAPE_HH

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
            bool isClone;

        public:
            /* CONSTRUCTORS */
            tape();
            tape(size_t size);
            tape(std::initializer_list<T> list);
            tape(tape<T> & other_tape);
            
            /* DESTRUCTORS */
            ~tape();

            /* OPERATORS */

            inline T & operator=(tape<T> & other_tape);
            
            /* FUNCTIONS */
            constexpr size_t size();
            T & at(size_t reference);
            tape<T> & copy(std::initializer_list<T> list);
            tape<T> & copy(tape<T> & other_tape);
            void resize(size_t new_size);
            void clear();
            void destroy();


            tape<T> & clone(tape<T> & other_tape);
            bool isClone();
            /* FRIEND */
            friend tape<T> & duplicate(tape<T> & other_tape);

    };
    


}







#endif