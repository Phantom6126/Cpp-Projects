#include<iostream>
#include<cmath>
using namespace std;

int main(){
    cout<<"~~~~~~~~ AREA CALCULATOR ~~~~~~~~"<<endl;
    int choice;
    float area,radius,length,width;

    cout<<"1 - Area of Circle"<<endl;
    cout<<"2 - Area of Rectangle"<<endl;
    cout<<"3 - Area of Square"<<endl;
    cout<<"Enter Your Choice : ";
    cin>>choice;

    switch(choice){
        case 1:
            cout<<"\nEnter the Radius of the Circle : ";
            cin>>radius;
            area = 3.14 * pow(radius,2);
        break;

        case 2:
            cout<<"\nEnter the Length of the Rectangle : ";
            cin>>length;
            cout<<"Enter the Width of the Rectange : ";
            cin>>width;
            area = length * width;
        break;

        case 3:
            cout<<"\nEnter the Length of the Side of Square : ";
            cin>>length;
            area = pow(length,2);
        break;

        default:
            cout<<"\nInvalid choice...!";
    }
    cout<<"\nArea : "<<area<<endl;
    return 0;
}
