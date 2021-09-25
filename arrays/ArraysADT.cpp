/**
 * 
 */
#include <iostream>
#include <algorithm>

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
        for (int i = 0; i < 10; i++)
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
        for (int i = 0; i < length; i++)
        {
            printf("%d ", A[i]);
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

    /**
     * Searching an element in an array.
     * Some ways of improving are:
     * 1- Transposition.
     * 2- Move to Head.
     */
    int linearSearch(int element)
    {  
        int found = -1;
        for(int i = 0; i < length; i++) 
        {
            if(A[i] == element)
                found = 1;
        }
        return found;
    }

    int binarySearch(int element)
    {
        int first = 0, last = 0, mid = 0, found = -1;

        //sorting the array.
        sort(A, A + length);

        last = length-1;
        mid = (first + last) / 2;
        while(A[first] != A[last])
        {
            if(element > A[mid])
            {
                first = mid + 1;
            }
            else if(element < A[mid])
            {
                last = mid - 1;
            }
            else
            {
                found = 1;
                return found;
            }
        }
        return found;
    }

    int getAtIndex(int index)
    {
        return A[index];
    }

    void setAtIndex(int index, int element)
    {
        for(int i = 0; i < length; i++)
        {
            if(i == index)
                A[i] = element;
        }
    }

    int findMaximum()
    {
        int max = A[0];
        for(int i = 0; i < length; i++)
        {
            if(max < A[i])
                max = A[i];
        }
        return max;
    }

};

int main(int argc, char const *argv[])
{
    ArrayADT *arr = new ArrayADT(20);
    int arrTemp[] = {1, 2, 30, 40, 5, 6, 8, 9, 12, 113}, found = 0;
    cout << " \n //-----------Initialize array---------" << endl;
    arr->initializeArray(arrTemp);
    arr->display();
    printf("\n%d", arr->getSize());
    printf("\n%d", arr->getLength());
    cout << " \n //-----------insert into array----------" << endl;
    arr->insertElement(6,3);
    arr->display();
    printf("\n%d", arr->getLength());
    cout << " \n //--------delete from an array--------" << endl;
    arr->deleteElement(0);
    arr->display();
    printf("\n%d", arr->getLength());
    cout << " \n //--------linear search an array-------" << endl;
    found = arr->linearSearch(11);
    if(found == -1)
        printf("Element not found");
    else
        printf("Element found");
    cout << " \n //--------Binary search an array----------" << endl;
    found = arr->binarySearch(8);
    if(found == -1)
        printf("Element not found");
    else
        printf("Element found");
    cout << " \n //---------get item at index---------" << endl;
    arr->display();
    printf("%d", arr->getAtIndex(5));
    cout << " \n //---------set element at index-------" << endl;
    arr->display();
    arr->setAtIndex(6, 200);
    cout << " \n //--------finding maximum value from an array----------" << endl;
    arr->display();
    printf("%d", arr->findMaximum());

    return 0;
}
