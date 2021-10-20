#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <string>
#include <sStream>
#include <iostream>

template <class T> class SplayTree;

template <class T>
class Node{
    public:
        Node(T);
        Node(T, Node*, Node*, Node*);
        Node(T, Node*);

        Node* add(T);
        Node* remove();
        Node* find(T);
        int size();

        Node* rot_right(Node*);
        Node* rot_left(Node*);
        Node* splay(Node*, Node*);
        Node* succesor_r();
        Node* succesor_l();
        void removeChilds();
        void print_tree(std::stringstream&) const;
        void preorder(std::stringstream&) const;
        void inorder(std::stringstream&) const;

        friend class SplayTree<T>;

    private:
        T value;
        Node *left, *right, *parent;

};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0), parent(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri, Node<T> *p): value(val), left(le), right(ri), parent(p) {}

template <class T>
Node<T>::Node(T val, Node<T> *p): value(val), left(0), right(0), parent(p) {}

template <class T>
Node<T>* Node<T>::add(T val){
    if(val>value)
        if(right != 0)
            return right -> add(val);
        else{
            right = new Node(val, this);
            return right;
        }
    else
        if(left != 0)
            return left -> add(val);
        else{
            left = new Node(val, this);
            return left;
        }
}

template <class T>
Node<T>* Node<T>::find(T val){
    if(value == val)
        return this;
    else if(val > value)
            if(right != 0)
                return right->find(val);    
            else
                return 0;
        else if(left !=0)
            return left->find(val);
            else 
                return 0;
}

template <class T>
Node<T>* Node<T>::succesor_r(){
    Node<T> *le, *ri;

    if(right == 0) return 0;

	le = left;
	ri = right;

    if(left == 0)  return ri;

	if (right->left == 0) {
		right = right->right;
		ri->right = 0;
		return ri;
	}

	Node<T> *parent, *child;
	parent = right;
	child = right->left;
	while (child->left != 0) {
		parent = child;
		child = child->left;
	}
	parent->left = child->right;
	child->right = 0;
	return child;
}

template <class T>
Node<T>* Node<T>::succesor_l(){
    Node<T> *le, *ri;

    if(left==0) return 0;

	le = left;
	ri = right;

    if(right == 0) {
        left = le->left;
        right = le->right;
        return le;
    } 
	Node<T> *parent, *child;
	parent = left;
	child = left->right;
	while (child->right != 0) {
		parent = child;
		child = child->right;
	}
	parent->right = child->left;
	child->left = 0;
	return child;
}

template <class T>
Node<T>* Node<T>::remove(){

    if (left == 0 && right != 0) {
		right->parent = parent;
        return right;
    }else if (right == 0 && left != 0) {
		left->parent = parent;
        return left;
    } else {
        Node<T> *succ = succesor_l();
        if (succ == 0) 
            succ = succesor_r();
        if(succ != 0){
            succ->left = left;
            succ->right = right;
            succ->parent = parent;
            if(succ->left != 0)
                succ->left->parent = succ;
            if(succ->right != 0)
                succ->right->parent = succ;
        }
        return succ;
    }
}

template <class T>
Node<T>* Node<T>::rot_right(Node<T>* y){
    Node<T> *x = y->left;
    
    y->left = x->right;
    if(x->right) y->left->parent = y;

    x->right = y;
    x->parent = y->parent;
    y->parent = x;

    if (x->parent)
        if ((x->parent->right) && (x->parent->value < x->value))
            x->parent->right = x;
        else
            x->parent->left = x;

    return x;
}

template <class T>
Node<T>* Node<T>::rot_left(Node<T>* x){
    Node<T> *y = x->right;

    x->right = y->left;
    if(x->right) x->right->parent = x;

    y->left = x;
    y->parent = x->parent;
    x->parent = y;

    if(y->parent)
        if((y->parent->left)&&(y->parent->value > y->value))
            y->parent->left = y;
        else
            y->parent->left = y;

    return y;
}

