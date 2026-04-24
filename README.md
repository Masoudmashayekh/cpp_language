# 💻 C++ Learning Journey
Welcome to my C++ learning journey! This repository documents my progress as I explore the fundamentals of programming using C++ from basic concepts to more advanced topics.

## Section 1:
A bit is the smallest unit of data in a computer and can be either 0 or 1.  
A byte is made up of 8 bits.  
10101010 = #  




C or C++ ??!!  
compiler C++ 11 , Compiler C++ 3
C => K & R book
ansi => C 90 , C 99

C++11, C++14, C++17, C++20  

- Trust the Programmer
  

### Type system:
  

### Work's steps:  
- What ???  
- How ???  
- Use Code Editor
- Use file with .cpp

### C++ compilers:
- GCC
- Clang
- MSVC
- Intel C++ Compiler
- MinGW-w64
  
### C++ structure:
 - Every statement must end with a semicolon ;
 - A valid C++ program must have a function named main() because execution always starts there.
 - use // for single-line comments.   
 // → single-line comment  
 /* ... */ → multi-line comment  
   
## Section 2:

- int x = 5; => int is integer
- double y = 4.8; => double is a floating-point data type used to store decimal (real) numbers.  
- int a=5 , b=4; // all should be integer  
int s, g;  

- int should be descriptive:  int age = 20; not int x = 20;
- C++ is case sensitive:     
In C++, uppercase and lowercase letters are treated as different characters, so:  
r ≠ R  
sum ≠ Sum ≠ SUM  
- In C++, camelCase is commonly used, but it’s not a strict rule and not “everyone uses it”.  
camelCase: userAge, totalScore, calculateSum()  
  
- An object helps us access data (values) and functions defined in a class.  
int x=5;  
int → data type (what kind of value it stores: integer)  
x → identifier (variable name)  
5 → value (literal constant)  
  
int a; // default initialization  
int b = 5; // copy initialization  
int c(6); // direct initialization - can not use for list    
int d{7}; // uniform initialization  
- code-runner.executor => settings.json => add => -std=c++11
  
- std::endl vs "\n":  
std::endl → newline + flush (slower)   
"\n" → just newline (faster, preferred in most cases)  

- In C++, std::cin and std::cout are the standard input and output objects used for basic console interaction.  
cout → Character out  
cin → Character in  
  
using namespace std; // It allows you to avoid writing std:: every time.

- int x; → declares variable (but value is random ❌)  
int x = 0; or int x{0}; → safe initialization ✔  
initializing variables helps prevent bugs ✔   

- Operators in C++:  
+   // addition
-   // subtraction
*   // multiplication
/   // division
%   // modulus (remainder)
=   // assign
+=  // add and assign
-=  // subtract and assign
*=  // multiply and assign
/=  // divide and assign
==  // equal
!=  // not equal
>   // greater
<   // less
>=  // greater or equal
<=  // less or equal
&&  // AND
||  // OR
!   // NOT
++  // increase by 1
--  // decrease by 1
## Operators in C++

| Operator | Description              |
|----------|--------------------------|
| +        | Addition                 |
| -        | Subtraction              |
| *        | Multiplication           |
| /        | Division                 |
| %        | Modulus (remainder)      |
| =        | Assign                   |
| +=       | Add and assign           |
| -=       | Subtract and assign      |
| *=       | Multiply and assign      |
| /=       | Divide and assign        |
| ==       | Equal                    |
| !=       | Not equal                |
| >        | Greater                  |
| <        | Less                     |
| >=       | Greater or equal         |
| <=       | Less or equal            |
| &&       | Logical AND              |
| \|\|     | Logical OR               |
| !        | Logical NOT              |
| ++       | Increment (increase by 1)|
| --       | Decrement (decrease by 1)|