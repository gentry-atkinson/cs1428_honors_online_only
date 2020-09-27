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
        //Q7a: prompt the user to enter a grade using a do...while loop
        do{
            cout << "Pleaes enter one grade: ";
            cin >> studentGrades[i];
        }while(studentGrades[i] < 0 || studentGrades[i] > 100);
        //Q7b: store the new grade in the file
        outFile << studentGrades[i] << endl;
    }

    //Q8: create a while loop
    //  Q8a: initialize a variable i=0;
    //  Q8b: run while i is less than CLASS_SIZE
    //  Q8c: increase i by 1 every time the loop runs
    int i = 0;
    while(i < CLASS_SIZE){
        //Q9a: if grades[i] is the smallest processed yet, update the minimum variable
        if(studentGrades[i] < minimum) minimum = studentGrades[i];
        //Q9b; if grades[i] is the largest processed yet, update the maximum variable
        if(studentGrades[i] > maximum) maximum = studentGrades[i];
        //Q9c: add grades[i] into the sum variable
        total += studentGrades[i];
        i++;
    }

    //Q10a: print the maximum grade
    cout << "The maximum grade is: " << maximum << endl;
    //Q10b: print the minimum grade
    cout << "The minimum grade is: " << minimum << endl;
    //Q10c: print the average grade
    cout << "The average grade is: " << total/CLASS_SIZE << endl;

    //Q11: close your output file and print a goodbye message
    outFile.close();
    cout << "Thank you. Goodbye." << endl;

    return 0;
}
