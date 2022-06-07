#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "acct_func.c"

int main(void)
{
    int opt, usrFound = 0;
    FILE *fp;
    person info, info_store;
    person *point_info = &info;

    char choice;
    system("cls");
    system("color 0b");
    printf("\n\t\t\t------------Welcome to the Account Registration System----------------");
    printf("\nPlease choose your operation");
    printf("\n1.Signup Your Account and Deposit");
    printf("\n2.Request For Account Details");
    printf("\n3.Exit");

    printf("\nYour choice:\t");
    scanf("%d", &opt);

    fgetc(stdin);

    switch (opt)
    {
    case 1:
        take_input(point_info, 'n');
        take_input(point_info, 'e');
        take_input(point_info, 'p');
        take_input(point_info, 'a');
        take_password(point_info, 1);
        take_password(point_info, 2);

        if (!(compare_str(point_info->pin, point_info->pin2)))
        {
            fp = fopen("Acct.dat", "a+");
            if ((fp == NULL))
            {
                fprintf(stderr, "%s", "Failed to open file ");
                break;
            }
            else
            {
                printf("\nWould you like to make a deposit (y/n): ");
                scanf("%c", &choice);
                fgetc(stdin);
                if (choice == 'y')
                {
                    deposit(point_info);
                }

                if (!(fwrite(&info, sizeof(person), 1, fp)))
                {
                    fprintf(stderr, "%s", "Account Registration Unsuccessfull");
                    break;
                }
                else
                {
                    printf("Account Registration Successfull");
                }
            }
        }
        fclose(fp);
        break;
    case 2:
        take_input(point_info, 'a');
        take_password(point_info, 1);
        fp = fopen("Acct.dat", "r");
        if (fp == NULL)
        {
            fprintf(stderr, "Error opening file for reading");
            exit(1);
        }

        while(fread(&info_store, sizeof(person), 1, fp))
        {
            printf("%s\n", info_store.acct_num);
            printf("%s\n", info_store.pin);
            if (!compare_str(info_store.acct_num, info.acct_num))
            {

                if (!compare_str(info.pin, info_store.pin))
                {
                    system("cls");
                    printf("\n\t\t\t\t\t\t\t\t\tWelcome %s", info_store.fname);
                    printf("\n\n|Full Name:\t%s", info_store.fname);
                    printf("\n|Email:\t\t%s", info_store.email);
                    printf("\n|Account Number: %s", info_store.acct_num);
                    printf("\n|Contact no.:\t%s", info_store.phone_num);
                    printf("\n|Account Balance:\t%d", info_store.bal);
                }

                else
                {
                    printf("\n\nInvalid Password!");
                    Beep(800, 300);
                }
                usrFound = 1;
            }
        }

        if (!usrFound)
        {
            printf("\n\nUser is not registered!");
            Beep(800, 300);
        }
        fclose(fp);
        break;

    case 3:
        printf("\t\t\t Goodbye");
        break;
    }
    return 0;
}
