#include <algorithm>
#include <iostream>

class MyString
{
private:
    char *m_data{};
    int m_length{};

public:
    MyString(const char *data = nullptr, int length = 0)
        : m_length{std::max(length, 0)}
    {
        if (length)
        {
            m_data = new char[static_cast<std::size_t>(length)];
            for (int i{0}; i < length; ++i)
            {
                m_data[i] = data[i];
            }
        }
    }

    ~MyString()
    {
        delete[] m_data;
    }

    MyString &operator=(const MyString &str);
    friend std::ostream &operator<<(std::ostream &out, const MyString &s);
};

std::ostream &operator<<(std::ostream &out, const MyString &s)
{
    out << s.m_data << '\n';
    return out;
}

MyString &MyString::operator=(const MyString &str)
{
    if (this == &str)
    {
        return *this;
    }

    if (m_data)
        delete[] m_data;

    m_length = str.m_length;
    m_data = nullptr;

    if (m_length)
    {
        m_data = new char[static_cast<std::size_t>(str.m_length)];
    }
    for (int i{0}; i < str.m_length; ++i)
    {
        m_data[i] = str.m_data[i];
    }
    return *this;
}

int main()
{
    /* -------resut: Alex--------
        MyString alex("Alex", 5);
        MyString employee;
        employee = alex;
        std::cout << employee;
    */

    MyString alex("Alex", 5);
    alex = alex;
    std::cout << alex;
    return 0;
}