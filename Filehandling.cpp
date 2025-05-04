#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void insert_record(string r , string n,string d ,string a){

    fstream f;
    string name,roll,addr,div;
    f.open("sample.txt",ios::app);
    f<<r<<" "<<n<<" "<<d<<" "<<a<<endl;
    f.close();
};


void display(){
    fstream f;
    string name,roll,addr,div;
    f.open("sample.txt",ios::in);
    while (f >> roll >> name >> div >> addr ) {

    cout << "Roll No.: " << roll << "\n";
    cout << "Name: " << name << "\n";
    cout << "Division: " << div << "\n";
    cout<<"Address :"<<addr<<'\n';
    cout << "--------------------------\n";
    }
    f.close();

}

void remove_record(string roll){
    ifstream f("sample.txt");
    ofstream f2("temp.txt");
    string n,r,a,d,line;
    while (f >> r >> n >> d >> a ) {
            if (roll !=r){
                f2<<r<<" "<<n<<" "<<d<<" "<<a<<endl;               
            }
        }
    f.close();
    f2.close();
    remove("sample.txt");
    rename("temp.txt","sample.txt");
    cout<<"Record deleted Succesffully....."<<endl;
    
}

void search_record(string roll){
    fstream f;
    int flag=0;
    string r,n,d,a;
    f.open("sample.txt",ios::in);
    while(f>>r>>n>>d>>a){
        if (r==roll){
            cout<<"Record Found !!"<<endl;
            cout << "Roll No.: " << r << "\n";
            cout << "Name: " << n << "\n";
            cout << "Division: " << d << "\n";
            cout<<"Address :"<<a<<'\n';  
            flag=1; 
        }    
    }
    if (flag==0){ cout<<"Record not present";}

}

int main(){
    while(true){

        int ch;
        string name,roll,addr,div;
        cout<<"1.insert Record"<<endl;
        cout<<"2.Delete Record"<<endl;
        cout<<"3.Display Record"<<endl;
        cout<<"4.Search Record"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your Choice :";
        cin>>ch;
        
        switch(ch){
            case 1:
                cout<<"Enter Roll_No :";
                cin>>roll;
                cout<<"Enter Name :";
                cin>>name;
                cout<<"Enter Division :";
                cin>>div;
                cout<<"Enter Address :";
                cin>>addr;
                insert_record(roll,name,div,addr);
                break;
    
            case 2:
                cout<<"Enter Roll_No :";
                cin>>roll;
                remove_record(roll);
                break;
            
            case 3:
                display();
                break;
    
            case 4:
                cout<<"Enter Roll_No :";
                cin>>roll;
                search_record(roll);
                break;
            default :
                cout<<" !!! Invalid Choice !!!";

            case 5:
                exit(0);
                break;
    
        }


    }
    
    return 0;
}
