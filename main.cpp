#include "managerhierarchy.hpp"

int main() {
    ManagerHierarchy m;

    m.insert("Tom", "Mary");
    m.insert("Mary", "Bob");
    m.insert("Mary", "Sam");
    m.insert("Bob", "John");
    m.insert("Sam", "Katie");
    m.insert("Sam", "Pete");

    std::cout << "Have: '" << m.get_common_manager("Mary", "Bob")->get_name() << "' resolve the issue" << std::endl;

    /*
    m.insert("Frank", "Mary");
    m.insert("Mary", "Bob");
    m.insert("Mary", "Sam");
    m.insert("Sam", "Katie");
    m.insert("Sam", "Pete");
    m.insert("Bob", "John");

    std::cout << "Finding supervisor to resolve issue..." << std::endl;
    std::cout << "Have: '" << m.get_common_manager("Katie", "Bob")->get_name() << "' resolve the issue" << std::endl;
    */

    //std::cout << "*** FINDING ***" << std::endl;
    //std::cout << m.find("asdf") << std::endl;
    return 0;
}
