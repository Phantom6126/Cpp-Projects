#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string rollnum,name,fname,address,search;
    fstream file;
    public:
        void addstu();
        void viewstu();
        void searchstu();
}obj;

int main(){
    cout<<"####### STUDENT RECORDS MANAGEMENT ######"<<endl;
    int mode;
    cout<<"-----------------------------"<<endl;
    cout<<"1 - Add Student Record"<<endl;
    cout<<"2 - View Student Record"<<endl;
    cout<<"3 - Searh Student Record"<<endl;
    cout<<"4 - Exit"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"choose any of the option from above : ";
    cin>>mode;

    switch(mode){
        case 1:
            cin.ignore();
            obj.addstu();
        break;
        case 2:
            cin.ignore();
            obj.viewstu();
        break;
        case 3:
            cin.ignore();
            obj.searchstu();
        break;
        case 4:
            return 0;
        break;
        default:
            cout<<"Please select a valid option! ";
    }

    return 0;
}

void temp :: addstu(){

    cout<<"\nEnter Student Roll Number : ";
    getline(cin,rollnum);
    cout<<"Enter Student Name : ";
    getline(cin,name);
    cout<<"Enter Student's Father Name : ";
    getline(cin,fname);
    cout<<"Enter Student Address : ";
    getline(cin,address);

    file.open("studentdata.txt",ios :: out | ios :: app);
    file<<rollnum<<"*";
    file<<name<<"*";
    file<<fname<<"*";
    file<<address<<endl;
    file.close();
}

void temp :: viewstu(){

    file.open("studentdata.txt",ios :: in);
    getline(file,rollnum,'*');
    getline(file,name,'*');
    getline(file,fname,'*');
    getline(file,address,'\n');
    while(!file.eof()){
        cout<<"\n";
        cout<<"Student Roll Number : "<<rollnum<<endl;
        cout<<"Student Name : "<<name<<endl;
        cout<<"Student Father Name : "<<fname<<endl;
        cout<<"Student Address : "<<address<<endl;

        getline(file,rollnum,'*');
        getline(file,name,'*');
        getline(file,fname,'*');
        getline(file,address,'\n');
    }
    file.close();
}

void temp :: searchstu(){
    
    cout<<"\nEnter Student Roll Number : ";
    getline(cin,search);

    file.open("studentdata.txt",ios :: in);
    getline(file,rollnum,'*');
    getline(file,name,'*');
    getline(file,fname,'*');
    getline(file,address,'\n');
    while(!file.eof()){
        if(rollnum == search){
            cout<<"\n";
            cout<<"Student Roll Number : "<<rollnum<<endl;
            cout<<"Student Name : "<<name<<endl;
            cout<<"Student Father Name : "<<fname<<endl;
            cout<<"Student Address : "<<address<<endl;
        }

        getline(file,rollnum,'*');
        getline(file,name,'*');
        getline(file,fname,'*');
        getline(file,address,'\n');
    }
    file.close();
}
