//Author:
//Date:
//Class: CS1428 HL1
//Description: This program will automatically review students for admissions
//  at a university.

#include<iostream>
#include<fstream>

using namespace std;

int main(){
    //get user input and store in appropriate variables
    string name;
    float gpa;
    int act, zip;
    cout << "What is this students last name: ";
    cin >> name;
    cout << "What is this students GPA: ";
    cin >> gpa;
    cout << "How many extracurricular activities: ";
    cin >> act;
    cout << "What ZIP code is this student’s address in: ";
    cin >> zip;

    //open the output file stream in append mode using open("accepted.txt", std::fstream::app)
    ofstream outFile;
    outFile.open("accepted.txt", std::fstream::app);

    //adjust gpa using extracurricular activities
    if (act > 3) gpa += 0.3;
    else gpa += (0.1 * act);

    //print "accept", "wait list", or "do not accept" using adjusted gpa
    //this output should be on the console
    //if the ourput is accept, write the name to accepted.txt on its own line

    if (zip == 78666){
        if (gpa > 3.5) {
            cout << "accept" << endl;
            outFile << name << endl;
        }
        else if(gpa > 3.2)
            cout << "wait list" << endl;
        else
            cout << "do not accept" << endl;

    }
    else{
        if (gpa > 3.7) {
            cout << "accept" << endl;
            outFile << name << endl;
        }
        else if(gpa > 3.4)
            cout << "wait list" << endl;
        else
            cout << "do not accept" << endl;
    }

    outFile.close();
    return 0;
}
