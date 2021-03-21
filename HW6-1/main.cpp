//
//  main.cpp
//  HW6-1
//
//  Created by Alyaev Roman on 17.03.2021.
//

#include <iostream>
#include <fstream>
#include <string>


enum class State
{
    reading,
    previous_is_slash,
    previous_is_backslash,
    in_string,
    in_comment,
    waiting_for_slash
};


int main(int argc, const char * argv[])
{
    std::string input_filename;
    std::cout << "Hello, enter the input filename (name.extention): ";
    std::cin >> input_filename;
    
    std::ifstream inputf(input_filename);
    std::ofstream outputf("without_comments.txt");
    
    if (!inputf.is_open())
    {
        outputf << "This file wasn't found..." << std::endl;
        exit(1);
    }
    
    std::string string;

    State state = State::reading;
    
    while(getline(inputf, string))
    {
        for(auto i: string)
        {
            switch(state)
            {
                case State::reading:
                    if (i == '/')
                    {
                        state = State::previous_is_slash;
                    }
                    else if (i == '\\')
                    {
                        state = State::previous_is_backslash;
                    }
                    else if (i == '"')
                    {
                        outputf << i;
                        state = State::in_string;
                    }
                    else
                    {
                        outputf  << i;
                    }
                    break;
                    
                case State::previous_is_slash:
                    if (i == '/')
                    {
                        goto next_string;
                    }
                    else if (i == '*')
                    {
                        state = State::in_comment;
                    }
                    else
                    {
                        state = State::reading;
                        outputf << i;
                    }
                    break;
                    
                case State::in_comment:
                    if ( i == '*' )
                    {
                        state = State::waiting_for_slash;
                    }
                    break;
                    
                case State::waiting_for_slash:
                    if (i == '/')
                    {
                        state = State::reading;
                    }
                    else
                    {
                        state = State::in_comment;
                    }
                    break;
                    
                case State::in_string:
                    if (i == '\\')
                    {
                        state = State::previous_is_backslash;
                    }
                    if (i == '"')
                    {
                        state = State::reading;
                    }
                    outputf << i;
                    break;
                    
                case State::previous_is_backslash:
                    state = State::in_string;
                    outputf << i;
                    break;
                    
                default:
                    break;
            }
        }
    next_string: outputf << std::endl;
    }
    
    outputf.close();
    
    if(outputf.is_open())
    {
        outputf << "Not able to close..." << std::endl;
        exit(1);
    }
    
    return 0;
}

