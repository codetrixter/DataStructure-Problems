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
     */
    void insertElement(int index)
    {

    }

    /**
     * Deletes from an array at the given index.
     */
    void deleteElement(int index)
    {
        
    }
};

int main(int argc, char const *argv[])
{
    ArrayADT *arr = new ArrayADT(10);
    int arrTemp[5] = {1, 2, 3, 4, 5};
    arr->initializeArray(arrTemp);
    arr->display();
    printf("%d", arr->getSize());
    printf("%d", arr->getLength());

    return 0;
}
