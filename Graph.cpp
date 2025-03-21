#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
class Node{
	public:
		char data;
		Node* next;
		Node(char x){
			data=x;
			next=NULL;
		}
};
class Graph{
	int n;
	vector<char> vertices;
	vector<vector<int>> mat;
	vector<Node*> list;
	public:
		Graph(){
			cout<<"Enter no. of vertices ";
			cin>>n;
			mat.resize(n,vector<int>(n,0));
		}
		void accept(){
			for(int i=0;i<n;i++){
				char str;
				cout<<"Enter name of vertex "<<i+1<<": ";
				cin>>str;
				vertices.push_back(str);
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					char s;
					cout<<"Is there edge from vertex "<<vertices[i]<<" to "<<vertices[j]<<" (y/n)";
					cin>>s;
					if(s=='y')
						mat[i][j]=1;
					else 
						mat[i][j]=0;
				}
			}
		}
		
		void display_mat(){
			cout<<"\n\n Ajacanecy matrix:"<<endl;
			cout<<"   ";
			for(int i=0;i<n;i++){
				cout<<vertices[i]<<"  ";
			}
			cout<<endl;
			for(int i=0;i<n;i++){
				cout<<vertices[i]<<"  ";
				for(int j=0;j<n;j++){
					cout<<mat[i][j]<<"  ";
				}
				cout<<endl;
			}
		}
		
		void display_list(){
			for(int i=0;i<n;i++){
				list.push_back(new Node(vertices[i]));
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(mat[i][j]==1){
						Node* temp=list[i];
						while(temp->next!=NULL){
							temp=temp->next;
						}
						temp->next=new Node(vertices[j]);
					}
				}
			}
			cout<<"\n\nAdjacency list:"<<endl;
			for(int i=0;i<n;i++){
				cout<<list[i]->data;
				Node* temp=list[i]->next;
				while(temp!=NULL){
					cout<<"->"<<temp->data;
					temp=temp->next;
				}
				cout<<endl;
			}
			cout<<endl;
		}
		
		void DFS(char start){
		    cout<<"DFS traversal: ";
		    int start_index=0;
		    for(int i=0;i<n;i++){
		        if(start==vertices[i])
		            start_index=i;
		    }
		    stack<int> s;
		    vector<bool> visited(n,false);
		    int index;
		    s.push(start_index);
		    visited[start_index]=true;
		    cout<<vertices[start_index]<<"  ";
		    while(!s.empty()){
		        index=s.top();
		        bool neighbour=false;
		        
		        for(int i=0;i<n;i++){
		            if(mat[index][i]==1 && !visited[i]){
		                s.push(i);
		                visited[i]=true;
		                cout<<vertices[i]<<"  ";
		                neighbour=true;
		                break;
		            }
		        }
		        if(neighbour==false){
		            s.pop();
		        }   
		    }
		    cout<<endl;
		}
		
		void BFS(char start){
		    cout<<"BFS traversal: ";
		    int start_index=0;
		    for(int i=0;i<n;i++){
		        if(start==vertices[i])
		            start_index=i;
		    }
		    queue<int> q;
		    vector<bool> visited(n,false);
		    int index;
		    q.push(start_index);
		    visited[start_index]=true;
		    while(!q.empty()){
		        int index=q.front();
		        q.pop();
		        cout<<vertices[index]<<"  ";
		        
		        for(int i=0;i<n;i++){
		            if(mat[index][i]==1 && !visited[i]){
		                q.push(i);
		                visited[i]=true;
		            }
		        }
		    }
		    cout<<endl;
		}
};
int main(){
	Graph g;
	g.accept();
	g.display_mat();
	g.display_list();
	g.DFS('A');
	g.BFS('A');
	return 0;	
}
