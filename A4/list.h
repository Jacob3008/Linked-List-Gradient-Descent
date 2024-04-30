#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

struct Node {
	double data;
	Node* next;
	Node* prev;
};

class List {
public:
	void createList(float, float, float, int);
	void display(bool);
	double getError();
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int nodes = 0;
	double error = NULL;
};

void List::createList(float x, float b, float s, int n) {
	Node* newnode = new Node;

	newnode->next = nullptr;
	
	// if list is empty
	if (head == nullptr) {
		newnode->data = abs(tanh(x) - b);
		newnode->prev = nullptr;
		head = newnode;
		nodes++;

		// repeat if there are more hidden nodes
		if (nodes < n)
			createList(x, b, s, n);
		return;
	}
	
	// find next empty node
	Node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	newnode->prev = temp;
	temp->next = newnode;

	// set new data and repeat if there are more hidden nodes
	newnode->data = temp->data * s;
	nodes++;
	if (nodes < n)
		createList(x, b, s * 10, n);
	else {
		error = newnode->data;
		tail = newnode;
	}
		
}

void List::display(bool reverse) {
	Node* ptr;

	// set ptr to either tail or head
	if (reverse)
		ptr = tail;
	else
		ptr = head;

	// display all nodes
	while (ptr != nullptr) {
		cout << setprecision(6) << fixed << ptr->data << " -> ";
		if (reverse)
			ptr = ptr->prev;
		else
			ptr = ptr->next;
	}
	cout << "nullptr" << endl;
}

double List::getError() {
	return error;
}