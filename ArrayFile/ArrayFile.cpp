#include <fstream>
#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>

#include <time.h>

using namespace std;

typedef double* pDouble;
int taskNumber;
int taskType;
int taskInput;
const int MAX_SIZE = 560;

int GetInput() {
    int choice;
    cin >> choice;
    return choice;
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
            taskNumber = 1;
            break;
        case 2:
            isSelected = true;
            taskNumber = 2;
            break;
        case 3:
            isSelected = true;
            taskNumber = 3;
            break;
        default:
            break;
        }
    }
}

void showMenuTask() {
    cout << "     Menu Task   \n";
    cout << "    1.  Local array  \n";
    cout << "    2.  Dynamic array 1 \n";
    cout << "    3.  Dynamic array 2  new \n";
    cout << "    4.  Dynamic array : vector \n";
    cout << "    5.  Exit \n";
}

void menuTask() {
    bool isSelected = false;
    while (!isSelected) {
        system("cls");
        showMenuTask();
        int ch = GetInput();
        switch (ch) {
        case 1:
            isSelected = true;
            taskType = 1;
            break;
        case 2:
            isSelected = true;
            taskType = 2;
            break;
        case 3:
            isSelected = true;
            taskType = 3;
            break;
        case 4:
            isSelected = true;
            taskType = 4;
            break;
        case 5:
            isSelected = true;
            break;
        default:
            break;
        }
    }
}

void showMenuInput() {
    cout << "     Menu Input   \n";
    cout << "    1.  Console all \n";
    cout << "    2.  Console - size, array - random \n";
    cout << "    3.  File 1.txt \n";
    cout << "    4.  bb    \n";
    cout << "    5.  Exit \n";
}

void menuInput() {
    bool isSelected = false;
    while (!isSelected) {
        system("cls");
        showMenuInput();
        int ch = GetInput();
        switch (ch) {
        case 1:
            isSelected = true;
            taskInput = 1;
            break;
        case 2:
            isSelected = true;
            taskInput = 2;
            break;
        case 3:
            isSelected = true;
            taskInput = 3;
            break;
        case 4:
            isSelected = true;
            taskInput = 4;
            break;
        case 5:
            isSelected = true;
            break;
        default:
            break;
        }
    }
}

int ConsoleInputSizeArray(const int sizeMax) {
    int size = 0;
    do {
        cout << " Input size Array (0 < 1 < " << sizeMax << "):";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    return size;
}

int ConsoleInputArray(int sizeMax, double A[]) {
    int size = ConsoleInputSizeArray(sizeMax);
    for (int i = 0; i < size; i++) {
        cout << " Array[" << i << "]:";
        cin >> A[i];
    }
    return size;
}

int ConsoleReadArrayTextFile(int n, double* arr, const char* fileName) {
    int size;
    ifstream fin(fileName);
    if (fin.fail())
        return 0;
    fin >> size;
    if (size <= 0)
        return 0;
    if (size > n)
        size = n;
    for (int i = 0; i < n; i++)
        fin >> arr[i];
    fin.close();
    return size;
}

int ConsoleInputArrayRandom(int sizeMax, double A[]) {
    int size = ConsoleInputSizeArray(sizeMax);
    int r1 = 0, r2 = 0;
    srand(size);

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
        cout << A[i] << "   ";
    }

    cout << endl;

    return size;
}

int ConsoleInputDynamicArray_calloc(int sizeMax, pDouble& pA) {
    int size = ConsoleInputSizeArray(sizeMax);
    pA = (double*)calloc(size, sizeof(double));
    if (pA == nullptr) {
        return 0;
    }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] ";
        cin >> pA[i];
    }
    return size;
}

int ConsoleInputDynamicArrayRandom(int sizeMax, pDouble& pA) {
    int size = ConsoleInputSizeArray(sizeMax);
    pA = new double[size];
    int r1 = 0, r2 = 0;
    srand(size);

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        pA[i] = 100.0 * r1;
        pA[i] = pA[i] / (1.0 + r2);
        cout << pA[i] << "   ";
    }

    cout << endl;

    return size;
}

int ConsoleReadArrayBinFile(int n, double* arr, const char* fileName) {
    int size = 0;
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail())
        return 0;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0)
        return 0;
    if (size > n)
        size = n;
    bfin.read((char*)arr, static_cast<std::streamsize>(size) * sizeof(double));
    bfin.close();
    // ssdhs
    return size;
}

