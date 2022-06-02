﻿#include <iostream>
#include <fstream> // для работы с файлом
#include <vector> // добавляет контейнер vector (динамический массив с индексами и своими функциями)
#include <string> // упрощение работы со строками
#include <cmath> // добавляет дополнительнные математические функции
#include <chrono> // добавляет функции для измерения времени работы алгоритма
using namespace std;

int File_check(ifstream& file, ifstream& file_1, ofstream& file_analysis, ofstream& file_result) // проверка открытия файлов
{
    if (!file) {
        cout << "Файл original.txt не открылся" << endl;
        return -1;
    }
    else cout << "E:\\Учебная практика\\program\\original.txt" << endl;
    if (!file_1) {
        cout << "Файл original.txt не открылся" << endl;
        return -1;
    }
    else cout << "E:\\Учебная практика\\program\\original.txt" << endl;
    if (!file_analysis) {
        cout << "Файл analysis.txt не открылся" << endl;
        return -1;
    }
    else cout << "E:\\Учебная практика\\program\\analysis.txt" << endl;
    if (!file_result) {
        cout << "Файл result.txt не открылся" << endl;
        return -1;
    }
    else cout << "E:\\Учебная практика\\program\\result.txt" << endl;
    return 0;
}

vector<string> Removal_of_excess(vector<string> words, string word, ifstream& file) // удаление знаков препинания и чисел, создание массива слов
{
    for (file >> word; !file.eof(); file >> word) { // создание массива слов
        words.push_back(word);
    }

    for (int i = 0; i < words.size(); i++) { // удаление знаков препинания и чисел
        for (int j = words[i].length(); j >= 0; j--) {
            if (!(words[i][j] >= 'A' && words[i][j] <= 'Z' or words[i][j] >= 'a' && words[i][j] <= 'z' or words[i][j] == '\'')) {
                words[i].erase(j, 1);
            }
        }
    }
    return words;
}

vector<string> Shell_sorting(vector<string> words, ofstream& file_result) // сортировка Шелла массива слов по убыванию, вывод результата в result.txt
{
    int distance = words.size();
    string buf;
    while (distance > 0) {
        for (int i = 0; i < words.size() - distance / 2; i++) {
            if (words[i].length() < words[i + distance / 2].length()) {
                buf = words[i];
                words[i] = words[i + distance / 2];
                words[i + distance / 2] = buf;
            }
        }
        distance--;
    }
    while (words.back() == "\0") words.pop_back(); // удаление пустых строк

    for (int i = 0; i < words.size(); i++) { // вывод результата в result.txt
        file_result << words[i] << endl;
    }

    return words;
}

int main()
{
    setlocale(LC_ALL, "rus");

    ifstream file("E:\\Учебная практика\\program\\original.txt");
    ifstream file_1("E:\\Учебная практика\\program\\original.txt"); // для вывода текста в файл analysis.txt
    ofstream file_analysis("E:\\Учебная практика\\program\\analysis.txt");
    ofstream file_result("E:\\Учебная практика\\program\\result.txt");

    File_check(file, file_1, file_analysis, file_result);

    vector<string> words;
    string word;

    auto start = chrono::high_resolution_clock::now();
    words = Removal_of_excess(words, word, file);
    words = Shell_sorting(words, file_result);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duraction = end - start; // время сортировки
    cout << duraction.count() << " сек" << endl;

    file.close();
    file_1.close();
    file_analysis.close();
    file_result.close();

}