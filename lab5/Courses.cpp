/*
Jack Hansen and Jules Weick
10/8/24
Implementation file for Courses, 2d array example
Andrew Shallue, CS229, Fall 2024
*/

#include "Courses.h"

// default constructor will fill with two fixed courses
Courses::Courses(){

    // allocate a 10x10 array of cstrings
    // first allocate the outside column array
    Courses::course_list_ = new char**[ Courses::row_capacity_ ];
    for(int i = 0; i < Courses::row_capacity_; i++){
        // create a row, then assign it to a space in course_list
        char** row = new char*[ Courses::col_capacity_ ];
        Courses::course_list_[i] = row;
    }

    // I'm creating two courses.  Names pulled from https://1000randomnames.com/
    // Note that there is an allocation for each string.  I create the string on the stack,
    // then copy it to the allocation on the heap.
    // This is because cstrings like course1 will be garbage collected at the end of the function.
    char course1[] = "GW100"; char* course1_p = new char[str_length];
    strcpy(course1_p, course1);  Courses::course_list_[0][0] = course1_p;
    char name1[] = "Dangelo";  char* name1_p = new char[str_length];
    strcpy(name1_p, name1);    Courses::course_list_[0][1] = name1_p;
    char name2[] = "Erick";    char* name2_p = new char[str_length];
    strcpy(name2_p, name2);    Courses::course_list_[0][2] = name2_p;
    char name3[] = "Alina";    char* name3_p = new char[str_length];
    strcpy(name3_p, name3);    Courses::course_list_[0][3] = name3_p;
    char name4[] = "Rachel";   char* name4_p = new char[str_length];
    strcpy(name4_p, name4);    Courses::course_list_[0][4] = name4_p;
    char name5[] = "Forrest";  char* name5_p = new char[str_length];
    strcpy(name5_p, name5);    Courses::course_list_[0][5] = name5_p;
    char name6[] = "Brielle";  char* name6_p = new char[str_length];
    strcpy(name6_p, name6);    Courses::course_list_[0][6] = name6_p;
    char name7[] = "Shepard";  char* name7_p = new char[str_length];
    strcpy(name7_p, name7);    Courses::course_list_[0][7] = name7_p;
    char name8[] = "Scott";    char* name8_p = new char[str_length];
    strcpy(name8_p, name8);    Courses::course_list_[0][8] = name8_p;
    char name9[] = "Brooklyn"; char* name9_p = new char[str_length];
    strcpy(name9_p, name9);    Courses::course_list_[0][9] = name9_p;

    // these are names of my family members
    char course2[] = "CS127";  char* course2_p = new char[str_length];
    strcpy(course2_p, course2);    Courses::course_list_[1][0] = course2_p;
    char name10[] = "Andrew";  char* name10_p = new char[str_length];
    strcpy(name10_p, name10);    Courses::course_list_[1][1] = name10_p;
    char name11[] = "Heather"; char* name11_p = new char[str_length];
    strcpy(name11_p, name11);    Courses::course_list_[1][2] = name11_p;
    char name12[] = "Bob";     char* name12_p = new char[str_length];
    strcpy(name12_p, name12);    Courses::course_list_[1][3] = name12_p;
    char name13[] = "Diane";   char* name13_p = new char[str_length];
    strcpy(name13_p, name13);    Courses::course_list_[1][4] = name13_p;
    char name14[] = "Anna";    char* name14_p = new char[str_length];
    strcpy(name14_p, name14);    Courses::course_list_[1][5] = name14_p;
    char name15[] = "Katie";   char* name15_p = new char[str_length];
    strcpy(name15_p, name15);    Courses::course_list_[1][6] = name15_p;

    // set sizes
    Courses::num_courses_ = 2;
    Courses::row_sizes_[0] = 10;
    Courses::row_sizes_[1] = 7;

    // I currently don't have the time, but I should zero out all of the _p pointers
    // doesn't matter, b/c they are garbage collected.  Just good hygiene.
}

