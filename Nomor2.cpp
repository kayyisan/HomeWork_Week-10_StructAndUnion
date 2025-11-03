#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int NUM_STUDENTS = 20;

// Struct untuk menyimpan data tiap mahasiswa
struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// ==== PROTOTYPE ====
void getData(studentType students[], int size);
void assignGrade(studentType students[], int size);
int findHighest(const studentType students[], int size);
void printHighest(const studentType students[], int size, int highestScore);
void printAll(const studentType students[], int size);

// ==== MAIN ====
int main() {
    studentType students[NUM_STUDENTS];

    getData(students, NUM_STUDENTS);
    assignGrade(students, NUM_STUDENTS);

    int highestScore = findHighest(students, NUM_STUDENTS);

    cout << "\n=== STUDENT SCORES ===\n";
    printAll(students, NUM_STUDENTS);

    cout << "\n=== HIGHEST SCORE ===\n";
    printHighest(students, NUM_STUDENTS, highestScore);

    return 0;
}

// ==== 1. INPUT DATA ====
void getData(studentType students[], int size) {
    cout << "Masukkan data " << size
         << " mahasiswa (format: FirstName LastName TestScore):\n";
    cout << "------------------------------------------------------\n";

    for (int i = 0; i < size; i++) {
        cout << "Mahasiswa ke-" << i + 1 << ": ";
        cin >> students[i].studentFName
            >> students[i].studentLName
            >> students[i].testScore;

        // Validasi skor antara 0–100
        while (students[i].testScore < 0 || students[i].testScore > 100) {
            cout << "⚠️ Skor harus antara 0–100. Ulangi: ";
            cin >> students[i].testScore;
        }
    }
}

// ==== 2. TENTUKAN NILAI HURUF ====
void assignGrade(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        int score = students[i].testScore;
        if (score >= 90)
            students[i].grade = 'A';
        else if (score >= 80)
            students[i].grade = 'B';
        else if (score >= 70)
            students[i].grade = 'C';
        else if (score >= 60)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }
}

// ==== 3. CARI NILAI TERTINGGI ====
int findHighest(const studentType students[], int size) {
    int highest = students[0].testScore;
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > highest)
            highest = students[i].testScore;
    }
    return highest;
}

// ==== 4. CETAK MAHASISWA DENGAN NILAI TERTINGGI ====
void printHighest(const studentType students[], int size, int highestScore) {
    cout << "Nilai tertinggi: " << highestScore << endl;
    cout << "Mahasiswa dengan nilai tertinggi:\n";
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highestScore) {
            cout << left << setw(20)
                 << (students[i].studentLName + ", " + students[i].studentFName)
                 << " | Grade: " << students[i].grade << endl;
        }
    }
}

// ==== 5. CETAK SEMUA DATA ====
void printAll(const studentType students[], int size) {
    cout << left << setw(20) << "Name"
         << setw(12) << "TestScore"
         << "Grade" << endl;
    cout << string(40, '-') << endl;

    for (int i = 0; i < size; i++) {
        cout << left << setw(20)
             << (students[i].studentLName + ", " + students[i].studentFName)
             << setw(12) << students[i].testScore
             << students[i].grade << endl;
    }
}
