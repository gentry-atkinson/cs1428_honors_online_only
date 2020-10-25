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


string generate_ID();

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
int searchRoster(const facultyMember[], string, string, int);
void sortRoster(facultyMember[], int);
void swap_roster(facultyMember&, facultyMember&);

int main(){
    ofstream outFile("catalog.txt", std::fstream::app);

    char input;
    float grades[CLASS_SIZE];
    string studentID, firstName, lastName;
    facultyMember roster[MAX_FACULTY_SIZE];
    int numFaculty, foundAt;
    numFaculty = loadRoster(roster, MAX_FACULTY_SIZE);

    do{
        cout << "i- generate an ID" << endl;
        cout << "a- determine if a student is Accepted" << endl;
        cout << "c- enter a Course in the catalog" << endl;
        cout << "g- print the max, min, and avg Grade of an assignment" << endl;
        cout << "r- print the faculty Roster" << endl;
        cout << "n- add a New faculty member to the roster" << endl;
        cout << "s- Search the faculty roster" << endl;
        cout << "o- sOrt the faculty roster" << endl;
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
            case 's':
                cout << "First name to search: ";
                cin >> firstName;
                cout << "Last name to search: ";
                cin >> lastName;
                foundAt = searchRoster(roster, firstName, lastName, numFaculty);
                if(foundAt == -1) cout << "That name is not in the roster." << endl;
                else cout << firstName << " " << lastName << " found at index "
                    << foundAt << endl;
                break;
            case 'o':
                sortRoster(roster, numFaculty);
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
//######## Q1: fill in the search function functions #####################
//Search Roster
//This function should check every entry in the roster for a matching first name AND last name
//Parameters:
//      roster: an array of facultyMember structs that will be searched
//      firstName, lastName: two strings that both must be matched as search values
//      s: an integer size for the array
//Returns: the first index in roster that matches both names or -1 if no match is found
//Side effects: none
int searchRoster(const facultyMember roster[], string firstName, string lastName, int s){
    for(int i = 0; i < s; i++){
        if(firstName == roster[i].firstName && lastName == roster[i].lastName)
            return i;
    }
    return -1;
}



//######## Q2: fill in the sort function functions #####################
//Sort Roster
//This function should sort the roster alphabetically by last name. Use the compare
//function from the string library to determine the ordering of two strings
//Parameters:
//      roster: an array of facultyMember structs that will be searched
//      s: an integer size for the array
//Returns: nothing
//Side Effects
void sortRoster(facultyMember roster[], int s){
    bool done = false;
    int maxElement = s-1;
    while(!done){
        done = true;
        for(int i = 0; i < maxElement; i++){
            if(roster[i].lastName.compare(roster[i].lastName) < 0){
                swap_roster(roster[i], roster[i+1]);
                done = false;
            }
        }
        maxElement--;
    }
    return;
}



//############### DON'T MAKE ANY CHANGES BELOW THIS LINE#######################
void swap_roster(facultyMember &a, facultyMember &b){
    facultyMember temp;

    temp.firstName = a.firstName;
    temp.lastName = a.lastName;
    temp.department = a.department;
    temp.title = a.title;

    a.firstName = b.firstName;
    a.lastName = b.lastName;
    a.title = b.title;
    a.department = b.department;

    b.firstName = temp.firstName;
    b.lastName = temp.lastName;
    b.title = temp.title;
    b.department = temp.department;

    return;
}

//Add Faculty Member
//Parameters: the roster and an index to write to
//Return: the next valid index to write
//Side Effects: one entry has been written into the roster.
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
//Parameters: the roster and its size
//Returns: nothing
//Side Effects: the formatted roster is printed on the console
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
//Parameters: the roster and its size
//Returns: nothing
//Side Effects: the roster.txt file is overwritten with the current contents of roster
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
//Parameters: the array to load, and a max size
//Returns: the number of facutlty members read from the file
//Side Effects: the roster has some number less than m entries filled in
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
