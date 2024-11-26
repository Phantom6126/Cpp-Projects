#include<iostream>
#include<fstream>
using namespace std;

class dash_board{
    string id,name,author,search;
    fstream file;
    public:
    void showbooks();
    void getbooks();
    void addbooks();
}obj;

int main(){
    cout<<"\n########## WELCOME TO DIGITAL LIBRARY ##########";
    char mode;
    cout<<"\n------------------------------------------------";
    cout<<"\n    1 - Show Books";
    cout<<"\n    2 - Get Books";
    cout<<"\n    3 - Add Books";
    cout<<"\n    4 - Exit";
    cout<<"\n------------------------------------------------";
    cout<<"\nChoose any of the mode from above : ";
    cin>>mode;

    switch(mode){
        case '1':
            cin.ignore();
            obj.showbooks();
        break;
        case '2':
            cin.ignore();
            obj.getbooks();
        break;
        case '3':
            cin.ignore();
            obj.addbooks();
        break;
        case '4':
            return 0;
        break;
        default:
            cout<<"Please choose a valid mode!";
    } 
    return 0;
}

void dash_board :: addbooks(){
    cout<<"\nEnter Book ID : ";
    getline(cin,id);
    cout<<"\nEnter Book Name : ";
    getline(cin,name);
    cout<<"\nEnter Book's Author Name : ";
    getline(cin,author);

    file.open("bookdata.txt",ios :: out | ios :: app);
    file<<id<<"*"<<name<<"*"<<author<<endl;
    file.close();
}

void dash_board :: showbooks(){
    file.open("bookdata.txt",ios :: in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');

    cout<<"\n\n";
    cout<<"\t\t BOOK ID \t\t\t BOOK NAME \t\t\t BOOK'S AUTHOR"<<endl;

    while(!file.eof()){
        cout<<"\t\t "<<id<<" \t\t\t\t "<<name<<" \t\t\t "<<author<<endl;
        getline(file,id,'*');
        getline(file,name,'*');
        getline(file,author,'\n');
    }
    file.close();
}

void dash_board :: getbooks(){

    showbooks();
    cout<<"Enter Book ID : ";
    getline(cin,search);

    file.open("bookdata.txt",ios :: in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
    
    cout<<"\n\n";
    cout<<"\t\t BOOK ID \t\t\t BOOK NAME \t\t\t BOOK'S AUTHOR"<<endl;

    while(!file.eof()){
        cout<<"\t\t "<<id<<" \t\t\t\t "<<name<<" \t\t\t "<<author<<endl;
        getline(file,id,'*');
        getline(file,name,'*');
        getline(file,author,'\n');
    }
    file.close();
}
