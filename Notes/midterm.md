# Classes

## Construtors

* Constructor is called as such. 'Time t;'
* No return type.
* For a class with the name "Time"; Default constructor is defined in the Class as 'Time()'
* Overloading functions. Only # of datatypes and the types matter.

## Destructors

* Member function that is called automaticly called when an object is destroyed.
* Called by '~className();'
* Does not take parameters.
* Doesn't care if a function is overloaded.

``` cpp
#include #Inventory.h
Inventory::Inventory(int size) {
    parts = new string[size]; // dynamic allocation.
    count = 0;
}

// Destructor gets called whenever we destroy an object of Inventory
Inventory::~Inventory() {
    delete [] parts; // release memory
}
```

## Arrays of objects
