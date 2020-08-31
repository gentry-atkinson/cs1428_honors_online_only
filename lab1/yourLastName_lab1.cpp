//Author:
//Date:
//Class: CS1428 HL1
//Description: This program will create a student ID number and save a student's
//    information in a separate file.

#include<iostream>
#include<fstream>

using namespace std;

//This function will print the number of a letter from the alphabet
//A = 1, B = 2, C = 3, and so on...
int numberOfCharacter(char a){
    return int(a) - 'A' + 1;
}

int main(){
    //Define your variables here

    //Print questions and take answers here

    //open the filestream with a unique name
    outFile.open(firstName + ".txt");

    //write the answers to the file

    //generate and print the ID number on the console

    outFile.close();
    return 0;
}
