#ifndef TYPED_H
#define TYPED_H

#include <cstdint>

template<typename T>
class TypeID
{
public:
    static std::uintptr_t id()
    {
        static char c;
        return reinterpret_cast<std::uintptr_t>( &c );
    }
};

class Typed
{
public:
    virtual ~Typed() = default;
    virtual std::uintptr_t getTypeID() const = 0;
};

template<typename T>
class TypeResolver : public Typed
{
public:
    std::uintptr_t getTypeID() const override
    {
        return TypeID<T>::id();
    }
};

#endif // TYPED_H
