#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *left;
		Node *right;
		Node(int x){
			data=x;
			left=NULL;
			right=NULL;
		}
};

class bst{
	public:
		Node* root;
		bst(){
			root=NULL;
		}
		
		Node* create(int x){
			root=new Node(x);
			return root;
		}
		void insert(int x,Node *root){
			Node *temp=root;
			if(x<=temp->data){
				if(temp->left==NULL){
					temp->left=new Node(x);
					cout<<x<<" Inserted at left"<<endl;
					return;
				}
				else if(temp->left!=NULL){
					cout<<"Going to left subtree"<<endl;
					insert(x,temp->left);
				}
			}
			else if(x>temp->data){
				if(temp->right==NULL){
					temp->right=new Node(x);
					cout<<x<<" Inserted at right"<<endl;
					return;
				}
				else if(temp->right!=NULL){
					cout<<"Going to right subtree"<<endl;
					insert(x,temp->right);
				}
			}
		}
		
		void insert1(int x,Node *root){
			Node *temp=root;
			while(temp!=NULL){
				if(x<=temp->data){
					if(temp->left==NULL){
						temp->left=new Node(x);
						cout<<x<<" Inserted at left"<<endl;
						return;
					}
					cout<<"Going to left subtree"<<endl;
					temp=temp->left;
				}
				else{
					if(temp->right==NULL){
						temp->right=new Node(x);
						cout<<x<<" Inserted at right"<<endl;
						return;
					}
					cout<<"Going to right subtree"<<endl;
					temp=temp->right;
				}
			}
			//cout<<x<<" Inserted"<<endl;
			temp=new Node(x);
		}
		
		void search(int x,Node* root){
			Node *temp=root;
			if(temp->data==x){
				cout<<x<<" found at root\n"<<endl;
				return;
			}
			else if(x<=temp->data){
				if(temp->left==NULL){
					cout<<x<<" does not exist in BST\n"<<endl;
					return;
				}
				else if(temp->left!=NULL){
					cout<<"Going to left subtree"<<endl;
					search(x,temp->left);
				}
			}
			else if(x>temp->data){
				if(temp->right==NULL){
					cout<<x<<" does not exist in BST\n"<<endl;
					return;
				}
				else if(temp->right!=NULL){
					cout<<"Going to right subtree"<<endl;
					search(x,temp->right);
				}
			}
		}
		
		void search1(int x,Node *root){
			Node *temp=root;
			while(temp!=NULL){
				if(temp->data==x){
					cout<<x<<" found at root\n"<<endl;
					return;
				}
				else if(x<=temp->data){
					cout<<"Going to left subtree"<<endl;
					temp=temp->left;
				}
				else if(x>temp->data){
					cout<<"Going to right subtree"<<endl;
					temp=temp->right;
				}
			}
			cout<<x<<" does not exist in BST\n"<<endl;
			
		}
		
		//just for debugging swaping
		void search2(int x,Node *root){
			Node *temp=root;
			while(temp!=NULL){
				if(temp->data==x){
					cout<<x<<" found at root\n"<<endl;
					return;
				}
				else if(x>=temp->data){
					cout<<"Going to left subtree"<<endl;
					temp=temp->left;
				}
				else if(x<temp->data){
					cout<<"Going to right subtree"<<endl;
					temp=temp->right;
				}
			}
			cout<<x<<" does not exist in BST\n"<<endl;
			
		}
		
		void swap(Node *root){
			//swap left ptr with right in all nodes
			if(root==NULL)
				return;
			Node *swap_temp=root->left;
			root->left=root->right;
			root->right=swap_temp;
			
			swap(root->left);
			swap(root->right);
		}

		int longestPath(Node* root) {
			if (root == NULL)
				return 0;
		
			int leftHeight = longestPath(root->left);
			int rightHeight = longestPath(root->right);
		
			return max(leftHeight, rightHeight) + 1;
		}
		
};
int main(){
	bst b;
	Node *root=b.create(20);
	cout<<"Root is 20"<<endl;
	cout<<endl<<"insert(30)"<<endl;
	b.insert(30,root);
	cout<<endl<<"insert(25)"<<endl;
	b.insert(25,root);
	cout<<endl<<"insert(35)"<<endl;
	b.insert(35,root);
	cout<<endl<<"insert(12)"<<endl;
	b.insert(12,root);
	cout<<endl<<"insert(15)"<<endl;
	b.insert(15,root);
	cout<<endl<<"insert(50)"<<endl;
	b.insert(50,root);
	cout<<endl<<"insert(45)"<<endl;
	b.insert(45,root);
	cout<<endl<<"insert(5)"<<endl;
	b.insert(5,root);
	cout<<endl<<"insert(20)"<<endl;
	b.insert(20,root);
	
	cout<<endl<<"************************************";
	cout<<endl<<"Inserting using loops"<<endl;
	bst b1;
	Node *root1=b1.create(20);
	cout<<"Root is 20"<<endl;
	cout<<endl<<"insert(30)"<<endl;
	b1.insert1(30,root1);
	cout<<endl<<"insert(25)"<<endl;
	b1.insert1(25,root1);
	cout<<endl<<"insert(35)"<<endl;
	b1.insert1(35,root1);
	cout<<endl<<"insert(12)"<<endl;
	b1.insert1(12,root1);
	cout<<endl<<"insert(15)"<<endl;
	b1.insert1(15,root1);
	cout<<endl<<"insert(50)"<<endl;
	b1.insert1(50,root1);
	cout<<endl<<"insert(45)"<<endl;
	b1.insert1(45,root1);
	cout<<endl<<"insert(5)"<<endl;
	b1.insert1(5,root1);
	
	cout<<endl<<"************************************";
	cout<<endl<<"searching using recursion"<<endl;
	b.search(15,root);
	b.search(50,root);
	b.search(1,root);
	
	cout<<endl<<"************************************";
	cout<<endl<<"searching using loops"<<endl;
	b1.search1(15,root1);
	b1.search1(50,root1);
	b1.search1(1,root1);
	
	cout<<endl<<"************************************";
	b1.swap(root1);
	cout<<endl<<" searching after swaping"<<endl;
	b1.search2(15,root1);
	b1.search2(50,root1);
	b1.search2(1,root1);
	
	return 0;
}



