#include <iostream>
using namespace std;

// 定义顺序队列的类
class SeqQueue {
private:
    int* data;       // 存储数据元素的一维数组指针
    int front;       // 队头指针，指向队头元素的下一个位置
    int rear;        // 队尾指针，指向队尾元素
    int maxSize;     // 顺序队列的最大容量

public:
    // 1. 初始化顺序队列
    SeqQueue(int size) {
        maxSize = size;
        data = new int[maxSize];
        front = 0;
        rear = -1;
    }

    // 2. 数据元素入队
    void Enqueue(int element) {
        if (IsFull()) {
            cout << "队列已满，无法入队" << endl;
            return;
        }
        rear = (rear + 1) % maxSize;
        data[rear] = element;
    }

    // 3. 数据元素出队
    int Dequeue() {
        if (IsEmpty()) {
            cout << "队列已空，无法出队" << endl;
            return -1;
        }
        int element = data[front];
        front = (front + 1) % maxSize;
        return element;
    }

    // 4. 读队头元素
    int GetFront() {
        if (IsEmpty()) {
            cout << "队列已空，无队头元素" << endl;
            return -1;
        }
        return data[front];
    }

    // 5. 判定队列空/满
    bool IsEmpty() {
        return front == (rear + 1) % maxSize;
    }

    bool IsFull() {
        return (rear + 2) % maxSize == front;
    }

    // 6. 销毁顺序队列
    void Destroy() {
        delete[] data;
        data = NULL;
        front = 0;
        rear = -1;
    }
};

int main() {
    SeqQueue queue(5);

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);

    cout << "队头元素: " << queue.GetFront() << endl;

    cout << "出队元素: " << queue.Dequeue() << endl;

    if (queue.IsEmpty()) {
        cout << "队列为空" << endl;
    } else {
        cout << "队列不为空" << endl;
    }

    queue.Destroy();
    return 0;
}
