#include<bits/stdc++.h>
using namespace std;

/* ===================
part 1 : abstract class
================== 

class Shape { // abstract class --> can create obj of abstract class
public :

 virtual void draw() = 0 ; // pure virtual fn
};

class Circle : public Shape {
 public : 
 void draw () {
 cout<<"drawing a circle ..\n";
 }
};

int main() {
 Circle c1;
 c1.draw();

 return 0 ; 
}

*/

/* ===================
part 2.1 : Static keyword
================== 
*/

/*
void fun() {
 int x = 0 ; 
 cout<<"x : "<< x << endl;
 x++;
}

int main() {
fun();    // every time gives 0 as output 
fun();
fun(); 
}
*/

/*
// part 2.2 ;
void fun() {
 static int x = 0 ;  // initial once 
 cout<<"x : "<< x << endl;
 x++;
}

int main() {
fun();    // O/P = 0 ;     due to static key word 
fun();    // O/P = 1 ;
fun();    // O/P = 2 ;
}

*/

/*
// part 2.3 ;  normal case ;
class A {
 public : 
 int x ;

 void incX() {
 x = x+1 ;
 }
};

int main() {
A obj1;
A obj2;

obj1.x = 100;
cout<<obj1.x<<endl;    // 100;
obj1.incX();
obj2.x = 200;

cout<<obj1.x<<endl;   // 101 ;

cout<<obj2.x<<endl;   // 200 ; 

return 0 ;
}

*/

// part 2.4 ;  with static case ;
class ABC {
 public : 

  ABC() {
 cout<<"constructor\n";
 }

 ~ABC() {
 cout<<"Destructor \n";
 }
};

int main() {
if(true) {
 ABC obj;    // O/P = Constru ,destru ,  end of main fn ;
}

// if(true) {
//  static ABC obj;    // O/P = Constru ,  end of main fn , destructor ;
// }
cout<<"end of main fn\n";

return 0 ;
}



