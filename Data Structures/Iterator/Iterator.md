# Iterator

An **iterator** is an object (like a `pointer`) that points to an element inside the container.
=
- Iterators are used to point at the memory addresses of STL containers.

- Iterator is similar to pointer but for some containers some operations are not allowed.
    ![](https://media.geeksforgeeks.org/wp-content/uploads/C_Iterator_Support.jpg)

- Algorithms in STL don’t work on containers, instead they work on iterators, they manipulate the data pointed by the iterators.

- Types of iterators and their allowed operations on containers
    ![](https://images.slideplayer.com/11/3264822/slides/slide_3.jpg)

## Notes
- We can't use + or - operator in lists, sets, maps etc,. (refer first and second picture)

## Syntax
```c++
    container_type <parameter_list>::iterator iterator_name;
```

#### Example :
```c++
    #include<iostream>
    #include<vector>

    using namespace std;

    int main()
    {
        vector<int>::iterator i;
        /* create an iterator named i to a vector of integers */
    
        vector<string>::iterator j;
        /* create an iterator named j to a vector of strings */
    
        list<int>::iterator k;
        /* create an iterator named k to a vector of integers */
    
        map<int, int>::iterator l;
        /* create an iterator named l to a map  of integers */
    }
```

```c++
    #include<iostream>
    #include<vector>

    using namespace std;

    int main()
    {
        vector<int> vect = {1,2,3};
        auto itr = vect.begin();
        /* auto is an automatic pointer internally typecasting is happening */
        /* create an iterator named itr to the first element in the vector vect */
    }
```

## References
1. [Iterators in C++ (geeksforgeeks)](https://www.geeksforgeeks.org/introduction-iterators-c/)
2. [Iterators (studytonight)](https://www.studytonight.com/cpp/stl/stl-iterator-library)