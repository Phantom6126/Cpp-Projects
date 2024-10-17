#include<bits/stdc++.h>
using namespace std;

//containers in STL:
//use these templates according to requirements and time and space complexity
void explain_pair(){
    pair <int, int> p = {1,2};
    cout<<p.first<<" "<<p.second; //1 2
    cout<<endl;

    pair <int, pair<int, int>> p2 = {1, {3, 4}};
    cout<<p2.first<<" "<<p2.second.first<<" "<<p2.second.second;//1 3 4
    //cout<<p2.second; //this shows error bcoz it prints more than one element.
    cout<<endl;

    pair<int, int> arr[] = {{1,2},{3,4},{5,6}};
    cout<<arr[1].second; //4
    //cout<<arr[1]; //this shows error bcoz it prints more than one element.
    cout<<endl;

    // we cannot print more than one element i.e pairs as such.
    /*  output:
        1 2
        1 3 4 
        4
    */
}
void explain_vector(){
    vector < int > v;

    for (int i = 0; i < 10; i++) {
        v.push_back(i); //inserting elements in the vector
    }

    cout << "the elements in the vector: ";
    for (auto it = v.begin(); it != v.end(); it++){ // auto declares the datatype automatically.
        cout << * it << " ";
    }//0 1 2 3 4 5 6 7 8 9

    cout << "\nThe front element of the vector: " << v.front(); //0
    cout << "\nThe last element of the vector: " << v.back(); //9
    cout << "\nThe size of the vector: " << v.size(); //10 //if you add an element(by using methods) it redefines it's size 
    cout << "\nDeleting element from the end: " << v[v.size() - 1]; //9 // v[] accessing the last element
    v.pop_back(); //deletes the last element 

    cout << "\nPrinting the vector after removing the last element:" << endl;
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    } //0 1 2 3 4 5 6 7 8

    cout << "\nInserting 5 at the beginning:" << endl;
    v.insert(v.begin(), 5); //adding 5 at the beginning 
    //v.insert(x,y) ~ x-refers to the position.
    //                y-refers to the element to be added.

    cout << "The first element is: " << v[0] << endl; //5
    
    cout << "Erasing the first element" << endl;
    v.erase(v.begin()); //erasing or removing the first element

    cout << "Now the first element is: " << v[0] << endl; //0

    if (v.empty()) //false i.e not empty
        cout << "\nvector is empty";
    else
        cout << "\nvector is not empty" << endl;

    v.clear(); //the vector is empty now
    cout << "Size of the vector after clearing the vector: " << v.size(); //0

}
void explain_vector2(){
    vector<int> v; // created a object 'v' of class or template vector.
    vector <int> v11,v22; // we can create multiple objects at the same time.
    v.push_back(1); // adding 1 to v
    v.emplace_back(2); // adding 2 to v
    //v={1,2}
    //emplace_back() is faster than push_back()

    vector<pair<int, int>> vec; // created a object 'vec' of vector and pair.

    vec.push_back({1,2}); //we need to use curly braces for push_back in pair
    vec.emplace_back(3,4); //no need to use curly braces for emplace_back in pair

    vector<int> v1(5,100); //{100,100,100,100,100}
    vector<int> v2(3); //{0,0,0}
    vector<int> v3(v2); //{0,0,0}

    vector<int>::iterator it = v1.begin();
    it++; //it=2nd position
    cout<<*(it)<<" ";

    vector<int> v4={1,2,3,4,5};
    /*
    vector<int>::iterator it = v4.end(); //refers after last element
    //initially points after 5, later it-- points at 5.

    vector<int>::iterator it = v4.rend(); 
    vector<int>::iterator it = v4.rbegin();
    //r means reverse.so, v4={5 , 4 , 3 , 2 , 1}, this is just for an idea but it really doesn't alter v4
    //                   begin^               ^end
    */
    
    cout<<v[0]<<" "<<v.at(0)<<endl; //1 1 //i.e both works or refers the same element

    for(vector<int>::iterator it = v4.begin();it!=v4.end();it++){
        cout<<*(it)<<" ";
    }//1 2 3 4 5

    cout<<endl;

    for(auto it = v4.begin();it!=v4.end();it++){
        cout<<*(it)<<" ";
    }//1 2 3 4 5
    //'auto' automatically specifies the datatype i.e no need to specify explicitly.

    cout<<endl;
    
    for(auto it:v4){
        cout<<it<<" ";
    }//1 2 3 4 5
    //'for (type element : container)' thtis is a range-based for loop introduced in c++11.
    //range-based for loop is used for iterating over containers like arrays,vectors etc..

    v4.erase(v4.begin()+2,v4.begin()+4); // erases aacording to range
    //v4={1,2,3,4,5} => v4={1,2,5}
    //        ^ ^

    vector<int> v5{ 2 , 100 }; //{100,100}
    v5.insert( v5.begin() , 100 ); //{300,100,100}
    v5.insert( v.begin()+1 , 2 , 10 ); //{300,10,10,100,100}
    v5.insert( v5.begin() , v.begin() , v.end() ); //{1,0,300,10,10,100,100}

    //v4={1,2,5}
    //v5={1,0,300,10,10,100,100}
    v5.swap(v4); //v5={1,2,5}
                 //v4={1,0,300,10,10,100,100}

}
void explain_list(){
    list<int> ls;

    ls.push_back(2); //{2}
    ls.emplace_back(4); //{2,4}
    //difference b/w the push and emplace is - 
        //push - you need to create an temporary object.
        //emplace - it directly takes the value.

    ls.push_front(5); //{5,2,4}
    ls.emplace_front(2); //{2,5,2,4}
    //In time & space complexity - 
        // push,emplace are cheaper i.e good to use.
        // insert is costly i.e not preferable to use.

    for (int val : ls) {
        cout << val << " ";  // Prints each element of the list
    }//2 5 2 4
    cout << endl;

    //remaining functions are same as vector.
    list<int> ls2;

    ls2.begin();
    ls2.end();
    ls2.rbegin();
    ls2.rend();
    ls2.insert(ls2.begin(),3);
    ls2.clear();
    ls2.size();
    ls2.swap(ls);
    //these are few examples and many more are there....

}
void explain_deque(){
    deque<int> dq;

    dq.push_back(1); //{1}
    dq.emplace_back(2); //{1,2}
    dq.push_front(3); //{3,1,2}
    dq.emplace_front(4); //{4,3,1,2}

    dq.pop_back(); //{4,3,1} //deletes last element
    dq.pop_front(); //{3,1} //deletes first element

    for (int var : dq) {
        cout << var << " ";  // Prints each element of the deque
    }//3 1
    cout << endl;

    //remaining functions are same as vector.
    deque<int> dq2;

    dq2.begin();
    dq2.end();
    dq2.rbegin();
    dq2.rend();
    dq2.insert(dq2.begin(),3);
    dq2.clear();
    dq2.size();
    dq2.swap(dq);
    //these are few examples and many more there....

}
void explain_stack(){
    stack<int> st;
    //LIFO - last in first out
    st.push(1); //{1}
    st.push(2); //{2,1}
    st.push(3); //{3,2,1}
    st.push(3); //{3,3,2,1}
    st.emplace(5); //{5,3,3,2,1}

    //indexing is not allowed.
    cout<<st.top(); //5 //prints the top or latest element
    //st[2] is not valid i.e there are no indexes.

    cout<<endl;
    st.pop(); //{3,3,2,1} //removes or deletes the top element

    //it has less functions or methods than vector
    //the three generic functions of stack are -
        //push , pop , top

    cout<<st.top(); //3
    cout<<st.size(); //4
    cout<<st.empty(); //{}

    stack<int> st1,st2;
    st1.swap(st2);

}
void explain_queue(){
    queue<int> q;
    //FIFO - first in first out
    q.push(1); //{1}
    q.push(2); //{1,2}
    q.emplace(4); //{1,2,4}

    q.back() += 5; //{1,2,9} //altering the value of last element
    //adding 5 to the last element - {1,2,4+5} -> {1,2,9} 

    cout<<q.back(); //9
    cout<<q.front(); //1

    q.pop(); //{2,9} //removes the first element bcoz "first in first out"

    cout<<q.front(); //2

    //reamaining functions are same as stack
    queue<int> q2;
    q.size();
    q.swap(q2);
    q.empty();

}
void explain_priority_queue(){
    priority_queue<int> pq;
    // Arranges in descending order - "MAXIMUM HEAP"
    pq.push(5); //{5}
    pq.push(2); //{5,2}
    pq.push(8); //{8,5,2}
    pq.emplace(10); //{10,8,5,2}

    //the data is not stored in a linear fashion i.e it is not a linear data structure
    //the data enters in middle and it likely stores the data as trees in data structures

    cout<<pq.top(); //10 //prints the top i.e greatest element
    pq.pop(); //{8,5,2} //removes the top i.e greatest element
    cout<<pq.top(); //8

    //size,swap,empty fuctions are same as others


    priority_queue<int, vector<int>, greater<int>> pq2;
    // Arranges in ascending order - "MINIMUM HEAP"
    pq2.push(5); //{5}
    pq2.push(2); //{2,5}
    pq2.push(8); //{2,5,8}
    pq2.emplace(10); //{2,5,8,10}

    cout<<pq2.top(); //2 //prints the top i.e lowest element

}
void explain_set(){
    set<int> st;
    // Everything is "SORTED" and "UNIQUE".
    st.insert(1); //{1}
    st.insert(2); //{1,2}
    st.insert(2); //{1,2} //unique - repeated elements are not considered.
    st.insert(4); //{1,2,4}
    st.emplace(3); //{1,2,3,4} //sorted - the elements are arranged in a order by default.
    //there is no push() function
    
    //in vectors functionality of insert is same as push and emplace , it just increases the efficiency

    auto it1 = st.find(3); //it reutrns an iterator which points to the element '3'
    //st = { 1 , 2 , 3 , 4 }
    //               ^it
    auto it2 = st.find(6); //as the set doesn't have the element it returns 'st.end()'
                          //it returns an iterator which points after the last element
    //st = { 1 , 2 , 3 , 4 , }
    //                      ^it

    st.erase(3); //{1,2,4} //erases the element '5'

    int cnt = st.count(1); //1 //checks the number of elements exists with the same value i.e number of occurences
    //it does ressembles the number of occurences
    //returns 0 if no such element is present 

    auto it3 = st.find(2); //finding the element 2
    st.erase(it3); //erases the element which iterator is pointing

    st.insert(2); //adding some elements
    st.insert(3);
    st.insert(5);
    st.insert(6);
    st.insert(7);
    st.insert(8);
    
    auto it4 = st.find(6); //it4 pointing the element 6
    auto it5 = st.find(8); //it4 pointing the element 8
    st.erase(it4,it5); //{1,2,3,4,5,8} //erasing the elements from 6 to 8, including 6 and not including 8


    // lower_bound() and upper_bound() works as the same as in vectors 


    //lower_bound() 
        //lower_bound(x) returns an iterator to the first element that is greater than or equal to x.
        //If there is no such element, it returns st.end(), which is an invalid iterator for dereferencing.
    //example-1
    auto it9 = st.lower_bound(2);
    if (it9 != st.end()) {
        cout << *it9;  // If the element exists, print it
    }
    else {
        cout << "No element found greater than or equal to 10." << endl;  // Handle the case when it points to end()
    }//2

    //example-2
    auto it6 = st.lower_bound(10);
    if (it6 != st.end()) {
        cout << *it6;  // If the element exists, print it
    } else {
        cout << "No element found greater than or equal to 10." << endl;  // Handle the case when it points to end()
    }//No element found greater than or equal to 10.


    //upper_bound() 
        // It returns an iterator to the first element greater than x.
        // If x is larger than or equal to the largest element in the set, it returns st.end().
    //example-1
    auto it8 = st.upper_bound(3);
    cout<<*it8; //4 //Dereferencing it7 will give the value 4, since it7 points to 4

    //example-2
    auto it7 = st.upper_bound(9);  // Find the first element greater than 9
    if (it7 != st.end()) {
        cout << *it7;  // Dereference and print the value if the iterator is valid
    } else {
        cout << "No element found greater than 9." << endl;  // Handle case where no element is found
    }//No element found greater than 9.


    //remaining functions are same as vector.
    set<int> st2;

    st2.begin();
    st2.end();
    st2.rbegin();
    st2.rend();
    st2.insert(st2.begin(),3);
    st2.clear();
    st2.size();
    st2.empty();
    st2.swap(st);
    //these are few examples and many more are there....
}
void explain_multiset(){
    multiset<int> ms;
    // Everything is "SORTED" and "COMMON / NOT UNIQUE".
    ms.insert(1); //{1}
    ms.insert(1); //{1,1}
    ms.insert(2); //{1,1,2}
    ms.insert(2); //{1,1,2,2}
    ms.insert(2); //{1,1,2,2,2}
    ms.insert(3); //{1,1,2,2,2,3}

    ms.erase(1); //{2,2,2,3} //all the occurences of 1 are erased.

    int cnt1 = ms.count(1); //checks the number of elements exists with the same value i.e number of occurences
    cout<<cnt1; //0
    int cnt2 = ms.count(2);
    cout<<cnt2; //3
    int cnt3 = ms.count(3);
    cout<<cnt3; //1
    cout<<endl;

    ms.erase(ms.find(2)); //{2,2,3} //it deletes only one occurence , without find() it will delete all the occurences of 2
    //it erases only single '2' , in detail it deletes only the first occurence of '2'
    //it deletes only single occurence bcoz the find() function passes the address of first '2'

    auto it1 = ms.find(2);
    auto it2 = it1;
    ++it2;
    ++it2;
    ms.erase(it1,it2); //Erase the range [it1, it2) i.e "inclusive of first and exclusive of last"
    //it is erasing all the elements from "first occurence of 2" to "next two places" i.e find(2) to find(2)+2. the third place will not be erased.
    // we cannot do ms.erase(ms.find(2),ms.find(2)+2) bcoz we cannot add integers directly so we do it by incrementing onr of the iterators
    cout<<endl;
    for (auto it = ms.begin(); it != ms.end(); ++it) {
        cout << *it << " ";
    }//3 //{3} //3 is the only element in the multiset

}
void explain_unordered_set(){
    unordered_set<int> us;
    // Everything is "UNORDERED / NOT SORTED" and "UNIQUE".
    us.insert(5); //{5}
    us.insert(2); //{5,2}
    us.insert(2); //{5,2} //unique 
    us.insert(9); //{5,2,9}
    us.insert(4); //{5,2,9,4}
    us.insert(0); //{5,2,9,4,0} //not sorted

    //lower_bound(),upper_bound() functions does not work
    //remaining all functions are same as set
    //it does not store the elements in order so it has a better time complexity than set in most cases
    //except some cases when collision happens

}
void explain_map(){
    map<int,int> mp;
    // Everything is "SORTED" and "UNIQUE".
    //map < x , y > - x refers to 'key' which is 'unique' and in 'sorted order' in all the cases
    //                y refers to 'value' which 'can be common' in all the cases
    
    //type of ways to store - 

    mp[1] = 2; //similar to array
    // ^key ^value
    mp.emplace(3,1); //no need of curly brackets for emplace function
    //      key^ ^value  
    mp.insert({2,4}); //curly brackets are must
    //      key^ ^value
    
    for(auto it:mp ){
        cout<<it.first<<" "<<it.second<<endl;
    } //output - 1 2
      //         2 4
      //         3 1
    //   it.first^ ^it.second
    
    cout<<mp[1]; //2
    cout<<mp[2]; //4
    cout<<mp[3]; //1
    cout<<mp[4]; //0(null) //as there is no key with value 4 so it gives value 0 
    cout<<endl;

    auto it1 = mp.find(3); //this key,value pair exists in the map

    cout<<it1->first; //3 //key
    cout<<(*it1).first; //3 //key
    cout<<endl;

    cout<<it1->second; //1 //value
    cout<<(*it1).second; //1 //value
    cout<<endl;

    auto it2 = mp.find(5); //this key,value pair does not exist in the map

    cout<<it2->first; //4 //these are garbage or random values
    cout<<endl; 

    cout<<it2->second; //1 //these are garbage or random values
    cout<<endl;


    map<pair<int, int>, int> mpp1;
    mpp1[{2,3}] = 10;

    map<int, pair<int, int>> mpp2;
    mpp2[5] = {6,8};

}
void explain_multimap(){
    multimap<int, int> mmp;
    // Everything is "SORTED" and "COMMON / NOT UNIQUE".
    mmp.emplace(3,6);
    mmp.insert({4,7});
    // mmp[2] = 4; //we cannot use this in multimap

    //remaining is similar to map.
    //same as set and multiset difference.

}
void explain_unordered_map(){
    unordered_map<int, int> ump;
    // Everything is "UNORDERED / NOT SORTED" and "UNIQUE".

    //same as set and unordered_set difference.
    //lower_bound(),upper_bound() functions does not work
    //remaining is similar to map.
    //it does not store the elements in order so it has a better time complexity than set in most cases
    //except some cases when collision happens

}


int main(){

    // explain_pair();
    // explain_vector();
    // explain_vector2();
    // explain_list();
    // explain_deque();
    // explain_stack();
    // explain_queue();
    // explain_priority_queue();
    // explain_set();
    // explain_multiset();
    // explain_unordered_set();
    // explain_map();
    // explain_multimap();
    // explain_unordered_map();


    return 0;
}