//Author:
//Date:
//Class: CS1428 HL1
//Description: This program will time and test two search algorithms using parallelism
#include<iostream>
#include<omp.h>
#include<chrono>
#include<cstdlib>

using namespace std;
using namespace std::chrono;

const int NUMBER_OF_CORES = 4;

//Fill in the definition of calcEfficiency
int seqSearch(const int[], int, int);
int parSearch(const int[], int, int);
float calcEfficiency(float, float);

//### Do not make any changes to the Main function###
int main(){

  const int LIST_SIZE = 100000;
  const int SEARCH_VALUE = 1337;
  int list[LIST_SIZE];

  //Assign a random value to every entry in the list and then make sure that
  //the search term is included in the list somewhere
  srand(23);
  for(int i = 0; i < LIST_SIZE; i++) list[i] = rand();
  list[rand() % LIST_SIZE] = SEARCH_VALUE;

  //time a run of sequential search
  auto start = high_resolution_clock::now();
  int seqFound = seqSearch(list, LIST_SIZE, SEARCH_VALUE);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  float seqDuration = static_cast<float>(duration.count());

  //time a run of parallel search
  start = high_resolution_clock::now();
  int parFound = parSearch(list, LIST_SIZE, SEARCH_VALUE);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  float parDuration = static_cast<float>(duration.count());

  //print results
  cout << "Sequential search found the value " << SEARCH_VALUE << " at index "
    << seqFound << " in " << seqDuration << " microseconds" << endl;

  cout << "Parallel search found the value " << SEARCH_VALUE << " at index "
    << parFound << " in " << parDuration << " microseconds" << endl;
  cout << "The efficiency of the parallel algorithm is: " << calcEfficiency(seqDuration, parDuration)
    << endl;

  return 0;
}

//Sequential Search
//Parameters:
//  arr: the list to search
//  s: the size of the list arr
//  value: the term to search for in arr
//Return: an index with value in arr
//Side Effects:none
//###Do not make changes to this function###
int seqSearch(const int arr[], int s, int value){
  int foundAt = -1;

  for(int i = 0; i < s; i++){
        if(arr[i] == value) foundAt = i;
  }

  return foundAt;
}

//Parallel Search
//Parameters:
//  arr: the list to search
//  s: the size of the list arr
//  value: the term to search for in arr
//Return: an index with value in arr
//Side Effects:none
//###Do not make changes to this function###
int parSearch(const int arr[], int s, int value){
  int foundAt = -1;
  omp_set_num_threads(NUMBER_OF_CORES);

  #pragma omp parallel for
  for(int i = 0; i < s; i++){
        if(arr[i] == value) foundAt = i;
  }

  return foundAt;
}

//Calculate Efficiency
//Parameters:
//
//Return:
//Side Effects:
float calcEfficiency(float seqRunTime, float parRunTime){
    return (seqRunTime/parRunTime)/NUMBER_OF_CORES;
}
