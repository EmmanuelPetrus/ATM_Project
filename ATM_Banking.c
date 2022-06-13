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
    int opt,opt1;
    int amount;
    int state = 1;
    int no;
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
    case 3:
        printf("\tMegwa oo");
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
                person *user_save = &user;
                system("cls");
                system("color 3A");
                printf("\n\t\t\t\t\t\t\t\t\nWelcome %s", user.fname);
                printf("Your balance is:%d\n", user.bal);
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
                case 2:
                    printf("\t\t=========================>Welcome to the Deposit Page<===============================");
                    printf("\nEnter the amount you want to deposit:");
                    scanf("%d", &amount);
                    fgetc(stdin);
                    user.bal += amount;
                    amount = 0;
                    file_write(&user,fpoint);
                    break;
                default:
                    break;
                case 1:
                    system("cls");
                    system("color 3F");
                    printf("Kindly select the denomination you want to make your withdrawal: ");
                    printf("\n <<1>> 100 <<>>");
                    printf("\t\t\t\t\t\t\t <<2>> 200 <<>>\n");
                    printf(" <<3>> 500 <<>>");
                    printf("\t\t\t\t\t\t\t <<4>> 1000 <<>>\n");
                    printf(" <<->> Input your choice here: ");
                    scanf("%d", &opt1);
                    fgetc(stdin);
                    switch (opt1)
                    {
                    case 1:
                        system("cls");
                        while (state)
                        {
                            int opt2;
                            system("color 0b");
                            printf("Kindly select the amount you want to withdraw: ");
                            printf("\n <<1>> 100 <<>>");
                            printf("\t\t\t\t\t\t\t <<2>> 500 <<>>\n");
                            printf(" <<3>> 1000 <<>>");
                            printf("\t\t\t\t\t\t <<4>> 1500 <<>>\n");
                            printf(" <<5>> Other Amount <<>>\n");
                            printf(" <<->> Input your choice here: ");
                            scanf("%d", &opt2);
                            fgetc(stdin);
                            switch (opt2)
                            {
                            case 1:
                                amount = 100;
                                state = sub_amount(user_save, amount, no);
                                file_write(&user, fpoint);
                                break;
                            case 2:
                                amount = 500;
                                state = sub_amount(user_save, amount, no);
                                file_write(&user, fpoint);
                                break;
                            case 3:
                                amount = 1000;
                                state = sub_amount(user_save, amount, no);
                                file_write(&user, fpoint);
                                break;
                            case 4:
                                amount = 1500;
                                state = sub_amount(user_save, amount, no);
                                file_write(&user, fpoint);
                                break;
                            case 5:
                                printf("Enter the amount you want to withdraw:");
                                scanf("%d", &amount);
                                if (amount % 100 != 0 || amount % 200 != 0 || amount % 500 != 0 || amount % 1000 != 0)
                                {
                                    printf("Amount entered is not a multiple of the selected denomination!!!\n");
                                    break;
                                }
                                else
                                {
                                    state = sub_amount(user_save, amount, no);
                                    file_write(&user, fpoint);
                                    break;
                                }
                            default:

                                break;
                            }
                        }
                    case 2:
                        system("cls");
                        while (state)
                        {
                            int opt2;
                            system("color 0b");
                            printf("Kindly select the amount you want to withdraw: ");
                            printf("\n <<1>> 400 <<>>");
                            printf("\t\t\t\t\t\t\t <<2>> 1000 <<>>\n");
                            printf(" <<3>> 2000 <<>>");
                            printf("\t\t\t\t\t\t <<4>> 5000 <<>>\n");
                            printf(" <<5>> Other Amount <<>>\n");
                            printf(" <<->> Input your choice here: ");
                            scanf("%d", &opt2);
                            fgetc(stdin);
                            switch (opt2)
                            {
                            case 1:
                                amount = 400;
                                state = sub_amount(user_save, amount, no);
                                file_write(&user, fpoint);
                                break;
                            case 2:
                                amount = 1000;
                                state = sub_amount(user_save, amount, no);
                                file_write(&user, fpoint);
                                break;
                            case 3:
                                amount = 2000;
                                state = sub_amount(user_save, amount, no);
                                file_write(&user, fpoint);
                                break;
                            case 4:
                                amount = 5000;
                                state = sub_amount(user_save, amount, no);
                                file_write(&user, fpoint);
                                break;
                            case 5:
                                printf("Enter the amount you want to withdraw:");
                                scanf("%d", &amount);
                                if (amount % 400 != 0 || amount % 1000 != 0 || amount % 2000 != 0 || amount % 5000 != 0)
                                {
                                    printf("\nAmount entered is not a multiple of the selected denomination!!!\n");
                                    break;
                                }
                                else
                                {
                                    state = sub_amount(user_save, amount, no);
                                    file_write(&user, fpoint);
                                    break;
                                }
                                break;
                            default:
                                break;
                            }
                        }
                    case 3:
                        system("cls");
                        while (state)
                        {
                            int opt2;
                            system("color 0b");
                            printf("Kindly select the amount you want to withdraw: ");
                            printf("\n <<1>> 500 <<>>");
                            printf("\t\t\t\t\t\t\t <<2>> 1000 <<>>\n");
                            printf(" <<3>> 2000 <<>>");
                            printf("\t\t\t\t\t\t <<4>> 5000 <<>>\n");
                            printf(" <<5>> Other Amount <<>>\n");
                            printf(" <<->> Input your choice here: ");
                            scanf("%d", &opt2);
                            fgetc(stdin);
                            switch (opt2)
                            {
                            case 1:
                                amount = 500;
                                state = sub_amount(user_save, amount, no);
                                file_write(&user, fpoint);
                                break;
                            case 2:
                                amount = 1000;
                                state = sub_amount(user_save, amount, no);
                                file_write(&user, fpoint);
                                break;
                            case 3:
                                amount = 2000;
                                state = sub_amount(user_save, amount, no);
                                file_write(&user, fpoint);
                                break;
                            case 4:
                                amount = 5000;
                                state = sub_amount(user_save, amount, no);
                                file_write(&user, fpoint);
                                break;
                            case 5:
                                printf("Enter the amount you want to withdraw:");
                                scanf("%d", &amount);
                                if (amount % 500 != 0)
                                {
                                    printf("\nAmount entered is not a multiple of the selected denomination!!!\n");
                                    break;
                                }
                                else
                                {
                                    state = sub_amount(user_save, amount, no);
                                    file_write(&user, fpoint);
                                    break;
                                }
                            default:
                                break;
                            }
                        }
                    case 4:
                        system("cls");
                        while (state)
                        {
                            int opt2;
                            system("color 0b");
                            printf("Kindly select the amount you want to withdraw: ");
                            printf("\n <<1>> 500 <<>>");
                            printf("\t\t\t\t\t\t\t <<2>> 1000 <<>>\n");
                            printf(" <<3>> 2000 <<>>");
                            printf("\t\t\t\t\t\t <<4>> 5000 <<>>\n");
                            printf(" <<5>> Other Amount <<>>\n");
                            printf(" <<->> Input your choice here: ");
                            scanf("%d", &opt2);
                            fgetc(stdin);
                            switch (opt2)
                            {
                            case 1:
                                amount = 500;
                                state = sub_amount(user_save, amount, no);
                                file_write(&user, fpoint);
                                break;
                            case 2:
                                amount = 1000;
                                state = sub_amount(user_save, amount, no);
                                file_write(&user, fpoint);
                                break;
                            case 3:
                                amount = 2000;
                                state = sub_amount(user_save, amount, no);
                                file_write(&user, fpoint);
                                break;
                            case 4:
                                amount = 5000;
                                state = sub_amount(user_save, amount, no);
                                file_write(&user, fpoint);
                                break;
                            case 5:
                                printf("Enter the amount you want to withdraw:");
                                scanf("%d", &amount);
                                if (amount % 1000 != 0)
                                {
                                    printf("\nAmount entered is not a multiple of the selected denomination!!!\n");
                                    break;
                                }
                                else
                                {
                                    state = sub_amount(user_save, amount, no);
                                    file_write(&user, fpoint);
                                    break;
                                }
                            default:
                                break;
                            }
                        }
                    default:
                        break;
                    }
                }
            }
        }
    default:
        break;
    }
    return 0;
}
