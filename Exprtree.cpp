#include<iostream>
#include<string>
#include<cctype>
using namespace std;
class Node{
    public:
        string data;
        Node *left,*right;
            
        Node(char x){
                data=x;
                left=NULL;
                right=NULL;
        }
};
class stack{
	int size=30;
   Node* stk[30];
     int top=-1;
    public:
        void push(Node* newNode){
                if(!isfull())
            stk[++top]=newNode;
      }
      Node* pop(){
            	if(!isempty())
                    return stk[top--];
      } 
      	Node* seek(){
      		if(!isempty())
                    return stk[top];
      	} 
      	bool isfull(){
      			return top==size-1;
      }
      bool isempty(){
      			return top==-1; 
      }         
};
class Tree{
	stack s,s1;
	public:
		void exprTree(string prefix_expr){
			for(int i=prefix_expr.size()-1;i>=0;i--){
				if(isalpha(prefix_expr[i])){
					s.push(new Node(prefix_expr[i]));
				}
				else{
					Node* top=new Node(prefix_expr[i]);
					top->left=s.pop();
					top->right=s.pop();
					s.push(top);
				}
			}
			cout<<"Expression tree built"<<endl;
		}
		
		void postorder(){
			while(!s.isempty()){
				Node* node=s.pop();
				s1.push(node);
				if(node->left) s.push(node->left);
				if(node->right) s.push(node->right);
			}
			cout<<"Postorder traversal:"<<endl;
			while(!s1.isempty()){
				Node* node=s1.pop();
				cout<<node->data<<"   ";
			}
			cout<<endl;
		}
		void preorder(){
			preorder_traversal(s.seek());
		}
		void preorder_traversal(Node* node){
			if(node==NULL)
				return;
				
			cout<<node->data<<"   ";
			preorder_traversal(node->left);
			preorder_traversal(node->right);
		}
};

int main(){
	Tree t;
	t.exprTree("+--a*bc/def");
	cout<<"Preorder traversal :"<<endl;
	t.preorder();
	cout<<endl;
	t.postorder();
	return 0;
	
}
