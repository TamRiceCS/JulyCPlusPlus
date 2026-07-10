#include <iostream>
#include <cstdint>
// sizes of types are not standard over all OS or system types. Operate within min size.
int main()
{
    // rationals
    float piFloat = 3.41;            // 4 bytes long
    double piDouble = 3.41;          // 4-8 bytes long
    long double piLongDouble = 3.41; // 8-16 bytes long

    std::cout << "\n"
              << sizeof(float) << ": float, " << sizeof(double) << ": double, " << sizeof(long double);
    std::cout << ": long double.\n\n";

    // characters
    char letter = 'a';        // standard letter less than 255, 1 byte
    wchar_t letterWide = 'a'; // wide letter greater than 255 -> foreign lang, 2 bytes
    // char8_t letter8t = 'a'; c++ 20,
    char16_t letter16t = 'a'; //
    char32_t letter32t = 'a';

    // integers, range is -(2^(n-1)) to (2(n-1))-1.
    short int numShort = 1;        // 2 bytes
    short justShort = 1;           // 2 bytes
    int num = 1;                   // 4 bytes
    long justLong = 1'000'000;     // 4 bytes
    long int numLong = 1;          // 4 bytes
    long long justLongLong = 1;    // 8 bytes
    long long int numLongLong = 1; // 8 bytes
    // standard practice to drop int on short, long, and long long.
    // all integers are signed by default.
    // unsigned nums are positive only, BE CAREFUL EASY TO CAUSE OVERFLOW -1 AND LESS WILL DO IT.
    unsigned int numSigned = -1;

    // c ints, need #include <cstdint>

    std::cout << sizeof(short) << ": short, " << sizeof(int) << ": int, " << sizeof(long) << ": long, ";
    std::cout << sizeof(long long) << ": long long.\n\n";
    std::cout << "This will be weird, overflow occurs with -1 in a unsigned int... " << numSigned << "\n\n";

    // boolean
    bool fact = false;
    return 0;
}