class MyCircularQueue {
    private:
    vector<int>q;
    int front,rear,capacity,size;
public:
    MyCircularQueue(int k) {
        capacity=k;
        q.resize(k);
        front=-1;
        rear=-1;
        size=0;
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        if(isEmpty()){
            front=rear=0;
        }
        else{
            rear=(rear+1)%capacity;
        }
        q[rear]=value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(front==rear)
        {
            front=rear=-1;
        }
        else{
            front=(front+1)%capacity;
        }
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:q[front];
    }
    
    int Rear() {
       return isEmpty()?-1:q[rear]; 
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};
