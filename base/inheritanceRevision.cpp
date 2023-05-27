#include <iostream>
#include <string_view>
#include <string>

class Animal
{
protected:
    std::string m_name;

    Animal(std::string_view name) : m_name{ name }
    {
    }
    Animal(const Animal&) = default;
    Animal& operator=(const Animal&) = default;
};