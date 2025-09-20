#include <bits/stdc++.h>
using namespace std;

/* ===================
part 1 : inheritance (base(parent) , derived(child)) , 
constructor(non paramertarized ), destructor
==================

class Person {
 public : 
 string name;
 int age ;

//  Person(string name , int age ) {
//  this->name = name ;
//  this->age = age ;
//  }

Person() {
 cout<<"parent constructor..\n";
}

~Person() {
 cout<<"parent destructor..\n";
}

};

class Student : public Person {
 public :
 int rollno ; 

 Student() {
 cout<<"child constructor..\n";
 }

  ~Student() {
 cout<<"child destructor..\n";
 }

 void getInfo() {
 cout<<"name : "<< name <<endl;
 cout<<"age : " << age << endl;
 cout<<"rollno : " << rollno <<endl;  
 }
};

int main() {
 Student s1;

 s1.name = "rahul" ; 
 s1.age = 21 ; 
 s1.rollno = 1232 ;

 s1.getInfo();

 return 0 ; 
}

*/

/* ===================
part 2 : inheritance ,
 constructor(parametarized), destructor
==================

class Person {
 public : 
 string name;
 int age ;

 // parametarized constructor
 Person(string name , int age ) {
 cout<<"parent constructor..\n";
 this->name = name ;
 this->age = age ;
 }

~Person() {
 cout<<"parent destructor..\n";
}

};

class Student : public Person {
 public :
 int rollno ; 

 // parametarized constructor 
 Student(string name, int age , int rollno) : Person( name ,  age) { // int parent only pass values not type b/c fn calling 
 cout<<"child constructor..\n";
 this->rollno = rollno;
 }

  ~Student() {
 cout<<"child destructor..\n";
 }

 void getInfo() {
 cout<<"name : "<< name <<endl;
 cout<<"age : " << age << endl;
 cout<<"rollno : " << rollno <<endl;  
 }
};

int main() {
 Student s1("rahul kumar", 22, 1232);

 s1.getInfo();

 return 0 ; 
}

*/

/* ===================
part 3 :  type of inheritance sigle , multi-level 
==================

class Person {
 public : 
 string name;
 int age ;

};

class Student : public Person {
 public :
 int rollno ; 

};

class GradeStudent : public Student{
 public:
 string researchArea;

 void getInfo() {
 cout<<"name : "<< name <<endl; 
 cout<<"age : " << age << endl;     // it gives garbage value ;
 cout<<"rollno : " << rollno <<endl;    // it gives garbage value ;
 cout<<"researchArea : " <<researchArea<<endl;
 }
};

int main() {
 GradeStudent s1;

 s1.name = "tony stark";
 s1.researchArea = "quantum physics";
 
 s1.getInfo();

 return 0 ; 
}

*/

/* ===================
part 4 :  type of inheritance multiple inheritance 
==================


class Student {
 public :
 string name;
 int rollno ; 

};

class Teacher {
 public:
 string subject;
 double salary;
};

class TA :public Student , public Teacher {
public:

 void getInfo() {
 cout<<"name : "<< name <<endl; 
 cout<<"subject : " << subject <<endl;    
 }
};

int main() {
 TA t1;

 t1.name = "tony stark";
 t1.subject = "quantum physics";
 
 t1.getInfo();

 return 0 ; 
}
*/

/* ===================
part 4 :  type of inheritance hierarchial inheritance 
==================


class Person {
 public :

 string name ;
  int age ;
};

class Student : public Person {
 public :
 int rollno ; 

};

class Teacher : public Person{
 public:
 string subject;

 void getInfo() {
 cout<<"name : "<< name <<endl; 
 cout<<"subject : " << subject <<endl;    
 }

};

int main() {
 Teacher t1;

 t1.name = "tony stark";
 t1.subject = "quantum physics";
 
 t1.getInfo();

 return 0 ; 
}
 
*/

/* ===================
part 5 : type of inheritance 
Hybrid inheritance (Person -> Student/Teacher -> GradeStudent/TA)
================== 
*/

#include <bits/stdc++.h>
using namespace std;

class Person {
public:
    string name;
    int age;
};

// virtual inheritance to avoid duplicate Person in TA
class Student : virtual public Person {
public:
    int rollno;
};

class Teacher : virtual public Person {
public:
    string subject;
};

class GradeStudent : public Student {
public:
    string researchArea;

    void getInfo() {
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "rollno : " << rollno << endl;
        cout << "researchArea : " << researchArea << endl;
    }
};

// TA inherits from both Student and Teacher
class TA : public Student, public Teacher {
public:
    string assignedCourse;

    void getInfo() {
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "rollno : " << rollno << endl;
        cout << "subject (as teacher) : " << subject << endl;
        cout << "assignedCourse : " << assignedCourse << endl;
    }
};

int main() {
    GradeStudent gs;
    gs.name = "Peter Parker";
    gs.age = 21;
    gs.rollno = 101;
    gs.researchArea = "Web Science";
    cout << "=== GradeStudent Info ===" << endl;
    gs.getInfo();

    cout << endl;

    TA ta1;
    ta1.name = "Tony Stark";
    ta1.age = 40;
    ta1.rollno = 202;
    ta1.subject = "Quantum Physics";
    ta1.assignedCourse = "CS101 - OOPs";
    cout << "=== TA Info ===" << endl;
    ta1.getInfo();

    return 0;
}
