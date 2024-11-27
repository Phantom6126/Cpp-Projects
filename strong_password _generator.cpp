#include<iostream> // for input and output operations
#include<cstdlib> // for rand() function , for random number
#include<ctime> // for present time , for random numer
#include<string> // for string manipulation and variables
using namespace std;

string getpassword(int length){
    string password = "";
    string characters = "aquickbrownfoxjumpsoverthelazydogAQUICKBROWNFOXJUMPSOVERTHELAZYDOG0123456789";
    int charsize = characters.size();
    srand(time(0)); // gets a random number based on the time 
    int randomindex;
    for(int i=0;i<length;i++){
        randomindex = rand() % charsize; // getting the index of characters in range of 0 to charsize
        password = password + characters[randomindex]; // adding each character to the string "password"
    }
    return password;
}

int main(){
    cout<<"~~~~~~~ PASSWORD GENERATOR ~~~~~~~"<<endl;
    int length;
    cout<<"\nEnter the Length of the Password : ";
    cin>>length;
    string password = getpassword(length);
    cout<<"Generated Password : "<<password;

    return 0;
}
