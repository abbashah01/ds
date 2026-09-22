#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    const int NUM_STUDENTS = 6;
    const int NUM_SUBJECTS = 4;
    
    string subjects[NUM_SUBJECTS] = {"English", "Mathematics", "Programming", "AI"};
    
    // 2D Array storing marks of 6 students across 4 subjects
    int marks[NUM_STUDENTS][NUM_SUBJECTS] = {
        {85, 90, 88, 92}, // Student 1
        {78, 82, 75, 80}, // Student 2
        {92, 95, 98, 94}, // Student 3
        {65, 70, 68, 72}, // Student 4
        {88, 85, 90, 87}, // Student 5
        {72, 75, 80, 78}  // Student 6
    };

    // Arrays to store totals and averages for each student
    int totalMarks[NUM_STUDENTS] = {0};
    double averageMarks[NUM_STUDENTS] = {0.0};

    // Calculate Total and Average Marks for each student
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        for (int j = 0; j < NUM_SUBJECTS; ++j) {
            totalMarks[i] += marks[i][j];
        }
        averageMarks[i] = static_cast<double>(totalMarks[i]) / NUM_SUBJECTS;
    }

    // Task 2: Display complete marks table with total and average
    cout << "=========================================================================\n";
    cout << left << setw(12) << "Student" 
         << setw(10) << "English" 
         << setw(13) << "Mathematics" 
         << setw(13) << "Programming" 
         << setw(8)  << "AI" 
         << setw(8)  << "Total" 
         << setw(8)  << "Average" << endl;
    cout << "=========================================================================\n";

    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << left << setw(12) << ("Student " + to_string(i + 1));
        for (int j = 0; j < NUM_SUBJECTS; ++j) {
            cout << setw(11 + (j == 0 ? 0 : 1)) << marks[i][j];
        }
        cout << setw(8) << totalMarks[i] 
             << fixed << setprecision(2) << setw(8) << averageMarks[i] << endl;
    }
    cout << "=========================================================================\n\n";

    // Task 5: Find highest marks in each subject
    cout << "Highest Marks in Each Subject:\n";
    cout << "------------------------------\n";
    for (int j = 0; j < NUM_SUBJECTS; ++j) {
        int highestSubjectMark = marks[0][j];
        for (int i = 1; i < NUM_STUDENTS; ++i) {
            if (marks[i][j] > highestSubjectMark) {
                highestSubjectMark = marks[i][j];
            }
        }
        cout << left << setw(15) << subjects[j] + ":" << highestSubjectMark << endl;
    }
    cout << endl;

    // Task 6: Find student with the highest total marks
    int topStudentIndex = 0;
    for (int i = 1; i < NUM_STUDENTS; ++i) {
        if (totalMarks[i] > totalMarks[topStudentIndex]) {
            topStudentIndex = i;
        }
    }

    cout << "Top Performing Student:\n";
    cout << "-----------------------\n";
    cout << "Student " << (topStudentIndex + 1) 
         << " with a Total Score of " << totalMarks[topStudentIndex] 
         << " (" << fixed << setprecision(2) << averageMarks[topStudentIndex] << " Avg)" << endl;

    return 0;
}