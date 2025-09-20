#include <bits/stdc++.h>
using namespace std;
// to run the code ==>  g++ file_name.cpp -o a.exe && ./a.exe

/* ================================
   Part 1 --> basic , getter , setter 
   properties/attributes, methods
=================================

class Teacher {
private:
    double salary;

public:
    // properties or attributes
    string name;
    string dept;
    string subject;

    // methods or member functions
    void changeDept(string newDept) {
        dept = newDept;
    }

    // setter 
    void setSalary(double s) {
        salary = s;
    }

    // getter 
    double getSalary() {
        return salary;
    }
};

class Account {
private: // data hiding
    double balance;
    string password;

public:
    string accountId;
    string username;
};

int main() {
    Teacher t1;  // constructor called
    t1.name = "Digamber";
    t1.dept = "C++";
    t1.setSalary(25000);

    cout << t1.name << endl;
    cout << t1.getSalary() << endl;

    return 0;
}
*/

/* ================================
   Part 2 --> constructors
   (non-para, para using this, copy constructor)
=================================

class Teacher {
private:
    double salary;

public:
    string name;
    string dept;
    string subject;

    // Non-parameterized constructor
    // Teacher() {
    //     cout << "Hi, I am constructor\n";
    //     dept = "Computer Science";
    // }

    // Parameterized constructor (without this)
    // Teacher(string n, string d, string s, double sal) {
    //     name = n;
    //     dept = d;
    //     subject = s;
    //     salary = sal;
    // }

    // Parameterized constructor (with this)
    Teacher(string name, string dept, string sub, double slry) {
        this->name = name;
        this->dept = dept;
        this->subject = sub;
        this->salary = slry;
    }

    void changeDept(string newDept) {
        dept = newDept;
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main() {
    // Teacher t1; // constructor called
    // t1.name = "Digamber";
    // cout << t1.name << endl;
    // cout << t1.dept << endl;

    Teacher t1("Digamber", "CS", "C++", 25050);
    // t1.getInfo();

    Teacher t2(t1); // default copy constructor invoked
    t2.getInfo();

    return 0;
}
*/

/*================================
   Part 3 --> constructors
   ( para using this, custom copy constructor)
=================================
class Teacher {
private:
    double salary;

public:
    string name;
    string dept;
    string subject;

    // Parameterized constructor (with this)
    Teacher(string name, string dept, string sub, double slry) {
        this->name = name;
        this->dept = dept;
        this->subject = sub;
        this->salary = slry;
    }

    // customizecopy constructor
    Teacher(Teacher &orgObj) { // pass by reference 
     cout<< "I am custom copy constructor...\n" ;
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->subject = orgObj.subject;
        this->salary = orgObj.salary;
    }

    void changeDept(string newDept) {
        dept = newDept;
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main() {
    // Teacher t1; // constructor called
    // t1.name = "Digamber";
    // cout << t1.name << endl;
    // cout << t1.dept << endl;

    Teacher t1("Digamber", "CS", "C++", 25050);
    // t1.getInfo();

    Teacher t2(t1); // custom copy constructor invoked
    t2.getInfo();

    return 0;
}


*/

/*================================
   Part 4 --> constructors
   ( shallow copy and  deep copy , destructor)
=================================
*/


class Student {
public:
    string name;
    double *cgpaPtr;

    Student(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    // // shallow copy constructor
    // Student(Student &obj) {
    //     this->name = obj.name;
    //     this->cgpaPtr = obj.cgpaPtr;
       
    // }

       // deep copy constructor
    Student(Student &obj) {
        this->name = obj.name;
        cgpaPtr = new double ;
        *cgpaPtr = *obj.cgpaPtr;
       
    }

    void getInfo() {
        cout << "Name : " << name << endl;
        cout << "cgpa : " << *cgpaPtr << endl;
    }

    // Destructor to free memory
    ~Student() {
        delete cgpaPtr;   // need to delete b/c mememory allocate in heap ;
        cout<<"Hi, I delete everything\n";
    }
};

int main() {
    Student s1("Rahul Kumar", 8.9);
    Student s2(s1);  // deep copy constructor called

    s1.getInfo();
    *(s2.cgpaPtr) = 9.2 ;
    s1.getInfo();

    s2.name = "neha" ; 
    s2.getInfo();
    return 0;
}
