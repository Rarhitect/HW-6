//
//  main.cpp
//  HW6-1
//
//  Created by Alyaev Roman on 17.03.2021.
//

#include <iostream>
#include <fstream>
#include <string>

bool is_comment()
{
    // the test is it a comment or not
    
    return false;
}

int main(int argc, const char * argv[])
{
    std::string filename;
    std::cout << "Enter the filename (name.extention): ";
    std::cin >> filename;
    
    std::fstream inout(filename, std::ios::in | std::ios::out);
    
    if(!inout)
    {
        std::cerr << "Can't open/write..." << std::endl;
        exit(1);
    }
    
    while(inout)
    {
        if(is_comment() == true)
        {
            // deleting the symbols that create comments
        }
    }
    
    return 0;
}
