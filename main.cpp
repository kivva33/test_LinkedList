#include <iostream>
#include "file.h"

int main() {
    /*LinkedList Nech;
    LinkedList Chet;
    Nech.push_back(11);
    Nech.push_back(10);
    Nech.push_back(9);
    Nech.push_back(8);
    Nech.push_back(7);

    Chet.push_back(6);
    Chet.push_back(5);
    Chet.push_back(4);
    Chet.push_back(3);
    Chet.push_back(2);


    print(&Chet);
    printf("\n");
    print(&Nech);*/
#pragma region
    LinkedList test;
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);

    print(&test);
    int b;
    b = test[1];
    std::cout << b << std::endl;
    test[6] = 10;
    test[5] = 11;

    print(&test);
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
        std::cout << "OK";
    }
#pragma endregion
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
