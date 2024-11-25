#include <iostream> 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <vector> 

//Размеры массивов 
const int N = 5;
const int N2 = 15;
const int N3 = 13;
const int size = 5;

//Обьявление функций 
void find_min_max(int* massive1, char choice);
void my_sort_ubav(int* massive2, char choice);
void my_sort_vozrast(int* massive2, char choice);
void reverse(int* massive3, char choice);
void decTobin(int num);
void decToOctal(int num);

int main()
{
    setlocale(LC_ALL, "Russian");

    int massive1[N] = { 2, 4, 5, 8, 9 };
    int massive2[N2] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    int massive3[N3] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    char choice;
    int num;

    std::cout << "m - min, x - max, p - po ubav, k - po vozrast, r - razver, t -decToBin, e - decToOctal \n";
    std::cout << "Enter a script: ";
    std::cin >> choice;

    switch (choice)
    {
    case 'm':
        find_min_max(massive1, choice);
        break;

    case 'x':
        find_min_max(massive1, choice);
        break;

    case 'p':
        my_sort_ubav(massive2, choice);
        break;

    case 'k':
        my_sort_vozrast(massive2, choice);
        break;
    case 'r':
        reverse(massive3, choice);
        break;

    case 't':
        std::cout << "Enter a number: ";
        std::cin >> num;
        decTobin(num);
        break;

    case 'e':
        std::cout << "Enter a number: ";
        std::cin >> num;
        decToOctal(num);
        break;

    default:
        std::cout << "Fail";
    }

    return 0;
}


void find_min_max(int* massive1, char choice) // Функция для нахождения мин. и макс. числа в массиве  
{
    int min = massive1[0];
    int max = massive1[0];

    for (int i = 1; i < N; i++) // Исправила алгоритм 
    {
        if (massive1[i] < min)
        {
            min = massive1[i];
        }
        if (massive1[i] > max)
        {
            max = massive1[i];
        }
    }

    if (choice == 'm')
    {
        std::cout << "Min: " << min;
    }
    else if (choice == 'x')
    {
        std::cout << "Max: " << max;
    }
}

void my_sort_ubav(int* massive2, char choice) // Функция, которая делает сортировку пузырьком по убыванию 
{
    for (int i = 0; i < N2 - 1; i++)
    {
        for (int j = 0; j < N2 - i - 1; j++)
        {
            if (massive2[j] < massive2[j + 1])
            {
                int obmen = massive2[j];
                massive2[j] = massive2[j + 1];
                massive2[j + 1] = obmen;
            }
        }
    }
    std::cout << "Final massive2: ";
    for (int i = 0; i < N2; i++)
    {
        std::cout << massive2[i] << " ";
    }
}

void my_sort_vozrast(int* massive2, char choice) // Функция, которая делает сортировку пузырьком по возрастанию  
{
    for (int i = 0; i < N2 - 1; i++)
    {
        for (int j = 0; j < N2 - i - 1; j++)
        {
            if (massive2[j] > massive2[j + 1])
            {
                int obmen = massive2[j];
                massive2[j] = massive2[j + 1];
                massive2[j + 1] = obmen;
            }
        }
    }
    std::cout << "Final massive2: ";
    for (int i = 0; i < N2; i++)
    {
        std::cout << massive2[i] << " ";
    }
}



void reverse(int* massive3, char choice) // Функция, которая разворачивает массив 
{
    // Не поняла зачем нужно передавать N3(Глобальная переменная)? 
    int N4 = N3 / 2;

    for (int i = 0; i < N4; i++)
    {
        int TMP = massive3[i];
        massive3[i] = massive3[N3 - i - 1];
        massive3[N3 - i - 1] = TMP;
    }

    std::cout << "Final massive2: ";
    for (int i = 0; i < N3; i++)
    {
        std::cout << massive3[i] << " ";
    }
}

void decTobin(int num) // Перевод из 10 в 2 с.с. 
{
    int bin = 0, pos = 1;

    while (num)
    {
        bin +=
(num % 2)* pos;
pos *= 10;
num /= 2;
    }
    std::cout << bin;
}

void decToOctal(int num) // Перевод из 10 в 8 с.с. 
{
    //Пример взят из интернета, саму логику разобрала. 

    std::vector<int> digits; // Вектор для хранения восьмеричных цифр 

    while (num > 0) {
        digits.push_back(num % 8); // Остаток от деления на 8 
        num /= 8;
    }

    // Выводим цифры в обратном порядке 
    for (auto it = digits.rbegin(); it != digits.rend(); ++it)
    {
        std::cout << *it;
    }
    /*Метод rbegin() возвращает итератор на последний элемент вектора(на который ссылается обратный итератор), а метод rend() возвращает итератор, указывающий на "fictitious" элемент вектора, который следует перед первым элементом.

    Таким образом, цикл for будет работать, выполняя итерации через все элементы вектора, но в обратном порядке.

    Переменная it является указателем на текущий элемент, который увеличивается на каждой итерации, используя оператор++.

    Далее, для вывода текущего элемента в консоль используется оператор << , который выводит содержимое элемента на стандартный поток вывода.

    А оператор* it используется для получения значения текущего элемента, так как it является указателем на текущий элемент типа int.

    Поэтому выражение* it возвращает соответствующее значение типа int, которое в дальнейшем передается в метод std::cout << для вывода в стандартный поток вывода.
    */
}
