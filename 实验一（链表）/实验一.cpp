#include <iostream>

// ������ڵ�ṹ��
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(NULL) {}
};

// 1. ���嵥����Ĵ洢�ṹ
class LinkedList {
private:
    ListNode* head;

public:
	
	    // ������β������ڵ�
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
    // 2. (1) ��ʼ���������޲Σ�
    LinkedList() {
        head = NULL;
    } 

    // 2. (1) ��ʼ���������вΣ�����һ�����鼰���鳤������ʼ������
    LinkedList(int arr[], int n) {
        head = NULL;
        for (int i = 0; i < n; ++i) {
            insertAtTail(arr[i]);
        }
    }

    // 2. (2) ��������
    int length() {
        int count = 0;
        ListNode* current = head;
        while (current!= NULL) {
            ++count;
            current = current->next;
        }
        return count;
    }

    // 2. (3) ��λ�ò���
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


    // 2. (4) ��ֵ����
    ListNode* findByValue(int value) {
        ListNode* current = head;
        while (current!= NULL && current->data!= value) {
            current = current->next;
        }
        return current;
    }

    // 2. (5) ��λ��i����һ������Ԫ��
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
        //�ҵ���Ҫ�������ݵ�ǰһ���ڵ㣬û�ҵ��ͽ��� 
        ListNode* prev = findAtPosition(position - 1);
        if (prev == NULL) {
            return;
        }
        ListNode* newNode = new ListNode(value);
        newNode->next = prev->next;
        prev->next = newNode;
    }
   
	// 2. (6) ɾ��λ��i������Ԫ��
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

    // 2. (7) ����������
    void traverse() {
        ListNode* current = head;
        while (current!= NULL) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // 2. (8) �ϲ�����ֱ�����ӣ���
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

    // 2. (9) ���ٵ�����
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
    // �����޲γ�ʼ�����������
    LinkedList list1;
    list1.insertAtPosition(0, 1);
    list1.insertAtPosition(1, 3);
    list1.insertAtPosition(2, 5);

    // �����вγ�ʼ��
    int arr[] = {2, 4, 6};
    LinkedList list2(arr, 3);

    // �����󳤶�
    std::cout << "List1 length: " << list1.length() << std::endl;
    std::cout << "List2 length: " << list2.length() << std::endl;

    // ���԰�λ�ò���
    ListNode* nodeAtPos = list1.findAtPosition(1);
    if (nodeAtPos!= NULL) {
        std::cout << "Node at position 1 in List1:  " << nodeAtPos->data << std::endl;
    }

    // ���԰�ֵ����
    ListNode* nodeByVal = list2.findByValue(4);
    if (nodeByVal!= NULL) {
        std::cout << "Node with value 4 in List2:  " << nodeByVal->data << std::endl;
    }

    // ������λ�ò���
    list1.insertAtPosition(2, 4);

    // ����ɾ��λ��Ԫ��
    list1.deleteAtPosition(1);

    // ���Ա���
    std::cout << "List1 after operations:  ";
    list1.traverse();

    // ���Ժϲ�����
    list1.merge(list2);
    std::cout << "Merged list:  ";
    list1.traverse();

    // ������������
    list1.destroy();
    std::cout << "list:  ";
    list1.traverse();
    return 0;
}
