#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <type_traits>
#include <vector>

// Класс для экспериментов с ним и над ним
class Person final
{
public:
    Person()
    {
        static int counter = 10;
        age = ++counter;
        name = std::to_string((intptr_t)this);
        std::cout << "con-or: " << this << std::endl;
    }

    Person(int Age)
    {
        age = Age;
        name = std::to_string((intptr_t)this);
        std::cout << "con-or: " << this << std::endl;
    }

    Person(int Age, std::string Name) : name{Name}, age{Age}
    {
        std::cout << "con-or: " << this << std::endl;
    }

    ~Person()
    {
        std::cout << "des-or: " << this << std::endl;
    }

    Person(Person const &v) : name(v.name), age(v.age)
    {
        std::cout << "copy con-or: " << &v << " -> " << this << std::endl;
    }

    Person(Person &&v) : name(std::move(v.name)), age(v.age)
    {
        std::cout << "move con-or: " << &v << " -> " << this << std::endl;
    }

    Person &operator=(Person const &v)
    {
        std::cout << "copy op-or: " << &v << " -> " << this << std::endl;
        name = v.name;
        age = v.age;
        return *this;
    }

    Person &operator=(Person &&v)
    {
        std::cout << "move op-or: " << &v << " -> " << this << std::endl;
        if (this == &v)
            return *this;
        name = std::move(v.name);
        age = v.age;
        return *this;
    }

    auto to_s() const
    {
        return name + "( " + std::to_string(age) + " )";
    }

    auto say() const
    {
        std::cout << to_s() << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &os, Person const &v)
    {
        return os << v.to_s();
    }

protected:
    std::string name;
    int age = 0;
};
