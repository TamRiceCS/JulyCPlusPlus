#include <iostream>
#include <bitset>

void narcissistPledge(bool happened, bool bad, bool bigDeal, bool fault)
{
    std::cout << "That didn't happen..." << std::endl;
    if (happened)
    {
        std::cout << "And if it did, it wasn't that bad..." << std::endl;
    }
    if (bad)
    {
        std::cout << "And if it was, that's not a big deal..." << std::endl;
    }
    if (bigDeal)
    {
        std::cout << "And if it is, that's not my fault..." << std::endl;
    }
    if (fault)
    {
        std::cout << "And if it is, you deserved it..." << std::endl;
    }

    // notice how the output changes w/ an if else if else structure!

    std::cout << "\nNotice how the output changes w/ if-elseif-else structure" << std::endl;

    if (happened)
    {
        std::cout << "And if it did, it wasn's that bad..." << std::endl;
    }
    else if (bad) // an else if always need an matching if
    {
        std::cout << "And if it was, that's not a big deal..." << std::endl;
    }
    else if (bigDeal)
    {
        std::cout << "And if it is, that's not my fault..." << std::endl;
    }
    else // else must ALWAYS follow an if or else if
    {
        std::cout << "And if I did, you deserved it..." << std::endl;
    }
    bool yikes = (happened && bad && bigDeal && fault) ? true : false;

    if (yikes)
    {
        std::cout << "So, yikes!" << std::endl;
    }
}

// Remember De Morgan's laws !(x&&y) and !(x&&y), nots x and y while flipping and <--> or
void conditionalFun(bool here, bool there)
{
    if (0)
    {
        std::cout << "I will never output, condition always false..." << std::endl;
    }

    if (1)
    {
        std::cout << "\nTautologies will always output." << std::endl;
    }

    if (here || there)
    {
        std::cout << "It is either here or there" << std::endl;
    }
    else
    {
        std::cout << "It isn't here or there" << std::endl;
    }
    if (here && there)
    {
        std::cout << "It is here and there" << std::endl;
    }
    else
    {
        std::cout << "It isn't here and there" << std::endl;
    }
}

// Bitset size MUST match in calls
void outputBits(std::bitset<8> example)
{
    std::cout << "The bits in the example are: ";
    for (int i = 0; i < 8; i++)
    {
        std::cout << example.test(i);
    }
    std::cout << "\n";
}

void bitExample()
{
    std::bitset<8> example = 0; // maxes out at 8, extra size is not used
    outputBits(example);

    example.set(0);
    example.set(2);
    example.set(4);
    example.set(6);
    outputBits(example);

    example.reset(2);
    example.reset(6);
    outputBits(example);

    example.flip(1);
    example.flip(3);
    outputBits(example);

    std::cout << "The size given is: " << example.size() << std::endl;
    std::cout << "The number of bits set to true is: " << example.count() << std::endl;

    std::cout << "Are all bits true? " << example.all() << std::endl;
    std::cout << "Are any bits true? " << example.any() << std::endl;

    example = 0xFF; // Now a tautology;
    std::cout << "After setting to 0xFF, is it all true? " << example.all() << std::endl;
    std::cout << "After setting to 0xFF, are any true? " << example.any() << std::endl;

    example = 0x00; // Now always false
    std::cout << "After setting to 0xFF, is it all false? " << example.none() << std::endl;
}

// modifier is commonly called a bitmask
void bitwiseOperators(int base, int shifter, int modifier)
{
    std::cout << "The base given is: " << base << std::endl;
    std::cout << "The modifier given is: " << modifier << std::endl;

    std::cout << "Base shifted by modifer right is: " << (base >> shifter) << std::endl;
    std::cout << "The prior number shifted left is: " << (base << shifter) << std::endl;
    // Shifting back to the left does not restore the original value!!!

    std::cout << "The base inverted is: " << (~base) << std::endl;

    std::cout << "Base & modifier (binary and) is: " << (base & modifier) << std::endl;
    std::cout << "Base | modifier (binary or) is: " << (base | modifier) << std::endl;
    std::cout << "Base ^ modifier (binary Xor) is: " << (base ^ modifier) << std::endl;
}