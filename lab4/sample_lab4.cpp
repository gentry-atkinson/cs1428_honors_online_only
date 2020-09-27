//Author:
//Date:
//Class: CS1428 HL1
//Description: This program will collect grades for one assignment

#include<iostream>
#include<fstream>

using namespace std;

//Q1: create a constant integer named CLASS_SIZE
const int CLASS_SIZE = 10;

int main(){
    //Q2: ask the user to enter a class title
    string classTitle;
    cout << "What is the title of this course: ";
    cin >> classTitle;
    //Q3: open an output filestream using the class title
    ofstream outFile(classTitle+".txt");
    //Q4: create an array with size CLASS_SIZE to hold the grades
    int studentGrades[CLASS_SIZE];

    //Q5: create variable to store a minimum grade, a maximum grade, and the
    //  sum of all of the grades. Initialize all of the variables.
    int maximum = -1, minimum = 101;
    float total = 0.0;

    //Q6: create a for loop
    //  Q6a: initialize a variable i=0;
    //  Q6b: run while i is less than CLASS_SIZE
    //  Q6c: increase i by 1 every time the loop runs
    for(int i = 0; i < CLASS_SIZE; i++){

    }

    return 0;
}
