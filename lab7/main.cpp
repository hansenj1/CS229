/* main file for linked lists
Andrew Shallue, CS229, Fall 2024
*/

#include "LLNode.h"
#include "LinkedList.h"
//#include "LinkedListPlus.h"
#include <iostream>

void part1_test(){
    std::cout << "This is Andrew's test function for Lab6 Part1 \n\n";
    LinkedList ll1 = LinkedList();
    std::cout << "Should see an error while attempting to Pop an empty list:\n";
    ll1.Pop();
  
    ll1.Append('A'); ll1.Append('B'); ll1.Append('C');
    ll1.Append('D'); ll1.Append('E'); ll1.Append('F');
    std::cout << ll1.ToString() << std::endl;  // should see [A, B, C, D, E, F]
    if(ll1.GetSize() == 6){
        std::cout << "ll1 has correct size\n";
    }else{
        std::cout << "ll1 does not have the correct size after Append\n";
    }

    std::cout << "\nCreating two new objects using the other two constructors\n";
    char name[] = "AndrewShallue";
    LinkedList ll2 = LinkedList(name);
    std::cout << ll2.ToString() << std::endl;  //should see [A, n, d, r, e, w, S, h, a, l, l, u, e]
    LinkedList ll3 = LinkedList(ll1);
    std::cout << ll3.ToString() << std::endl;  // should see [A, B, C, D, E, F]
    if(ll2.GetSize() == 13 && ll3.GetSize() == 6){
        std::cout << "sizes are correct for ll2 and ll3\n";
    }else{
        std::cout << "one of ll2 or ll3 has the incorrect size\n";
    }

    std::cout << "\nTesting Pop and Insert\n";
    ll2.Pop();  ll2.Pop();  ll2.Pop();
    std::cout << "After 3 pops, should see AndrewShal\n";
    std::cout << ll2.ToString() << std::endl;
    char c1 = ll2.Pop(7);  char c2 = ll2.Pop(7); char c3 = ll2.Pop(7);
    std::cout << "After 3 more pops, should see AndrewS\n";
    std::cout << ll2.ToString() << std::endl;
    std::cout << "The three chars popped were " << c1 << " " << c2 << " " << c3 << " " << "\n";
    std::cout << "Two Pops that should have no effect, should see error messages:\n";
    ll2.Pop(-1);  ll2.Pop(100);
    std::cout << ll2.ToString() << std::endl;

    ll2.Insert('D', 0);  ll2.Insert('R', 7);
    std::cout << ll2.ToString() << std::endl;  // should see DAndrewRS
    std::cout << "Final size of ll2 should be 9: " << ll2.GetSize() << "\n";
}

void part2_test(){
  char name[] = "andrewandrewaaa";
  LinkedList ll1 = LinkedList(name);
  std::cout << ll1.ToString() << "\n";  // should see andrewandrewaa

  std::cout << ll1.Get(0) << " " << ll1.Get(6) << " " << ll1.Get(12) << "\n";
  if(ll1.Contains('a') && !ll1.Contains('z')){
    std::cout << "two Contains values are correct\n";
  }else{
    std::cout << "one of the two Contains values are incorrect\n";
  }
  ll1.Set('1', 12);  ll1.Set('2', 13);  ll1.Set('3', 14);
  std::cout << ll1.ToString() << "\n";  // shoudl see andrewandrew123
  std::cout << "\n";

  // Over-declared to test constructor.
  char test_array[20] = "123456";
  LinkedList ll2 = LinkedList(test_array);
  std::cout << ll2.ToString() << " has size " << ll2.GetSize() << std::endl; 
  // Expecting 1 2 3 4 5 6 has size 6

  char testArray[] = "abcde";
  LinkedList ll3 = LinkedList(testArray);
  std::cout << ll3.ToString() << " has size " << ll3.GetSize() << std::endl; 
  // Expecting a b c d e has size 5

  ll2.Extend(ll3);
  std::cout << ll2.ToString() << " has size " << ll2.GetSize() << std::endl; 
  // Expecting 1 2 3 4 5 6 a b c d e has size 11
  LinkedList ll4 = ll2.Slice(2, 4);
  std::cout << ll4.ToString() << " has size " << ll4.GetSize() << std::endl; 
  // Expecting 3 4 has size 2

  ll4 = ll3.Slice(1, 1);
  std::cout << ll4.ToString() << " has size " << ll4.GetSize() << std::endl; 
  // Expecting [] has size 0

  ll3.Extend(ll4);
  std::cout << ll3.ToString() << " has size " << ll3.GetSize() << std::endl; 
  // Expecting a b c d e has size 5

  ll3.Reverse();
  std::cout << ll3.ToString() << std::endl;
  // Expecting e d c b a
}
/*
void part3_test(){
    char name[] = "Andrew";
    LinkedListPlus ll0 = LinkedListPlus();
    LinkedListPlus ll1 = LinkedListPlus(name);
    std::cout << ll1.ToString() << " has size " << ll1.GetSize();
    std::cout << " and access_ points at " << ll1.AtAccess() << "\n";

    ll1.MoveAccess(0);
    std::cout << "access_ points at " << ll1.AtAccess() << "\n";
    ll1.MoveAccess(2);
    std::cout << "access_ points at " << ll1.AtAccess() << "\n";
    ll1.SetAccess('$');
    std::cout << ll1.ToString() << "\n";

    ll1.PopAccess(); ll1.PopAccess();
    std::cout << ll1.ToString() << "\n";

    ll1.InsertAccess('1');  ll1.InsertAccess('2');
    std::cout << ll1.ToString() << "\n";
}
*/

int main(){
    //LLNode_main();

    part1_test();
    part2_test();
    //part3_test();
}