#include <iostream>
#include "include/del_vowels.h"

using namespace std;

int main()
{
    string comment;
    std::cout << "Troll, write a comment: ";
    getline(cin, comment);
    
    std::cout << "Result: " << del_vowels(comment) << std::endl;

    return 0;
}
