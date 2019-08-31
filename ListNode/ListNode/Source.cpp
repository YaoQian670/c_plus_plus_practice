
#include <iostream>
#include <set>
using namespace std;

template <class T>
class ListNode {
public:
	ListNode(T t) {
		value = t;
		next = NULL;
	}
	T value;
	ListNode<T>* next;
};

template <class T>
void iterateList(ListNode<T>* head) {
	ListNode<T>* tmp = head;
	while (tmp != NULL) {
		cout << tmp->value << "\t";
		tmp = tmp->next;
	}
	cout << endl;
}

template <class T>
ListNode<T>* reverseList(ListNode<T>* head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode<T>* tmp1 = head;
	ListNode<T>* tmp2 = head->next;
	head->next = NULL;
	while (tmp2) {
		ListNode<T>* tmp3 = tmp2->next;
		tmp2->next = tmp1;
		tmp1 = tmp2;
		tmp2 = tmp3;
	}
	return tmp1;
}

template <class T>
bool ifCircle(ListNode<T>* head) {
	set<ListNode<T>*> nodeAddSet;
	ListNode<T>* tmp = head;
	while (tmp != NULL) {
		if (nodeAddSet.insert(tmp).second)
			tmp = tmp->next;
		else
			return true;
	}
	return false;
}

template <class T>
ListNode<T>* pairReverse(ListNode<T>* head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode<T>* tmp1 = head, * tmp2 = head->next, * tmp3 = head->next->next;
	ListNode<T>* reversedListHead = tmp2;
	while (1) {
		tmp2->next = tmp1;
		if (tmp3 == NULL || tmp3->next == NULL) {
			tmp1->next = tmp3;
			break;
		}
		tmp1->next = tmp3->next;
		tmp1 = tmp3;
		tmp2 = tmp3->next;
		tmp3 = tmp2->next;
	}
	return reversedListHead;
}


int main() {
	ListNode<int>* node1 = new ListNode<int>(1);
	ListNode<int>* node2 = new ListNode<int>(2);
	ListNode<int>* node3 = new ListNode<int>(3);
	ListNode<int>* node4 = new ListNode<int>(4);
	ListNode<int>* node5 = new ListNode<int>(5);
	ListNode<int>* node6 = new ListNode<int>(6);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = NULL;
	iterateList(node1);
	/*ListNode<int>* reversedListHead = reverseList(node1);
	iterateList(reversedListHead);*/
	/*node5->next = node1;
	if (ifCircle(node1))
		cout << "circle" << endl;
	else
		cout << "not circle" << endl;*/
	iterateList(pairReverse(node1));
}