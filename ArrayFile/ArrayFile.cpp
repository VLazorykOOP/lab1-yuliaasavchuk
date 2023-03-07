﻿ // ArrayFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
#include <unordered_map>

#include <time.h>

using namespace std;
const int MaxSize = 560;

typedef double* pDouble;
/*
*   ConsoleInputArrayDouble
*   
*/
int ConsoleInputSizeArray(const int sizeMax)
{
    int size = 0; 
    do {
        cout << " Input size Array ( 0< 1 < " << sizeMax << " ) ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    return size;
}
/*
*   ConsoleInputArrayDouble
*
*/
int ConsoleInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
        for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> A[i];
    }
    return size;
}

/*
*   RndInputArrayDouble
*
*/
int RndInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1=0, r2=0;
    srand(size);

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
        cout << A[i] << "   ";
    }
    return size;
}

int ConsoleInputDynamicArrayNew(int sizeMax, pDouble &pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = new double[size];
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

int ConsoleInputDynamicArray_calloc(int sizeMax, pDouble& pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = (double*)calloc(size, sizeof(double));      // pA = (double*)malloc(size * sizeof(double)); 
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

void ConsoleInputVector(int sizeMax, vector<double> &A)
{
    int size = ConsoleInputSizeArray(sizeMax);
    double d;
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> d; A.push_back(d);
    }
    return ;
}


/*
*  WriteArrayTextFile 
*
*/

void WriteArrayTextFile(int n, double *arr, const char *fileName )
{
    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close(); //
}
/*
*  ReadArrayTextFile
*
*/


int ReadArrayTextFile(int n, double* arr, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0) return 0;
    if (size > n) size = n;   
    for (int i = 0; i < n; i++)
       fin>> arr[i];
    fin.close();
    return size;
    
}


void WriteArrayBinFile(int n, double* arr, const char* fileName)
{
    //ios_base
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&n, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(n) *sizeof(double);
    bfout.write((const char*)arr, cn);
    bfout.close();
}

int ReadArrayBinFile(int n, double* arr, const char* fileName)
{
    int size=0;
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail()) return 0;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0) return 0;
    if (size > n) size = n;
    bfin.read((char*)arr, static_cast<std::streamsize>(size) * sizeof(double));
    bfin.close();
    // ssdhs
    return size;
}


void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Local array  \n";
    cout << "    2.  Dynamic array 1 \n";
    cout << "    3.  Dynamic array 2  new \n"; 
    cout << "    4.  Dynamic array : vector \n";
    cout << "    5.  Exit \n";
}

void MenuInput()
{
    cout << "     Menu Input   \n";
    cout << "    1.  Console all \n";
    cout << "    2.  Console - size, array - random \n";
    cout << "    3.  File 1.txt \n";
    cout << "    4.  bb    \n";
    cout << "    5.  Exit \n";
}


/*
* Задано одновимірний масив А розміру 2N. 
* Побудувати два масиви В і С розміру N, 
* включивши  у масив В елементи масиву А з парними індексами,
* а у С - з непарними.
*****************
*  A - in 
*  B, C - out 
*/
void  TestVariant(int N, double* A, double* B, double* C) {
    for (int i = 0; i < N; i++) {
        B[i] = A[2 * i];
        C[i] = A[2 * i + 1];
    }
}
/*
*  Task  Var
* 
* 
*/
void TaskV()
{
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
            switch (ch) {
             case '1': cout << " 1 "; break;
             case '2': cout << " 2 "; break;
            //
            case '5': return;
            }
        cout << " Press any key and enter\n";
        ch = getchar();
        } while (ch != 27);
    
}

void ArrayLocal()
{
    double A[1000], B[500], C[500];
    int n;
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
        switch (ch) {
        case '1': cout << " 1 "; break;
        case '2': cout << " 2 "; break;
            //
        case '5': return;
        }
        cout << " Press any key and enter\n";
        ch = getchar();
    } while (ch != 27);

}

