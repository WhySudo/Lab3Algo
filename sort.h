#ifndef LAB3ALGO_SORT_H
#define LAB3ALGO_SORT_H
#include <iostream>
#include <memory>

const int insertionSortAmount = 16;

template<typename T, typename Compare>
void insertion_sort(T *first, T *last, Compare comp)
{
    if(first == last)
        return;
    T* current;
    T storedValue;
    for(T *idx = first + 1; idx <= last; idx++){
        storedValue = *idx;
        for(current = idx;current > first && comp(storedValue, *(current-1));current--){
            *current = std::move(*(current-1));
        }
        if(current != idx){
            *current = std::move(storedValue);
        }
    }
}

template<typename T, typename Compare>
T* get_middle(T *first, T *last, Compare comp){
    T* middle = (last - first) / 2 + first;
    if(comp(*last, *middle))std::swap(*middle, *last);
    if(comp(*last, *first))std::swap(*first, *last);
    if(comp(*middle, *first))std::swap(*middle, *first);
    return middle;
}
template<typename T, typename Compare>
T* get_partition(T *first, T *last, T midValue, Compare comp){
    T* left = first;
    T* right = last;
    for(;;){
        for(;comp(*left, midValue);left++);
        for(;comp(midValue, *right);right--);
        if(left >= right)break;
        std::swap(*left, *right);
        left++, right--;
    }
    return right;
}

template<typename T, typename Compare>
void sort(T *first, T *last, Compare comp, bool useInsert = true)
{
    while (first < last){
        if(useInsert && last - first <= insertionSortAmount){
            insertion_sort(first, last, comp);
            return;
        }
        T* middle = get_middle(first, last, comp);
        T* partition = get_partition(first, last, *middle, comp);
        //right points at border
        if(last - partition > partition - first){
            sort(first, partition, comp, useInsert);
            first = partition+1;
        }
        else{
            sort(partition+1, last, comp, useInsert);
            last = partition;
        }
    }
}
#endif //LAB3ALGO_SORT_H
