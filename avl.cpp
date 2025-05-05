#include<iostream>
#include<cmath>
#include<string>
using namespace std;

class Node{
	public:
		char key;
		string meaning;
		Node *left,*right;
		int bf;
		Node(char x,string y){
			key=x;
			meaning=y;
			bf=0;
			left=right=NULL;
		}
};

class AVL{

	public:
		Node *root=NULL;
		void create(){
			cout<<"Enter keyword: ";
			char x;
			cin>>x;
			cout<<"Enter meaning: ";
			string y;
			cin>>y;
			root=new Node(x,y);
		}
		
		Node* insert(char x,string y,Node *&temp){
			if(temp==NULL){
				//cout<<"\ninserted";
				return new Node(x,y);
			}
			else if(x<=temp->key){
				//cout<<"\nleft";
				temp->left=insert(x,y,temp->left);
			}
			else{
				//cout<<"\nright";
				temp->right=insert(x,y,temp->right);
			}
			
			temp->bf=height(temp->left)-height(temp->right);
			
			if (temp->bf > 1 && x < temp->left->key)  // LL case
            			return LL(temp);
        		if (temp->bf < -1 && x > temp->right->key) // RR case
            			return RR(temp);
        		if (temp->bf > 1 && x > temp->left->key)  // LR case
            			return rotateLeftRight(temp);
        		if (temp->bf < -1 && x < temp->right->key) // RL case
            			return rotateRightLeft(temp); 
			return temp;
		}
		
		Node* LL(Node* x) {  
       			Node* y = x->left;
        		Node* T2 = y->right;
        		y->right = x;
        		x->left = T2;
        		y->bf = height(y->left) - height(y->right);
        		x->bf = height(x->left) - height(x->right);
        		return y;
   		 }
    
    		Node* RR(Node* x) {
        		Node* y = x->right;
        		Node* T2 = y->left;
        		y->left = x;
        		x->right = T2;
        		x->bf = height(x->left) - height(x->right);
        		y->bf = height(y->left) - height(y->right);
        		return y;
    		}
    
    		Node* rotateLeftRight(Node* node) {
        		node->left = RR(node->left);
        		return LL(node);
    		}
    
    		Node* rotateRightLeft(Node* node) {
        		node->right = LL(node->right);
        		return RR(node);
    		}

		int height(Node *node){
			if(node==NULL)
				return 0;
			return max(height(node->left),height(node->right))+1;
		}
		
		void display_asc(Node *temp){
			if(!temp)
				return;
			display_asc(temp->left);
			cout<<temp->key<<" : "<<temp->meaning<<"  (Balance factor : "<<temp->bf<<")"<<endl;
			display_asc(temp->right);
		}
		void display_des(Node *temp){
			if(!temp)
				return;
			display_des(temp->right);
			cout<<temp->key<<" : "<<temp->meaning<<"  (Balance factor : "<<temp->bf<<")"<<endl;
			display_des(temp->left);
		}
		
		void search(char key,Node *temp) {
        		while (temp != NULL) {
            			if (key < temp->key) {
                			temp = temp->left;  // Search left subtree
            			}
            			else if (key > temp->key) {
                			temp = temp->right;  // Search right subtree
            			}
            			else {
                			cout << "Keyword found: " << temp->key << " : " << temp->meaning << endl;
                			return;  // Found the keyword
            			}
        		}
        		cout << "Keyword not found." << endl;  // Keyword not found
    		}
		
			Node* deleteNode(Node* root, char key) {
				if (!root) return root;
			
				// Step 1: Perform standard BST deletion
				if (key < root->key)
					root->left = deleteNode(root->left, key);
				else if (key > root->key)
					root->right = deleteNode(root->right, key);
				else {
					// Node with only one child or no child
					if (!root->left || !root->right) {
						Node* temp = root->left ? root->left : root->right;
						if (!temp) {
							temp = root;
							root = nullptr;
						} else
							*root = *temp;
						delete temp;
					} else {
						// Node with two children: Get inorder successor
						Node* temp = minValueNode(root->right);
						root->key = temp->key;
						root->meaning = temp->meaning;
						root->right = deleteNode(root->right, temp->key);
					}
				}
			
				if (!root) return root;
			
				// Step 2: Update balance factor
				root->bf = height(root->left) - height(root->right);
			
				// Step 3: Balance the tree
				if (root->bf > 1 && balanceFactor(root->left) >= 0)
					return LL(root);
				if (root->bf > 1 && balanceFactor(root->left) < 0)
					return rotateLeftRight(root);
				if (root->bf < -1 && balanceFactor(root->right) <= 0)
					return RR(root);
				if (root->bf < -1 && balanceFactor(root->right) > 0)
					return rotateRightLeft(root);
			
				return root;
			}
			Node* minValueNode(Node* node) {
				Node* current = node;
				while (current && current->left != NULL)
					current = current->left;
				return current;
			}			
};
int main(){
	AVL tree;
	int flag=1;
	while(flag){
		cout<<"Enter choice\n1.Add keyword\n2.Search keyword\n3.display in ascending order\n4.display in descending order\n5.exit\n";
		int ch;
		cin>>ch;
		switch(ch){
			case 1:
				{
					if(tree.root==NULL){
						tree.create();
					}
					else{
						cout<<"Enter keyword: ";
						char x;
						cin>>x;
						cout<<"Enter meaning: ";
						string y;
						cin>>y;
						tree.root=tree.insert(x,y,tree.root);
					}
					break;
				}
			case 2:
				{
					cout<<"Enter key to search :";
					char x;
					cin>>x;
					tree.search(x,tree.root);
					break;
				}
			case 3:
				tree.display_asc(tree.root);
				break;
			case 4:
				tree.display_des(tree.root);
				break;
			case 5:
				flag=0;
				break;
		}
	}
	//tree.balance_factor(tree.root);
	
	return 0;
}
