#include <QCoreApplication>
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int n;
    clock_t start, stop;
    double czas;
    cout<<"Podaj ilosc razy obliczenia CRC:";
    cin>>n;
    int max;
    cout<<"Podaj ilosc znakow ramki: ";
    cin>>max;
    uint8_t tab_hexa[max/2]; // tablica do przechowywania po bajcie (dwa znaki)

    // Przyjecie danych i przetworzenie do tablicy hex
    cout<<"Ramke podaj od lewej"<<endl;
    for(int h = 0;h<max/2;h++)
    {
        char first,second;
        cout<<"Podaj znak i potwierdz ENTER (Znak 0-9 || A-F)"<<endl;
        cin>>first;
        cout<<"Podaj znak i potwierdz ENTER (Znak 0-9 || A-F)"<<endl;
        cin>>second;
        int pierwsza, druga = 0;
        switch(first)
        {
            case '0':
                pierwsza = 0;
            break;
            case '1':
                pierwsza = 1;
            break;
            case '2':
                pierwsza = 2;
            break;
            case '3':
                pierwsza = 3;
            break;
            case '4':
                pierwsza = 4;
            break;
            case '5':
                pierwsza = 5;
            break;
            case '6':
                pierwsza = 6;
            break;
            case '7':
                pierwsza = 7;
            break;
            case '8':
                pierwsza = 8;
            break;
            case '9':
                pierwsza = 9;
            break;
            case 'A':
                pierwsza = 10;
            break;
            case 'B':
                pierwsza = 11;
            break;
            case 'C':
                pierwsza = 12;
            break;
            case 'D':
                pierwsza = 13;
            break;
            case 'E':
                pierwsza = 14;
            break;
            case 'F':
                pierwsza = 15;
            break;
            default:
                pierwsza = 0;
            break;
        }
        switch(second)
        {
            case '0':
                druga = 0;
            break;
            case '1':
                druga = 1;
            break;
            case '2':
                druga = 2;
            break;
            case '3':
                druga = 3;
            break;
            case '4':
                druga = 4;
            break;
            case '5':
                druga = 5;
            break;
            case '6':
                druga = 6;
            break;
            case '7':
                druga = 7;
            break;
            case '8':
                druga = 8;
            break;
            case '9':
                druga = 9;
            break;
            case 'A':
                druga = 10;
            break;
            case 'B':
                druga = 11;
            break;
            case 'C':
                druga = 12;
            break;
            case 'D':
                druga = 13;
            break;
            case 'E':
                druga = 14;
            break;
            case 'F':
                druga = 15;
            break;
            default:
                druga = 0;
            break;
        }
        int suma = pierwsza*16+druga*1;
        tab_hexa[h]=suma;
    }

    uint16_t swapped_crc;
    //start liczenia czasu
    start = clock();

    for(int k = 0;k<n;k++)
    {
        uint16_t crc = 0xFFFF;
        for(int i = 0; i < max/2;i++)
        {
            crc = crc^tab_hexa[i];
            for(int j=8;j>0;j--)
            {
                if((crc & 0x0001)==0)
                {
                    crc = crc >> 1;
                }else{
                    crc = crc >> 1;
                    crc=crc^0xA001;
                }
            }
            swapped_crc = (crc>>8) | (crc<<8);
        }
    }
    stop = clock();
    czas = (double)(stop - start)/CLOCKS_PER_SEC;
    cout << hex << "CRC to " << swapped_crc<<endl;
    cout << "Obliczenia zajely: "<<czas<<endl;
    cout << "Czas jednej iteracji to: "<<czas/n<<endl;
    int w;
    cout<<"Wpisz jakikolwiek znak i nacisnij enter aby wyjsc";
    cin>>w;
    exit( 0 );
    return a.exec();
}
