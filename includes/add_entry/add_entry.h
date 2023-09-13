#ifndef ADD_ENTRY_H
#define ADD_ENTRY_H
#include <iostream>

#include "../../includes/array_functions/array_functions.h"

template<class T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity){

  /*adds new_entry into the next available index of list
    if size == capacity reallocate array into double capacity
    then add into the newly allocated array*/

    T* src_array = list;
    T* next_index = src_array + size;
    
    if (size == capacity){
        capacity *= 2;
        T* reallocated_array = reallocate(list, size, capacity);      
        next_index = (reallocated_array + size);
        *next_index = new_entry;
        size++;
        return reallocated_array; 
    }
    else{
        *next_index = new_entry;
        size++;
        return src_array;
    }
}


template<class T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity){
//removes the entry of delete_me and then halves the capacity of the array
//if the size is 1/4th of the capacity


}


template <class T>
T *remove_last_entry(T *list, T &popped, int &size, int &capacity){

}

template <class T>
T *insert_entry(T *list, const T &insert_this, int insert_here, int &size, int &capacity){

}

template <class T>
T *erase_entry(T *list, int index, int &size, int &capacity){

}
#endif