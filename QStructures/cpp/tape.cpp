#include "tape.h"




/* CONSTRUCTORS */

template<typename T>
quart::tape<T>::tape() { this->clear(); }
        
template<typename T>
quart::tape<T>::tape(size_t size) { this->resize(size); }
        
template<typename T>
quart::tape<T>::tape(quart::tape<T> & other_tape) { this->copy(other_tape); }

template<typename T>
quart::tape<T>::tape(std::initializer_list<T> list) { this->copy(other_tape); }


/* DESTRUCTORS */

template<typename T>
quart::tape<T>::~tape() { this->clear(); }


/* OPERATORS */

template <typename T>
inline T & quart::tape<T>::operator=(quart::tape<T> & other_data)
{
    this->copy(other_tape);
}



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
        // Destroy this and then give it the new size
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
    // Deletes the data if it's not a clone and there is data to be deleted
    if((this->isClone == false) && (this->data != NULL)) { delete this->data; }
    
    // Set it to it's primal state the data if it exists
    this->data == NULL;
    this->size = 0;
    this->isClone = false;
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
    this->clear();
    this->data = other_tape.data;
    this->size = other_tape.size;
    this->isClone = true;
    return *this;
}

template<typename T>
bool quart::tape<T>::isClone()
{
    return this->isClone;
}


template<typename T>
friend quart::tape<T> & quart::tape<T>::duplicate(quart::tape<T> & other_tape) { return new quart::tape<T>(other_tape); }