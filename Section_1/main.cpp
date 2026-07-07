// Single line comment

/*
Multi
Line
Comment
*/

/*
General:
    - Run code w/ 'g++ main.cpp -o newName'
        - With every added .cpp file, you'll need to include them after g++ for example
        'g++ main.cpp basicCalc.cpp -o main'
        - To execute code ./main
    - Notice how on occasion the '::' operator is used? This is called the scope resolution operator. It tells the
    preprocessor where to find the function / variable. std is the standard namespace, it defines a bunch of
    variables and functions that will be used throughout the code.
    - TOD0: Come back and handle improper user inputs!
*/

#include <iostream> // stands for input / output library
// DO NOT INCLUDE .CPP FILES! You can get all kinds of weird collisions (includes, funcs, etx)
// Instead include a header file, they end in '.h'
#include "basicCalc.h" // user defined files are "" base cpp libraries are in <>
// Do not use 'using namespace std' this may make the scope resolution operator unnecessary, but it can cause
// collisions in large code bases. Okay for small projects.
#include <string>

// Let's pretend that exampleFunction used to take an integer parameter, later on we deemed this non-essential.
// We have a whole bunch of existing function calls that have the parameter filled in. Don't change them!
// Leave a hanging type with no name, it will accept a func call that has that param blank, AND filled out.
void exampleFunction(int)
{
    std::cout << "Welcome to my simple calculator program..." << std::endl;
    return; // not necessary to exit function but allowed. may be useful to exit early.
}
int exFuncReturn()
{
    std::cout << "Calculator is functioning and ready to go, returning a value of 1..." << std::endl;
    return 1; // functions can ONLY return one value.
}
void exFuncParam(int param)
{
    std::cout << "Calibrating, the number given is: " << param << std::endl;
}
void exFunc3Params(int param1, int param2, int param3)
{
    std::cout << "Calibrating, the numbers given are: " << param1 << ", " << param2;
    std::cout << ", and " << param3 << std::endl;
}

// Notice all the short functions at the top, for long functions you can define them below where they are called
// and then forward declare them.

// The int main() function is the entry point of the program
// Always returns of type int, 0 means successful termination
// Other numbers signify an error, no standard way to handle accross OS. Just use 0.
// Main cannot be explicitly called
int main()
{
    // Ways to initialize a variable
    int defaultAge;                                     // default init
    int copyInitAge = 25;                               // copy init
    int directInitAge(25);                              // direct init
    int directListInitAge{25};                          // direct list init
    int zeroInitAge{};                                  // zero init
    int chain1Age = 20, chain2Age = 25, chain3Age = 30; // chain init
    // Add the const variable to any init type to make a literal- an unchangeable var
    const int versionNum = 1;

    // Notice how defaultAge outputs a random value, this is why init a var w/ a value is prefered.
    // Even if it is zero!
    std::cout << "Let's list all of the initialized variables... " << defaultAge << " "; // cout outputs texts
    // queued the line above, no endline
    std::cout << copyInitAge << " " << directInitAge << " " << directListInitAge << " ";
    // queued the line above, no endline
    std::cout << zeroInitAge << " " << chain1Age << " " << chain2Age << " " << chain3Age << std::endl;
    // flush everything queued, endline seen. Could have used the new line character ('/n') to queue
    // output happens for two reasons, flush is called (endline calls flush), or output queue gets full
    // the << operator is called the insertion operator

    std::cout << "Let's make a simple calculator to demonstrate section 1...\n"
              << std::flush; // another way to flush queue w/o endl

    // Types of operators:
    // Unary, only the - or negative sign
    // Binary, operation between two values
    // Ternary, operation between three values only one will be mentioned w/ conditionals
    // Nullary, only the throw operator will be mentioned w/ error handling

    std::cout << "\n";
    exampleFunction(0);
    exFuncReturn();
    exFuncParam('a');
    exFunc3Params('a', 'b', 'c');

    std::cout << "\n";

    std::cout << "You can add 1 + 2 ... " << add(1, 2) << std::endl;
    std::cout << "You can subtract 10 - 4... " << subtract(10, 4) << std::endl;
    std::cout << "You can multiply 20 * 10... " << multiply(20, 10) << std::endl;
    std::cout << "You can divide 100 / 5.... " << divide(100, 5) << std::endl;
    std::cout << "You can iter up 50... " << iterUp(50) << std::endl;
    std::cout << "You can iter down 50... " << iterDown(50) << std::endl;
    std::cout << "You can self multiply 100... " << multiplySelf(100) << std::endl;
    std::cout << "You can self divide 100... " << divideSelf(100) << std::endl;

    std::cout << "\n";
    std::cout << "Alright, your turn!" << std::endl;
    std::string userInput = "";
    int operand1 = -999;
    int operand2 = -999;
    std::string operation = "";
    char exit = 'n';

    while (true)
    {
        std::cout << "\nWould you like to exit? (y/n): ";
        std::cin >> exit;
        if (exit == 'Y' || exit == 'y')
        {
            break;
        }
        while (operand1 == -999)
        {
            std::cout << "\nPlease enter an operand: ";
            std::cin >> operand1;
        }
        while (operation == "")
        {
            std::cout << "\nPlease pick an operation: " << std::endl;
            std::cout << "(+, -, *, /, ++, --, *=, or /=)" << std::endl;
            std::cout << "Your choice: ";
            std::cin >> operation;
        }

        if (operation == "++")
        {
            std::cout << "Iter Up: " << iterUp(operand1) << std::endl;
            operand1 = -999;
            operation = "";
            continue;
        }
        else if (operation == "--")
        {
            std::cout << "Iter Down: " << iterDown(operand1) << std::endl;
            operand1 = -999;
            operation = "";
            continue;
        }
        else if (operation == "*=")
        {
            std::cout << "Self Multiply: " << multiplySelf(operand1) << std::endl;
            operand1 = -999;
            operation = "";
            continue;
        }
        else if (operation == "/=")
        {
            std::cout << "Self Divide: " << divideSelf(operand1) << std::endl;
            operand1 = -999;
            operation = "";
            continue;
        }

        while (operand2 == -999)
        {
            std::cout << "\nPlease enter another operand: ";
            std::cin >> operand2;
        }

        if (operation == "+")
        {
            std::cout << "\nThe answer is:" << add(operand1, operand2) << std::endl;
            operand1 = -999;
            operation = "";
            operand2 = -999;
            continue;
        }

        else if (operation == "-")
        {
            std::cout << "\nThe answer is:" << subtract(operand1, operand2) << std::endl;
            operand1 = -999;
            operation = "";
            operand2 = -999;
            continue;
        }

        else if (operation == "*")
        {
            std::cout << "\nThe answer is:" << multiply(operand1, operand2) << std::endl;
            operand1 = -999;
            operation = "";
            operand2 = -999;
            continue;
        }
        std::cin.clear();
    }
    std::cout << "\n";

    return 0;
}

void functionBelow()
{
    std::cout << "Empty calibrating..." << std::endl;
}