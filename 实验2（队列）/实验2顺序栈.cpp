 #include <iostream>
using namespace std;

// 定义顺序栈的类
class SeqStack {
private:
    int* data;  // 存储数据元素的一维数组指针
    int top;    // 栈顶指针，存储栈顶下标
    int maxSize;  // 顺序栈的最大容量

public:
    // 1. 初始化顺序栈
    SeqStack(int size) {
        maxSize = size;
        data = new int[maxSize];  // 动态分配数组空间
        top = -1;  // 初始化栈顶指针，栈为空时为 -1
    }

    // 2. 数据元素入栈
    void Push(int element) {
        if (IsFull()) {
            cout << "栈已满，无法入栈" << endl;
            return;
        }
        top++;
        data[top] = element;
    }

    // 3. 数据元素出栈
    int Pop() {
        if (IsEmpty()) {
            cout << "栈已空，无法出栈" << endl;
            return -1;  // 返回一个特殊值表示出错情况，这里简单返回 -1
        }
        int element = data[top];
        top--;
        return element;
    }

    // 4. 读栈顶元素
    int GetTop() {
        if (IsEmpty()) {
            cout << "栈已空，无栈顶元素" << endl;
            return -1;  // 返回一个特殊值表示出错情况，这里简单返回 -1
        }
        return data[top];
    }

    // 5. 判定栈空操作
    bool IsEmpty() {
        return top == -1;
    }

    // 判定栈满操作
    bool IsFull() {
        return top == maxSize - 1;
    }

    // 6. 销毁顺序栈
    void Destroy() {
        delete[] data;
        data = NULL;
        top = -1;
    }
};

int main() {
    SeqStack stack(5);  // 创建一个大小为5的顺序栈

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    cout << "栈顶元素: " << stack.GetTop() << endl;

    cout << "出栈元素: " << stack.Pop() << endl;

    if (stack.IsEmpty()) {
        cout << "栈为空" << endl;
    } else {
        cout << "栈不为空" << endl;
    }

    stack.Destroy();
    return 0;
}
