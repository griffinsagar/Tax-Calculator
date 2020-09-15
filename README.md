# M1OEP-Style-Errors-gsagar

## Description
This program is used to calculate personal income tax owed in the state of Vermont. The formulas used come from the [state tax tables from 2019](https://tax.vermont.gov/sites/tax/files/documents/RateSched.pdf). There are four different options for filing taxes.

1. Single *(Schedule X)*
1. Married, joint *(Schedule Y-1)*
1. Married, separate *(Schedule Y-2)*
1. Head of Household *(Schedule Z)*

Each of these four options have different base taxes, tax rates, and tax brackets. The *[main.cpp](main.cpp)* file contains a program that guides the user through entering their information. This program repeats until the user chooses to end it.

## Style choices
#### Egyptian-style braces
I like this style of braces because it reduces the number of lines required in a program. As long as the closing braces are on their own line, the indentation makes it easy enough to see where the scope starts without an extra line break. Also, I don't like the way hanging-style braces look. 

#### Camel case
I prefer camel case because it's the style I have always used for programming. When scripting or typing up small-scale programs, I find that camel case is much faster to type and read. Camel case also lends itself to using prefixes, as the prefix is the only uncapitalized word in the variable.

#### Method comments
I prefer to comment before each variable and method. This makes it easier to find how a method, variable, or other element is meant to be used in the code. By keeping the description next to the code, I can see the implementation without having to scroll. Top-of-file comments may be more efficient for simple programs, but I would still opt for method comments.

#### No variable prefixes
While variable prefixes are extremely useful for quickly finding a variable's scope, they make the variable names harder to read. Context is key for variable names, and the scope can be easily deduced by searching for places where the variable will be used. 

## Errors
####1. No match for operator \">>\" (Compiler)
This error came up when coding the `getUserInput` function. This error was caused by a lack of parentheses around the `if` clause:

    if (!cin >> variable) {
        ...
    }

By putting the `!` in front of the `cin` without parentheses, the input stream was turned into a boolean. There is no overloaded `>>` between a boolean and a string, so the program would not compile.

####2. Endless loop (Runtime)
While coding the user prompts for this program (main.cpp, Ln 46 in master branch), there was one point where the program would not accept any user input from the console. 

    getUserInput(usrStatus);
    while (usrStatus < 1 || usrStatus > 4) {
        cout << "Please enter an integer from 1-4: ";
        getUserInput(usrStatus);
    }
    
I used the debugger and found that the program was prompting for user input twice. Even though the function call would update the `usrStatus` variable, the `while` clause would call the function again. I fixed this by adding the function call into the `while` loop as a clause. 

####3. 
