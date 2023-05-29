#include <iostream>

class Product
{
public:
    virtual ~Product() = default;
    virtual std::string operation() const = 0;
};

class ConcreteProduct1 : public Product
{
public:
    std::string operation() const override
    {
        return "{Result of the ConcreteProduct1}";
    }
};
class ConcreteProduct2 : public Product
{
public:
    std::string operation() const override
    {
        return "{Result of the ConcreteProduct2}";
    }
};

class Creator
{
public:
    virtual ~Creator() = default;
    virtual Product *factoryMethod() const = 0;

    std::string someOperation() const
    {
        Product *product{this->factoryMethod()};
        std::string result{"Creator: The same creator's code has just worked with " + product->operation()};
        delete product;
        return result;
    }
};

class ConcreteCreator1 : public Creator
{
public:
    Product *factoryMethod() const override
    {
        return new ConcreteProduct1();
    }
};
class ConcreteCreator2 : public Creator
{
public:
    Product *factoryMethod() const override
    {
        return new ConcreteProduct2();
    }
};

void clientCode(const Creator &creator)
{
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
              << creator.someOperation();
}

int main()
{
    std::cout << "App: Launch with the ConcreteCreator1.\n";
    Creator *creator1{new ConcreteCreator1()};
    clientCode(*creator1);
    std::cout << std::endl;
    std::cout << "App: Launch with the ConcreteCreator2.\n";
    Creator *creator2{new ConcreteCreator2()};
    clientCode(*creator2);
    std::cout << std::endl;

    delete creator1;
    delete creator2;
    return 0;
}
