// S003.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    char s1[256];
    char s2[256];
    int strt;
    int lng;
    char f[] = "%s";
    char fd[] = "%d";
    _asm {
        //считывание первой строки
        lea ebx, s1
        push ebx
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        //считывание начала и длины удаления
        lea ebx, strt
        push ebx
        lea edx, fd
        push edx
        call scanf
        add esp, 8
        lea ebx, lng
        push ebx
        lea edx, fd
        push edx
        call scanf
        add esp, 8
        //подготовка к подсчету длины строки
        lea ebx, s1
        dec ebx
        mov ecx, -1
        //подсчет длины строки
        b1:
        inc ecx
            inc ebx
            mov al, [ebx]
            cmp al, 0
            jnz b1
            //подготовка к началу удаления
            lea edx, s1
            dec edx
            //проверка стартового индекса удаления
            mov eax, strt
            cmp eax, ecx
            jge end
            cmp eax, 0
            jg skip
            mov eax, 0 //если стартовый индекс меньше 0, помещаем 0

            skip:
        //подготовка к циклу
        lea ebx, s1
            dec ebx
            lea edx, s2
            dec edx
            mov ecx, lng
            inc eax
            push eax
            //копируем не удаляемую часть
            del1 :
        pop eax
            inc ebx
            dec eax
            push eax
            cmp eax, 0
            jnz del3
            del2 :
        dec ecx
            inc ebx
            cmp ecx, 0
            jnz del2
            del3 :
        inc edx
            mov al, [ebx]
            mov[edx], al
            cmp al, 0
            jz end
            jmp del1

            end :
        inc edx
            mov[edx], 0
            lea ebx, s2
            push ebx
            lea ecx, f
            push ecx
            call printf
            add esp, 12
    }

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
