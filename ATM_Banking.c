#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "acct_store.c"

int main()
{
    person user, info;
    person *userp;
    userp = &info;
    int opt;
    FILE *fpoint;
    system("cls");
    system("color fc");

    printf("\t\t\t\t\t\t>>>>>>>>Welcome to Our ATM System<<<<<<<<<<\n\n");
    printf("->>> Kindly select your language: \n\n");
    printf(" <<1>> Yoruba  <<>>\n");
    printf(" <<2>> English <<>>\n");
    printf(" <<3>> Igala   <<>>\n\n");
    printf("->Input your number here: ");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        printf("\tE ka bo ");
        break;
    case 2:
        system("cls");
        system("color 0b");
        printf("\tYou're welcome");
        take_input(userp, 'a');
        take_password(userp, 1);
        fpoint = fopen("Acct.dat", "r");
        if (fpoint == NULL)
        {
            fpointrintf(stderr, "Error opening file for reading");
            exit(1);
        }
        // printf("\nYour password is %s\n\n", info.pin);
        while (fread(&info, sizeof(person), 1, fpoint))
        

        printf("\tYou're welcome");
        break;
    case 3:
        printf("\tMegwa oo");
    default:
        break;
    }
    return 0;
}
