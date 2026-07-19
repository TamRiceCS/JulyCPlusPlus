#include <iostream>
#include <iomanip>
#include <cstdint>
#include <string>
// sizes of types are not standard over all OS or system types. Operate within min size.
// the /n you see sometimes is called an escape character, it represents a newline

void echo(std::string repeat);
void betterEcho(std::string_view repeatView);

int main()
{
    // rationals
    float piFloat = 3.41;            // 4 bytes long
    double piDouble = 3.41;          // 8 bytes long
    long double piLongDouble = 3.41; // 8, 12, or 16 bytes long, don't use due to variation
    // Floating comparisons are not safe, .0001 and .0000000001 aren't equal
    // rounding errors become more and more serious after every operation

    std::cout << "\n"
              << sizeof(float) << ": float, " << sizeof(double) << ": double, " << sizeof(long double);
    std::cout << ": long double.\n\n";

    piFloat = 3.000;
    std::cout << "Fractional part is not printed if 0 by default: " << piFloat << std::endl;
    // to use setprecision, #include <iomanip>
    // will also need to use fixed in order to print trailing 0s as they aren't sigfigs
    std::cout << "\nAfter using set precision to print fractional 0: " << std::fixed << std::setprecision(4);
    std::cout << piFloat << "\n";

    // character
    char letter = 'a';        // standard letter less than 255, 1 byte
    wchar_t letterWide = 'a'; // wide letter greater than 255 -> foreign lang, 2 bytes
    // char8_t letter8t = 'a'; c++ 20,
    char16_t letter16t = 'a'; //
    char32_t letter32t = 'a';

    // integers, range is -(2^(n-1)) to (2(n-1))-1.
    short int numShort = 1;        // 2 bytes
    short justShort = 1;           // 2 bytes
    int num = 1;                   // 4 bytes
    long justLong = 1'000'000;     // 4 bytes, you can use ' to break up big numbers into groups of 3
    long int numLong = 1;          // 4 bytes
    long long justLongLong = 1;    // 8 bytes
    long long int numLongLong = 1; // 8 bytes
    // standard practice to drop int on short, long, and long long.
    // all integers are signed by default, using the signed keyword is redundant
    // unsigned nums are positive only, BE CAREFUL EASY TO CAUSE OVERFLOW -1 AND LESS WILL DO IT.
    unsigned int numSigned = -1;

    std::cout << "\n"
              << sizeof(short) << ": short, " << sizeof(int) << ": int, " << sizeof(long) << ": long, ";
    std::cout << sizeof(long long) << ": long long.\n\n";
    std::cout << "This will be weird, overflow occurs with -1 in a unsigned int... " << numSigned << "\n\n";

    // c ints, need #include <cstdint>, NOT ALL WILL BE DEFINED ON EVERY OS
    std::int8_t c8int = -100;   // behaves like a char due to ascii table
    std::uint8_t c8unint = 100; // behaves like a char due to ascii table
    std::int16_t c16int = -255;
    std::uint16_t c16unint = 255;
    std::int32_t c32int = -2'000'032'000;
    std::uint32_t c32unint = 2'000'032'000;
    std::int64_t c64int = -3'000'000'000'000'000'000;
    std::uint64_t c64unint = 3'000'000'000'000'000'000;

    std::cout << "u/int8_t: " << c8int << " " << c8unint << "\nu/int16_t: " << c16int << " ";
    std::cout << c16unint << "\nu/int32_t: " << c32int << " " << c32unint << "\nu/int64_t: ";
    std::cout << c64int << " " << c64unint << std::endl;

    // Why use int_fast? It will use the fastest type w/ minimum bits!
    int_fast8_t exfast8 = 100;
    int_fast16_t exfast16 = 10'000;
    int_fast32_t exfast32 = 10'000'000;
    int_fast64_t exfast64 = 100'000'000'000'000;

    std::cout << "\nFastest value to store 100 in w/ a min of 8 bits: " << sizeof(exfast8) * 8 << std::endl;
    std::cout << "Fastest value to store 10,000 in w/ a min of 16 bits: " << sizeof(exfast16) * 8 << std::endl;
    std::cout << "Fastest value to store 10mil in w/ a min of 32 bits: " << sizeof(exfast32) * 8 << std::endl;
    std::cout << "Fastest value to store 100tril w/ a min of 64 bits: " << sizeof(exfast64) * 8 << std::endl;

    // Why use int_least? It will use the most efficient memory usage w/ minimum bits!
    int_least8_t exleast8 = 100;
    int_least16_t exleast16 = 10'000;
    int_least32_t exleast32 = 10'000'000;
    int_least64_t exleast64 = 100'000'000'000'000;

    std::cout << "\nMinimum storage to store 100 in w/ a min of 8 bits: " << sizeof(exleast8) * 8 << std::endl;
    std::cout << "Minimum storage to store 10,000 in w/ a min of 16 bits: " << sizeof(exleast16) * 8 << std::endl;
    std::cout << "Minimum storage to store 10mil in w/ a min of 32 bits: " << sizeof(exleast32) * 8 << std::endl;
    std::cout << "Minimum storage to store 100tril in w/ a min of 64 bits: " << sizeof(exleast64) * 8 << std::endl;

    // boolean
    // note that cin will only accept nums for bools
    bool fact = false;
    std::cout << "\nOutput bool as a num: " << fact << std::endl;
    std::cout << "Output bool as a word: " << std::boolalpha << fact << std::endl;
    std::cout << "Output as a num again: " << std::noboolalpha << fact << std::endl;

    // ways to convert fundamental types from one type to another:
    // one, static_cast
    std::cout << "\nConvert w/ static cast:" << static_cast<int>(true) << std::endl;
    std::cout << "\nConvert w/ C-style cast (): " << (int)true << std::endl;

    // there two types of constants: named and unnamed.
    // unnamed constants are like the number 5, it is always 5.
    const bool tautology = true; // this is a named const and will now always be true
    // function parameters can be const as well, useful to make sure parameter is not changed
    // return variables can be const but they are considered bad practice

    // strings are not a built in type, c version is an array of chars ending in '\0'(null char)
    // Need to include <string>
    std::cout << "\n";
    std::string intro = "Hello, my name is Tamara";
    echo(intro); // passing a whole string is expensive, don't do it

    std::string_view introView = intro; // basically a string ptr
    betterEcho(introView);
    intro = "Meow, my name is Babby Kettin";

    echo(intro);
    betterEcho(introView); // this will be strange because stringView hasn't been updated
    introView = intro;
    betterEcho(introView);
    // Do not return stringViews, many reasons not to

    std::cout << "\n";
    return 0;
}

void echo(std::string repeat)
{
    std::cout << repeat << std::endl;
}

// does not create a copy of a char array!
void betterEcho(std::string_view repeatView)
{
    std::cout << repeatView << std::endl;
}