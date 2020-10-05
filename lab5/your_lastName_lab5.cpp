//Author:
//Date:
//Class: CS1428 HL1
//Description: This program will connect four code modules to make a convenient
//      program for school administration.

#include<iostream>
#include<fstream>

using namespace std;

const int CLASS_SIZE = 10;

//Generate ID
//Parameters: none
//Returns: the student's ID number
//Side effects: none
string generate_ID();

//Accepted
//Parameters: none
//Returns: 'a' if the student is accepted, 'w' for waitlist, 'n' for not accepted
//Side effects: none
char accepted();

//Build Catalog
//Parameters: an output filestream
//Returns: none
//Side effects: Writes course information to file
void build_catalog(ofstream&);

//Grade Book
//Parameters: an array of student grades
//Returns: none
//Side effects: print max, min, and avg to console
void grade_book(float[]);

int main(){
    //Q1: create an output filestream in append mode and open "catalog.txt"

    //Q2: create a loop that will run until the user chooses to quit

        //Q3: print the menu and accept the user's choice


        //Q4: branch to call the correct function
        switch(){
            //Q5: choice is 'i'
            //Print the student ID to console
            case 'i':

                break;

            //Q6: choice is 'a'
            //Print "accepted", "wait list", or "do not accept"
            case 'a':

                break;

            //Q7: choice is 'c'
            //Pass your filestream to the build_catalog function
            case 'c':

                break;

            //Q8: choice is 'g'
            //Store 10 grades in an array and pass the array to grade_book
            case 'g':

                break;

            //Q9: choice is 'q'
            //Prtint a goodbye message
            case 'q':

                break;

            //Q10: print an error if the user chooses an option that is not on the menu
            default:

                break;
        }


    //Q11: close the filestream

    return 0;
}

int numberOfCharacter(char a){
    return int(a) - 'A' + 1;
}

string generate_ID(){
    //Define your variables here
    string firstName;
    char lastInitial;
    int birthYear;
    char fallOrSpring;
    int last4;

    //Print questions and take answers here
    cout << "What is the student's first name: ";
    cin >> firstName;
    cout << "What is the first letter of the last name (capitalized): ";
    cin >> lastInitial;
    cout << "What year was the student born in: ";
    cin >> birthYear;
    cout << "Will the student start school in the Fall or the Spring (F or S): ";
    cin >> fallOrSpring;
    cout << "What are the last 4 digits of the student's social: ";
    cin >> last4;

    //generate and print the ID number on the console
    int group1 =  numberOfCharacter(lastInitial)+numberOfCharacter(fallOrSpring);
    int group2 =  birthYear + (last4%1337);

    return to_string(group1) + "-" + to_string(group2);
}

char accepted(){
    //get user input and store in appropriate variables
    float gpa;
    int act, zip;
    cout << "What is this students GPA: ";
    cin >> gpa;
    cout << "How many extracurricular activities: ";
    cin >> act;
    cout << "What ZIP code is this student’s address in: ";
    cin >> zip;

    //adjust gpa using extracurricular activities
    if (act > 3) gpa += 0.3;
    else gpa += (0.1 * act);

    //print "accept", "wait list", or "do not accept" using adjusted gpa
    //this output should be on the console
    //if the ourput is accept, write the name to accepted.txt on its own line

    if (zip == 78666){
        if (gpa > 3.5) {
            return 'a';
        }
        else if(gpa > 3.2)
            return 'w';
        else
            return 'n';

    }
    else{
        if (gpa > 3.7) {
            return 'a';
        }
        else if(gpa > 3.4)
            return 'w';
        else
            return 'n';
    }
}

void build_catalog(ofstream &outFile){
    string prefix;
    int cNumber, cYear;
    char semester, pfOrL, saveFile;
    //course prefix
    //Valid answers: "CS", "LANG", or "ECE"
    do{
        cout << "What is the course prefix(CS, LANG, or ECE):";
        cin >> prefix;
    }while(prefix != "CS" && prefix != "LANG" && prefix != "LANG");

    //course number
    //Valid answers: 1000-4999
    do{
        cout << "What is the course number(1000-4999): ";
        cin >> cNumber;
    }while(cNumber < 1000 || cNumber > 4999);

    //semester
    //Valid answers: F, S
    do{
        cout << "What semester is this course taught(F or S): ";
        cin >> semester;
    }while(semester != 'F' && semester != 'S');

    //course year
    //Valid answers: 2020+
    cYear = 0;
    while(cYear < 2020){
        cout << "What year will this course be taught(2020 or later): ";
        cin >> cYear;
    }

    //pass/fail or letter
    //Valid answers: P, L
    pfOrL = 'a';
    while(pfOrL != 'P' && pfOrL != 'L'){
        cout << "Pass/fail or letter grade (P or L): ";
        cin >> pfOrL;
    }
    cout << endl;
    //write to file
    outFile << prefix << "-" << cNumber << ", " << semester << " " << cYear << ", " << pfOrL << endl;
}

void grade_book(float studentGrades[]){
    int maximum = -1, minimum = 101;
    float total = 0.0;
    for(int i = 0; i < CLASS_SIZE; i++){
        //if grades[i] is the smallest processed yet, update the minimum variable
        if(studentGrades[i] < minimum) minimum = studentGrades[i];
        //if grades[i] is the largest processed yet, update the maximum variable
        if(studentGrades[i] > maximum) maximum = studentGrades[i];
        //add grades[i] into the sum variable
        total += studentGrades[i];
        i++;
    }

    cout << "The maximum grade is: " << maximum << endl;
    cout << "The minimum grade is: " << minimum << endl;
    cout << "The average grade is: " << total/CLASS_SIZE << endl;
}
