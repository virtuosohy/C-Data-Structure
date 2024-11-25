#include <iostream>

// 单链表节点结构体
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(NULL) {}
};

// 1. 定义单链表的存储结构
class LinkedList {
private:
    ListNode* head;

public:
	
	    // 在链表尾部插入节点
    void insertAtTail(int value) {
        ListNode* newNode = new ListNode(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        ListNode* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}; 
    // 2. (1) 初始化单链表（无参）
    LinkedList() {
        head = NULL;
    } 

    // 2. (1) 初始化单链表（有参，传入一个数组及数组长度来初始化链表）
    LinkedList(int arr[], int n) {
        head = NULL;
        for (int i = 0; i < n; ++i) {
            insertAtTail(arr[i]);
        }
    }

    // 2. (2) 求单链表长度
    int length() {
        int count = 0;
        ListNode* current = head;
        while (current!= NULL) {
            ++count;
            current = current->next;
        }
        return count;
    }

    // 2. (3) 按位置查找
    ListNode* findAtPosition(int position) {
        if (position < 0) {
            return NULL;
        }
        ListNode* current = head;
        int index = 0;
        while (current!= NULL && index < position) {
            current = current->next;
            ++index;
        }
        return current;
    }


    // 2. (4) 按值查找
    ListNode* findByValue(int value) {
        ListNode* current = head;
        while (current!= NULL && current->data!= value) {
            current = current->next;
        }
        return current;
    }

    // 2. (5) 在位置i插入一个数据元素
    void insertAtPosition(int position, int value) {
        if (position < 0) {
            return;
        }
        if (position == 0) {
            ListNode* newNode = new ListNode(value);
            newNode->next = head;
            head = newNode;
            return;
        }
        //找到需要插入内容的前一个节点，没找到就结束 
        ListNode* prev = findAtPosition(position - 1);
        if (prev == NULL) {
            return;
        }
        ListNode* newNode = new ListNode(value);
        newNode->next = prev->next;
        prev->next = newNode;
    }
   
	// 2. (6) 删除位置i的数据元素
    void deleteAtPosition(int position) {
        if (position < 0 || head == NULL) {
            return;
        }
        if (position == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        ListNode* prev = findAtPosition(position - 1);
        if (prev == NULL || prev->next == NULL) {
            return;
        }
        ListNode* temp = prev->next;
        prev->next = temp->next;
        delete temp;
    }

    // 2. (7) 遍历单链表
    void traverse() {
        ListNode* current = head;
        while (current!= NULL) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // 2. (8) 合并链表（直接连接？）
void merge(LinkedList& otherList) {
    if (head == NULL) {
        head = otherList.head;
        return;
    }
    if (otherList.head == NULL) {
        return;
    }
    ListNode* current = head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = otherList.head;
}

    // 2. (9) 销毁单链表
    void destroy() {
        ListNode* current = head;
        ListNode* next;
        while (current!= NULL) {
            next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
    }



int main() {
    // 测试无参初始化及插入操作
    LinkedList list1;
    list1.insertAtPosition(0, 1);
    list1.insertAtPosition(1, 3);
    list1.insertAtPosition(2, 5);

    // 测试有参初始化
    int arr[] = {2, 4, 6};
    LinkedList list2(arr, 3);

    // 测试求长度
    std::cout << "List1 length: " << list1.length() << std::endl;
    std::cout << "List2 length: " << list2.length() << std::endl;

    // 测试按位置查找
    ListNode* nodeAtPos = list1.findAtPosition(1);
    if (nodeAtPos!= NULL) {
        std::cout << "Node at position 1 in List1:  " << nodeAtPos->data << std::endl;
    }

    // 测试按值查找
    ListNode* nodeByVal = list2.findByValue(4);
    if (nodeByVal!= NULL) {
        std::cout << "Node with value 4 in List2:  " << nodeByVal->data << std::endl;
    }

    // 测试在位置插入
    list1.insertAtPosition(2, 4);

    // 测试删除位置元素
    list1.deleteAtPosition(1);

    // 测试遍历
    std::cout << "List1 after operations:  ";
    list1.traverse();

    // 测试合并链表
    list1.merge(list2);
    std::cout << "Merged list:  ";
    list1.traverse();

    // 测试销毁链表
    list1.destroy();
    std::cout << "list:  ";
    list1.traverse();
    return 0;
}
