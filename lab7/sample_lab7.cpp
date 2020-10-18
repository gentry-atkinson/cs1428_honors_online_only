//Author:
//Date:
//Class: CS1428 HL1
//Description: This program will connect four code modules to make a convenient
//      program for school administration.
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

const int CLASS_SIZE = 10;
const int MAX_FACULTY_SIZE = 10;

//Generate ID
//Parameters: none
//Returns: the student's ID number
//Side effects: none
string generate_ID();

//Q1: Define your facutlyMember struct here
struct facultyMember{
    string firstName;
    string lastName;
    string title;
    string department;
};

char accepted();
void build_catalog(ofstream&);
void grade_book(float[]);

int addFacultyMember(facultyMember[], int);
void printRoster(facultyMember[], int);
void saveRoster(facultyMember[], int);
int loadRoster(facultyMember[], const int);

int main(){
    ofstream outFile("catalog.txt", std::fstream::app);

    char input;
    float grades[CLASS_SIZE];
    string studentID;
    facultyMember roster[MAX_FACULTY_SIZE];
    int numFaculty;
    numFaculty = loadRoster(roster, MAX_FACULTY_SIZE);

    do{
        cout << "i- generate an ID" << endl;
        cout << "a- determine if a student is Accepted" << endl;
        cout << "c- enter a Course in the catalog" << endl;
        cout << "g- print the max, min, and avg Grade of an assignment" << endl;
        cout << "r- print the faculty Roster" << endl;
        cout << "n- add a New faculty member to the roster" << endl;
        cout << "q- Quit the program" << endl;
        cout << "Please select one option from the menu: ";
        cin >> input;

        switch(input){
            case 'i':
                studentID = generate_ID();
                cout << "Student ID: " << studentID << endl;
                break;
            case 'a':
                switch(accepted()){
                    case 'a':
                        cout << "accepted" << endl;
                        break;
                    case 'w':
                        cout << "wait list" << endl;
                        break;
                    case 'n':
                        cout << "not accepted" << endl;
                        break;
                }
                break;
            case 'c':
                build_catalog(outFile);
                break;
            case 'g':
                for(int i = 0; i < CLASS_SIZE; i++){
                    cout << "Enter one grade: ";
                    cin >> grades[i];
                }
                grade_book(grades);
                break;
            case 'r':
                printRoster(roster, numFaculty);
                break;
            case 'n':
                numFaculty = addFacultyMember(roster, numFaculty);
                break;
            case 'q':
                saveRoster(roster, numFaculty);
                cout << "Thank you for using this program." << endl;
                break;
            default:
                cout << "That is not a valid selection." << endl;
                break;
        }
    }while(input!='q');

    outFile.close();
    return 0;
}
//######## Q2: fill in the functions below #####################

//Add Faculty Member
//This function should ask the user for information about a faculty member and
//store that information in the roster
//Parameters:
//    an array of facultyMembers to
//    an integer index to save the new values in
//Returns: the next valid index to write into
//Side Effects: roster[index] has new information stored in it
int addFacultyMember(facultyMember roster[], int index){
    cout << "What is the faculty member's first name: ";
    cin >> roster[index].firstName;
    cout << "What is the faculty member's last name: ";
    cin >> roster[index].lastName;
    cout << "What is the faculty member's title: ";
    cin >> roster[index].title;
    cout << "What department do they work for: ";
    cin >> roster[index].department;
    return index + 1;
}

//Print Roster
//This function should print ever faculty member stored in the roster on the console
//Parameters:
//    an array of facultyMembers with information stored in some indexes
//    an integer indicating how many factulty members are stored in the array
//Return: nothing
//Side Effects: none
void printRoster(facultyMember roster[], int s){
    cout << endl;
    for(int i = 0; i < s; i++){
        cout << "Name: " << roster[i].title << " " << roster[i].firstName
            << " " << roster[i].lastName << endl;
        cout << "Department: " << roster[i].department << endl << endl;
    }
    return;
}

