#include<iostream> //for input and output operations
#include<fstream> //for file handling and storing data
using namespace std;

class dash_board //class "dash_board" containing all the necessary functions
{
    string username,email,password;
    string searchname,searchpass,searchemail;
    fstream file;
    public:
        void login();
        void signup();
        void forgot();
}obj;


int main(){
    char choice;
    cout<<endl;
    cout<<"########## WELCOME ##########"<<endl; //dash board of the login page 
    cout<<"\n1 - Login"; 
    cout<<"\n2 - Sign-up"; 
    cout<<"\n3 - Forgot Password";
    cout<<"\n4 - Exit";
    cout<<"\nChoose any of the mode from above : ";
    cin>>choice;

    switch(choice){
        case '1':
            cin.ignore();
            obj.login();
        break;
        case '2':
            cin.ignore();
            obj.signup();
        break;
        case '3':
            cin.ignore();
            obj.forgot();
        break;
        case '4':
            return 0; //stops the running of the code
        break;
        default:
            cout<<"Please choose a valid mode and try again!)";
    }
}
void dash_board :: signup(){  //for first time user sign up is necessary, details are stored in "logindata.txt" file
        cout<<"\n~~~~~~~~SIGN-UP~~~~~~~~";
    cout<<"\nEnter your user name : ";
    getline(cin,username);
    cout<<"\nEnter your email address : ";
    getline(cin,email);
    cout<<"\nEnter your password : ";
    getline(cin,password);

    file.open("logindata.txt",ios :: out|ios :: app);
    file<<username<<"*"<<email<<"*"<<password<<endl;
    file.close();
}
void dash_board :: login(){  //login details are verified with sign up details 
    cout<<"\n~~~~~~~~LOGIN~~~~~~~~";
    cout<<"\nEntere your user name : ";
    getline(cin,searchname);
    cout<<"\nEnter your password : ";
    getline(cin,searchpass);

    file.open("logindata.txt",ios :: in);
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'\n');
    while(!file.eof()){
        if(username==searchname){
            if(password==searchpass){
                cout<<"\nSuccessfully logined!"<<endl;
                cout<<"\nUsername : "<<username<<endl;
                cout<<"E-mail : "<<email;
            }
            else{
                cout<<"Password is incorrect!";
            }
        }
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'\n');
    }
    file.close();
}
void dash_board ::forgot(){ //gives the password for the given username and email address
    cout<<"\nEnter your username : ";
    getline(cin,searchname);
    cout<<"\nEnter your E-mail address : ";
    getline(cin,searchemail);

    file.open("logindata.txt",ios :: in);
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'\n');
    while(!file.eof()){
        if(username==searchname){
            if(email==searchemail){
                cout<<"\nAccount found!"<<endl;
                cout<<"Your password : "<<password<<endl;
            }
            else{
                cout<<"Email not found!\n";
            }
        }
        else{
            cout<<"Username not found!\n";
        }
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'\n');
    }
    file.close();
}
