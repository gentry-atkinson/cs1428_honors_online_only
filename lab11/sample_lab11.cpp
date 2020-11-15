//Author:
//Date:
//Class: CS1428 HL1
//Description: This program will initialize a random array and print some statistics about it
#include<iostream>
#include<cstdlib>

using namespace std;

int findMaxValue(int arr[], int s);
int findMinValue(const int arr[], int s);
long findSum(const int arr[], int s);


//### Do not make any changes to the Main function###
int main(){

  const int LIST_SIZE = 10000;
  int arr[LIST_SIZE];

  //Assign a random value to every entry in the list and then make sure that
  //the search term is included in the list somewhere
  srand(23);
  for(int i = 0; i < LIST_SIZE; i++) arr[i] = rand();
  //for(int i = 0; i < LIST_SIZE; i++) cout << arr[i] << " ";
  //cout << endl;

  cout << "The smallest value in the list is: " << findMinValue(arr, LIST_SIZE) << endl;
  cout << "The largest value in the list is: " << findMaxValue(arr, LIST_SIZE) << endl;
  cout << "The sum of the values in the list is: " << findSum(arr, LIST_SIZE) << endl;

  return 0;
}

//Find Max Value
//Parameters:
//  arr:    an array of integers
//  s:      the size of arr
//Returns: the largest value in arr
//Side Effects: none
int findMaxValue(int arr[], int s){
    int maxIndex = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < s; j++){
            if(arr[j] > arr[maxIndex]) maxIndex = j;
        }
    }
    return arr[maxIndex];
}

//Find Min Value
//Parameters:
//  arr:    an array of integers
//  s:      the size of arr
//Returns: the smallest value in arr
//Side Effects: none
int findMinValue(const int arr[], int s){
    int arr_copy[s];
    for(int i = 0; i < s; i++)arr_copy[i] = arr[i];

    bool done = false;
    int temp, maxVal=s-1;
    while(!done){
        done = true;
        for(int i = 0; i<maxVal; i++){
            if(arr_copy[i] > arr_copy[i+1]){
                temp = arr_copy[i];
                arr_copy[i] = arr_copy[i+1];
                arr_copy[i+1] = temp;
                done = false;
            }
        }
        maxVal--;
    }
    return arr_copy[0];
}

//Just a helper function
void add(long &a, int b){
    a = a+b;
    return;
}

//Find Sum
//Parameters:
//  arr:    an array of integers
//  s:      the size of arr
//Returns: the sum of all values in arr
//Side Effects: none
long findSum(const int arr[], int s){
    long total = 0;
    for(int i = 0; i < s; i++){
        add(total, arr[i]);
    }
    return total;
}

