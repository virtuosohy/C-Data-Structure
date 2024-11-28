#include <iostream>
using namespace std;

// ����˳����е���
class SeqQueue {
private:
    int* data;       // �洢����Ԫ�ص�һά����ָ��
    int front;       // ��ͷָ�룬ָ���ͷԪ�ص���һ��λ��
    int rear;        // ��βָ�룬ָ���βԪ��
    int maxSize;     // ˳����е��������

public:
    // 1. ��ʼ��˳�����
    SeqQueue(int size) {
        maxSize = size;
        data = new int[maxSize];
        front = 0;
        rear = -1;
    }

    // 2. ����Ԫ�����
    void Enqueue(int element) {
        if (IsFull()) {
            cout << "�����������޷����" << endl;
            return;
        }
        rear = (rear + 1) % maxSize;
        data[rear] = element;
    }

    // 3. ����Ԫ�س���
    int Dequeue() {
        if (IsEmpty()) {
            cout << "�����ѿգ��޷�����" << endl;
            return -1;
        }
        int element = data[front];
        front = (front + 1) % maxSize;
        return element;
    }

    // 4. ����ͷԪ��
    int GetFront() {
        if (IsEmpty()) {
            cout << "�����ѿգ��޶�ͷԪ��" << endl;
            return -1;
        }
        return data[front];
    }

    // 5. �ж����п�/��
    bool IsEmpty() {
        return front == (rear + 1) % maxSize;
    }

    bool IsFull() {
        return (rear + 2) % maxSize == front;
    }

    // 6. ����˳�����
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

    cout << "��ͷԪ��: " << queue.GetFront() << endl;

    cout << "����Ԫ��: " << queue.Dequeue() << endl;

    if (queue.IsEmpty()) {
        cout << "����Ϊ��" << endl;
    } else {
        cout << "���в�Ϊ��" << endl;
    }

    queue.Destroy();
    return 0;
}
