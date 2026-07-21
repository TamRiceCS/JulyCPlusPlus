#include <iostream>

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