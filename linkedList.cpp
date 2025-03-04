#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int val){
		data = val;
		next = NULL;
	}
};

void insertAtTail(Node* &head,int val){
	Node* newNode = new Node(val);

	if(head == NULL) {
		head = newNode;
		return;
	}

	Node* tmp = head;
	while(tmp->next!=NULL){
		tmp = tmp->next;
	}
	tmp->next = newNode;
}

void insertAtHead(Node* &head, int val){
	Node* newNode = new Node(val);
	newNode->next = head;
	head = newNode;
}

void display(Node* head){
	Node* tmp = head;
	while(tmp!=NULL){
		cout << tmp->data<<"->";
		tmp=tmp->next;
	}
	cout<<"NULL"<<endl;

}

bool search(Node* head, int key){
	Node* tmp = head;
	while(tmp!=NULL){
		if(tmp->data==key){
			return true;
		}
		tmp= tmp->next;
	}

	return false;
}

void deleteAtHead(Node* &head){
	if(head==NULL) return;

	Node* toDelete = head;
	head = head->next;
	delete toDelete;
}

void deletion(Node* &head, int val){
	Node* tmp = head;
	if(head==NULL) return;

	if(head->data == val){
		deleteAtHead(head);
		return;
	} 

	while(tmp->next != NULL && tmp->next->data!=val){
		tmp = tmp->next;
	}
	if (tmp->next == NULL) return;

	Node* toDelete = tmp->next;
	tmp->next = tmp->next->next;
	delete toDelete;
}

void reverse(Node* &head){
	Node* prev = NULL;
	Node* curr = head;

	while(curr!=NULL){
		Node* tmp = curr->next;
		curr->next = prev;

		prev = curr;
		curr = tmp;
	}

	head = prev;
}

Node* reverseRecursive(Node* &head){
	if(head == NULL || head->next == NULL) return head;

	Node* newHead = reverseRecursive(head->next);
	head->next->next = head;
	head->next = NULL;

	return newHead;
}

Node* reverseK(Node* &head, int k){
	Node* prevptr = NULL;
	Node* currptr = head;
	Node* nextptr;

	int count =0;
	while(currptr!=NULL && count<k){
		nextptr = currptr->next;
		currptr->next = prevptr;

		prevptr = currptr;
		currptr = nextptr;
		count++;
	}

	if(nextptr!=NULL) head->next = reverseK(nextptr,k);

	return prevptr;
}

Node* reverseKGroup(Node* &head,int k){
	Node* tmp = head;

	//check count
	int cnt = 0;
	while(cnt<k){
		if(tmp==NULL){
			return head;
		}
		tmp = tmp->next;
		cnt++;
	}

	//recursice call for rest linked list
	Node* prevNode = reverseKGroup(tmp,k);

	//reverse current group
	tmp = head; cnt =0;
	while(cnt<k){
		Node* nextptr = tmp->next;
		tmp->next = prevNode;

		prevNode = tmp;
		tmp=nextptr;
		cnt++;
	}

	return prevNode;
}

void removeKfromEnd(Node* &head,int k){
	Node* tmp = head;
	int n = 0;
	while(tmp!=NULL){
		n++;
		tmp = tmp->next;
	}

	tmp = head;
	if (n-k == 0){
		head = head->next;
		return;
	}

	int i = n-k-1;
	while(tmp!=NULL && i>0){
		tmp = tmp->next;
		i--;
	}

	Node* toDelete = tmp->next;
	tmp->next = toDelete->next;
	delete toDelete;
}

void removeDuplicateFromSorted(Node* &head){
	Node* prevNode = new Node(0);
    if (head == NULL || head->next == NULL) return;

	Node* currentNode = head;
	head = prevNode;

    while (currentNode != NULL && currentNode->next != NULL) {
        if(currentNode->next != NULL && currentNode->next->data == currentNode->data){
        	while(currentNode->next != NULL && currentNode->next->data == currentNode->data){
                currentNode = currentNode->next;
            }
            prevNode->next = currentNode->next;
        } else {
            prevNode->next = currentNode;
            prevNode = prevNode->next;
        }
        currentNode = currentNode->next;
    }

    head = head->next;
}


int main(){
	Node* head = NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	insertAtTail(head,4);
	insertAtTail(head,4);
	insertAtTail(head,4);
	insertAtTail(head,5);
	display(head);

	// insertAtHead(head,0);
	// display(head);
	// deletion(head,4);
	// display(head);
	// reverse(head);
	// display(head);
	// Node* tmp = reverseRecursive(head);
	// display(tmp);

	// Node* tmp = reverseKGroup(head,2);
	// display(tmp);

	//removeKfromEnd(head,1);
	//display(head);

	removeDuplicateFromSorted(head);
	display(head);

}