template <class T>
Node<T>* Node<T>::splay(Node<T> *rt, Node<T> *x){
    while(x->parent != 0){

        if(rt->value == x->parent->value)
            if(x->parent->left && x->parent->left->value == x->value)
                rot_right(rt);   //Zag
            else
                rot_left(rt);  //Zig
        else{
            Node<T>*p = x->parent; 
			Node<T>*g = p->parent;
                //Zig-Zig
            if((g->left) && (p->left) &&
                (g->left->value == p->value) && (p->left->value == x->value)){
                rot_right(g);
                rot_right(p);
            }   //Zag-Zag 
            else if((g->right) && (p->right) &&
                    (g->right->value == p->value) && (p->right->value == x->value)){
                    rot_left(g);
                    rot_left(p);
            }   //Zag-Zig
            else if((g->left) && (p->right) && 
                    (g->left->value == p->value) && (p->right->value == x->value)){
                    rot_left(p);
                    rot_right(g);
            }   //Zig-Zag
            else{
                rot_right(p);
                rot_left(g);    
            }
        }

    }
    return x;
}

template <class T>
void Node<T>::removeChilds() {
	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}

template <class T>
void Node<T>::print_tree(std::stringstream &aux) const {
	if (parent != 0){
		aux << "\n node " << value;
		aux << " parent " << parent->value;
	}else
		aux << "\n root " << value;
	if (left != 0)
		aux << " left " << left->value;
	if (right != 0)
		aux << " right " << right->value;
	aux << "\n";

	if (left != 0)  left->print_tree(aux);
	if (right != 0) right->print_tree(aux);
}


template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
	if (left != 0) left->inorder(aux);

	if (aux.tellp() != 1) aux << " ";

	aux << value;

	if (right != 0) right->inorder(aux);
}

template <class T>
class SplayTree{
    public:
        SplayTree();
        ~SplayTree();
        bool empty() const;
        void add(T);
        bool find(T);
        void remove(T);
        void removeAll();
        std::string inorder() const;
        std::string print_tree() const;
        std::string preorder() const;

    private:
        Node<T> *root;

};

template <class T>
SplayTree<T>::SplayTree() : root(0) {}

template <class T>
SplayTree<T>::~SplayTree(){
    removeAll();
}

template <class T>
bool SplayTree<T>::empty() const{
    return (root == 0);
}

template <class T>
void SplayTree<T>::removeAll() {
    if (root != 0)  root->removeChilds();
    delete root;
    root = 0;
}

template <class T>
void SplayTree<T>::add(T val){
    if(empty())
        root = new Node<T>(val);
    else{
        Node<T> *added = root -> add(val);
        root = root->splay(root, added);
    }
}

template <class T>
bool SplayTree<T>::find(T val){
    if(!empty()){
        Node<T> *found = root->find(val);
        if(found != 0) root = root->splay(root, found);
        else return -false;
        return true;
    }
    return false;
}


template <class T>
void SplayTree<T>::remove(T val){
	if(!empty()){
        Node<T> *found = root->find(val);
        if(found != 0) {
            root = root->splay(root, found);
            Node<T> *aux = root->remove();
            delete root;
            root = aux;
        }
    }
}

template <class T>
std::string SplayTree<T>::inorder() const {
    std::stringstream aux;

    aux << "[";
    if (!empty())   root->inorder(aux);

    aux << "]";
    return aux.str();
}

template <class T>
std::string SplayTree<T>::print_tree() const {
    std::stringstream aux;

    aux << "\n ================================ ";
        
    if (!empty())   root->print_tree(aux);

    aux << " ================================ \n";
    return aux.str();
}



template <class T>
std::string SplayTree<T>::preorder() const {
    std::stringstream aux;

    aux << "[";
    if (!empty())   root->preorder(aux);

    aux << "]";
    return aux.str();
}

#endif