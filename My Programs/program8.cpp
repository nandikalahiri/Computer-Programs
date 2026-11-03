Q8. Design three classes: Student, Exam and Result. The student class has data members such as roll no, name etc. Create a class Exam by inheriting the
Student class. The Exam class adds data members representing the marks scored in six subjects. Derive the Result from class Exam and it has its own
members such as total marks. Write an interactive program to model this relationship. What type of inheritance this model belongs to?
  INPUT - 
  #include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// ---------------- Base class ----------------
class Student {
protected:
    int  rollNo;
    char name[64];

public:
    void getStudentData() {
        cout << "Enter Roll No   : ";
        cin  >> rollNo;
        cout << "Enter Name      : ";
        cin.ignore();
        cin.getline(name, 64);
    }

    void showStudentData() {
        cout << "Roll No : " << rollNo << "\n";
        cout << "Name    : " << name   << "\n";
    }
};

// ---------------- Derived class (Level 1) ----------------
// Exam inherits Student
class Exam : public Student {
protected:
    float marks[6];   // marks in 6 subjects

public:
    void getExamData() {
        cout << "\nEnter marks in 6 subjects (out of 100 each):\n";
        for (int i = 0; i < 6; i++) {
            cout << "  Subject " << (i + 1) << " : ";
            cin  >> marks[i];
        }
    }

    void showExamData() {
        cout << "\nMarks obtained:\n";
        for (int i = 0; i < 6; i++)
            cout << "  Subject " << (i + 1) << " : " << marks[i] << "\n";
    }
};

// ---------------- Derived class (Level 2) ----------------
// Result inherits Exam, which inherits Student  -> MULTILEVEL INHERITANCE
class Result : public Exam {
private:
    float totalMarks;
    float percentage;
    char  grade;

    void calculateResult() {
        totalMarks = 0;
        for (int i = 0; i < 6; i++)
            totalMarks += marks[i];

        percentage = totalMarks / 6.0f;   // 6 subjects, out of 100 each

        if (percentage >= 90)      grade = 'A';
        else if (percentage >= 75) grade = 'B';
        else if (percentage >= 60) grade = 'C';
        else if (percentage >= 40) grade = 'D';
        else                       grade = 'F';
    }

public:
    void processResult() {
        getStudentData();   // from Student
        getExamData();      // from Exam
        calculateResult();  // own method
    }

    void displayResult() {
        cout << "\n==================================================\n";
        cout << "                   RESULT SHEET\n";
        cout << "==================================================\n";
        showStudentData();  // from Student
        showExamData();     // from Exam
        cout << fixed << setprecision(2);
        cout << "\nTotal Marks : " << totalMarks << " / 600\n";
        cout << "Percentage  : " << percentage   << " %\n";
        cout << "Grade       : " << grade        << "\n";
        cout << "==================================================\n";
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin  >> n;

    Result *res = new Result[n];

    for (int i = 0; i < n; i++) {
        cout << "\n--- Student " << (i + 1) << " ---\n";
        res[i].processResult();
    }

    cout << "\n\n############ FINAL RESULTS ############\n";
    for (int i = 0; i < n; i++)
        res[i].displayResult();

    delete [] res;
    return 0;
}

OUTPUT - 
  Enter number of students: 2

--- Student 1 ---
Enter Roll No   : 101
Enter Name      : Priya Das

Enter marks in 6 subjects (out of 100 each):
  Subject 1 : 85
  Subject 2 : 83
  Subject 3 : 91
  Subject 4 : 77
  Subject 5 : 87
  Subject 6 : 80

--- Student 2 ---
Enter Roll No   : 120
Enter Name      : Shankar Deb

Enter marks in 6 subjects (out of 100 each):
  Subject 1 : 92
  Subject 2 : 86
  Subject 3 : 75
  Subject 4 : 95
  Subject 5 : 89
  Subject 6 : 100


############ FINAL RESULTS ############

==================================================
                   RESULT SHEET
==================================================
Roll No : 101
Name    : Priya Das

Marks obtained:
  Subject 1 : 85
  Subject 2 : 83
  Subject 3 : 91
  Subject 4 : 77
  Subject 5 : 87
  Subject 6 : 80

Total Marks : 503.00 / 600
Percentage  : 83.83 %
Grade       : B
==================================================

==================================================
                   RESULT SHEET
==================================================
Roll No : 120
Name    : Shankar Deb

Marks obtained:
  Subject 1 : 92.00
  Subject 2 : 86.00
  Subject 3 : 75.00
  Subject 4 : 95.00
  Subject 5 : 89.00
  Subject 6 : 100.00

Total Marks : 537.00 / 600
Percentage  : 89.50 %
Grade       : B
==================================================
