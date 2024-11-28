 #include <iostream>
using namespace std;

// ����˳��ջ����
class SeqStack {
private:
    int* data;  // �洢����Ԫ�ص�һά����ָ��
    int top;    // ջ��ָ�룬�洢ջ���±�
    int maxSize;  // ˳��ջ���������

public:
    // 1. ��ʼ��˳��ջ
    SeqStack(int size) {
        maxSize = size;
        data = new int[maxSize];  // ��̬��������ռ�
        top = -1;  // ��ʼ��ջ��ָ�룬ջΪ��ʱΪ -1
    }

    // 2. ����Ԫ����ջ
    void Push(int element) {
        if (IsFull()) {
            cout << "ջ�������޷���ջ" << endl;
            return;
        }
        top++;
        data[top] = element;
    }

    // 3. ����Ԫ�س�ջ
    int Pop() {
        if (IsEmpty()) {
            cout << "ջ�ѿգ��޷���ջ" << endl;
            return -1;  // ����һ������ֵ��ʾ�������������򵥷��� -1
        }
        int element = data[top];
        top--;
        return element;
    }

    // 4. ��ջ��Ԫ��
    int GetTop() {
        if (IsEmpty()) {
            cout << "ջ�ѿգ���ջ��Ԫ��" << endl;
            return -1;  // ����һ������ֵ��ʾ�������������򵥷��� -1
        }
        return data[top];
    }

    // 5. �ж�ջ�ղ���
    bool IsEmpty() {
        return top == -1;
    }

    // �ж�ջ������
    bool IsFull() {
        return top == maxSize - 1;
    }

    // 6. ����˳��ջ
    void Destroy() {
        delete[] data;
        data = NULL;
        top = -1;
    }
};

int main() {
    SeqStack stack(5);  // ����һ����СΪ5��˳��ջ

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    cout << "ջ��Ԫ��: " << stack.GetTop() << endl;

    cout << "��ջԪ��: " << stack.Pop() << endl;

    if (stack.IsEmpty()) {
        cout << "ջΪ��" << endl;
    } else {
        cout << "ջ��Ϊ��" << endl;
    }

    stack.Destroy();
    return 0;
}
