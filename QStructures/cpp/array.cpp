#include "array.h"



template<typename T, typename ...Args>
bool quart::array<T>::dimensionalize(Args... args)
{
    std::initializer_list<int> argsList({args...});
    // Make sure they are all valid
    return this->dimensionalize(argsList);
}


template<typename T>
bool quart::array<T>::dimensionalize(std::initialize_list<int> argsList)
{

    // Validate the args in args list
    for(int arg : argsList) { if(arg < 1) { return false; } }

    // If it gets past this, then the args are valid and we want to change the data

    // Clear this if there is already data
    this->clear();
    

    // Allocate the space for the dimensions
    dimensions->resize(argsList->size());
                
    size_t index = 0; // Used to assign the dimensions index as we iterate through the args
    // Set the value of each dimension
    for(int arg : argsList)
    {
        dimensions[index] = (size_t) arg;
        index++;
    }


    // If there exists a single dimension, return true
    if(dimensions.size() > 0) 
    { 
        // Create the data array
        this->data.resize(this->size());

        // Return the proper dimensionalization
        return true; 
    }

    // Default return
    return false;
}





template <typename T>
constexpr quart::tape<T> quart::array<T>::dimensions() { return this->dimensions; }

template <typename T>
constexpr size_t quart::array<T>::size() { return this->data.size(); }


template<typename T>
quart::array<T> & quart::array<T>::copy(quart::array<T> & other_array)
{

    // If this is not the array, copy the data
    if(this != &other_data)
    {
        // Clear this
        this->clear();

        // Copy each variable
        this->data.copy(other_array.data);
        this->dimensions.copy(other_array.dimensions);
    }

    return *this;
}


template <typename T>
void quart::array<T>::clear()
{
    // Clear data and dimensions
    this->data.clear();
    this->dimensions.clear();
}