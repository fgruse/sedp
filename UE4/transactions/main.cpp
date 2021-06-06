
#include <iostream>

#include "Transaction.h"


void testMI()
{
    // TODO: adapt declarations (t1..t4) to use your solution for a)
    
    // Basic transaction
    Transaction t1{ "t1" };
    t1.process("do something");
    std::cout << std::endl;

    // Transaction with logging
    Transaction t2{ "t2" };
    t2.process("do something with logging");
    std::cout << std::endl;

    // Secured transaction
    Transaction t3{ "t3" };
    t3.process("do something secured");
    std::cout << std::endl;

    // Secured transaction with logging
    Transaction t4{ "t4" };
    t4.process("do something secured with logging");
    std::cout << std::endl;
}


void testNonMI()
{
    // TODO: adapt declarations (t1..t4) to use your solution for b)

    // Basic transaction
    Transaction t1{ "t1" };
    t1.process("do something");
    std::cout << std::endl;

    // Transaction with logging
    Transaction t2{ "t2" };
    t2.process("do something with logging");
    std::cout << std::endl;

    // Secured transaction
    Transaction t3{ "t3" };
    t3.process("do something secured");
    std::cout << std::endl;

    // Secured transaction with logging
    Transaction t4{ "t4" };
    t4.process("do something secured with logging");
    std::cout << std::endl;
}


int main(int argc, char * argv[])
{
    std::cout << "Testing MI implementation..." << std::endl;
    testMI();
    std::cout << std::endl;

    std::cout << "Testing non-MI implementation..." << std::endl;
    testNonMI();
    std::cout << std::endl;
}