int InputLocalArray(int sizeMax, double A[]) {
    int size;
    switch (taskInput) {
    case 1:
        size = ConsoleInputArray(sizeMax, A);
        break;
    case 2:
        size = ConsoleInputArrayRandom(sizeMax, A);
        break;
    case 3:
        size = ConsoleReadArrayTextFile(sizeMax, A, "1.txt");
        break;
    case 4:
        size = ConsoleReadArrayBinFile(sizeMax, A, "1.bin");
        break;
    default:
        break;
    }
    return size;
}

int ConsoleReadDynamicArrayTextFile(int n, pDouble& pA, const char* fileName) {
    int size;
    ifstream fin(fileName);
    if (fin.fail())
        return 0;
    fin >> size;
    if (size <= 0)
        return 0;
    if (size > n)
        size = n;
    pA = new double[size];
    for (int i = 0; i < n; i++)
        fin >> pA[i];
    fin.close();
    return size;
}

int ConsoleReadDynamicArrayBinFile(int n, pDouble& pA, const char* fileName) {
    int size = 0;
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail())
        return 0;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0)
        return 0;
    if (size > n)
        size = n;
    pA = new double[size];
    bfin.read((char*)pA, static_cast<std::streamsize>(size) * sizeof(double));
    bfin.close();
    // ssdhs
    return size;
}

int InputDynamicArray(int sizeMax, pDouble& pA) {
    int size;
    switch (taskInput) {
    case 1:
        size = ConsoleInputDynamicArray_calloc(sizeMax, pA);
        break;
    case 2:
        size = ConsoleInputDynamicArrayRandom(sizeMax, pA);
        break;
    case 3:
        size = ConsoleReadDynamicArrayTextFile(sizeMax, pA, "1.txt");
        break;
    case 4:
        size = ConsoleReadDynamicArrayBinFile(sizeMax, pA, "1.bin");
        break;
    default:
        break;
    }
    return size;
}

int ConsoleInputDynamicArrayNew(int sizeMax, pDouble& pA) {
    int size = ConsoleInputSizeArray(sizeMax);
    pA = new double[size];
    if (pA == nullptr) {
        return 0;
    }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] ";
        cin >> pA[i];
    }
    return size;
}

int InputDynamicArrayNew(int sizeMax, pDouble& pA) {
    int size;
    switch (taskInput) {
    case 1:
        size = ConsoleInputDynamicArrayNew(sizeMax, pA);
        break;
    case 2:
        size = ConsoleInputDynamicArrayRandom(sizeMax, pA);
        break;
    case 3:
        size = ConsoleReadDynamicArrayTextFile(sizeMax, pA, "1.txt");
        break;
    case 4:
        size = ConsoleReadDynamicArrayBinFile(sizeMax, pA, "1.bin");
        break;
    default:
        break;
    }
    return size;
}

int ConsoleInputVector(int sizeMax, vector<double>& A) {
    int size = ConsoleInputSizeArray(sizeMax);
    double d;
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] ";
        cin >> d;
        A.push_back(d);
    }
    return size;
}

int ConsoleInputVectorRandom(int sizeMax, vector<double>& A) {
    int size = ConsoleInputSizeArray(sizeMax);
    double d;
    int r1 = 0, r2 = 0;
    srand(size);

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        d = 100.0 * r1;
        d = d / (1.0 + r2);
        A.push_back(d);
        cout << A[i] << "   ";
    }

    cout << endl;

    return size;
}

int ReadInputVectorTextFile(int n, vector<double>& A, const char* fileName) {
    int size;
    double d;
    ifstream fin(fileName);
    if (fin.fail())
        return 0;
    fin >> size;
    if (size <= 0)
        return 0;
    for (int i = 0; i < size; i++) {
        fin >> d;
        A.push_back(d);
    }
    fin.close();
    return size;
}

int ReadArrayVectorBinFile(int n, vector<double>& A, const char* fileName) {
    int size = 0;
    double d;
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail())
        return 0;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0)
        return 0;
    if (size > n)
        size = n;
    for (int i = 0; i < size; i++) {
        bfin.read(reinterpret_cast<char*>(&d), sizeof(double));
        A.push_back(d);
    }
    bfin.close();
    // ssdhs
    return size;
}

void WriteArrayTextFile(int n, double* arr, const char* fileName) {
    ofstream fout(fileName);
    if (fout.fail())
        return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close(); //
}

void WriteArrayBinFile(int n, double* arr, const char* fileName) {
    ofstream fout(fileName, ios_base::binary);
    if (fout.fail())
        return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close(); //
}

int InputVector(int sizeMax, vector<double>& A) {
    int size;
    switch (taskInput) {
    case 1:
        size = ConsoleInputVector(sizeMax, A);
        break;
    case 2:
        size = ConsoleInputVectorRandom(sizeMax, A);
        break;
    case 3:
        size = ReadInputVectorTextFile(sizeMax, A, "1.txt");
        break;
    case 4:
        size = ReadArrayVectorBinFile(sizeMax, A, "1.bin");
        break;
    default:
        break;
    }
    return size;
}

