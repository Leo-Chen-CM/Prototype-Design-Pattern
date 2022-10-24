// Prototype Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
struct Franchise
{
    string      m_street;
    string      m_city;
    float     m_price;
};
class FastFood 
{
    string  m_name;
    Franchise* m_franchise;
    // Private constructor, so direct instance can not be created except for `class EmployeeFactory`
    FastFood(string n, Franchise* o) : m_name(n), m_franchise(o) {}
    friend class FastFoodFactory;
public:
    FastFood(const FastFood& rhs) : m_name{ rhs.m_name }, m_franchise{ new Franchise{*rhs.m_franchise} }
    { }
    FastFood& operator=(const FastFood& rhs) 
    {
        if (this == &rhs) return *this;
        m_name = rhs.m_name;
        m_franchise = new Franchise{ *rhs.m_franchise };
        return *this;
    }
    friend ostream& operator<<(ostream& os, const FastFood& o) 
    {
        return os << o.m_name << " selling at "
            << o.m_franchise->m_street << " " << o.m_franchise->m_city << " at the price of: $" << o.m_franchise->m_price;
    }
};
class FastFoodFactory 
{
    static FastFood MCD;
    static FastFood KFC;

    static unique_ptr<FastFood> NewFastFood(string n, int32_t c, FastFood& proto) 
    {
        auto f = make_unique<FastFood>(proto);
        f->m_name = n;
        f->m_franchise->m_price = c;
        return f;
    }
public:
    static unique_ptr<FastFood> NewMcDonaldMenu(string name, int32_t price) {
        return NewFastFood(name, price, MCD);
    }
    static unique_ptr<FastFood> NewKFCMenu(string name, int32_t price) {
        return NewFastFood(name, price, KFC);
    }
};
// Static Member Initialization 
FastFood FastFoodFactory::MCD{ "", new Franchise{"160 Broadway", "New York", 5.99f} };
FastFood FastFoodFactory::KFC{ "", new Franchise{"Louisville", "Kentucky", 7.99f} };
int main()
{
    auto cheeseburger = FastFoodFactory::NewMcDonaldMenu("Cheese Burger", 5.99f);
    auto friedChicken = FastFoodFactory::NewKFCMenu("Fried Chicken", 7.99f);
    cout << *cheeseburger << endl << *friedChicken << endl;
    return EXIT_SUCCESS;
}

//void init(int color)
//{
//	switch (color)
//	{
//	case 1:
//		std::cout << "Color is red\n";
//		break;
//	case 2:
//		std::cout << "Color is blue\n";
//		break;
//	default:
//		break;
//	}
//}
//int main()
//{
//    std::cout << "Hello World!\n";
//
//	init(1);
//	init(2);
//}