// destructor to free up memory for course_list_
Courses::~Courses(){
    // first call delete on each string entry
    for(int i = 0; i < Courses::num_courses_; i++){
        for(int j = 0; j < Courses::row_sizes_[i]; j++){
            delete[] Courses::course_list_[i][j];
        }
    }
    // now call delete on each row in turn
    for(int i = 0; i < Courses::row_capacity_; i++){
        delete[] Courses::course_list_[i];
        course_list_[i] = 0;
    }
    // now call delete on the outer array
    delete[] course_list_;
    course_list_ = 0;
}

Courses::Courses(const Courses& other){
    // copy over sizes.  Capacities are static and don't change
    Courses::num_courses_ = other.num_courses_;
    for(int i = 0; i < Courses::num_courses_; i++){
        Courses::row_sizes_[i] = other.row_sizes_[i];
    }

    // now allocate memory for course_list_, 
    Courses::course_list_ = new char**[ Courses::row_capacity_ ];
    for(int i = 0; i < Courses::row_capacity_; i++){
        // create a row, fill with strings, then assign it to a space in course_list
        char** row = new char*[ Courses::col_capacity_ ];
        for(int j = 0; j < Courses::col_capacity_; j++){
            char* entry = new char[ Courses::str_length ];
            row[j] = entry;
        }
        Courses::course_list_[i] = row;
    }
    // copy over the information from other.  Bounds are size, not capacity
    for(int i = 0; i < Courses::num_courses_; i++){
        for(int j = 0; j < Courses::row_sizes_[i]; j++){
            // need to call strcpy, the line just below doesn't work b/c it simply copies pointers
            //Courses::course_list_[i][j] = other.course_list_[i][j];

            strcpy(Courses::course_list_[i][j], other.course_list_[i][j]);
        }
    }
}

Courses& Courses::operator=(const Courses& other){
    // using the same code I used for DynamicArray
    // if the two objects are the same, nothing to do
    if(this == &other){
        return *this;
    }else{
        // clear current information
        // delete each string
        for(int i = 0; i < Courses::num_courses_; i++){
            for(int j = 0; j < Courses::row_sizes_[i]; j++){
                delete[] Courses::course_list_[i][j];
            }
        }
        // then delete each row
        for(int i = 0; i < Courses::row_capacity_; i++){
            delete[] Courses::course_list_[i];
        }
        // then delete outer array
        delete[] Courses::course_list_;

        // copy the size attributes.  Capacities are fixed
        Courses::num_courses_ = other.num_courses_;
        for(int i = 0; i < Courses::num_courses_; i++){
            Courses::row_sizes_[i] = other.row_sizes_[i];
        }
        // now allocate memory for course_list_, 
        Courses::course_list_ = new char**[ Courses::row_capacity_ ];
        for(int i = 0; i < Courses::row_capacity_; i++){
            // create a row, then assign it to a space in course_list
            char** row = new char*[ Courses::col_capacity_ ];
            for(int j = 0; j < Courses::col_capacity_; j++){
                char* entry = new char[ Courses::str_length ];
                row[j] = entry;
            }
            Courses::course_list_[i] = row;
        }
        // copy over the information from other.  Bounds are size, not capacity
        for(int i = 0; i < Courses::num_courses_; i++){
            for(int j = 0; j < Courses::row_sizes_[i]; j++){
                strcpy(Courses::course_list_[i][j], other.course_list_[i][j]);
            }
        }

        // return the object we have modified
        return *this;
    }
}

// intended for testing purposes only, print an element
void Courses::print_at(int row, int column){
    if(row < Courses::num_courses_ && column < Courses::row_sizes_[row]){
        std::cout << Courses::course_list_[row][column];
    }else{
        std::cout << "Out of bounds error in print_at\n";
    }
    
}

