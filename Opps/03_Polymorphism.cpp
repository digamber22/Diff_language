#include<bits/stdc++.h>
using namespace std;

/* ===================
part 1.1 :  Polymorphism --> compile time (costructor overloading);
==================

class Student {
 public :
 string name;
 
 Student() {
 cout<<"Non Parametarized constructor..\n";
 }

 Student(string name) {
 this->name = name ;
 cout<<"Parametarized constructor...\n";
 }

};


int main() {
 Student s1; // calling non parametarized constructor 
 Student s2("Digamber") ;  // parametarized constructor ;

 return 0 ; 
}
 
*/

/* ===================
part 1.2 :  Polymorphism --> compile time (function overloading);
==================

class Print {
 public :

 void show(int x) {
 cout<<"int : "<< x << endl;
 }

 void show(char ch){
 cout<<"char : " << ch << endl;
 }

};


int main() {
 Print p1; 
  p1.show('&') ;  
  p1.show(108);

 return 0 ; 
}
 
*/

/* ===================
part 1.3 :  Polymorphism --> compile time (operator overloading);
================== 

// do you own . 
class Number {
public:
    int value;

    // constructor
    Number(int v = 0) {
        value = v;
    }

    // operator= overloading
    Number& operator=(const Number& other) {
        cout << "operator= called" << endl;
        this->value = other.value;   // copy value
        return *this;                // return self reference
    }

    void show() {
        cout << "value : " << value << endl;
    }
};

int main() {
    Number a(10);   // a = 10
    Number b;       // default constructor

    b = a;          // calls overloaded operator=
    
    cout << "a : "; a.show();
    cout << "b : "; b.show();

    return 0;
}
*/

/* ===================
part 2.1 :  Polymorphism --> Run time (Function overriding );
================== 

class Parent {
public:

void getInfo() {
 cout<<"parent class ..\n";
}

};

class Child : public Parent {
public:

void getInfo() {
 cout<<"child class ..\n";
}

};


int main() {
//  Child c1;
// c1.getInfo();

Parent p1;
p1.getInfo();
    
    return 0;
}

*/

/* ===================
part 2.2 :  Polymorphism --> Run time (virtual Function overriding );
================== 

*/
class Parent {
public:

void getInfo() {
 cout<<"parent class ..\n";
}

virtual void hello () {
cout<<"hello from par \n";
}

};

class Child : public Parent {
public:

void getInfo() {
 cout<<"child class ..\n";
}


 void hello () {
cout<<"hello from child \n";
}

};


int main() {
 Child c1;
c1.hello();
 
    return 0;
}
