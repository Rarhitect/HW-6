//
//  main.cpp
//  HW6-2
//
//  Created by Alyaev Roman on 17.03.2021.
//

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, const char * argv[])
{
    std::string filename = "Strings.txt";
    constexpr int string_length = 13;
    constexpr int string_quantity = 4;
    std::ofstream o_f(filename);
    
    if(!o_f)
    {
        std::cerr << "Can't open..." << std::endl;
        exit(1);
    }
    
    int string_number;
    std::cout << "Insert string number: ";
    std::cin >> string_number;
    
    if((string_number > string_quantity) || (string_number < 0))
    {
        std::cout << "File doesn't have that number" << std::endl;
        exit(1);
    }
    
    static char filling_character = 'A';
    
    for(auto i = 0; i < string_quantity; i++)
    {
        for(auto j = 0; j < string_length; j++)
        {
            o_f << filling_character;
            ++filling_character;
            if(filling_character == '[')
            {
                filling_character += 6;
            }
        }
        o_f << std::endl;
    }
    
    std::ifstream i_f(filename);
    
    if(string_number > 1)
    {
        i_f.seekg((string_number - 1) * (string_length + 1));
    }
    else
    {
        i_f.seekg(0);
    }
    
    std::string destination_string;
    std::getline(i_f, destination_string);
    std::cout << "Your destination string is:" << std::endl << destination_string << std::endl;
    
    
    return 0;
}
