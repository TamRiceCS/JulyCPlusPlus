/*
Order of C++ Operations
- fail safe in case of a tie is left most evaluated first
() Parentheses
*, /, % Multiplication, Division, Modulus
+, - Addition, Subtraction
>, <, >=, <= Comparison
==, != Equality
&& Logical AND
|| Logical OR
= Assignment
*/

int add(int num1, int num2)
{
    return num1 + num2;
}

int subtract(int num1, int num2)
{
    return num1 - num2;
}

int multiply(int num1, int num2)
{
    return num1 * num2;
}

int divide(int num1, int num2)
{
    return num1 / num2;
}

int iterUp(int num)
{
    return ++num;
}
int iterDown(int num)
{
    return --num;
}
int multiplySelf(int num)
{
    num *= num;
    return num;
}
int divideSelf(int num)
{
    num /= num;
    return num;
}