#include <iostream>
using namespace std;

int factorial(int n);
void revers(int* fb, int* sn);
void masSR(double sum, int n);
void masPrint(int* ptr, int n);
void Matrix();
void RandMassive();

int main()
{
    setlocale(LC_ALL, "RUS");

    int operation;
    int n;
    int result;
    int fn;
    int sn;
    int sum;
    int yn;
    int* ptr;

    while (true) {
        cout << "Введите операцию\n";
        cout << "1 - Факториал через рекурсию\n";
        cout << "2 - Изменение местами переменных\n";
        cout << "3 - Массивы\n";
        cout << "4 - Матрицы\n";
        cout << "5 - Рандомный массив\n";
        cin >> operation;

        if (operation > 5 || operation < 1)
        {
            main();
            cout << "\n";
        }


        switch (operation) {
        case 1:
            cout << "Введите число - ";
            cin >> n;
            result = factorial(n);
            cout << "Факториал - " << result;
            break;
        case 2:
            cout << "Введите первое значение - ";
            cin >> fn;
            cout << "Введите второе значение - ";
            cin >> sn;

            revers(&fn, &sn);

            cout << "Первое значение - " << fn << "\n";
            cout << "Второе значение - " << sn << "\n";

            break;
        case 3:
            sum = 0;

            cout << "Введите длинну массива: ";
            cin >> n;

            ptr = new int[n];

            for (int i = 0; i < n; i++)
            {
                cout << "Введите число: ";
                cin >> yn;
                *(ptr + i) = yn;
                sum += yn;
            }

            cout << "сумма - " << sum << "\n";
            masPrint(ptr, n);
            cout << "\n";
            cout << " среднее арифметическое - ";
            masSR(sum, n);
            break;
        case 4:
            Matrix();
            break;
        case 5:
            RandMassive();
            break;
        }
        cout << "\n";
        cout << "\n";
    }
}

void revers(int* fb, int* sn)
{
    int num;
    num = *fb;
    *fb = *sn;
    *sn = num;
}

int factorial(int n)
{
    if (n > 1)
    {
        return n * factorial(n - 1);
    }
    return 1;
}

void masSR(double sum, int n)
{
    cout << sum / n;
}

void masPrint(int* ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ptr[i] << " ";
    }
}

void Matrix()
{
    int N;
    int M;
    int sum = 0;
    cout << "Введите кол-во строк матрицы: ";
    cin >> N;
    cout << "Введите кол-во столбцов матрицы: ";
    cin >> M;

    srand(time(NULL));
    int* matx = new int[N];
    for (int i = 0; i < N; i++)
    {
        int* mas = new int[M];
        for (int j = 0; j < M; j++)
        {
            *(mas + j) = 1 + rand() % 100;
            cout << mas[j] << " ";
            sum = sum + *(mas + j);
        }
        *(matx + i) = *mas;
        cout << "\n";
    }
    cout << "Сумма: " << sum << "\n";
    delete[] matx;
}

void RandMassive()
{
    int length;
    cout << "Введите размер массива: ";
    cin >> length;

    srand(time(NULL));
    int* mas = new int[length];

    for (int i = 0; i < length; i++)
    {
        *(mas + i) = 1 + rand() % 100;
        cout << mas[i] << " ";
    }

    int min = mas[0];
    for (int i = 0; i < length; ++i)
    {
        if (mas[i] < min)
        {
            min = mas[i];
        }
    }

    cout << "\nНаименьший элемент: " << min;
}