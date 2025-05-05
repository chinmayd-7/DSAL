#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;
class Edge{
	public:
		int cost;
		int start_idx,end_idx;
		Edge(int s,int e,int x){
			start_idx=s;
			end_idx=e;
			cost=x;
		}
};
class MST{
	public:
	int n,no_of_edges;
	vector<Edge*> edges;
	vector<string> vertices;
	vector<vector<int>> mat;
	MST(){
		cout<<"Enter no. of Cities: ";
		cin>>n;
		mat.resize(n,vector<int>(n,0));
	}
	void accept(){
		for(int i=0;i<n;i++){
			string str;
			cout<<"Enter name of city "<<i+1<<": ";
			cin>>str;
			vertices.push_back(str);
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				char s;
				cout<<"\nIs there connection from "<<vertices[i]<<" to "<<vertices[j]<<" (y/n)";
				cin>>s;
				if(s=='y'){
					int weight=-1;
					cout<<"Enter weight :";
					cin>>weight;
					mat[i][j]=weight;
					mat[j][i]=weight;
					edges.push_back(new Edge(i,j,weight));
					no_of_edges++;
				}
				else{
					mat[i][j]=-1; 
					mat[j][i]=-1; 
				}		
			}
		}
	}
	
	void prims() {
		cout << "\n*Using Prims*\n";
		vector<int> visited(n, -1);
		visited[0] = 1;
		int min_cost = 0;
	
		for (int k = 0; k < n - 1; k++) {
			int min = INT_MAX;
			int row = -1, col = -1;
	
			for (int i = 0; i < n; i++) {
				if (visited[i] == 1) {
					for (int j = 0; j < n; j++) {
						if (visited[j] == -1 && mat[i][j] != -1 && mat[i][j] < min) {
							min = mat[i][j];
							row = i;
							col = j;
						}
					}
				}
			}
	
			if (min == INT_MAX) {
				cout << "Graph is not connected.\n";
				return;
			}
	
			visited[col] = 1;
			cout << vertices[row] << " -> " << vertices[col] << " (cost: " << min << ")\n";
			min_cost += min;
		}
	
		cout << "\nTotal cost of MST: " << min_cost << endl;
	}
	
	
	void kruskals(){
		cout<<"\n**Using Kruskals\n";
		vector<int> visited(n,-1);
		Edge* temp;
		int min_cost=0;
		int min,min_idx;
		for(int i=0;i<no_of_edges-1;i++){
			min=edges[i]->cost;
			for(int j=i+1;j<no_of_edges;j++){
				if(edges[j]->cost < min){
					min=edges[j]->cost;
					min_idx=j;
				}
					
			}
			temp=edges[min_idx];
			edges[min_idx]=edges[i];
			edges[i]=temp;
		}
		//for(int i=0;i<no_of_edges;i++){
		//	cout<<edges[i]->cost<<endl;
		//}
		for(int i=0;i<no_of_edges;i++){
			if(visited[edges[i]->start_idx]!=1 || visited[edges[i]->end_idx]!=1){
				min_cost=edges[i]->cost+min_cost;
				visited[edges[i]->start_idx]=1;
				visited[edges[i]->end_idx]=1;
				cout<<vertices[edges[i]->start_idx]<<"->"<<vertices[edges[i]->end_idx]<<endl;
			}
		}
		cout<<"\nCost of MST: "<<min_cost<<endl;
		
	}
};
int main(){
	MST m;
	m.accept();
	m.prims();
	m.kruskals();
	return 0;
}
