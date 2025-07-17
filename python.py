# print values 
print("Hellow Word")
name = "Digamber"
age = 22 
print(name)
is_adult=True 

# taking input 
""" 6 """

""" old_age = input("input your age : ")
old_age = int(old_age)
new_age = old_age + 12 
print("new age is :" )
print(new_age) """

#conversion values 
int()
float()
str()
bool()

# differents methods of string ;
""" name = "DIgamBER kumar "
print(name.lower()); print(name.upper()); print(name.find('k')) ; print(name.find("kumar")) ; print(name.replace("kumar", "bosak"))
print(name)
 """
""" # operators
print(5/2)
print(5//2)   #  this use to remove digits after decimal 

age = 20       
if age >= 18:           # if-else statement 
    print("you are an adult ")
    print ("You can vote")

elif age < 18 and age > 3:
    print("you are in school")

else :
    print("you are a child")         

print ("thank you")     """

 # range 
"""
numbers = range(5)
print(numbers)      # o/p = (0,5)   5 is excluded  """

#loop
""" i=1
while i<=5:
    print(i * "*")
    i=i+1

for i in range(5):
    print(i+1) """

#
marks = [95, 98 , 97 , 96 , 99]
""" print(marks)
print(marks[0])
print(marks[-2])    # this print from right side e.i 96
print(marks[1:3])   # this will print marks on index 1, 2 but it exclude index 3 

for i in marks:
    print(i) """

# append, insert 
""" marks.append(100) 
print(marks)

marks.insert(0, 102)
print(marks)

print(93 in marks)

print(len(marks))     # o/p = 7 

i=0
while i < len(marks):
    print(marks[i])
    i+=1

marks.clear()
print(marks) """

""" students = ["ram", "shyam", "kishan", "radha", "radhika"]

for i in students:
    if i=="radha" :
        break
    elif i=="kishan":
        continue
    
    print(i) """

# tuple  -> we can not change it like can't insert, 
""" marks =(95, 98, 97 ,97 , 97 )   
print(marks.index(97))
print (marks.count(97)) """

# [] -> for list , {} -> set , () ->tuple ,in tuple () this bracket is optional ;

# set
""" marks = {95, 98 , 97 , 97 , 97 }
for i in marks:
    print(i) """
# dictonary
""" marks = {"englisn" : 95 , "chemisty" : 98}
marks["physics"] = 99
print(marks["chemisty"])    # o/p = 98
print(marks)
 """
# functions  -> 3 type -> in-built fn , module fn , user-defined fn ; 
""" in-built fn -> str() , int() , bool()
module fn -> math module 
user-defined fn ->  """
 
from math import * 
print(sqrt(16))

# user-defined fn 

def print_sum(first, second):
    print(first+second)

print_sum(1,2)

