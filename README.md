# 📋 Sortowanie uczniów po nazwisku – C++

Prosty program konsolowy w C++, który wczytuje listę uczniów jednej klasy z pliku tekstowego, sortuje ją alfabetycznie po nazwisku i zapisuje wynik z powrotem do tego samego pliku. Całość jest zamknięta w klasie `ClassOfStudents`, a pojedynczy uczeń opisany jest strukturą `Persons`.

## ✨ Funkcje

- Wczytywanie danych uczniów z pliku `students.txt`
- Wyświetlanie liczby wczytanych uczniów
- Sortowanie alfabetyczne po nazwisku (`std::sort`)
- Zapis posortowanej listy do tego samego pliku
- Obsługa do **30 uczniów** w jednej klasie

## 🧰 Wymagania

- Kompilator C++ obsługujący standard C++11 lub nowszy (np. `g++`, `clang++`, MSVC)
- Plik `students.txt` w katalogu, z którego uruchamiasz program

## 📁 Struktura projektu

```
.
├── main.cpp         # kod programu
└── students.txt     # lista uczniów (dane wejściowe i wyjściowe)
```

## 📄 Format pliku `students.txt`

Każdy uczeń w osobnej linii, w formacie:

```
imię nazwisko numer_w_dzienniku
```

Przykład:

```
Jan Nowak 3
Anna Kowalska 1
Piotr Adamski 2
Ewa Zielinska 4
```

Pola oddzielone są spacjami. Imię i nazwisko muszą być pojedynczymi słowami.

## 🚀 Kompilacja i uruchomienie

```bash
g++ -std=c++11 main.cpp -o sortowanie
./sortowanie
```

Na Windowsie uruchom wygenerowany plik `sortowanie.exe`.

### Przykładowy wynik w konsoli

```
Data has been read from the file.

Number of students: 4
Data has been sorted by the students' surnames.
Data has been saved to the file.
```

### Zawartość `students.txt` po uruchomieniu

```
Piotr Adamski 2
Anna Kowalska 1
Jan Nowak 3
Ewa Zielinska 4
```

## ⚙️ Jak to działa

### Struktura `Persons`

Rekord pojedynczego ucznia:

```cpp
struct Persons
{
    string name;
    string surname;
    int noInClass;
};
```

### Funkcja porównująca

```cpp
bool compareSurnames(Persons one, Persons two) {
    return one.surname < two.surname;
}
```

Porównuje dwóch uczniów według nazwiska i jest przekazywana do `std::sort`.

### Klasa `ClassOfStudents`

Przechowuje tablicę 30 rekordów oraz licznik uczniów `studentCount`.

| Metoda | Zadanie |
|---|---|
| `fromFile(fileName)` | Wczytuje kolejnych uczniów z pliku, aż do końca danych lub do 30 rekordów |
| `displayStudentCount()` | Wypisuje liczbę wczytanych uczniów |
| `sortBySurname()` | Sortuje uczniów po nazwisku |
| `toFile(fileName)` | Nadpisuje plik posortowaną listą |

### Przebieg programu

W funkcji `main()` kolejno wykonywane są cztery kroki:

```cpp
ClassOfStudents class1;
class1.fromFile("students.txt");
class1.displayStudentCount();
class1.sortBySurname();
class1.toFile("students.txt");
```

## ⚠️ Uwagi i ograniczenia

- **Plik jest nadpisywany.** Wynik trafia do tego samego pliku co dane wejściowe, więc oryginalna kolejność przepada. Warto zachować kopię zapasową.
- **Limit 30 uczniów.** Jeśli plik zawiera więcej rekordów, nadmiarowe są ignorowane przy wczytywaniu, a przy zapisie **znikają z pliku**.
- **Brak pliku wejściowego.** Gdy `students.txt` nie istnieje, program mimo to wypisze komunikat o wczytaniu danych, a następnie utworzy pusty plik.
- **Pojedyncze słowa.** Imiona i nazwiska ze spacją (np. nazwiska dwuczłonowe zapisane ze spacją) zostaną wczytane błędnie. Dane z linii, w której wczytywanie się nie powiedzie, nie są dalej odczytywane.
- **Sortowanie rozróżnia wielkość liter** i porównuje znaki bajt po bajcie. Wielkie litery trafiają przed małe, a polskie znaki (ą, ć, ę, ł, ń, ó, ś, ź, ż) w kodowaniu UTF-8 lądują po literze „z”.
- **Kolejność uczniów o tym samym nazwisku jest nieokreślona**, ponieważ `std::sort` nie jest stabilny.
- Komunikaty w konsoli są po angielsku, a komentarze w kodzie po polsku.

## 💡 Pomysły na rozwój

- Zastąpienie tablicy `Persons students[30]` kontenerem `vector<Persons>`, aby znieść limit 30 uczniów
- Przekazywanie argumentów do `compareSurnames` przez stałą referencję (`const Persons&`) zamiast kopii
- Zapis wyniku do osobnego pliku (np. `students_sorted.txt`)
- Sortowanie z uwzględnieniem polskich znaków i bez rozróżniania wielkości liter
- Obsługa błędów, np. brak pliku lub niepoprawny format linii
- Wybór kryterium sortowania (nazwisko, imię, numer w dzienniku)
- Użycie `std::stable_sort`, aby zachować kolejność uczniów o tym samym nazwisku

## 📄 Licencja

Projekt udostępniony na licencji MIT. Możesz go dowolnie używać, modyfikować i rozwijać.