// Р—Р°РґР°РЅРѕ РѕРґРЅРѕРІРёРјС–СЂРЅС– РјР°СЃРёРІРё Рђ С– Р’ СЂРѕР·РјС–СЂСѓ N. Р’СЃС– РґРѕРґР°С‚РЅС– РµР»РµРјРµРЅС‚Рё РјР°СЃРёРІСѓ Рђ
// Р·Р°РјС–РЅРёС‚Рё РµР»РµРјРµРЅС‚Р°РјРё Р· РІС–РґРїРѕРІС–РґРЅРёРјРё С–РЅРґРµРєСЃР°РјРё РјР°СЃРёРІСѓ Р’.

void task1() {
    double B[MAX_SIZE];
    int nB, nA;
    vector<double> vA;
    switch (taskType) {
    case 1:
        double A[MAX_SIZE];
        nA = InputLocalArray(MAX_SIZE, A);

        for (int i = 0; i < nA; i++) {
            cout << "Array B[" << i << "]";
            cin >> B[i];
        }

        for (int i = 0; i < nA; i++) {
            if (A[i] > 0) {
                A[i] = B[i];
            }
        }

        for (int i = 0; i < nA; i++) {
            cout << A[i] << " ";
        }
        break;
    case 2:
        pDouble pA;
        nA = InputDynamicArray(MAX_SIZE, pA);

        for (int i = 0; i < nA; i++) {
            cout << "Array B[" << i << "]";
            cin >> B[i];
        }

        for (int i = 0; i < nA; i++) {
            if (pA[i] > 0) {
                pA[i] = B[i];
            }
        }

        for (int i = 0; i < nA; i++) {
            cout << pA[i] << " ";
        }

        break;
    case 3:
        pDouble pB;
        nA = InputDynamicArrayNew(MAX_SIZE, pB);
        for (int i = 0; i < nA; i++) {
            cout << "Array B[" << i << "]";
            cin >> B[i];
        }

        for (int i = 0; i < nA; i++) {
            if (pB[i] > 0) {
                pB[i] = B[i];
            }
        }

        for (int i = 0; i < nA; i++) {
            cout << pB[i] << " ";
        }
        break;
    case 4:
        nA = InputVector(MAX_SIZE, vA);
        for (int i = 0; i < nA; i++) {
            cout << "Array B[" << i << "]";
            cin >> B[i];
        }

        for (int i = 0; i < nA; i++) {
            if (vA[i] > 0) {
                vA[i] = B[i];
            }
        }

        for (auto v : vA) {
            cout << v << " ";
        }
        break;
    default:
        break;
    }
}

// Р—РЅР°Р№С‚Рё РЅРѕРјРµСЂ РїРµСЂС€РѕРіРѕ РјС–РЅС–РјР°Р»СЊРЅРѕРіРѕ РµР»РµРјРµРЅС‚Р° СЃРµСЂРµРґ РµР»РµРјРµРЅС‚С–РІ, Р±С–Р»СЊС€РёС… Рў1 С–
// СЂРѕР·С‚Р°С€РѕРІР°РЅРёС… РїСЂР°РІС–С€Рµ РїРµСЂС€РѕРіРѕ РµР»РµРјРµРЅС‚Р°, СЂС–РІРЅРѕРіРѕ Рў2.