// print function prints one course per line, 
// course name followed by : followed by student names
void Courses::print(){
    for(int i = 0; i < Courses::num_courses_; i++){
        // expecting at least a course title.  If size 0, throw error
        if(Courses::row_sizes_[i] == 0){
            std::cout << "Error in print, row size is 0\n";
        
        }else{
            // otherwise, print course title, followed by names
            std::cout << Courses::course_list_[i][0] << ": ";
            for(int j = 1; j < Courses::row_sizes_[i]; j++){
                std::cout << Courses::course_list_[i][j] << ", ";
            }
            std::cout << "\n";
        }   
    }   
}

int Courses::course_index(char course[]){
    /*This function will return the index of a course within the course list, f it exists
    Parameters:
        char course[]: the name of the course
    Returns:
        Either -1 or the index of the list
    */
   for(int i = 0; i < Courses::num_courses_; i++){
        if(strcmp(course, Courses::course_list_[i][0]) == 0){
            return i;
        }
   }
   return -1;

}

void Courses::add_student(char student[], char course[]){
    /*This function will add a student to a course if the course exists and is not full
    Parameters:
        char student[]: the name of the student
        chat course[]: the name of the course
    Returns:
        Nothing
    
    */
    // Find course index
    int course_i = Courses::course_index(course);
    if(course_i == -1){
        std::cout << "Course not found \n";
        return;
    }

    if(Courses::row_sizes_[course_i] >= Courses::col_capacity_){
        std::cout << "Cannot add student, course is full \n";
        return;
    }

    // Allocate memory and add the student
    char* name_p = new char[Courses::str_length];
    strcpy(name_p, student);
    Courses::course_list_[course_i][Courses::row_sizes_[course_i]] = name_p;
    Courses::row_sizes_[course_i]++;
    
}

void Courses::add_course(char course[]){
    /*This function will add a course to the course list if there is room
    Parameters:
        chat course[]: the name of the course
    Returns:
        Nothing
    */
   if (num_courses_ >= row_capacity_) {
        std::cout << "Cannot add course.\n";
        return;
    }
    int index = num_courses_;
    // Allocate course name
    char* course_p = new char[str_length];
    strcpy(course_p, course);
    course_list_[index][0] = course_p;
    // Initialize row size to 1
    Courses::row_sizes_[index] = 1;
    Courses::num_courses_++;
}

int Courses::which_course(char student[]){
    /*This function will return the index of a first class a student is found in, or -1 if they are not in one
    Parameters:
        char student[]: the student to be found
    Returns:
        either the index of the first course they are found to be in or -1 if they arent in one
    */
   for (int i = 0; i < num_courses_; i++) {
        for (int j = 0; j < row_sizes_[i]; j++) {
            if (strcmp(course_list_[i][j], student) == 0)
                return i;
        }
    }
    return -1;
}

void Courses::copy_course(char course[]){
    /*This function will copy an entire course and allocate a new row for it, given that there is room
    Parameters:
        char course[]: the course to be copied
    Returns:
        Nothing
    */
   if(Courses::num_courses_ >= Courses::row_capacity_){
       std::cout << "Cannot copy course, maximum capacity reached.\n";
       return;
   }

   int course_i = course_index(course);
   if(course_i == -1){
       std::cout << "Course not found \n";
       return;
   }
   add_course(course); // This already increments num_courses_, no need to increment again
   int new_course_index = Courses::num_courses_ - 1;
   //Copy each student from the original course to the new course
   for(int i = 1; i < Courses::row_sizes_[course_i]; i++){
       //Allocate memory for the new student name
       char* student_p = new char[Courses::str_length];
       strcpy(student_p, Courses::course_list_[course_i][i]);
       Courses::course_list_[new_course_index][i] = student_p;
   }
   // Set the row size for the new course
   Courses::row_sizes_[new_course_index] = Courses::row_sizes_[course_i];
}

