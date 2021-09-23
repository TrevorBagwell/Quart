#include "array.h"



template<typename T, typename ...Args>
bool quart::array<T>::reshape(Args... args)
{
    std::initializer_list<int> argsList({args...});
    // Make sure they are all valid
    return this->reshape(argsList);
}

template<typename T>
bool quart::array<T>::reshape(std::initialize_list<int> argsList)
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
    if(this->dimensions.size() > 0) 
    { 
        // Create the data array
        size_t total_size = 1;
        
        // Collect all the dimensions
        for(int index = 0; index < this->dimensions.size(); index++)
        {
            total_size *= this->dimensions[index];
        }

        this->data.resize(total_size);

        // Return the proper dimensionalization
        return true; 
    }

    // Default return
    return false;
}


template<typename T, typename ...Args>
quart::reference<T> quart::array<T>::at(Args... args)
{
    std::initializer_list<int> argsList({...args});
    return this->at(argsList);
}

template <typename T>
quart::reference<T> quart::array<T>::at(std::initialize_list<int> argsList)
{
    return this->data.at(this->index);
}


template <typename T, typename ...Args>
size_t quart::array<T>::index(Args... args)
{
    std::initializer_list<int> argsList({...args});
    return this->index(argsList);
}

template <typename T>
size_t quart::array<T>::index(std::initializer_list<int> argsList)
{
    
}





template <typename T>
constexpr quart::tape<T> quart::array<T>::shape() { return this->dimensions; }

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