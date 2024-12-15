//Lab 9 part 1
//Jack Hansen and Jules Weick, 11/12/2024
//working with iterators and trees

#include "Lab9Part1.h"
#include<iostream>

void print_vector(vector<int> nums){
    //This function will print out each element of a vector on one line
    //Parameters:
    //vector<int> nums: a vector of integers to be printed
    //Returns:
    //Nothing 
    for(int i = 0; i < nums.size(); i++){
        std::cout << nums.at(i) << " ";
    }
    std::cout << "\n";
}

bool is_div(int num){
    //This function will return whether a number is divisible by 11 or not, demonstrated by either true or false
    //Parameters:
    //int num the number to be checked
    //Returns:
    //Either true or false
    return num % 11 == 0;

}

void lab9_part1_main(){
    //main function for testing and running of part1
    vector<int> nums1;
    vector<int> nums2;
    //put 3-11 in the vector nums1
    for(int i = 3; i <= 11; i++){
        nums1.push_back(i);
    }
    //put 5,10,15,20 in nums2
    for(int i = 5; i <= 20; i+=5){
        nums2.push_back(i);
    }
    //declare iterators it1 and it2
    vector<int>::iterator it1;
    vector<int>::iterator it2;
    

    //printing nums1 and nums2 using different methods of printing
    std::cout << "printing nums1 using print_vector(): \n";
    print_vector(nums1);
    std::cout << "printing nums1 using iterator: \n";
    it1 = nums1.begin();
    while(it1 != nums1.end()){
        std::cout << *it1 << " ";
        it1++;
    }
    std::cout << "\n";
    std::cout << "printing nums2 using print_vector(): \n";
    print_vector(nums2);
    std::cout << "printing nums2 using iterator: \n";
    it2 = nums2.begin();
    while(it2 != nums2.end()){
        std::cout << *it2 << " ";
        it2++;
    }
    std::cout << "\n";
    std::cout << "nums1 iterator after being pushed out of bounds: " << *(it1+1000);
    std::cout << "\n";
    //erasing stuff from list
    it1 = nums1.begin();
    nums1.erase(it1+2); //erases the element at position 2
    nums1.erase(it1+ 2, it1 + 5);
    std::cout << "contents of nums1 after erasing: \n";
    print_vector(nums1);
    std::cout << "\n";
    for(int i = 0; i < nums1.size(); i++){
        // in order to get it in the order from the lab document,
        // need to add i to account for the size of the vector
        // changing.
        nums2.insert(nums2.begin() + 1 + i, nums1.at(i));
    }
    std::cout << "nums2 after inserting nums1: ";
    print_vector(nums2); //[5 3 4 9 10 11 10 15 20]
    std::cout << "\n";
    std::sort(nums2.begin(), nums2.end());
    std::cout << "nums2 after sorting: ";
    print_vector(nums2);
    it1 = std::lower_bound(nums2.begin(), nums2.end(), 7);
    std::cout << "Checking reference after lower_bound call: " << *it1 << "\n";
    it2 = std::find_if(nums2.begin(), nums2.end(), is_div);
    std::cout << "Checking reference after find_if call: " << *it2 << "\n";
}