/**
 * 
 */
#include <iostream>

using namespace std;

class ArrayADT
{
private:
    int *A;
    int length;
    int size;

public:
    ArrayADT(int size)
    {
        A = new int[size];
        this->size = size;
        length = 0;
    }

    /**
     * Initializes the array with the given array.
     */
    void initializeArray(int array[])
    {
        for (int i = 0; i < 5; i++)
        {
            A[i] = array[i];
            ++length;
        }
    }

    /**
     * Prints the contents of the array.
     */
    void display()
    {
        printf("\n");
        for (int i = 0; i < 10; i++)
        {
            printf("%d", A[i]);
        }
    }

    int getLength()
    {
        return length;
    }

    int getSize()
    {
        return size;
    }

    /**
     * Insert an element into the array at a given index. 
     * Complexity is O(n) in worst case.
     */
    void insertElement(int element, int index)
    {
        int i = 0;
        if(this->getLength() == this->getSize())
        {
            printf("array is full... exiting...");
            return ;
        }
            
        for(i = this->getLength(); i > index; i--)
        {
            A[i] = A[i-1];
        }

        A[i] = element;
        this->length++;
    }

    /**
     * Deletes from an array at the given index.
     * Complexity is O(n) under worst case.
     */
    void deleteElement(int index)
    {
        int deletedValue = 0;
        if(index < 0 && index > this->getSize())
        {
            printf("indvalid index...");
            return ;
        }

        for(int i = index; i < this->getLength(); i++)
        {
            deletedValue = A[index];
            A[i] = A[i+1];
        }
        A[length-1] = 0;
        this->length--;
    }
};

int main(int argc, char const *argv[])
{
    ArrayADT *arr = new ArrayADT(10);
    int arrTemp[5] = {1, 2, 3, 4, 5};
    arr->initializeArray(arrTemp);
    arr->display();
    printf("\n%d", arr->getSize());
    printf("\n%d", arr->getLength());

    arr->insertElement(6,3);
    arr->display();
    printf("\n%d", arr->getLength());

    arr->deleteElement(0);
    arr->display();
    printf("\n%d", arr->getLength());

    return 0;
}