//Save Roster
//This function should open an output (not append) filestream to the file "roster.txt"
//and should write the roster to the file with one entry on each line and whitespace
//separating each value.
//Parameters:
//    an array of facultyMembers
//    an index indicating how many entries are stored in the roster
//Return: nothing
//Side effects: the file "roster.txt" has been updated
void saveRoster(facultyMember roster[], int s){
    ofstream out("roster.txt");
    for(int i = 0; i < s; i++){
        out << roster[i].firstName << " ";
        out << roster[i].lastName << " ";
        out << roster[i].title << " ";
        out << roster[i].department;
        out << endl;
    }
    return;
}

//Load Roster
//#########YOU DO NOT NEED TO CHANGE THIS FUNCTION#####################
//This function will read the file "roster.txt" and save the values in an array
//Parameters
int loadRoster(facultyMember roster[], const int m){
    int i = 0;
    ifstream in("roster.txt");
    while(true){
        in >> roster[i].firstName;
        in >> roster[i].lastName;
        in >> roster[i].title;
        in >> roster[i].department;
        if (in.peek() == EOF){
            //cout << "End of roster file reach" << endl;
            return i;
        }
        i++;
        if(i >= m){
            //cout << "Max entries reached" << endl;
            return m;
        }
    }
    return m;
}

int numberOfCharacter(char a){
    return int(a) - 'A' + 1;
}

//############### DON'T MAKE ANY CHANGES BELOW THIS LINE#######################

//Generate ID
//Parameters: none
//Returns: the student's ID number
//Side effects: none
string generate_ID(){
    string firstName;
    char lastInitial;
    int birthYear;
    char fallOrSpring;
    int last4;

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

    int group1 =  numberOfCharacter(lastInitial)+numberOfCharacter(fallOrSpring);
    int group2 =  birthYear + (last4%1337);

    return to_string(group1) + "-" + to_string(group2);
}

//Accepted
//Parameters: none
//Returns: 'a' if the student is accepted, 'w' for waitlist, 'n' for not accepted
//Side effects: none
char accepted(){
    float gpa;
    int act, zip;
    cout << "What is this students GPA: ";
    cin >> gpa;
    cout << "How many extracurricular activities: ";
    cin >> act;
    cout << "What ZIP code is this student’s address in: ";
    cin >> zip;

    if (act > 3) gpa += 0.3;
    else gpa += (0.1 * act);

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

//Build Catalog
//Parameters: an output filestream
//Returns: none
//Side effects: Writes course information to file
void build_catalog(ofstream &outFile){
    string prefix;
    int cNumber, cYear;
    char semester, pfOrL, saveFile;
    do{
        cout << "What is the course prefix(CS, LANG, or ECE):";
        cin >> prefix;
    }while(prefix != "CS" && prefix != "LANG" && prefix != "LANG");

    do{
        cout << "What is the course number(1000-4999): ";
        cin >> cNumber;
    }while(cNumber < 1000 || cNumber > 4999);

    do{
        cout << "What semester is this course taught(F or S): ";
        cin >> semester;
    }while(semester != 'F' && semester != 'S');

    cYear = 0;
    while(cYear < 2020){
        cout << "What year will this course be taught(2020 or later): ";
        cin >> cYear;
    }

    pfOrL = 'a';
    while(pfOrL != 'P' && pfOrL != 'L'){
        cout << "Pass/fail or letter grade (P or L): ";
        cin >> pfOrL;
    }
    cout << endl;
    outFile << prefix << "-" << cNumber << ", " << semester << " " << cYear << ", " << pfOrL << endl;
    return;
}

//Grade Book
//Parameters: an array of student grades
//Returns: none
//Side effects: print max, min, and avg to console
void grade_book(float studentGrades[]){
    int maximum = -1, minimum = 101;
    float total = 0.0;
    for(int i = 0; i < CLASS_SIZE; i++){
        if(studentGrades[i] < minimum) minimum = studentGrades[i];
        if(studentGrades[i] > maximum) maximum = studentGrades[i];
        total += studentGrades[i];
    }

    cout << "The maximum grade is: " << maximum << endl;
    cout << "The minimum grade is: " << minimum << endl;
    cout << "The average grade is: " << total/CLASS_SIZE << endl;
    return;
}
