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
    string firstName;
    char lastInitial;
    int birthYear;
    char fallOrSpring;
    int last4;
    ofstream outFile;

    //Print questions and take answers here
    cout << "What is your first name: ";
    cin >> firstName;
    cout << "What is the first letter of your last name (capitalized): ";
    cin >> lastInitial;
    cout << "What year were you born in: ";
    cin >> birthYear;
    cout << "Will you start school in the Fall or the Spring (F or S): ";
    cin >> fallOrSpring;
    cout << "What are the last 4 digits of your social: ";
    cin >> last4;

    //open the filestream with a unique name
    outFile.open(firstName + ".txt");

    //write the answers to the file
    outFile << firstName << ", ";
    outFile << lastInitial << ", ";
    outFile << birthYear << ", ";
    outFile << fallOrSpring << ", ";
    outFile << last4 << endl;

    //generate and print the ID number on the console
    cout << numberOfCharacter(lastInitial)+numberOfCharacter(fallOrSpring);
    cout << "-";
    cout << birthYear + (last4%1337);

    outFile.close();

    return 0;
}
