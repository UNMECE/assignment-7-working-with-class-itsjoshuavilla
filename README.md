[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/He7kaRBl)
# ECE231_Assignment7
Working with class
# Lab Assignment 7
In this lab we will use C++ to make a class for managing Electric and Magnetic Fields.  

# Class Definition
Make two classes managing a three-dimensional electric field and a three-dimensional magnetic field.  The classes will contain a single variable for the electric field and magnetic field that is a dynamically allocated array.

```
class Electric_Field
{
  private:
    double *E;
  public:
    <functions>
};
```

Allocate an array of 3 doubles, where the [0] element is the x-componenet, [1] is the y-componenet, and [2] is the z-component.

# Functions
Implement a default constructor and a default destructor.  Your destructor needs to free memory.  Make a constructor for both Electric and Magnetic Fields such that the following code is valid and assigns the three components of the field.

```
Electric_Field E_default;
Electric_Field E_components(1e5, 10.9, 1.7e2);
```
Implement a function that calculates the magnitude of the vector.
```
double calculateMagnitude();
```

Make getters and setters for each variable.  Create a few electric and magnetic field objects that use the default constructor, the constructor that takes the 3 components, and then the setter functions.  Then output the magnitude of both fields.  

# Electric Field Class Specific
Calculate the inner product of the electric field vector.

Output the inner product result to the screen.

# Magnetic Field Class Specific
Calculate the unit vector of the magnetic field.

Output the magnetic field unit vector to the screen.

# Grading Scale
- 40% classes implement correctly
- 20% code compiles and runs
- 20% class specific functions implemented
- 20% correct result to the screen
