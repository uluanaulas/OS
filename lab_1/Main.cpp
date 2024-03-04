// Main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    string epmloyeeBinFileName;
    unsigned int numOfEmployees;
    cout << "Enter name of binary file that utility Creator will make" << endl;
    cin >> epmloyeeBinFileName;

  
    while (true) 
    {
        cout << "Enter amount of employees" << endl;
        if (cin >> numOfEmployees)
            break;
        else
            cout << "Invalid input. Please enter a valid natural number." << endl;
    }

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    string creatorCmdLine = "Creator.exe " + epmloyeeBinFileName + " " + to_string(numOfEmployees);
    wstring creatorCmdLineToLPWSTR = wstring(creatorCmdLine.begin(), creatorCmdLine.end());

    try
    {
        if (CreateProcess(NULL, &creatorCmdLineToLPWSTR[0], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
        {
            DWORD waitResult = WaitForSingleObject(pi.hProcess, INFINITE);

            if (waitResult != WAIT_OBJECT_0)
            {
                cout << "Error while waiting for object" << endl;
            }
        }
        else
        {
            cout << "Couldn't start Creator." << endl;
        }

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

    }
    catch (const std::exception&)
    {
        cout << "Something wrong while starting Creator." << endl;
    }

    cout << "Enter name of text file:" << endl;
    string reportFileName;
    cin >> reportFileName;
    unsigned int paymentRate;

    while (true) 
    {
        cout << "Enter payment rate: " << endl;
        if (cin >> paymentRate)
            break;
        else 
            cout << "Invalid input. Please enter a valid natural number." << endl;
    }

    creatorCmdLine = "Reporter.exe " + epmloyeeBinFileName + " " + reportFileName + " " + to_string(paymentRate);
    creatorCmdLineToLPWSTR = wstring(creatorCmdLine.begin(), creatorCmdLine.end());

    try
    {
        if (CreateProcess(NULL, &creatorCmdLineToLPWSTR[0], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
        {
            DWORD waitResult2 = WaitForSingleObject(pi.hProcess, INFINITE);

            if (waitResult2 != WAIT_OBJECT_0)
            {
                cout << "Error while waiting for object" << endl;
            }
        }
        else
        {
            cout << "Couldn't start Reporter" << endl;
        }

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

    }
    catch (const std::exception&)
    {
        cout << "Something wrong while starting Reporter" << endl;
    }

    return 0;
}





//CreateProcess(NULL,   // the path
//    &cretorCmdLineToLPWSTR[0],        // Command line LPWSTR format
//    NULL,           // Process handle not inheritable
//    NULL,           // Thread handle not inheritable
//    FALSE,          // Set handle inheritance to FALSE
//    0,              // No creation flags
//    NULL,           // Use parent's environment block
//    NULL,           // Use parent's starting directory 
//    &si,            // Pointer to STARTUPINFO structure
//    &pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
//);

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
