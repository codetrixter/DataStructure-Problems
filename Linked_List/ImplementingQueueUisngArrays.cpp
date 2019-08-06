#include <iostream>

#define MAX 20

class Queueing
{
    private:
        int front = -1;
        int rear = -1;

    public:
        void enqueue(int arr[], int item)
        {
            if(((front = 0) && (rear = (MAX-1))) || (front = rear + 1))
            {
                std::cout << "Overflow" << std::endl;
                return;
            }
            else if(front == -1 && rear == -1)
            {
                front = rear = 0;
            }
            else if(rear == (MAX-1))
            {
                rear = 0;
            }
            else
            {
                rear += 1;
            }
            arr[rear] = item;
        }

        void dequeue(int arr[])
        {
            if(front = -1)
            {
                std::cout << "Underflow" << std::endl;
                return; 
            }
            else if(front == rear)
            {
                front = rear = -1;
            }
            else if(front == MAX)
            {
                front = 0;
            }
            else
            {
                front += 1;
            }
        }

        void printQueue(int arr[])
        {
            if(front == -1)
            {
                std::cout << "queue is empty" << std::endl;
                return;
            }
            std::cout << "front of the queue is" << arr[front] << "\t rear of the queue is " << arr[rear] 
                        << std::endl;
            if(rear != (MAX-1))
            { 
                for(int ind = front; ind <= rear; ++ind)
                {
                    std::cout << arr[ind] << "\t";
                }
            }
            else if(rear == (MAX-1))
            {
                for(int ind = 0; ind < MAX; ++ind)
                {
                    std::cout << arr[ind] << "\t";
                }
            }
            
            std::cout << std::endl;
        }
};

int main(int argc, char const *argv[])
{
    int options, element = 0;
    Queueing *q1 = new Queueing();
    int qArr[MAX];
    do
    {
        std::cout << "Please select the following options to perform the respective actions on Queue..." << std::endl;
        std::cout << "1: Insert an Element into the Queue" << std::endl;
        std::cout << "2: Insert an Element into the Queue" << std::endl;
        std::cout << "3: Print the Queue" << std::endl;
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
