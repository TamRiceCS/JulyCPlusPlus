// Single line comment

/*
Multi
Line
Comment
*/

#include <iostream> // stands for input / output library

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

    return 0;
}