#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H
#include <iostream>

using namespace std;

const int MINIMUM_CAPACITY = 3;

template<class T>
T* allocate(int capacity= MINIMUM_CAPACITY){
    T* ptr = new T[capacity];                 //allocates a space in memory for an array
    return ptr;                                 //need to remember to delete[] this space in heap
}                                                  

template<class T>
T* reallocate(T* a, int size, int capacity){
    T* new_arr_ptr = new T[capacity]; 
                                                //allocates a temporary arr to reallocate the data from src arr
    T* cpy_walker = new_arr_ptr;              //then deletes the old arr and returns the temp arr
    T* src_walker = a;                        //just call copy array instead of a new loop
    for (int i = 0; i < size; i++){
        *cpy_walker = *src_walker;
        cpy_walker++;
        src_walker++;
    }
    delete[] a;
    return new_arr_ptr;
}           

template<class T>
void print_array(T* a, int size,                             //prints the number used and the total capacity to see if something is missing
            int capacity = 0, ostream& outs = cout){        //prints the array until (size/capacity) for debug
    outs << "( " << size << "/" << capacity << " ) ";

    outs << "[ ";
    for (int i = 0; i < (size); i++){
        outs << a[i] << " ";
    }
    outs << "]";
 }  

template <class T>
void print(T* a, unsigned int how_many, 
                                ostream& outs = cout){      //prints the size of array so must always be positive
    int capacity = 0;
    print_array(a, how_many, capacity, cout);

 }  

template<class T>
T* search_entry(T* a, int size, const T& find_me){          //searches for find_me in array with walker
                                                            //just call search and convert the int into an address.
                                                            //returns the pointer - has to convert pointer to int / vice versa
    T* walker = a;   
    T* found_index = a;
    for (int i = 0; i < size; i++){                         
        if (find_me == *walker){
            found_index = walker;
            return found_index;
            i = (size+1);
        }
        else if(i == (size-1)){
            return 0;
        }
        walker++;
    }                                     
    
}

template <class T>                                          
int search(T* a, int size, const T& find_me){               //searches for find_me in array with walker
                                                            //returns the index as an int specifically
    
    T* walker = a;   
    T* found_index = a;
    for (int i = 0; i < size; i++){                         
        if (find_me == *walker){
            found_index = walker;
            return i;
            i = (size+1);
        }
        else if(i == (size-1)){
            return -1;
        }
        walker++;
    } 

    /*T* ptr = search_entry(a, size, find_me);
    T index = *ptr;
    return index;*/
}

template <class T>
void shift_left(T* a, int& size, int shift_here){           //shifts all elements right of pos (shift_here)
                                                            //one elements to the left, overwriting pos
    //int pos = search(a, size, shift_here);
    T* shift_to_walker = (a + (shift_here));
    T* shift_from_walker = (shift_to_walker + 1);

    for (int i = shift_here; i < (size); i++){
        *shift_to_walker = *shift_from_walker;
        shift_to_walker++;
        shift_from_walker++;
    }
    size--;
}

template <class T>
void shift_left(T* a, int& size, T* shift_here){ 
    int pos = search(a, size, *shift_here);                
    T* shift_to_walker = (a + (pos));
    T* shift_from_walker = (shift_to_walker + 1);

    for (int i = pos; i < (size); i++){
        *shift_to_walker = *shift_from_walker;
        shift_to_walker++;
        shift_from_walker++;
    }
    size--;
}       

template <class T>
void shift_right(T *a, int &size, int shift_here){          //shifts all elements right of pos (shift_here)
                                                            //one elements to the right 
                                                            //makes the position empty
    int* shift_from_walker = (a + (size - 1));               
    int* shift_to_walker = (a + (size));                 //1 walker at end, 1 walker before end
    for (int i = size; i > shift_here; i--){
        *shift_to_walker = *shift_from_walker;
        shift_from_walker--;
        shift_to_walker--;
    }
    size++;
}      

template <class T>
void shift_right(T *a, int &size, T* shift_here){
    int* pos = search_entry(a, size, *shift_here);          //shift right is not shifting at 30 and at 60 --> works on 0 tho

    int* shift_from_walker = (a + (size - 1));               
    int* shift_to_walker = (a + (size)); 
  
    while (shift_to_walker > pos){
        *shift_to_walker = *shift_from_walker;
        shift_from_walker--;
        shift_to_walker--;
    }
    size++;
}      

template<class T>
void copy_array(T *dest, const T* src,                      //copies elements from src array to dest array
                                int many_to_copy){          //many to copy determines how many elements
    const int* src_walker = &src[0];                        //no idea if this legal according to guidelines but it works in theory
    int* dest_walker = dest;
    for (int i = 0; i < many_to_copy; i++){
        *dest_walker = *src_walker;
        dest_walker++;
        src_walker++;
    }
}      

template <class T>
T* copy_array(const T *src, int size){
    int* dest_start_ptr = new T[size];
    copy_array(dest_start_ptr, src, size);
    
    return dest_start_ptr;
    delete[] dest_start_ptr;                                //this might be bad rn - could delete it somewhere else after its used/.
}               

template <class T>
string array_string(const T *a, int size){                  //returns the array as a string
    ostringstream os;
    const int* walker = &a[0];
    os << "[";
    for (int i = 0; i < size; i++){
        os << *walker << " ";
        walker++;
    }
    os << "]";
    os << "[ " << size << " ]";
    string result(os.str());
    return result;
}             
#endif