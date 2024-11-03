/* 
Jack Hansen and Jules Weick
10/8/24
main file for Lab 5
Andrew Shallue, CS229, Fall 2024
*/

#include <iostream>
//#include "Pstring.h"
#include "Courses.h"
//#include "Lab5Part1.h"
#include <cstring>

// test function for Part 3 of the lab involving the Pstring class
/*
void pstring_test(){
    // testing constructors, copy constructor, copy assignment
    std::cout << "Testing rule of 3\n";
    Pstring name_ob0;
    std::cout << "Default object should have size 0: " << name_ob0.get_size() << "\n";
    std::cout << "Default object should have capacity 1: " << name_ob0.get_capacity() << "\n";

    char name[] = "Andrew Shallue";
    Pstring name_ob1 = Pstring(name);
    Pstring name_ob2 = name_ob1;
    Pstring name_ob3(name_ob2);

    std::cout << "All three objects are copies, should have the same value\n";
    name_ob1.print();
    std::cout << " ";
    name_ob2.print();
    std::cout << " ";
    name_ob3.print();
    std::cout << "\n";

    std::cout << "size = " << name_ob1.get_size() << " capacity = " << name_ob1.get_capacity() << "\n";
    std::cout << "Should see 14 for size and 15 for capacity\n";

    // testing + by appending Andrew to Shallue to get AndrewShallue, and then AndrewAndrew
    std::cout << "\nTesting + operator for appending strings\n";    
    char name1[] = "Andrew";
    char name2[] = "Shallue";
    name_ob1 = Pstring(name1);
    name_ob2 = Pstring(name2);
    name_ob3 = name_ob1 + name_ob2;
    Pstring name_ob4 = name_ob1 + name_ob1;
    // print the three strings
    name_ob1.print();
    std::cout << " ";
    name_ob2.print();
    std::cout << " ";
    name_ob3.print();
    std::cout << " ";
    name_ob4.print();
    std::cout << "\n";
    std::cout << "size of combined: " << name_ob3.get_size() << " capacity of combined: ";
    std::cout << name_ob3.get_capacity() << "\n";
    std::cout << "Should see 13 for size and 14 for capacity\n";

    // Testing slice, replace, split
    std::cout << "\nTesting slice, replace, split\n";
    Pstring name_ob5 = name_ob3.slice(5, 8);
    Pstring name_ob6 = name_ob4.slice(2, 10);
    Pstring name_ob7 = name_ob4.slice(8, 100);
    name_ob5.print();
    std::cout << " ";
    name_ob6.print();
    std::cout << " ";
    name_ob7.print();
    std::cout << "\n";
    std::cout << "The previous line should be: wSh drewAndr drew\n";

    std::cout << "Replace l with $ in AndrewShallue: ";
    Pstring name_ob8 = name_ob3.replace('l', '$');
    name_ob8.print();
    std::cout << "\n";
    std::cout << "Replace w with W in AndrewAndrew: ";
    Pstring name_ob9 = name_ob4.replace('w', 'W');
    name_ob9.print();
    std::cout << "\n";
    
    std::cout << "Split Andrew Shallue on spaces (by default), ";
    char space[] = " ";
    Pstring space_ob = Pstring(space);
    Pstring name_ob = name_ob1 + space_ob + name_ob2;
    vector<Pstring> words = name_ob.split();
    std::cout << "Should see Andrew , Shallue,: ";
    for(int i = 0; i < words.size(); i++){
        words.at(i).print();
        std::cout << ", ";
    }
    std::cout << "\n";

    std::cout << "Split AndrewAndrew on 'n', ";
    words = name_ob4.split('n');
    std::cout << "Should see A, drewA, drew,: ";
    for(int i = 0; i < words.size(); i++){
        words.at(i).print();
        std::cout << ", ";
    }
    std::cout << "\n";

    std::cout << "Split AndrewAndrew on 'A', ";
    words = name_ob4.split('A');
    std::cout << "Should see , ndrew, ndrew,: ";
    for(int i = 0; i < words.size(); i++){
        words.at(i).print();
        std::cout << ", ";
    }
    std::cout << "\n";

    std::cout << "\nTesting is_all_alpha()\n";
    if(name_ob4.is_all_alpha()){
        std::cout << "name correctly recognized as entirely alphabetic\n";
    }else{
        std::cout << "name being flagged incorrectly as not all alphabetic\n";
    }
    char random[] = "Andrew4%ab9";
    Pstring random_ob = Pstring(random);
    if(random_ob.is_all_alpha()){
        std::cout << "Incorrect, this string is not entirely alphabetic\n";
    }else{
        std::cout << "Random string correctly recognized as not entirely alphabetic\n";
    }
}
*/
void courses_test(){
    Courses catalog1 = Courses();
    catalog1.print();
    std::cout << "\n";
    //comment out line by line until i find which fnction breaks
    Courses catalog2(catalog1);
    char cs229[] = "CS229";
    catalog2.add_course(cs229);
    char name1[] = "Justin";
    char name2[] = "Beth";
    catalog2.add_student(name1, cs229);
    catalog2.add_student(name2, cs229);
    catalog2.print();

    if(catalog1.which_course(name2) == -1 && catalog2.which_course(name2) == 2){
        std::cout << "which_course passes the tests\n";
    }else{
        std::cout << "which_course failed at least one test\n";
    }
    std::cout << "\nTesting copy_course\n";

    catalog2.copy_course(cs229);
    catalog2.print();
    

}

int main(){
    
    //lab5_part1_main();
    courses_test();
    //pstring_test();

}