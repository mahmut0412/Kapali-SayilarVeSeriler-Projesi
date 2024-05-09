#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sort(int* number);
int check_number(int* number);
int check_closed(int* array_R, int* length, int* number);
int add_zero(int* N, int* R);

int main(void) {
    int number;
    do {
        printf("\nN= ");
        scanf("%d", &number);
        if (check_number(&number)) {
            sort(&number);
        }
        else {
            printf("\nerror number!!");
        }
    } while (!check_number(&number));
    return 0;
}

int sort(int* number) {
    char snumber[10],c;
    int L, S,R= *number,N=*number, length=0, array_R[100];
    do
    {
        itoa(R, snumber, 10);
        for (int i = 0; i < strlen(snumber) - 1; i++)
        {
            for (int j = i + 1; j < strlen(snumber); j++)
            {
                if (snumber[i] > snumber[j]) {
                    c = snumber[i];
                    snumber[i] = snumber[j];
                    snumber[j] = c;
                }
            }
        }
        S = atoi(snumber);
        for (int i = 0; i < strlen(snumber) - 1; i++)
        {
            for (int j = i + 1; j < strlen(snumber); j++)
            {
                if (snumber[i] < snumber[j]) {
                    c = snumber[i];
                    snumber[i] = snumber[j];
                    snumber[j] = c;
                }
            }
        }
        L = atoi(snumber);
        R = L - S;
        add_zero(&N, &R);

        if (check_closed(array_R, &length, &R)) {
            array_R[length] = R;
            length++;
            break;
        }
        else {
            N = R;
            array_R[length] = R;
            length++;
        }
    } while (1);
    int i = 0;
    while (array_R[i] != R)
    {
        i++;
    }
    if (length-i-1 > 1) {
        printf("\n%d adimda bir seriye ulasilmistir, serinin uzunlugu %d’tur ve seriyi olusturan sayilar sirayla:", length, length - i-1);
    }
    else {
        printf("\n%d adimda kapali bir sayiya ulasilmistir ve bu kapali sayi:", length);
    }
    while (i < length-1)
    {
        printf("\n%d", array_R[i]);
        i++;
    }

}
int check_number(int* number) {
    if (*number / 10 == 0 || *number / 1000000000 > 0) {
        return 0;
    }
    else {
        char snumber[10]; int i = 0,j;
        itoa(*number, snumber, 10);
        while (i< strlen(snumber)-1)
        {
            j = i + 1;
            while (j < strlen(snumber))
            {
                if (snumber[i] != snumber[j]) {
                    return 1;
                }
                j++;
            }
            i++;
        }
    }
    return 0;
}
int check_closed(int* array_R,int* length,int* number) {
    for (int i = 0; i < *length; i++)
    {
        if (array_R[i] == *number) {
            return 1;
        }
    }
    return 0;
}
int add_zero(int* N,int* R) {
    char snumber_N[10], snumber_R[10];
    itoa(*N, snumber_N, 10);
    itoa(*R, snumber_R, 10);
    int length_N = strlen(snumber_N);
    int length_R = strlen(snumber_R);
    if (length_N != length_R) {
        int dif = length_N - length_R, i = 1;
        while (i <= dif)
        {
            (*R) *= 10;
            i++;
        }
    }
}
