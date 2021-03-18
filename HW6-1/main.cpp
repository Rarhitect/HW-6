//
//  main.cpp
//  HW6-1
//
//  Created by Alyaev Roman on 17.03.2021.
//

#include <iostream>
#include <fstream>
#include <string>

bool is_comment(char char1, char char2)
{
    static int counter = 0;
    if(char2 == '"' and char1 != '//')
        {
            counter ? --counter : ++counter;
        }
    if(char2 == '//' and char1 != '//' and !counter)
        {
            return true;
        }
    return false;
}

int main(int argc, const char * argv[])
{
    std::string filename = "code.cpp";
    std::fstream inout(filename, std::ios::in | std::ios::out);
    
    if(!inout)
    {
        std::cerr << "Can't open/write..." << std::endl;
        exit(1);
    }
    
    char char1 = ' '; char char2;
    
    while(inout)
    {
        inout.get(char2);
        
        if(is_comment(char1, char2))
        {
            inout.seekg(-1, std::ios::cur);
            inout.put(' ');
            inout.put(' ');
        }
        
        char1 = char2;
    }
    
    return 0;
}
