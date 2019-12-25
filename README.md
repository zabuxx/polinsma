# Polinsma

## Introduction

C++ POlymorphic INhertiance example with SMArt pointers

The example attempts to provide a modern C++ implementation of the following concepts:
  * Polymorphism
  * Smart pointers
  * Containers 

It provies in a way to safely and efficiently manage large sets of derived classes.

## In detail

The classes are organized as follows:

![classShape](doc/classShape.png)

### Shape

Shape is the abstract base class used to derive the more specific classes from.  

Because we want to use `std::shared_ptr` to address the class, it derives from `std::enable_shared_from_this`. This allows for Shape and any derived class to safely emit `shared_ptr`'s.

### Derived classes: Circle, Triangle, ...

Through polymorphism the `is_XXX()` functions provide a way to test whether `Shape_p` was created from a derived class (through conversion to `bool`), and even to obtain a `shared_ptr` to the derived class (as shown in `main()` in main.cpp)

The `shared_ptr` is obtained through `shared_from_this()` member of `enabled_shared_from_this` derived by `Shape`. To convert it to the another `T` of  `shared_ptr<T>` in the same control block, `std::dynamic_pointer_cast` is used.

### ShapeList

Given the above we can use `Shape_p` in a container to hold classes of all direved types. The usage of standard library containers and smart pointers give an excellent flexibility in passing the objects around, while ensuring ellegant and correct memory management.

# Feedback

Is welcome!


