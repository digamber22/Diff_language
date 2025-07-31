//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;



public class Main {

    public static void printJava() {
        System.out.println("hello java ");
    }
    
    public static void main(String[] args) {

       /* System.out.print("Hello and welcome!");   // not give the break line when print , println->with line break;
        System.out.println("this is my first project");

         // variables;
        String namee = "digamber";
//        int umr = 30;
        String neibgr ="atul" ;

        // byte - 1 [-128 to 127 ] , short -2 , int - 4 , long - 8 , float -4 , double - 8 , char - 2 , boolean - 1 ;

        // primitive types
          byte num = 30 ;
          int phone_no = 1234567890 ;
          long phone_no2 = 12345678900L;
          float pi = 3.14f;    // may capital F instead of f ;
          char letter = '@' ;

      // non-primitive types
        String name = "Aman_clg" ;
//        String friends = new String(original: "akku") ;

        System.out.println(name.length());
        System.out.println(name.charAt(1));

        String name2 = name.replace('a','b');
        System.out.println(name2);
        System.out.println(name.substring(2,5));

 // Array
        int[] marks = new int[3] ;
        marks[0]=97;
        marks[1] = 98;
        marks[2] = 95;

        System.out.println(marks[0]);
        Arrays.sort(marks);                           // sort
        System.out.println(marks[0]);
        System.out.println(marks.length);

        int [] markss = {95 , 93  , 98};

        int[][] finalmarks ={{95,91 , 96},{88,87,89}};

        System.out.println(finalmarks[1][1]);

        // Casting
        double price = 100.00;
        double finalP = price + 18 ;
        System.out.println(finalP);

        int p = 100 ;
        int fp = p + (int)18.15 ;
        System.out.println(fp);

        // constant  -> using final ;
        final float PI = 3.14f ;
*/
        /*
        // How To take INPUT ;
         Scanner sc = new Scanner(System.in) ;
         System.out.println("INPUT Your Age: ");
         float age = sc.nextFloat();
         System.out.println(age);

         String name = sc.next();
         String sent = sc.nextLine();
//        System.out.println(name);
        System.out.println(sent);
        */

        // conditional stt

        boolean isSunUP = false;
        if(isSunUP   == true)
            System.out.println("day");
        else
            System.out.println("night");


        // LOOP

//        for(int i=0 ;i<=10; i++) {
//            System.out.println(i);
//        }

        // Do while
//        int k = 10 ;
//        do {
//            System.out.println(k);
//            k=k-1;
//        } while(k>=1);

       /*
// TRY - CATCH IN EXCEPTION HANDLING;
        int [] marks = {99, 91 , 98};
//        System.out.println(marks[5]);
        try{
            System.out.println(marks[5]);
        }catch (Exception exception){
            // do something after catching
        }

        System.out.println("The name is Aman");
*/

        // methods and functions ;

      printJava();
      printJava();

    }
}