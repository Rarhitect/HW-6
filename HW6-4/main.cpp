//
//  main.cpp
//  HW6-4
//
//  Created by Alyaev Roman on 17.03.2021.
//

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include "json.hpp"

using nlohmann::json;

class Haircut_client
{
private:
    std::string first_name;
    std::string second_name;
    double stiffness_coefficient; //it is a number from 1 to 3 that characterises the stiffness of client's hair
    int membership; //Quantity of years the client uses this salon
    
public:
    Haircut_client()
    {
        first_name = "NO";
        second_name = "NO";
        stiffness_coefficient = 0.0;
        membership = 0;
    }
    
    Haircut_client(std::string f_n, std::string s_n, double coef, int years):
    first_name(f_n), second_name(s_n), stiffness_coefficient(coef), membership(years)
    {};
    
    ~Haircut_client(){};
    
    friend std::ostream& operator<<(std::ostream & os, const Haircut_client & object)
    {
        os << "First name: " << object.first_name << std::endl
        << "Second name: " << object.second_name << std::endl
        << "Stiffness of hair: " << object.stiffness_coefficient << std::endl
        << "Membership: " << object.membership << " years" << std:: endl;
        
        return os;
    }
    
    friend std::istream& operator>>(std::istream & is, Haircut_client &  object)
    {
        is >> object.first_name >> object.second_name >> object.stiffness_coefficient
        >> object.membership;
        
        return is;
    }
    
};

int main(int argc, const char * argv[])
{
    
    
    return 0;
}
