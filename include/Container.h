#ifndef CONTAINER_H
#define CONTAINER_H


class Container
{
public:
    // Виртуальные методы, должны быть реализованы вашим контейнером
    virtual void insert(int value) = 0;
    virtual bool exists(int value) = 0;
    virtual void remove(int value) = 0;

    // И этот тоже, хотя к нему потом ещё вернёмся
    virtual void print() = 0;

    // Виртуальный деструктор (пока просто поверьте, что он нужен)
    virtual ~Container() { };
};

#endif // CONTAINER_H