void task2() {

    int nA;
    vector<double> vA;
    int T1, T2;
    int min_index = -1;
    int min_value = MAX_SIZE;
    bool found_t2 = false;
    switch (taskType) {
    case 1:
        double A[MAX_SIZE];
        nA = InputLocalArray(MAX_SIZE, A);
        cout << "Enter T1:";
        cin >> T1;
        cout << "Enter T2:";
        cin >> T2;

        for (int i = 0; i < nA; i++) {
            if (A[i] > T1 && (found_t2 == true || A[i] >= T2)) {
                if (A[i] < min_value && found_t2 == true) {
                    min_index = i;
                    min_value = A[i];
                }

                if (!found_t2) {
                    found_t2 = true;
                }
            }
        }

        if (min_index == -1) {
            std::cout << "No matching element found." << std::endl;
        }
        else {
            std::cout << "The index of the first minimal element is: " << min_index
                << std::endl;
        }
        break;
    case 2:
        pDouble pA;
        nA = InputDynamicArray(MAX_SIZE, pA);
        cout << "Enter T1:";
        cin >> T1;
        cout << "Enter T2:";
        cin >> T2;

        for (int i = 0; i < nA; i++) {
            if (pA[i] > T1 && (found_t2 == true || pA[i] >= T2)) {
                if (pA[i] < min_value && found_t2 == true) {
                    min_index = i;
                    min_value = pA[i];
                }

                if (!found_t2) {
                    found_t2 = true;
                }
            }
        }

        if (min_index == -1) {
            std::cout << "No matching element found." << std::endl;
        }
        else {
            std::cout << "The index of the first minimal element is: " << min_index
                << std::endl;
        }
        break;
    case 3:
        pDouble pB;
        nA = InputDynamicArrayNew(MAX_SIZE, pB);
        cout << "Enter T1:";
        cin >> T1;
        cout << "Enter T2:";
        cin >> T2;

        for (int i = 0; i < nA; i++) {
            if (pB[i] > T1 && (found_t2 == true || pB[i] >= T2)) {
                if (pB[i] < min_value && found_t2 == true) {
                    min_index = i;
                    min_value = pB[i];
                }

                if (!found_t2) {
                    found_t2 = true;
                }
            }
        }

        if (min_index == -1) {
            std::cout << "No matching element found." << std::endl;
        }
        else {
            std::cout << "The index of the first minimal element is: " << min_index
                << std::endl;
        }
        break;
    case 4:
        nA = InputVector(MAX_SIZE, vA);
        cout << "Enter the T number:";
        cout << "Enter T1:";
        cin >> T1;
        cout << "Enter T2:";
        cin >> T2;

        for (int i = 0; i < nA; i++) {
            if (vA[i] > T1 && (found_t2 == true || vA[i] >= T2)) {
                if (vA[i] < min_value && found_t2 == true) {
                    min_index = i;
                    min_value = vA[i];
                }

                if (!found_t2) {
                    found_t2 = true;
                }
            }
        }

        if (min_index == -1) {
            std::cout << "No matching element found." << std::endl;
        }
        else {
            std::cout << "The index of the first minimal element is: " << min_index
                << std::endl;
        }
        break;
    default:
        break;
    }
}

// Р—Р°РґР°РЅРѕ РјР°СЃРёРІ С†С–Р»РёС… С‡РёСЃРµР» A(n), n<400;
// Р РѕР·СЂРѕР±РёС‚Рё РїСЂРѕРіСЂР°РјСѓ, СЏРєР° Р·РЅР°С…РѕРґРёС‚СЊ
// РјР°РєСЃРёРјР°Р»СЊРЅРµ СЃРµСЂРµРґ С‚РёС… С‡РёСЃРµР», СЏРєС– РЅРµ РїРѕРІС‚РѕСЂСЋСЋС‚СЊСЃСЏ.

void task3() {
    int nA;
    vector<double> vA;
    unordered_map<int, int> count;
    double max_unique = -1;
    switch (taskType) {
    case 1:
        double A[MAX_SIZE];
        nA = InputLocalArray(MAX_SIZE, A);

        for (int i = 0; i < nA; i++) {
            count[A[i]]++;
        }

        for (int i = 0; i < nA; i++) {
            if (count[A[i]] == 1 && A[i] > max_unique) {
                max_unique = A[i];
            }
        }

        cout << max_unique << endl;
        break;
    case 2:
        pDouble pA;
        nA = InputDynamicArray(MAX_SIZE, pA);

        for (int i = 0; i < nA; i++) {
            count[pA[i]]++;
        }

        for (int i = 0; i < nA; i++) {
            if (count[pA[i]] == 1 && pA[i] > max_unique) {
                max_unique = pA[i];
            }
        }

        cout << max_unique << endl;
        break;
    case 3:
        pDouble pB;
        nA = InputDynamicArrayNew(MAX_SIZE, pB);

        for (int i = 0; i < nA; i++) {
            count[pB[i]]++;
        }

        for (int i = 0; i < nA; i++) {
            if (count[pB[i]] == 1 && pB[i] > max_unique) {
                max_unique = pB[i];
            }
        }

        cout << max_unique << endl;
        break;
    case 4:
        nA = InputVector(MAX_SIZE, vA);

        for (int i = 0; i < nA; i++) {
            count[vA[i]]++;
        }

        for (int i = 0; i < nA; i++) {
            if (count[vA[i]] == 1 && vA[i] > max_unique) {
                max_unique = vA[i];
            }
        }

        cout << max_unique << endl;
        break;
    default:
        break;
    }
}

void execTask() {
    switch (taskNumber) {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    default:
        break;
    }
}

int main() {
    mainMenu();
    menuTask();
    menuInput();
    execTask();
    return 0;
}