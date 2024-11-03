/* 
Jack Hansen and Jules Weick
10/8/24
Potential 2D array part for Lab5
Store a list of courses with students.  Each row is a coursename followed by student names
Andrew Shallue, Fall 2024, CS229
*/

#ifndef COURSES_H
#define COURSES_H

#include <iostream>
#include <cstring>

class Courses{
    /* This will be partially-filled array model.  So fixed capacity.
    Imagine it as a collection of rows, each allocated row_capacity
    */
    private:
        // row and col capacity fixed at 10
        static const int row_capacity_ = 10;
        static const int col_capacity_ = 10;
        // fix string length to be 100, should be enough characters for names
        static const int str_length = 100;

        // char*** means a 2d array of char*, i.e. 2d array of cstrings
        char*** course_list_;
        // number of courses is the current count of rows
        int num_courses_;
        // an array to store the size of each row
        int row_sizes_[row_capacity_];

    public:
        // default constructor will fill with two fixed courses
        Courses();
        // functions needed for the rule of 3
        ~Courses();
        Courses(const Courses& other);
        Courses& operator=(const Courses& other);

        // intended for testing purposes only, print an element
        void print_at(int row, int column);

        // print function prints one course per line, 
        // course name followed by : followed by student names
        void print();

        // function that returns the index of the given course in course_list
        // if course is not found in course_list, return -1
        int course_index(char course[]);

        // add a student to an existing course.  If problems arise, do nothing
        void add_student(char student[], char course[]);

        // add a course to the course_list.  Starts with no students
        void add_course(char course[]);

        // return the course that a student attends.  If not found, return -1
        // course is represented by its integer index in the array
        int which_course(char student[]);

        // make a copy of the given course.  This means copying the entire row.
        // Then add the new row to the end of the list.  Update appropriately.
        void copy_course(char course[]);

};

#endif