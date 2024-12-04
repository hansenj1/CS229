/* Test code for Lab8.
Andrew Shallue, Fall 2024, CS229
*/
// Main file for Lab 8.
// Provided by professor Shallue, any modifications by: Jack Hansen and Jules Weick

#include <iostream>
#include "HashMapLL.h"
#include "HashMapLinear.h"
#include "Lab8Part1.h"
#include <cstring>

void part2_test(){
    // testing rule of 3
    std::cout << "Testing rule of 3\n";
    HashMapLL hml1 = HashMapLL();
    for(int i = 0; i < 2; i++){
        hml1.add('a');
    }
    hml1.print();
    std::cout << "hml1 size, capacity, load: " << hml1.get_size() << " ";
    std::cout << hml1.get_capacity() << " " << hml1.get_load() << "\n";

    HashMapLL hml2(hml1);
    hml2.print();
    std::cout << "hml2 size, capacity, load: " << hml2.get_size() << " ";
    std::cout << hml2.get_capacity() << " " << hml2.get_load() << "\n";
    
    HashMapLL hml3;
    hml3 = hml1;
    hml3.print();
    std::cout << "hml3 size, capacity, load: " << hml3.get_size() << " ";
    std::cout << hml3.get_capacity() << " " << hml3.get_load() << "\n";
    std::cout << "End of testing rule of 3\n\n";

    // testing creation, check, erase
    HashMapLL hms = HashMapLL();
    std::cout << "An empty HashMapLL:\n";
    hms.print();  // expecting rows 0 - 4, all empty
    std::cout << "\n";

    std::cout << "Adding some characters\n";
    char name[] = "Andre";
    for(int i = 0; i < strlen(name); i++){
        char c = name[i];
        hms.add(c);
    }
    // following print should have reallocated, so rows 0 - 9
    // with 0:[n,d], 1:[e], 4:[r], 5:[A].  size 5, load 0.5
    hms.print(); 
    std::cout << "hms size, capacity, load: " << hms.get_size() << " ";
    std::cout << hms.get_capacity() << " " << hms.get_load() << "\n";

    // 'A' and 'd' should be in it, 's' and 'm' not
    bool check1 = hms.check('A');
    bool check2 = hms.check('d');
    bool check3 = hms.check('m');
    bool check4 = hms.check('s');
    if(check1 && check2 && !check3 && !check4){
        std::cout << "all calls to check correct\n";
    }else{
        std::cout << "at least one call to check failed\n";
    }

    // attempting to erase 's' should give an error
    hms.erase('s');
    // erasing d and r should work
    hms.erase('d');
    hms.erase('r');
    // check result
    std::cout << "\n";
    hms.print();
    std::cout << "hms size, capacity, load: " << hms.get_size() << " ";
    std::cout << hms.get_capacity() << " " << hms.get_load() << "\n";
}

void part3_test(){
    // testing rule of 3
    std::cout << "Testing rule of 3\n";
    HashMapLinear hml1 = HashMapLinear();
    for(int i = 0; i < 2; i++){
        hml1.add('a');
    }
    hml1.print();
    std::cout << "hml1 size, capacity, load: " << hml1.get_size() << " ";
    std::cout << hml1.get_capacity() << " " << hml1.get_load() << "\n";

    HashMapLinear hml2(hml1);
    hml2.print();
    std::cout << "hml2 size, capacity, load: " << hml2.get_size() << " ";
    std::cout << hml2.get_capacity() << " " << hml2.get_load() << "\n";
    
    HashMapLinear hml3;
    hml3 = hml1;
    hml3.print();
    std::cout << "hml3 size, capacity, load: " << hml3.get_size() << " ";
    std::cout << hml3.get_capacity() << " " << hml3.get_load() << "\n";
    std::cout << "End of testing rule of 3\n\n";

    // testing creation, check, erase
    HashMapLinear hms = HashMapLinear();
    std::cout << "An empty HashMapLinear:\n";
    hms.print();  // expecting rows 0 - 4, all empty
    std::cout << "\n";

    std::cout << "Adding some characters\n";
    char name[] = "Andre";
    for(int i = 0; i < strlen(name); i++){
        char c = name[i];
        hms.add(c);
    }
    // following print should have reallocated, so rows 0 - 9
    // with 0:, 1:[e], 4:[r], 5:[A].  size 5, load 0.5
    hms.print(); 
    std::cout << "hms size, capacity, load: " << hms.get_size() << " ";
    std::cout << hms.get_capacity() << " " << hms.get_load() << "\n";

    // 'A' and 'd' should be in it, 's' and 'm' not
    bool check1 = hms.check('A');
    bool check2 = hms.check('d');
    bool check3 = hms.check('m');
    bool check4 = hms.check('s');
    if(check1 && check2 && !check3 && !check4){
        std::cout << "all calls to check correct\n";
    }else{
        std::cout << "at least one call to check failed\n";
    }

    // attempting to erase 's' should give an error
    hms.erase('s');
    // erasing d and r should work
    hms.erase('d');
    hms.erase('r');
    // check result
    std::cout << "\n";
    hms.print();
    std::cout << "hms size, capacity, load: " << hms.get_size() << " ";
    std::cout << hms.get_capacity() << " " << hms.get_load() << "\n";

    // check that I can still find e
    bool check5 = hms.check('e');
    if(check5){
        std::cout << "still found e after erasing some elements\n";
    }else{
        std::cout << "should have found e but didn't\n";
    }

    std::cout << "\n";
    hms.add('e');
    hms.add('e');
    hms.print();
    std::cout << "hms size, capacity, load: " << hms.get_size() << " ";
    std::cout << hms.get_capacity() << " " << hms.get_load() << "\n";
}

int main(){
    lab8_part1_main();
    // part2_test();
    // part3_test();
}