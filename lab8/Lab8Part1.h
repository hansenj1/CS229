// Header file for Lab 8 Part 1
// Authors: Jules Weick and Jack Hansen

#ifndef L8P1
#define L8P1

#include <iostream>

void increment(int& index, int capacity);
int hash(int key, int capacity);
void add_basic(int key, int arr[], int& size, int capacity);
bool check_basic(int key, int arr[], int& size, int capacity);
void print(int capacity);
void lab8_part1_main();

#endif