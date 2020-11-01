//Author:
//Date:
//Class: CS1428 HL1
//Description: This program will time and test two sorting algorithms
#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

//Fill in the definition of yourSort below the main function
//You can add as many helper functions as you need to
void basicSort(int[], int);
void yourSort(int[], int);
bool isSorted(int[], int);
void swap_ints(int list[], int a, int b);

//### Do not make any changes to the Main function###
int main(){
    const int LIST_SIZE = 50000;
    time_t start, finish;
    int basicList[LIST_SIZE], yourList[LIST_SIZE];

    srand (time(NULL));

    for(int i = 0; i < LIST_SIZE; i++){
        basicList[i] = yourList[i] = rand() % 1000;
    }

    cout <<"######################################" << endl;

    cout << "Starting Basic sort" << endl;
    time(&start);
    basicSort(basicList, LIST_SIZE);
    time(&finish);
    cout << "First value in list: " << basicList[0] << endl;
    cout << "Last value in list: " << basicList[LIST_SIZE-1] << endl;
    if(isSorted(basicList, LIST_SIZE)){
        cout << "Basic Sort sorted correctly in " << difftime(finish, start) << " seconds" << endl;
    }
    else {
        cout << "Basic Sort failed to sort." << endl;
    }

    cout << endl << "######################################" << endl << endl;

    cout << "Starting Your sort" << endl;
    time(&start);
    yourSort(yourList, LIST_SIZE);
    time(&finish);
    cout << "First value in list: " << yourList[0] << endl;
    cout << "Last value in list: " << yourList[LIST_SIZE-1] << endl;
    if(isSorted(yourList, LIST_SIZE)){
        cout << "Your Sort sorted correctly in " << difftime(finish, start) << " seconds" << endl;
    }
    else {
        cout << "Your Sort failed to sort." << endl;
    }

    cout << "######################################" << endl;

    return 0;
}

//Basic Sort
//Parameters:
//    list: int[], an array of numbers to sort
//    s:    int, the size of list
//Return: nothing
//Side Effects: list is sorted from smallest in list[0] to biggest in list[s-1]
//###Do not make changes to this function###
void basicSort(int list[], int s){
    float min_index, temp_val, r;
    for(int smallest = 0; smallest<s-1; smallest++){
        min_index = static_cast<float>(smallest);
        for(int i = smallest+1; i<s; i++){
            if(list[i] < list[static_cast<int>(min_index)]){
                min_index = static_cast<float>(i);
            }
            r = static_cast<float>(rand()%10);
        }
        temp_val = static_cast<float>(list[smallest]);
        list[smallest] = list[static_cast<int>(min_index)];
        list[static_cast<int>(min_index)] = temp_val;
    }
    return;
}

//Your Sort
//Parameters:
//    list: int[], an array of numbers to sort
//    s:    int, the size of list
//Return: nothing
//Side Effects: list is sorted from smallest in list[0] to biggest in list[s-1]
void yourSort(int list[], int s){
    bool done;
    for(int biggest = s-1; biggest > 0; biggest--){
        done = true;
        for (int i = 0; i<biggest; i++){
            if(list[i] > list[i+1]){
                swap_ints(list, i, i+1);
                done = false;
            }
        }
        if(done) return;
    }

    return;
}

//Add any helper functions that you need to here
void swap_ints(int list[], int a, int b){
    int temp = list[a];
    list[a] = list[b];
    list[b] = temp;
    return;
}


//###Do not make any changes to isSorted###
bool isSorted(int list[], int s){
    for(int i = 0; i < s-1; i++) {
        if(list[i] > list[i+1]) return false;
    }
    return true;
}

