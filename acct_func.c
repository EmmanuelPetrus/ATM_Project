#include "acct_head.h"
void change_money()
{
    int money = 0;
    int opt1;
    printf("Please Insert the amount you want to change: ");
    scanf("%d", &money);
    fgetc(stdin);
    printf("Kindly select the denomination you'll like to change your money into: \n");
    printf("\n <<1>> 50 <<>>");
    printf("\t\t\t\t\t\t\t <<2>> 100 <<>>\n");
    printf(" <<3>> 200 <<>>");
    printf("\t\t\t\t\t\t\t <<4>> 500 <<>>\n");
    scanf("%d", &opt1);
    fgetc(stdin);
    switch (opt1)
    {
    case 1:
        if (money % 50 == 0)
        {
            int result = money / 50;
            printf("Kindly take your cash, confirm that it's %d pieces of goodness!!!", result);
        }
        else
        {
            printf("Money is not a multiple of the selected denomination!!!\n");
        }
        break;
    case 2:
        if (money % 100 == 0)
        {
            int result = money / 100;
            printf("Kindly take your cash, confirm that it's %d pieces of goodness!!!", result);
        }
        else
        {
            printf("Money is not a multiple of the selected denomination!!!\n");
        }
        break;
    case 3:
        if (money % 200 == 0)
        {
            int result = money / 200;
            printf("Kindly take your cash, confirm that it's %d pieces of goodness!!!", result);
        }
        else
        {
            printf("Money is not a multiple of the selected denomination!!!\n");
        }
        break;
    case 4:
        if (money % 500 == 0)
        {
            int result = money / 500;
            printf("Kindly take your cash, confirm that it's %d pieces of goodness!!!", result);
        }
        else
        {
            printf("Money is not a multiple of the selected denomination!!!\n");
        }
        break;
    default:
        printf("No Money Inserted!!!!");
        break;
    }
}

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

int sub_amount(person *bal_ance, int amount, char a)
{
    if (bal_ance->bal > amount)
    {
        bal_ance->bal -= amount;
        amount = 0;
        if (a == 'w')
        {
            printf("Transaction in Progress!!!!\n");
            printf("Your balance is: %d\n", bal_ance->bal);
            printf("Kindly take your cash");
        }
    }
    else
    {
        printf("\nYour balance is %d and it is insufficient", bal_ance->bal);
    }
    return bal_ance->bal;
}

void update_file(person *acct_details, FILE *fp, int amount)
{
    fclose(fp);
    rewind(fp);
    person pnewrecord;
    fp = fopen("Acct.bin", "rb+");
    if (fp == NULL)
    {
        fprintf(stderr, "\nError opening file for reading");
        exit(1);
    }
    while (fread(&pnewrecord, sizeof(person), 1, fp))
    {
        if (!(strcmp(acct_details->acct_num, pnewrecord.acct_num)))
        {
            pnewrecord.bal = amount;
            fseek(fp, -156, SEEK_CUR);
            fflush(stdin);
            fwrite(&pnewrecord, sizeof(person), 1, fp);
            fclose(fp);
            break;
        }
    }
}

void disp_trans(person *user)

{
    person user_trans;
    char acct_num[12];
    int choice = 0;
    int amou_nt = 0;
    int acct_found = 0;
    printf("Kindly enter the account number you want to transfer to: ");
    scanf("%s", acct_num);
    fgetc(stdin);
    FILE *fp;

    fp = fopen("Acct.bin", "rb+");
    if (fp == NULL)
    {
        fprintf(stderr, "\nError opening file for reading");
        exit(1);
    }
    while (fread(&user_trans, sizeof(person), 1, fp))
    {
        if (!compare_str(acct_num, user_trans.acct_num))
        {
            acct_found = 1;
            printf("Kindly Verify the details of the destination account\n");
            printf("Account Name: %s\n", user_trans.fname);
            printf("Account Number: %s\n", user_trans.acct_num);
            printf("Kindly press [1] to continue or [2] to exit:");
            scanf("%d", &choice);
            fgetc(stdin);
            if (choice == 1)
            {
                printf("Enter the amount you want to transfer: ");
                scanf("%d", &amou_nt);
                user_trans.bal += amou_nt;
                update_file(&user_trans, fp, user_trans.bal);
                int deduction = sub_amount(user, amou_nt, 'a');
                update_file(user, fp, deduction);
                printf("Transfer successfull!!!");
                break;
            }
        }
    }
    if (!(acct_found))
    {
        printf("\nAccount number not found !!!");
    }
}