int find_min_element_index(vector<double>& vec, int N, int T1, int T2)
{
    int min_index = -1;
    int min_value = INT_MAX;

    bool found_t2 = false;

    for (int i = 0; i < N; i++) {
        if (vec[i] > T1 && (found_t2 == true || vec[i] >= T2)) {
            if (vec[i] < min_value && found_t2 == true) {
                min_index = i;
                min_value = vec[i];
            }

            if (!found_t2) {
                found_t2 = true;
            }
        }
    }

    return min_index;
}

void showMainMenu() {
    cout << "    Main Menu  \n";
    cout << "    1.  Task 1  \n";
    cout << "    2.  Task 2  \n";
    cout << "    3.  Task 3  \n";
}

void mainMenu() {
    bool isSelected = false;
    while (!isSelected) {
        system("cls");
        showMainMenu();
        int ch = GetInput();
        switch (ch) {
        case 1:
            isSelected = true;
            cout << "Enter the n number";
            cin >> N;
            for (int i = 0; i < N; i++) {
                cout << "A[" << i << "]";
                cin >> A[i];
            }

            unordered_map<int, int> count;
            for (int i = 0; i < N; i++) {
                count[A[i]]++;
            }

            int max_unique = -1;
            for (int i = 0; i < N; i++) {
                if (count[A[i]] == 1 && A[i] > max_unique) {
                    max_unique = A[i];
                }
            }

            cout << max_unique << endl;
            break;
        case 2:
            isSelected = true;
            vector<double> vA;
            int T1, T2;
            cout << "Enter T1:";
            cin >> T1;
            cout << "Enter T2:";
            cin >> T2;
            int size;
            cout << "Enter numebr of elements in massive:";
            cin >> size;
            double d;
            for (int i = 0; i < size; i++) {
                cout << " Array[" << i << "] ";
                cin >> d;
                vA.push_back(d);
            };

            int min_index = find_min_element_index(vA, size, T1, T2);

            if (min_index == -1) {
                std::cout << "No matching element found." << std::endl;
            }
            else {
                std::cout << "The index of the first minimal element is: " << min_index << std::endl;
            }
            break;
        case 3:
            isSelected = true;
            int N;
            cout << "Enter the n number";
            cin >> N;
            int A[MaxSize];
            for (int i = 0; i < N; i++) {
                cout << "A[" << i << "]";
                cin >> A[i];
            }
            int B[MaxSize];
            for (int i = 0; i < N; i++) {
                cout << "B[" << i << "]";
                cin >> B[i];
            }
            for (int i = 0; i < N; i++) {
                if (A[i] > 0) {
                    A[i] = B[i];
                }
            }

            for (int i = 0; i < N; i++) {
                cout << A[i] << " ";
            }
            taskNumber = 3;
            break;
        default:
            break;
        }
    }
}


int main()
{
    mainMenu();
    /*int N;
    cout << "Enter the n number";
    cin >> N;
    int A[MaxSize];
    for (int i = 0; i < N; i++) {
        cout << "A[" << i << "]";
        cin >> A[i];
    }
    int B[MaxSize];
    for (int i = 0; i < N; i++) {
        cout << "B[" << i << "]";
        cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        if (A[i] > 0) {
            A[i] = B[i];
        }
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    
    vector<double> vA;
    int T1, T2;
    cout << "Enter T1:";
    cin >> T1;
    cout << "Enter T2:";
    cin >> T2;
    int size;
    cout << "Enter numebr of elements in massive:";
    cin >> size;
    double d;
    for (int i = 0; i < size; i++) {
        cout << " Array[" << i << "] ";
        cin >> d;
        vA.push_back(d);
    };

    int min_index = find_min_element_index(vA, size, T1, T2);

    if (min_index == -1) {
        std::cout << "No matching element found." << std::endl;
    }
    else {
        std::cout << "The index of the first minimal element is: " << min_index << std::endl;
    }
    
    cout << "Enter the n number";
    cin >> N;
    for (int i = 0; i < N; i++) {
        cout << "A[" << i << "]";
        cin >> A[i];
    }

    unordered_map<int, int> count;
    for (int i = 0; i < N; i++) {
        count[A[i]]++;
    }

    int max_unique = -1;
    for (int i = 0; i < N; i++) {
        if (count[A[i]] == 1 && A[i] > max_unique) {
            max_unique = A[i];
        }
    }

    cout << max_unique << endl;*/
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
