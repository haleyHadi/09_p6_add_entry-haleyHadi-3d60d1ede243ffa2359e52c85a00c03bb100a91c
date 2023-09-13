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

    T* index = search_entry(list, size, delete_me);
    shift_left(list, size, index);

    if (size < (capacity / 4)){
        capacity /= 2;
    }
    return list;
}


template <class T>
T *remove_last_entry(T *list, T &popped, int &size, int &capacity){
    //needs to shift left only the last index of the array
    
    T* end_ptr = (list + (size - 1));
    popped = *end_ptr;
    shift_left(list, size, end_ptr);

    if (size < (capacity / 4)){
        capacity /= 2;
    }
    
    return list;

}

template <class T>
T *insert_entry(T *list, const T &insert_this, int insert_here, int &size, int &capacity){
    //need to shift right at index insert_here
    //then input insert_this into the index of insert_here
    //might need to double capacity if size is equal before we shift
    //maybe call add_entry

    if (size == capacity){
        capacity *= 2;
    }

    shift_right(list, size, insert_here);
    T* insert_index = (list + insert_here);
    *insert_index = insert_this;
    return list;
}

template <class T>
T *erase_entry(T *list, int index, int &size, int &capacity){
    shift_left(list, size, index);

    if (size < (capacity / 4)){
        capacity /= 2;
    }
    return list;
}
#endif