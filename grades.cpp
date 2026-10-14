#include <iostream>
#include <string>

using namespace std;

class GradeRecordSystem {
private:
    int* scores;
    int capacity;
    int studentCount;

public:
    GradeRecordSystem(int maxCapacity) {
        capacity = maxCapacity;
        scores = new int[capacity];
        studentCount = 0;
    }

    ~GradeRecordSystem() {
        delete[] scores;
    }

    void addScore(int score) {
        if (studentCount < capacity) {
            scores[studentCount] = score;
            studentCount++;
            cout << "Score " << score << " added successfully.\n";
        } else {
            cout << "Error: Grade book array is full!\n";
        }
    }

    void displayScores() {
        cout << "Current Student Scores Array: [ ";
        for (int i = 0; i < studentCount; i++) {
            cout << scores[i] << " ";
        }
        cout << "]\n";
    }

    double calculateAverage() {
        if (studentCount == 0) return 0.0;
        int sum = 0;
        for (int i = 0; i < studentCount; i++) {
            sum += scores[i];
        }
        return (double)sum / studentCount;
    }
};

int main() {
    cout << "=== STUDENT GRADE RECORD SYSTEM (C++ Arrays) ===\n\n";
    GradeRecordSystem gradeBook(5);

    gradeBook.addScore(78);
    gradeBook.addScore(85);
    gradeBook.addScore(92);

    cout << "\n";
    gradeBook.displayScores();
    cout << "Class Average: " << gradeBook.calculateAverage() << "\n";

    return 0;
}
