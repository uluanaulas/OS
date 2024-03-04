// Creator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <string>
#include<vector>
#include<fstream>
#include <cstring>
#include<algorithm>
using namespace std;

struct Employee
{
    int ID;
    char name[10];
    double hours;
};

int main(int argc, char* argv[])
{
    string outputFileName = argv[1], buff;
    int numEmployees = stoi(argv[2]), number = 0;

    std::ofstream fout(outputFileName, std::ios::binary);

    if (!fout) {
        cout << "Error opening output file." << endl;
        return 1;
    }

    Employee Bob;

    for (int i = 0; i < numEmployees; i++)
    {
        cout << "Enter info about employee: num, name, hours" << endl;        
        while (true)
        {
            cout << "Enter info about employee: num, name, hours" << endl;
            if (cin >> Bob.ID >> buff >> Bob.hours)
                break;
            else 
                cout << "Invalid input. Please enter integer ID, string name, and floating-point hours." << endl;
        }
        for (int j = 0; j < 10 && j < buff.size(); j++)
            Bob.name[j] = buff[j];

        fout.write((char*)&Bob, sizeof(Employee));
    }

    fout.close();

    return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
