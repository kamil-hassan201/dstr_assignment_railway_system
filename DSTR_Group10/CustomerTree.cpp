#include "CustomerTree.h"

void CustomerTree::addLeftChild(Customer* parent, Customer* child)
{
	parent->left = child;

	if (child != nullptr) {
		child->parent = parent;
	}

}
void CustomerTree::addRightChild(Customer* parent, Customer* child)
{
	parent->right = child;

	if (child != nullptr) {
		child->parent = parent;
	}
}

void CustomerTree::insert(Customer* new_node)
{
	sizeOfList++;

	Customer* parent_node;
	Customer* current_node;

	if (root == nullptr) {
		root = new_node;
		return;
	}
	parent_node = nullptr;

	current_node = root;

	while (current_node != nullptr) {
		parent_node = current_node;

		if (new_node->id < current_node->id) {
			current_node = current_node->left;
		}
		else {
			current_node = current_node->right;
		}
	}

	if (new_node->id < parent_node->id) {
		addLeftChild(parent_node, new_node);
	}
	else {
		addRightChild(parent_node, new_node);
	}
}

void CustomerTree::displayInOrder(Customer* node)
{

	if (node->left != nullptr) {
		displayInOrder(node->left);
	}
	cout << "Id: " << node->id << "\tName: " << node->name << endl;

	if (node->right != nullptr) {
		displayInOrder(node->right);
	}

}

Customer* CustomerTree::search(int id)
{
	Customer* node = root;

	while (node != nullptr) {
		if (node->id == id) {
			return node;
		}
		if (id < node->id) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}

	return node;
}
