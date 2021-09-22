#include "tape.h"




/* Constructors */

template<typename T>
quart::tape<T>::tape() { this->clear(); }
        
template<typename T>
quart::tape<T>::tape(size_t size) { this->resize(size); }
        
template<typename T>
quart::tape<T>::tape(quart::tape<T> & other_tape) { this->copy(other_tape); }

template<typename T>
quart::tape<T>::tape(std::initializer_list<T> list) { this->copy(other_tape); }


/* Destructors */

template<typename T>
quart::tape<T>::~tape() { this->clear(); }



/* OPERATORS */
inline template<typename T>
T & quart::tape<T>::operator[](size_t index) { return this->at(reference); }

inline template<typename T>
quart::tape<T> & quart::tape<T>::operator=(quart::tape<T> & other_tape) { return this->copy(other_tape); }

inline template<typename T>
quart::tape<T> & quart::tape<T>::operator=(std::initializer_list<T> list) { return this->copy(list); }


/* FUNCTIONS */


template<typename T>
T & quart::tape<T>::at(size_t reference) { return this->data[reference]; }


template<typename T>
constexpr size_t quart::tape<T>::T & size() { return this->size; }



template<typename T>
void resize(size_t new_size)
{
    // If it's already this size, the person is fucking stupid
    // or is automating something and couldn't handle the case in which
    // this call is useless. So only resize it if the size is different
    if(this->size != new_size)
    {
        // Clear this and then give it the new size
        this->clear();

        // If we want to set it to a non-clear item, it must have a new_size greater than 0
        if(new_size > 0)
        {
            // Just create the size and instantiate the array
            this->size = new_size;
            this->data = new T[this->size];
        }
    }
}




template<typename T>
void quart::tape<T>::clear()
{
    // Delete the data if it exists
    if(this->data != NULL) { delete this->data; }
    
    // Set the data to NULL and 
    this->data = NULL;
    this->size = 0;
}


template<typename T>
quart::tape<T> & quart::tape<T>::copy(std::initializer_list<T> list)
{
    //TODO: Implement
    
    // Delete the old data and set the current size
    this->resize(list.size());
    
    // Put each value in the list in the data
    size_t index = 0; // Holds the index for the for each
    for(T item : list) 
    {
        // Copy the current item to the array
        this->data[index] = item;
        // Make sure to iterate as it's a for each assignment
        index++;
    }

    // Return this
    return *this;
}

template<typename T>
quart::tape<T> & quart::tape<T>::copy(quart::tape<T> & other_tape)
{
    //TODO: Implement
        // Delete the existing information if it exists
        /*
        if(this->size > 0)
        {
            delete this->data;
        }
        this->size = other_tape.size;
        this->data = new T[this->size];
        */
        //Simplified to this =>
    
    // Set the size of the list
    this->resize(other_tape.size());
    
    // Copy the data items if there is any
    for(int a = 0; a < other_tape.size(); a++) { this->data[a] = other_tape[a]; }
    
    return *this;
}
        
template <typename T>
quart::tape<T> & clone(quart::tape<T> & other_tape)
{
    this->data = other_tape.data;
    this->size = other_tape.size;

    return *this;
}

template<typename T>
static quart::tape<T> & quart::tape<T>::duplicate(quart::tape<T> & other_tape) { return new quart::tape<T>(other_tape); }