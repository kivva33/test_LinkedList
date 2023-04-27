#include <iostream>
#include "file.h"

int main() {
    LinkedList test;
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);

    print(&test);
    std::cout << std::endl;

    int b;
    b = test[1];
    std::cout << b << std::endl;
    test[6] = 10;
    test[2] = 11;

    print(&test);
    std::cout << std::endl;
    std::cout<< std::endl;

    LinkedList test1;
    test1.push_back(3);
    test1.push_back(4);
    test1.push_back(5);

    LinkedList test2;
    test2.push_back(3);
    test2.push_back(4);
    test2.push_back(5);

    if(test2==test1){
        std::cout << "OK\n";
    }
    else{
        std::cout << "Not equal\n";
    }
    test2.push_back(6);

    if(test2==test1){
        std::cout << "OK\n";
    }
    else{
        std::cout << "Not equal\n";
    }

    std::cout << std:: endl;

    LinkedList l1;
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    print(&l1);
    std::cout << std:: endl;
    LinkedList l2;
    l2.push_back(1);
    l2.push_back(5);
    print(&l2);
    std::cout << std:: endl;

    l2 = l1;
    print(&l2);

}
