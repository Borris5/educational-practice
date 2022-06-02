#include <iostream>
#include <fstream> // для работы с файлом
#include <string> // упрощение работы со строками
#include <cmath> // добавляет дополнительнные математические функции
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

int main()
{
    setlocale(LC_ALL, "rus");

    ifstream file("E:\\Учебная практика\\program\\original.txt");
    ifstream file_1("E:\\Учебная практика\\program\\original.txt"); // для вывода текста в файл analysis.txt
    ofstream file_analysis("E:\\Учебная практика\\program\\analysis.txt");
    ofstream file_result("E:\\Учебная практика\\program\\result.txt");

    File_check(file, file_1, file_analysis, file_result);

    file.close();
    file_1.close();
    file_analysis.close();
    file_result.close();

}