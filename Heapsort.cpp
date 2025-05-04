#include<iostream>
#include<vector>
using namespace std;
class heap{
    vector<int> arr;
    int n;
    public:
    heap(){
        
        cout<<"Enter the number of elements: ";
        cin>>n;
        cout<<"Enter the elements: ";
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
    }
    void buildmaxheap(){
        for(int i=n/2-1;i>=0;i--){
            maxheapify(i);
        }
        cout<<"maximum element "<<arr[0]<<endl;
    }
    void maxheapify(int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && arr[left]>arr[largest])
            largest=left;
        if(right<n && arr[right]>arr[largest])
            largest=right;
        if(largest!=i){
            swap(arr[i],arr[largest]);
            maxheapify(largest);
        }
    }
    void buildminheap(){
        for(int i=n/2-1;i>=0;i--){
            minheapify(i);
        }
        cout<<"minimum element "<<arr[0]<<endl;
    }
    
    void minheapify(int i){
        int smallest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && arr[left]<arr[smallest])
            smallest=left;
        if(right<n && arr[right]<arr[smallest])
            smallest=right;
        if(smallest!=i){
            swap(arr[i],arr[smallest]);
            minheapify(smallest);
        }
    }
};
int main(){
    heap h;
    h.buildmaxheap();
    
    h.buildminheap();
    // cout<<"Min heap built successfully!"<<endl;
    return 0;
}
