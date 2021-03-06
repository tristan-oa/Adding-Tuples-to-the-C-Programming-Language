# Adding Functionality to Array Operations and Introducing Tuple Representations in C

This project was the first Uni-related programming assignment, which made part of the [CPS1011: Programming Principles in C](https://www.um.edu.mt/courses/studyunit/CPS1011) course, forming part of my BSc Computer Science.

# Task Breakdown

In this project, the following tasks were performed:

1.  Array Operations:

    - `Cloning` functionality was made possible for 3D integer arrays having any size.
    - `Reversing` functionality was implemented to reverse the order of words in a given array of strings. Eg:

            {"This is the first sentence", "and this is the second"}
            becomes
            {"sentence first the is This", "second the is this and"}

2.  Tuple Operations:

    - `Creation` of new tuples, as identified by a string ID and a sequence of element type/value (In the case of an existing identfier, the new tuple replaces the existing one).
    - `Tuple Retrieval` of a tuple object pointer, given its ID.
    - `Tuple ID Retrieval` of an existing tuple object, given its pointer.
    - `Display` of a tuple's contents, given its pointer.
    - `Deletion` of tuple object, given its ID.
    - `Comparison` of 2 compatible tuple objects<sup id="a1">[1](#f1)</sup>, by performing in-order element comparison of their elements, and returning a:

      - _+1_ if the first non-equal element pair is larger for the first tuple.
      - _-1_ if the first non-equal element pair is smaller for the first tuple.
      - _0_ if all elements are equal.

      <b id="f1">1</b> Compatible tuples are those with the same element number and types, or where the element number/types of the first is a prefix of the second. . [↩](#a1)

    - `Joining` of 2 tuples, given the 2 pointers of tuples to be joined and a new tuple ID.
    - `Saving` of all existing tuple objects to disk.
    - `Loading` of all tuple objects from a saved file.

# Documentation

A report describing the design process and motivation behind this project can be found [here](https://github.com/tristan-oa/C-Programming-Principles-1st-year/Assignment_SPECIFICATION.pdf).

A detailed technical documentation of the source code written can be found [here](https://github.com/tristan-oa/C-Programming-Principles-1st-year/DOCUMENTATION.pdf).
