#include "gtest/gtest.h"
#include "../sort.h"
class SortingTests : public testing::Test {
public:
protected:
    void SetUp() override {

    }

public:
    template< typename T, typename Compare>
    void QuickSortingTest(T *targetItems, int size, Compare comp){
        sort(targetItems, targetItems+size-1, comp, false);
        for (int i = 1; i < size; ++i) {
            EXPECT_FALSE( comp(targetItems[i], targetItems[i-1]));
        }
    }

    template< typename T, typename Compare>
    void InsertionSortingTest(T *targetItems, int size, Compare comp){
        insertion_sort(targetItems, targetItems+size-1, comp);
        for (int i = 1; i < size; ++i) {
            EXPECT_FALSE( comp(targetItems[i], targetItems[i-1]));
        }
    }
    template< typename T, typename Compare>
    void BestSortingTest(T *targetItems, int size, Compare comp){
        sort(targetItems, targetItems+size-1, comp);
        for (int i = 1; i < size; ++i) {
            EXPECT_FALSE( comp(targetItems[i], targetItems[i-1]));
        }
    }
};

TEST_F(SortingTests, QuickSortTest){
    int array[] = {10, 20, 1, 2, 5, 7    };
    int bigArrayOrdered[100];
    int bigArray[100];
    auto comp = [](int a, int b){return a < b;};
    for(int i = 0; i < 100; i++){
        bigArray[i] = 100-i;
        bigArrayOrdered[i] = i;
    }
    QuickSortingTest(array, 6, comp);
    QuickSortingTest(bigArrayOrdered, 100, comp);
    QuickSortingTest(bigArray, 100, comp);
}
TEST_F(SortingTests, InsertSortTest){
    int array[] = {10, 20, 1, 2, 5, 7, 7, 7,7 };
    int bigArrayOrdered[100];
    int bigArray[100];
    auto comp = [](int a, int b){return a < b;};
    for(int i = 0; i < 100; i++){
        bigArray[i] = 100-i;
        bigArrayOrdered[i] = i;
    }
    InsertionSortingTest(array, 9, comp);
    InsertionSortingTest(bigArrayOrdered, 100, comp);
    InsertionSortingTest(bigArray, 100, comp);
}
TEST_F(SortingTests, BestSortTest){
    int array[] = {10, 20, 1, 2, 5, 7    };
    int bigArrayOrdered[100];
    int bigArray[100];
    auto comp = [](int a, int b){return a < b;};
    for(int i = 0; i < 100; i++){
        bigArray[i] = 100-i;
        bigArrayOrdered[i] = i;
    }
    BestSortingTest(array, 6, comp);
    BestSortingTest(bigArrayOrdered, 100, comp);
    BestSortingTest(bigArray, 100, comp);
}
