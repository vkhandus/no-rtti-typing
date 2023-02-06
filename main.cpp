#include "typed.h"

#include <iostream>
#include <memory>
#include <vector>

class ConcreteClass1 : public TypeResolver<ConcreteClass1>
{
public:
    void do_something1() const
    {
        std::cout << "do_something1 for type, with id: " << getTypeID() << std::endl;
    }
};

class ConcreteClass2 : public TypeResolver<ConcreteClass2>
{
public:
    void do_something2() const
    {
        std::cout << "do_something2 for type, with id: " << getTypeID() << std::endl;
    }
};

int main()
{
    std::vector<std::unique_ptr<Typed>> typedContainer;
    typedContainer.push_back( std::make_unique<ConcreteClass1>() );
    typedContainer.push_back( std::make_unique<ConcreteClass2>() );
    typedContainer.push_back( std::make_unique<ConcreteClass1>() );

    for ( const auto& pTypedInstance : typedContainer )
    {
        if ( pTypedInstance->getTypeID() == TypeID<ConcreteClass1>::id() )
        {
            static_cast<ConcreteClass1*>( pTypedInstance.get() )->do_something1();
        }
        else if ( pTypedInstance->getTypeID() == TypeID<ConcreteClass2>::id() )
        {
            static_cast<ConcreteClass2*>( pTypedInstance.get() )->do_something2();
        }
    }
}
