#include <iostream>
#include <fstream>
using namespace std;
void qsort(int *mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        qsort(mas, j + 1);
    }
    if (i < size) {
        //"Пpaвый кусок"
        qsort(&mas[i], size - i);
    }
}

int main(int argc, char *argv[])
{

    ifstream fin;
    ofstream fout;
    fin.open(argv[1]);
    fout.open(argv[2]);

    if (!(fin.is_open())) {
            cout << "Ошибка. Невозможно открыть файл." << endl;
            return 0;
    }
    int mass[100];
    int i = 0;

    while (!(fin.eof())) {
        fin >> mass[i];
        i++;
    }
    qsort(mass, i);	
    int n = i;
    for (i = 1; i < n; i++) {
        fout << mass[i] << ' ';
    }
     cout<<"Завершено"<<endl;
    fin.close();
    fout.close();
    return 0;
   
}

