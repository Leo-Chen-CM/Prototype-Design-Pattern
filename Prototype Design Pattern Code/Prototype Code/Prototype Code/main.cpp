// Prototype Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
//using namespace std;
//struct Franchise
//{
//    string      m_street;
//    string      m_city;
//    float     m_price;
//};
//class FastFood 
//{
//    string  m_name;
//    Franchise* m_franchise;
//    // Private constructor, so direct instance can not be created except for `class EmployeeFactory`
//    FastFood(string n, Franchise* o) : m_name(n), m_franchise(o) {}
//    friend class FastFoodFactory;
//public:
//    FastFood(const FastFood& rhs) : m_name{ rhs.m_name }, m_franchise{ new Franchise{*rhs.m_franchise} }
//    { }
//    FastFood& operator=(const FastFood& rhs) 
//    {
//        if (this == &rhs) return *this;
//        m_name = rhs.m_name;
//        m_franchise = new Franchise{ *rhs.m_franchise };
//        return *this;
//    }
//    friend ostream& operator<<(ostream& os, const FastFood& o) 
//    {
//        return os << o.m_name << " selling at "
//            << o.m_franchise->m_street << " " << o.m_franchise->m_city << " at the price of: $" << o.m_franchise->m_price;
//    }
//};
//class FastFoodFactory 
//{
//    static FastFood MCD;
//    static FastFood KFC;
//
//    static unique_ptr<FastFood> NewFastFood(string n, int32_t c, FastFood& proto) 
//    {
//        auto f = make_unique<FastFood>(proto);
//        f->m_name = n;
//        f->m_franchise->m_price = c;
//        return f;
//    }
//public:
//    static unique_ptr<FastFood> NewMcDonaldMenu(string name, int32_t price) {
//        return NewFastFood(name, price, MCD);
//    }
//    static unique_ptr<FastFood> NewKFCMenu(string name, int32_t price) {
//        return NewFastFood(name, price, KFC);
//    }
//};
//// Static Member Initialization 
//FastFood FastFoodFactory::MCD{ "", new Franchise{"160 Broadway", "New York", 5.99f} };
//FastFood FastFoodFactory::KFC{ "", new Franchise{"Louisville", "Kentucky", 7.99f} };
//int main()
//{
//    auto cheeseburger = FastFoodFactory::NewMcDonaldMenu("Cheese Burger", 5.99f);
//    auto friedChicken = FastFoodFactory::NewKFCMenu("Fried Chicken", 7.99f);
//    cout << *cheeseburger << endl << *friedChicken << endl;
//    return EXIT_SUCCESS;
//}

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


using std::string;

// Prototype Design Pattern
//
// Intent: Lets you copy existing objects without making your code dependent on
// their classes.

enum Type 
{
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

/**
 * The example class that has cloning ability. We'll see how the values of field
 * with different types will be cloned.
 */

class Prototype 
{
protected:
    string prototype_name_;
    float prototype_field_;

public:
    Prototype() {}
    Prototype(string prototype_name)
        : prototype_name_(prototype_name) 
    {
    }
    virtual ~Prototype() {}
    virtual Prototype* Clone() const = 0;
    virtual void Method(float prototype_field) 
    {
        this->prototype_field_ = prototype_field;
        std::cout << "Call Method from " << prototype_name_ << " with field : " << prototype_field << std::endl;
    }
};

/**
 * ConcretePrototype1 is a Sub-Class of Prototype and implement the Clone Method
 * In this example all data members of Prototype Class are in the Stack. If you
 * have pointers in your properties for ex: String* name_ ,you will need to
 * implement the Copy-Constructor to make sure you have a deep copy from the
 * clone method
 */

class ConcretePrototype1 : public Prototype 
{
private:
    float concrete_prototype_field1_;

public:
    ConcretePrototype1(string prototype_name, float concrete_prototype_field)
        : Prototype(prototype_name), concrete_prototype_field1_(concrete_prototype_field) {
    }

    /**
     * Notice that Clone method return a Pointer to a new ConcretePrototype1
     * replica. so, the client (who call the clone method) has the responsability
     * to free that memory. I you have smart pointer knowledge you may prefer to
     * use unique_pointer here.
     */
    Prototype* Clone() const override {
        return new ConcretePrototype1(*this);
    }
};

class ConcretePrototype2 : public Prototype 
{
private:
    float concrete_prototype_field2_;

public:
    ConcretePrototype2(string prototype_name, float concrete_prototype_field)
        : Prototype(prototype_name), concrete_prototype_field2_(concrete_prototype_field) {
    }

    Prototype* Clone() const override 
    {
        return new ConcretePrototype2(*this);
    }
};

/**
 * In PrototypeFactory you have two concrete prototypes, one for each concrete
 * prototype class, so each time you want to create a bullet , you can use the
 * existing ones and clone those.
 */

class PrototypeFactory 
{
private:
    std::unordered_map<Type, Prototype*, std::hash<int>> prototypes_;

public:
    PrototypeFactory() 
    {
        prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1 ", 50.f);
        prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2 ", 60.f);
    }

    /**
     * Be carefull of free all memory allocated. Again, if you have smart pointers
     * knowelege will be better to use it here.
     */

    ~PrototypeFactory() 
    {
        delete prototypes_[Type::PROTOTYPE_1];
        delete prototypes_[Type::PROTOTYPE_2];
    }

    /**
     * Notice here that you just need to specify the type of the prototype you
     * want and the method will create from the object with this type.
     */
    Prototype* CreatePrototype(Type type) 
    {
        return prototypes_[type]->Clone();
    }
};

void Client(PrototypeFactory& prototype_factory) 
{
    std::cout << "Let's create a Prototype 1\n";

    Prototype* prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_1);
    prototype->Method(90);
    delete prototype;

    std::cout << "\n";

    std::cout << "Let's create a Prototype 2 \n";

    prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_2);
    prototype->Method(10);

    delete prototype;
}

int main() 
{
    PrototypeFactory* prototype_factory = new PrototypeFactory();
    Client(*prototype_factory);
    delete prototype_factory;

    return 0;
}
