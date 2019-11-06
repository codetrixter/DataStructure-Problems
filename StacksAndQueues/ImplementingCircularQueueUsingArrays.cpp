#include <iostream>
#define MAX 5

class CircularQueue
{
    private:

    int front = -1, rear = -1;

    public:

    void enqueue(int arr[], int element)
    {
        if(((rear == (MAX-1)) && (front == 0)) || (rear+1 == front) )
        {
            std::cout << "Overflow..." << std::endl;
            return;
        }
        else if(rear == -1) //first element insertion.
        {
            rear = front = 0;
        }
        else
        { 
            if(rear == MAX-1)
            {
                rear = 0;
            }
            else
            {
                rear++;
            }
        }
        arr[rear] = element;
    }

    void dequeue(int arr[])
    {
        if(front == -1 )
        {
            std::cout << "Underflow..." << std::endl;
            return; 
        }
        else if(front == rear)
        {
            arr[front] = 0;
            front = rear = -1;
        }
        else 
        {
            if(front == MAX-1)
            {
                arr[front] = 0;
                front = 0;
            }
            else
            {
                arr[front] = 0;
                front++;
            }
        }
    }

    void printQueue(int arr[])
    {
        std::cout << "front of the queue is:: " << arr[front] << " and rear of the queue is :: " << arr[rear] << std::endl;

        for(int i = 0; i < MAX; i++)
        {
            std::cout << arr[i] << "\t" ;
        }
    }
};

int main(int argc, char const *argv[])
{
    int options, element = 0;
    CircularQueue *q1 = new CircularQueue();
    static int qArr[MAX];
    do
    {
        std::cout << "Please select the following options to perform the respective actions on CircularQueue..." << std::endl;
        std::cout << "1: Insert an Element into the CircularQueue" << std::endl;
        std::cout << "2: Delete an Element from the CircularQueue" << std::endl;
        std::cout << "3: Print the CircularQueue" << std::endl;
        std::cout << "0: Exit" << std::endl;
        std::cin >> options;

        switch(options)
        {
            case 1:
                std::cin >> element;
                q1->enqueue(qArr, element);
                std::cout << "operation done" <<std::endl;
                break;
            case 2:
                q1->dequeue(qArr);
                std::cout << "Operation done" << std::endl;
                break;
            case 3:
                q1->printQueue(qArr);
                break;
            case 0:
                std::cout << "O enetered.... exiting..." << std::endl;
                std::exit(0);
            default :
                std::cout << "Invalid entry" << std::endl;
        }
    }while(options != 0);
    return 0;
}