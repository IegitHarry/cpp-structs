#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Rekord osoby
struct Persons
{
    string name;
    string surname;
    int noInClass;
};
// Porownywanie nazwisk
bool compareSurnames(Persons one, Persons two) {
    return one.surname < two.surname;
}
// Klasa opisujaca klase w szkole
class ClassOfStudents
{
private:
    Persons students[30];
    int studentCount;

public:
    ClassOfStudents()
    {
        studentCount = 0;
    }
    // Pobiera dane z pliku
    void fromFile(string fileName) {
        string record;
        ifstream input(fileName);
        while(studentCount < 30) {
            input >> students[studentCount].name;
            input >> students[studentCount].surname;
            input >> students[studentCount].noInClass;

            if(!input)
                break;
            studentCount++;
        }
        cout << "Data has been read from the file.\n";
    }
    // Zwraca liczbe uczniow w klasie
    void displayStudentCount() {
        cout << "\nNumber of students: " << studentCount << "\n";
    }
    // Sortuje uczniow po nazwisku
    void sortBySurname() {
        sort(students, students + studentCount, compareSurnames);
        cout << "Data has been sorted by the students' surnames.\n";
    }
    // Zapisuje dane do tego samego pliku
    void toFile(string fileName) {
        ofstream output(fileName);
        for(int i = 0; i < studentCount; i++) {
            output << students[i].name << " " << students[i].surname << " " << students[i].noInClass << "\n";
        }
        cout << "Data has been saved to the file.\n";
    }
};


int main()
{
    ClassOfStudents class1;
    class1.fromFile("students.txt");
    class1.displayStudentCount();
    class1.sortBySurname();
    class1.toFile("students.txt");

    return 0;
}
