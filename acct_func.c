#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>
#include "acct_head.h"

typedef struct Detail person;
struct Detail
{
    char fname[BUFFER];
    char email[BUFFER];
    char phone_num[BUFFER];
    char acct_num[BUFFER];
    char pin[BUFFER];
    char pin2[BUFFER];
    long int bal;
};

// function to take input of users
void take_input(person *user, char n)
{
    if ((n == 'n') || (n == 'e'))
    {
        char *info = (n != 'n') ? "email" : "name";
        if (!strcmp(info, "name"))
        {
            printf("\nEnter your fullname: ");
            fgets(user->fname, BUFFER, stdin);
            fflush(stdin);
        }
        if (!strcmp(info, "email"))
        {
            printf("\nEnter your email: ");
            fgets(user->email, BUFFER, stdin);
            fflush(stdin);
        }
    }
    else if (n == 'p')
    {
        printf("\nEnter your phone number: ");
        fgets(user->phone_num, BUFFER, stdin);
        fflush(stdin);
    }
    else
    {
        fflush(stdin);
        printf("\nEnter your Account number: ");
        fgets(user->acct_num, BUFFER, stdin);
    }
}

// function to take in password of user
void take_password(person *p_word, int n)
{
    int k = 1;
    char *message = (n == k) ? "Enter" : "Confirm";
    if (!(strcmp(message, "Enter")))
    {
        char password[15] = {0};
        char ch;
        printf("\n%s your PIN: ", message);

        int i = 0;
        while (((ch = getch()) != '\r') && (i < 10))
        {
            if (ch == BACKSPACE)
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else
            {
                password[i++] = ch;
                printf("*");
            }
        }
        password[i] = '\0';
        strcpy(p_word->pin, password);
    }
    else
    {
        char ch;
        char password[15] = {0};
        printf("\n%s your PIN: ", message);

        int i = 0;
        while (((ch = getch()) != '\r') && (i < 10))
        {
            if (ch == BACKSPACE)
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else
            {
                password[i++] = ch;
                printf("*");
            }
        }
        password[i] = '\0';
        strcpy(p_word->pin2, password);
    }
}

// function to compare strings
int compare_str(char a[], char b[])
{
    int flag = 0, i = 0;                                                 // integer variables declaration
    while (a[i] != '\0' && b[i] != '\0' && a[i] != '\n' && b[i] != '\n') // while loop
    {
        if (a[i] != b[i])
        {
            flag = 1;
            break;
        }
        i++;
    }
    if (flag == 0)
        return 0;
    else
        return 1;
}

void deposit(person *depo)
{
    printf("\nHow much do you want to deposit:");
    scanf("%d", &depo->bal);
    fgetc(stdin);
}

int sub_amount(person *bal_ance, int amount, int state)
{
    if (bal_ance->bal > amount)
    {
        bal_ance->bal -= amount;
        amount = 0;
        state = 0;
        printf("Transaction in Progress!!!!\n");
        // wait
        printf("Your balance is: %d\n", bal_ance->bal);
        printf("Kindly take your cash");
    }
    else
    {
        printf("\nYour balance is %d and it is insufficient", bal_ance->bal);
    }
    return state;
}

void file_write(person *reg, FILE *fp)
{
    fclose(fp);
    fp = fopen("Acct.dat", "w");
    if (fp == NULL)
    {
        fprintf(stderr, "\nError opening file for reading");
        exit(1);
    }
    fwrite(reg, sizeof(person), 1, fp);
    fclose(fp);
}