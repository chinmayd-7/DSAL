#include<iostream> #include<string> using namespace std; 

class node{  	public: 

 	 	int count;  	 	node* childs[10];  	 	string label;  	 	node(string x){ 

 	 	 	label=x; 

 	 	} 

}; 

class tree{  	public: 

 	 	node* root;  	 	tree(){  	 	 	root=NULL; 

 	 	} 

 	 	void create(){ 

 	 	 	string name; 

 	 	 	cout<<"Enter name of book"<<endl; 

 	 	 	cin>>name; 

 	 	 	root=new node(name); 

 	 	 	 

 	 	 	cout<<"Enter no. of chapters"; 

 	 	 	cin>>root->count; 

 	 	 	 

 	 	 	for(int i=0;i<root->count;i++){  	 	 	 	cout<<"Enter name of chapter"<<i+1<<endl; 

 	 	 	 	string x; 

 	 	 	 	cin>>x; 

 	 	 	 	root->childs[i]=new node(x); 

 	 	 	 	cout<<"Enter no. of sections in chapter"<<i+1<<endl; 

 	 	 	 	cin>>root->childs[i]->count; 

 	 	 	 	for(int j=0;j<root->childs[i]->count;j++){ 

 	 	 	 	 	cout<<"Enter name of section"<<j+1<<endl; 

 	 	 	 	 	string y; 

 	 	 	 	 	cin>>y; 

 	 	 	 	 	root->childs[i]->childs[j]=new node(y);  	 	 	 	 	cout<<"Enter no. of subsections in section"<<j+1<<endl; 

 	 	 	 	 	cin>>root->childs[i]->childs[j]->count; 

 	 	 	 	 	for(int k=0;k<root->childs[i]->childs[j]->count;k++){ 

 	 	 	 	 	 	cout<<"Enter name of subsection"<<k+1<<endl;  	 	 	 	 	 	string z; 

 	 	 	 	 	 	cin>>z; 

 	 	 	 	 	 	root->childs[i]->childs[j]->childs[k]=new node(z); 

 	 	 	 	 	} 

 	 	 	 	} 

 	 	 	} 	  	 	} 

 

 	 	void display(){ 

 	 	 	int ht=0; 

   cout<<"Root node:"<<root->label<<endl;    cout<<root->label<<"-";    for(int i=0;i<root->count;i++){ 

 	 	 	 	cout<<root->childs[i]->label<<"-"; 

 	 	 	} 

 	 	 	cout<<endl; 

 	 	 	for(int i=0;i<root->count;i++){  	 	 	 	cout<<root->childs[i]->label<<"-";  	 	 	 	for(int j=0;j<root->childs[i]->count;j++){ 

 	 	 	 	 	cout<<root->childs[i]->childs[j]->label<<"-"; 

 	 	 	 	} 

 	 	 	 	cout<<endl; 

 	 	 	} 

 	 	 	for(int i=0;i<root->count;i++){ 

 	 	 	 	if(ht<1) 

 	 	 	 	ht=1; 

 	 	 	 	for(int j=0;j<root->childs[i]->count;j++){ 

 	 	 	 	 	if(ht<2) 

 	 	 	 	 	ht=2; 

 	 	 	 	 	cout<<root->childs[i]->childs[j]->label<<"-"; 

 	 	 	 	 	for(int k=0;k<root->childs[i]->childs[j]->count;k++){ 

 	 	 	 	 	 	if(ht<3) 

 	 	 	 	 	 	ht=3; 

 	 	 	 	 	 	cout<<root->childs[i]->childs[j]->childs[k]->label<<"-

"; 

 	 	 	 	 	} 

 	 	 	 	 	cout<<endl; 

 	 	 	 	} 

 	 	 	} 

 

 	 	 	cout<<"Height of tree:"<<ht<<endl; 

 	 	} 

}; 

int main(){ 

 	tree t;  	int flag=1;  	while(flag==1){ 

  cout<<"Enter choice\n1.Create\n2.display\n3.Exit"<<endl;   int ch;   cin>>ch; 

 	 	switch(ch){  	 	 	case 1: 

 	 	 	 	t.create(); 

 	 	 	 	break;  	 	 	case 2: 

 	 	 	 	t.display(); 

 	 	 	 	break;  	 	 	case 3:  	 	 	 	flag=0; 

 	 	 	 	break; 

 	 	} 

 	} 

 	return  0; 

} 

