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
    
    std::string get_first_name()
    {
        return first_name;
    }
    
    std::string get_second_name()
    {
        return second_name;
    }
    
    double get_stiffness()
    {
        return stiffness_coefficient;
    }
    
    double get_membership()
    {
        return membership;
    }
    
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
    std::cout << "Hello, user! To std::cin the client you need to insert:" << std::endl
    << "1) First name" << std::endl << "2) Second name" << std::endl << "3) Stiffness of hair"
    << std::endl << "4) Years of membership" << std::endl << std::endl;
    
    Haircut_client client1; Haircut_client client2; Haircut_client client3;
    
    std::cout << "Insert the data of client 1: " << std:: endl;
    std::cin >> client1;
    
    std::cout << "Insert the data of client 2: " << std:: endl;
    std::cin >> client2;
    
    std::cout << "Insert the data of client 3: " << std:: endl;
    std::cin >> client3;
    
    std::string pathname = "HW6-4_files";
    
    auto path = std::__fs::filesystem::current_path();
    std::__fs::filesystem::create_directory(path / pathname);
    std::__fs::filesystem::path output_1 = "HW6-4_files/client1.txt";
    std::__fs::filesystem::path output_2 = "HW6-4_files/client2.txt";
    std::__fs::filesystem::path output_3 = "HW6-4_files/client3.txt";
    
    json client_1; json client_2; json client_3;
    
    client_1["First name"] = client1.get_first_name();
    client_1["Second name"] = client1.get_second_name();
    client_1["Stiffness of hair"] = client1.get_stiffness();
    client_1["Membership"] = client1.get_membership();
    
    client_2["First name"] = client2.get_first_name();
    client_2["Second name"] = client2.get_second_name();
    client_2["Stiffness of hair"] = client2.get_stiffness();
    client_2["Membership"] = client2.get_membership();
    
    client_3["First name"] = client3.get_first_name();
    client_3["Second name"] = client3.get_second_name();
    client_3["Stiffness of hair"] = client3.get_stiffness();
    client_3["Membership"] = client3.get_membership();
    
    std::fstream out_1(output_1.string(), std::ios::out);
    out_1 << std::setw(4) << client_1;
    
    std::fstream out_2(output_2.string(), std::ios::out);
    out_2 << std::setw(4) << client_2;
    
    std::fstream out_3(output_3.string(), std::ios::out);
    out_3 << std::setw(4) << client_3;
    
    return 0;
}
