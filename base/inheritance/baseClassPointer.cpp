#include <iostream>
#include <string_view>
#include <string>

class Animal
{
protected:
    std::string m_name;

    Animal(std::string_view name) : m_name{name}
    {
    }
    Animal(const Animal &) = default;
    Animal &operator=(const Animal &) = default;

public:
    std::string_view getName() const { return m_name; }
    std::string_view speak() const { return "???"; }
};

class Cat : public Animal
{
public:
    Cat(std::string_view name)
        : Animal{name}
    {
    }

    std::string_view speak() const { return "Meow"; }
};

class Dog : public Animal
{
public:
    Dog(std::string_view name)
        : Animal{name}
    {
    }

    std::string_view speak() const { return "Woff"; }
};

int main()
{
    const Cat cat{"Fred"};
    std::cout << "cat is named " << cat.getName() << ", and it says " << cat.speak() << '\n';

    const Dog dog{"Garbo"};
    std::cout << "dog is named " << dog.getName() << ", and it says " << dog.speak() << '\n';

    const Animal *pAnimal{&cat};
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

    pAnimal = &dog;
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';
}