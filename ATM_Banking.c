#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "acct_func.c"

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
    fgetc(stdin);
    switch (opt)
    {
    case 1:
        printf("\tE ka bo ");
        break;
    case 2:
        system("cls");
        system("color 0b");
        printf("\tYou're welcome");
        take_password(userp, 1);
        fpoint = fopen("Acct.dat", "r");
        if (fpoint == NULL)
        {
            fprintf(stderr, "\nError opening file for reading");
            exit(1);
        }
        while (fread(&user, sizeof(person), 1, fpoint))
        {
            if (!compare_str(userp->pin, user.pin))
            {
                system("cls");
                system("color 3A");
                printf("\n\t\t\t\t\t\t\t\t\nWelcome %s", user.fname);
                printf("\t\t\tSelect the transaction you want to perform:\n");
                printf(" <<1>> Withdrawal <<>>\n");
                printf(" <<2>> Deposit <<>>\n");
                printf(" <<3>> Balance Enquiries <<>>\n");
                printf(" <<4>> Transfer <<>>\n");
                printf(" <<5>> Top-Up Services <<>>\n\n");
                printf(" <<->> Input your choice here: ");
                scanf("%d", &opt);
                switch (opt)
                {
                case 1:
                    system("cls");
                    system("color 0b");
                    printf("Kindly select the denomination you want to make your withdrawal: ");
                    printf("\n <<1>> 500 <<>>");
                    printf("\t\t\t\t\t\t\t <<2>> 1000 <<>>\n");
                    printf(" <<3>> 2000 <<>>");
                    printf("\t\t\t\t\t\t <<4>> 5000 <<>>\n");
                    // printf(" <<5>> Top-Up Services <<>>\n\n");
                    break;

                default:
                    break;
                }
            }
        }
        fclose(fpoint);
        break;
    case 3:
        printf("\tMegwa oo");
    default:
        break;
    }
    return 0;
}
