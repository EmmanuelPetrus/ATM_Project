#include "acct_head.h"
void change_moneyi()
{
    int money = 0;
    int opt1;
    printf("E lo lo fe se: ");
    scanf("%d", &money);
    fgetc(stdin);
    printf("Irufe eda owo wo lo fe se si: \n");
    printf("\n <<1>> 50 <<>>");
    printf("\t\t\t\t\t\t\t <<2>> 100 <<>>\n");
    printf(" <<3>> 200 <<>>");
    printf("\t\t\t\t\t\t\t <<4>> 500 <<>>\n");
    printf(">>>>");
    scanf("%d", &opt1);
    fgetc(stdin);
    switch (opt1)
    {
    case 1:
        if (money % 50 == 0)
        {
            int result = money / 50;
            printf("Gba owo re ki o si ri wipe %d ni oye ti o wa nibe!!!", result);
        }
        else
        {
            printf("Kosi eda owo ti o mu nibi!!!\n");
        }
        break;
    case 2:
        if (money % 100 == 0)
        {
            int result = money / 100;
            printf("Gba owo re ki o si ri wipe %d ni oye ti o wa nibe!!!", result);
        }
        else
        {
            printf("Kosi eda owo ti o mu nibi!!!\n");
        }
        break;
    case 3:
        if (money % 200 == 0)
        {
            int result = money / 200;
            printf("Gba owo re ki o si ri wipe %d ni oye ti o wa nibe!!!", result);
        }
        else
        {
            printf("Kosi eda owo ti o mu nibi!!!\n");
        }
        break;
    case 4:
        if (money % 500 == 0)
        {
            int result = money / 500;
            printf("Gba owo re ki o si ri wipe %d ni oye ti o wa nibe!!!", result);
        }
        else
        {
            printf("Kosi eda owo ti o mu nibi!!!\n");
        }
        break;
    default:
        printf("No Money Inserted!!!!");
        break;
    }
}

// function to take input of users
void take_inputi(person *user, char n)
{
    if ((n == 'n') || (n == 'e'))
    {
        const char *info = (n != 'n') ? "email" : "name";
        if (!strcmp(info, "name"))
        {
            printf("\nTe oruke re sibi: ");
            fgets(user->fname, BUFFER, stdin);
            fflush(stdin);
        }
        if (!strcmp(info, "email"))
        {
            printf("\nTe Maili re sibi: ");
            fgets(user->email, BUFFER, stdin);
            fflush(stdin);
        }
    }
    else if (n == 'p')
    {
        printf("\nTe phone number re sibi: ");
        fgets(user->phone_num, BUFFER, stdin);
        fflush(stdin);
    }
    else
    {
        fflush(stdin);
        printf("\nTe Number Accounti re sibi: ");
        fgets(user->acct_num, BUFFER, stdin);
    }
}

// function to take in password of user
void take_passwordi(person *p_word, int n)
{
    int k = 1;
    const char *message = (n == k) ? "Te" : "Se atunte ";
    if (!(strcmp(message, "Te")))
    {
        char password[15] = {0};
        char ch;
        printf("\n%s Piini re: ", message);

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
        printf("\n%s Piini re: ", message);

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
int compare_stri(char a[], char b[])
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

void depositi(person *depo)
{
    printf("\nElo lo fe fi pamo:");
    scanf("%d", &depo->bal);
    fgetc(stdin);
}

int sub_amounti(person *bal_ance, int amount, char a)
{
    if (bal_ance->bal > amount)
    {
        bal_ance->bal -= amount;
        amount = 0;
        if (a == 'w')
        {
            printf("Idina dura nlo lowo!!!!\n");
            printf("Ooye ti o wa lapo re ni : %d\n", bal_ance->bal);
            printf("Tewo Gba Owo re");
        }
    }
    else
    {
        printf("\nOoye ti o wa lapo re ni  %d ko si to", bal_ance->bal);
    }
    return bal_ance->bal;
}

void update_filei(person *acct_details, FILE *fp, int amount)
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

void disp_transi(person *user)

{
    person user_trans;
    char acct_num[12];
    int choice = 0;
    int amou_nt = 0;
    int acct_found = 0;
    printf("Te account ti o fe fowo ranse si: ");
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
            printf("Shey accounti ti o fe fowo ranse si naa ni?\n");
            printf("Oruko Accounti: %s\n", user_trans.fname);
            printf("Number Accounti: %s\n", user_trans.acct_num);
            printf("Te [1] lati tesiwaju tabi [2] lati pari idinadura:");
            scanf("%d", &choice);
            fgetc(stdin);
            if (choice == 1)
            {
                printf("Te oye ti o fe fi ranse: ");
                scanf("%d", &amou_nt);
                user_trans.bal += amou_nt;
                update_file(&user_trans, fp, user_trans.bal);
                int deduction = sub_amount(user, amou_nt, 'a');
                update_file(user, fp, deduction);
                printf("Aseyori fifi owo ranse!!!");
                break;
            }
        }
    }
    if (!(acct_found))
    {
        printf("\nKosi irufe accounti naa ni odo wa !!!");
    }
}