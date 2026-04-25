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
 - use `//` for single-line comments.   
 `//` → single-line comment  
 `/* ... */` → multi-line comment  
   
## Section 2:

- `int x = 5;` => `int` is integer
- `double y = 4.8;` => `double` is a floating-point data type used to store decimal (real) numbers.  
- `int a=5 , b=4;` // all should be integer  
`int s, g;`  

- int should be descriptive:  `int age = 20;` not `int x = 20;`
- C++ is case sensitive:     
In C++, uppercase and lowercase letters are treated as different characters, so:  
`r ≠ R`  
`sum ≠ Sum ≠ SUM`  
- In C++, camelCase is commonly used, but it’s not a strict rule and not “everyone uses it”.  
camelCase: `userAge`, `totalScore`, `calculateSum()`  
  
- An object helps us access data (values) and functions defined in a class.  
`int x=5;`  
`int` → data type (what kind of value it stores: integer)  
`x` → identifier (variable name)  
`5` → value (literal constant)  
  
`int a;` // default initialization  
`int b = 5;` // copy initialization  
`int c(6);` // direct initialization - can not use for list    
`int d{7};` // uniform initialization  
- code-runner.executor => settings.json => add => `-std=c++11`
  
- `std::endl` vs `"\n"`:  
`std::endl` → newline + flush (slower)   
`"\n"` → just newline (faster, preferred in most cases)  

- In C++, std::cin and std::cout are the standard input and output objects used for basic console interaction.  
`cout` → Character out  
`cin` → Character in  
  
`using namespace std;` // It allows you to avoid writing std:: every time.

- `int x;` → declares variable (but value is random ❌)  
`int x = 0;` or `int x{0};` → safe initialization ✔  
initializing variables helps prevent bugs ✔   

#### Operators in C++

| Operator | Description               |
|----------|---------------------------|
| +        | Addition                  |
| -        | Subtraction               |
| *        | Multiplication            |
| /        | Division                  |
| %        | Modulus (remainder)       |
| =        | Assignment                |
| +=       | Add and assign            |
| -=       | Subtract and assign       |
| *=       | Multiply and assign       |
| /=       | Divide and assign         |
| ==       | Equal to                  |
| !=       | Not equal to              |
| >        | Greater than              |
| <        | Less than                 |
| >=       | Greater than or equal to  |
| <=       | Less than or equal to     |
| &&       | Logical AND               |
| \|\|     | Logical OR                |
| !        | Logical NOT              |
| ++       | Increment (increase by 1) |
| --       | Decrement (decrease by 1) |


#### Operator Types in C++

| Type    | Operands | Example                          |
|---------|---------|----------------------------------|
| Unary   | 1       | `-5`                             |
| Binary  | 2       | `15 - 5`                         |
| Ternary | 3       | `age >= 18 ? "Adult" : "Minor"`  |  

#### Expression Components in C++

| Component        | Description                          | Example        |
|------------------|--------------------------------------|----------------|
| Values (literals)| Fixed values written directly        | `5`, `3.14`    |
| Variables        | Named storage holding values         | `x`, `age`     |
| Operators        | Perform operations on values         | `+`, `-`, `*`  |
| Function calls   | Execute functions that return values | `sum(a, b)`    |  
  


## Section 3:

#### Types of Functions in C++

| Type              | Description                              | Example              |
|------------------|------------------------------------------|----------------------|
| Predefined        | Built-in functions provided by C++       | `sqrt(25)`          |
| User-defined      | Functions created by the programmer      | `int add(int a, int b)` |
| Void function     | Function that returns no value           | `void show()`       |
| Parameterized     | Function that takes input values         | `add(5, 3)`         |
| Non-parameterized | Function with no input parameters        | `show()`            |
| Recursive         | Function that calls itself               | `factorial(n)`      |  
  
#### Parts of a Function in C++

| Part         | Description                          | Example              |
|--------------|--------------------------------------|----------------------|
| Return type  | Type of value returned               | `int`, `void`       |
| Function name| Name of the function                 | `add`, `sum`        |
| Parameters   | Input values                         | `(int a, int b)`    |
| Function body| Code inside the function            | `{ return a + b; }` |
| Return       | Sends value back to caller          | `return a + b;`     |  
  
`int` → function gives back a number  
`void` → function gives nothing back  
`x` → parameter `int x = 10;`  
`10` → argument  
The number of arguments must match the number of parameters in most cases.    
  
- Local variable = variable that lives only inside a function/block  
- Global variable = variable that lives entire program  
  

#### Why Functions Help Organize Code

| # | Concept        | Description                                                                 | Example                                      |
|---|---------------|-----------------------------------------------------------------------------|----------------------------------------------|
| 1 | Reusability   | Write code once, use it many times.                                        | A function to calculate the sum of two numbers |
| 2 | Readability   | Breaking a program into smaller functions makes it easier to understand.    | Splitting logic into clear, named functions   |
| 3 | Maintainability | Update code in one place instead of everywhere.                           | Fix a bug inside one function only            |
| 4 | Modularity    | Each function handles a specific task, keeping code structured and clean.   | Separate functions for input, processing, output |  
  
- Declaration → “It exists”
- Definition → “Here’s the code”
- Forward Declaration → “You’ll see it later
  
- Compile and Run C++ from Terminal: `g++ draft_6.cpp` and `./a.out` 