#pragma once
#include <iostream>

using namespace std;

struct Node {
	double data;
	Node* next;
	Node* prev;
};

class List {
public:
	void createList(double);
	void display(bool);
private:
	Node* head = NULL;
};

void List::createList(double newdata) {
	Node* newnode = new Node;

	newnode->next = NULL;
	
	// if list is empty
	if (head == NULL) {
		newnode->data = newdata;
		newnode->prev = NULL;
		head = newnode;

		// repeat if data is greater than 0.5
		if (newdata > 0.5)
			createList(newdata);
		return;
	}
	
	// find next empty node
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	newnode->prev = temp;
	temp->next = newnode;

	// set new data and repeat if value is greater than 0.5
	newnode->data = temp->data * 0.5;
	if (newnode->data > 0.5)
		createList(newnode->data);
}

void List::display(bool reverse) {
	Node* ptr = head;

	// set head to last element
	if (reverse) {
		while (ptr->next != NULL)
			ptr = ptr->next;
	}

	// display all nodes
	while (ptr != NULL) {
		cout << ptr->data << " -> ";
		if (reverse)
			ptr = ptr->prev;
		else
			ptr = ptr->next;
	}
	cout << endl;
}