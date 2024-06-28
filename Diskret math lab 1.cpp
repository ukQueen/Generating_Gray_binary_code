// Diskret math lab 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "GrayCode.h"
#include <regex>
#include "Multi.h"

 

int main()
{
    setlocale(LC_ALL, "rus");
    regex powerful("^[0-9]{0,50}$");
    //создание универсума
    string buf;

    cout << "Введите разрядность УНИВЕРСУМА (целое число 0-10)\n";
    while (true) {
        cin >> buf;
        if (regex_match(buf, powerful) && stoi(buf) >= 0 && stoi(buf) <= 10) {
            break; // Ввод соответствует регулярному выражению, выходим из цикла
        }
        else {
            std::cout << "\nОшибка ввода! Ведите число от 0 до 10\n\n";
        }
    }
    int n = stoi(buf);
    GrayCode m(n);
    m.Print();

    system("pause");

    /*
    //зануление
    if (m.Getk() > 0) {
    cout << "---------------------------------------" << endl;
    cout << "Хотели бы занулить любое количество элементов в вашем универсуме?\n";
    cout << "Если да, то напишите число не превышающее и не равное количеству различных элементов в вашем унимерсуме (целое чилосо 1-" << m.Getk() - 1 << "\n";
    cout << "Если нет, то просто напишите \"0\"" << endl;



        while (true) {
            cin >> buf;
            if (regex_match(buf, powerful) && stoi(buf) >= 0 && stoi(buf) < m.Getk()) {
                break; // Ввод соответствует регулярному выражению, выходим из цикла
            }
            else {
                std::cout << "\nОшибка ввода! Попробуйте снова)\n\n";
            }
        }

        int s = stoi(buf);
        m.ToNull(s);
        m.Print();
    }
    */

    Multi* A;
    if (m.Getk() > 0) {
        //создание множества А
        cout << "__________________________________________________" << endl;
        cout << "Давайте создадим множество А\n";
        cout << "\nВыберите, как будет заполняться ваше мультимножество:\n\t [0] - Автоматически;\n\t [1] - Вручную;\n";
        while (true) {
            cin >> buf;
            if (regex_match(buf, powerful) && stoi(buf) >= 0 && stoi(buf) <= 1) {
                break; // Ввод соответствует регулярному выражению, выходим из цикла
            }
            else {
                std::cout << "\nОшибка ввода! Ведите либо 0, либо 1\n\n";
            }
        }
        n = stoi(buf);

        //system("pause");

        cout << "\nСколько различных элементов должно быть в мультимножестве А?\n";
        while (true) {
            cin >> buf;

            if (regex_match(buf, powerful) && (stoi(buf) <= m.Getk() && stoi(buf) >= 0)) {
                break; // Ввод соответствует регулярному выражению, выходим из цикла
            }
            else {
                std::cout << "\nОшибка ввода! Количество различных элементов не должно превышать количества различных элементов в универсуме. \n\n";
            }
        }

        //system("pause");

        //Multi a(stoi(buf));
        //a.Avto();
        int s = stoi(buf);
        //Multi a(s, &m);
        A = new Multi (s, &m, 1);
        if (n == 0) {
            A->Avto();
            A->Print("Множество A");
        }
        else {
            A->Hand();
            A->Print("Множество A");
        }
        system("pause");
    }
    else
        A = new Multi(0, &m, 1);


    Multi* B;
    if (m.Getk() > 0) {
        //создание множества B
        cout << "__________________________________________________" << endl;
        cout << "Давайте создадим множество B\n";
        cout << "\nВыберите, как будет заполняться ваше мультимножество:\n\t [0] - Автоматически;\n\t [1] - Вручную;\n";
        while (true) {
            cin >> buf;
            if (regex_match(buf, powerful) && stoi(buf) >= 0 && stoi(buf) <= 1) {
                break; // Ввод соответствует регулярному выражению, выходим из цикла
            }
            else {
                std::cout << "\nОшибка ввода! Ведите либо 0, либо 1\n\n";
            }
        }
        n = stoi(buf);
        cout << "\nСколько различных элементов должно быть в мультимножестве B?\n";
        while (true) {
            cin >> buf;

            if (regex_match(buf, powerful) && (stoi(buf) <= m.Getk() && stoi(buf) >= 0)) {
                break; // Ввод соответствует регулярному выражению, выходим из цикла
            }
            else {
                std::cout << "\nОшибка ввода! Количество различных элементов не должно превышать количества различных элементов в универсуме. \n\n";
            }
        }
        //Multi a(stoi(buf));
        //a.Avto();
        int s = stoi(buf);
        B=new Multi (s, &m,1);
        if (n == 0) {
            B->Avto();
            B->Print("Множество B");
        }
        else {
            B->Hand();
            B->Print("Множество B");
        }
        system("pause");
    }
    else 
        B= new Multi (0, &m,1);

    while (true) {
            bool out = 0;
        printf("\n----------------------------------------");
        printf("\n\tОПЕРАЦИИ НАД МНОЖЕСТВАМИ\n");
        printf("\n1. Объединение множеств А и В");
        printf("\n2. Пересечение множеств А и В");
        printf("\n3. Разность множеств A и B");
        printf("\n4. Разность множеств B и A");
        printf("\n5. Арифметическая разность множеств A и B");
        printf("\n6. Арифметическая разность множеств B и A");
        printf("\n7. Дополнение множества A");
        printf("\n8. Дополнение множества В");
        printf("\n9. Симметрическая разность множеств A и B");
        printf("\n10. Арифметическая сумма A и B");
        printf("\n11. Арифметическое произведение A и B");
        printf("\n12. Вывод на экран множеств A и B");
        printf("\n13. Вывод на экран универсума\n");
        printf("\nВведите номер операции, либо [0] для выхода из программы\n");
        printf("----------------------------------------\n");
        while (true) {
            cin >> buf;
            if (regex_match(buf, powerful) && stoi(buf) >= 0 && stoi(buf) <= 13) {
                break; // Ввод соответствует регулярному выражению, выходим из цикла
            }
            else {
                std::cout << "\nОшибка ввода!\n";
            }
        }
        n = stoi(buf);
        Multi bufer(m.Getn(),&m,0);
        switch (n)
        {
        case 0:
            out++;
            break;
        case 1:
            bufer.Unification(*A, *B);
            bufer.Print("Объединение множеств А и В");
            break;
        case 2:
            bufer.Intersection(*A, *B);
            bufer.Print("Пересечение множеств А и В");
            break;
        case 3:
            bufer.DifferenceA(*A, *B);
            bufer.Print("Разность множеств A и B");
            break;
        case 4:
            bufer.DifferenceB(*A, *B);
            bufer.Print("Разность множеств B и A");
            break;
        case 5:
            bufer.Ar_DifferenceA(*A, *B);
            bufer.Print("Арифметическая разность множеств A и B");
            break;
        case 6:
            bufer.Ar_DifferenceB(*A, *B);
            bufer.Print("Арифметическая разность множеств B и A");
            break;
        case 7:
            bufer.AdditionA(*A, *B);
            bufer.Print("Дополнение множества A");
            break;
        case 8:
            bufer.AdditionB(*A, *B);
            bufer.Print("Дополнение множества B");
            break;
        case 9:
            bufer.Sim_Difference(*A, *B);
            bufer.Print("Симметрическая разность множеств A и B");
            break;
        case 10:
            bufer.Ar_Summ(*A, *B);
            bufer.Print("Арифметическая сумма A и B");
            break;
        case 11:
            bufer.Ar_Prod(*A, *B);
            bufer.Print("Арифметическое произведение A и B");
            break;
        case 12:
            A->Print("Множество A");
            B->Print("Множество B");
            break;
        case 13:
            m.Print();
            break;
        }
        if (out)
            break;
        system("pause");

        
    }
    delete A;
    delete B;
}

