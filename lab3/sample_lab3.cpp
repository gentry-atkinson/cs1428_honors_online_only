//Author:
//Date:
//Class: CS1428 HL1
//Description: This program will automatically help build a course catalog

#include<iostream>
#include<fstream>

using namespace std;

int main(){
    //Q1: create an output filestream and open "catalog.txt" in append mode
    ofstream outFile("catalog.txt", std::fstream::app);

    int numCourses;
    do{
        cout << "How many courses will be entered: ";
        cin >> numCourses;
    }while(numCourses <= 0);
    cout << endl;

    string prefix;
    int cNumber, cYear;
    char semester, pfOrL, saveFile;

    //Q2: fill in the condition of this for loop so that its loop body will run
    //  numCourses times.
    for(int i = 0; i < numCourses; i++){
        //Q3A: course prefix
        //Valid answers: "CS", "LANG", or "ECE"
        do{
            cout << "What is the course prefix(CS, LANG, or ECE):";
            cin >> prefix;
        }while(prefix != "CS" && prefix != "LANG" && prefix != "LANG");

        //Q3B: course number
        //Valid answers: 1000-4999
        do{
            cout << "What is the course number(1000-4999): ";
            cin >> cNumber;
        }while(cNumber < 1000 || cNumber > 4999);

        //Q3C: semester
        //Valid answers: F, S
        do{
            cout << "What semester is this course taught(F or S): ";
            cin >> semester;
        }while(semester != 'F' && semester != 'S');

        //Q3D: course year
        //Valid answers: 2020+
        cYear = 0;
        while(cYear < 2020){
            cout << "What year will this course be taught(2020 or later): ";
            cin >> cYear;
        }

        //Q3E: pass/fail or letter
        //Valid answers: P, L
        pfOrL = 'a';
        while(pfOrL != 'P' && pfOrL != 'L'){
            cout << "Pass/fail or letter grade (P or L): ";
            cin >> pfOrL;
        }
        cout << endl;
        //Q3F: write to file
        //Valid answers: y, n
        saveFile = 'a';
        while(saveFile != 'y' && saveFile != 'n'){
            cout << prefix << "-" << cNumber << ", " << semester << " " << cYear << ", " << pfOrL << endl;
            cout << "Save this course? (y or n)";
            cin >> saveFile;
        }
        if (saveFile == 'y'){
            outFile << prefix << "-" << cNumber << ", " << semester << " " << cYear << ", " << pfOrL << endl;
        }

        cout << endl;
    }//end for loop

    cout << "Thank you. Goodbye." << endl;
    outFile.close();
    return 0;
}
