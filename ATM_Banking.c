#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "acct_func.c"

int main()
{
    person user, info, user_trans;
    person *user_password, *user_deposit;
    user_deposit = &user;
    user_password = &info;
    int opt, opt1, index;
    int amount;
    int state;
    int no = 1;
    FILE *fpoint = NULL;
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
        take_password(user_password, 1);
        fpoint = fopen("Acct.bin", "rb+");
        if (fpoint == NULL)
        {
            fprintf(stderr, "\nError opening file for reading");
            exit(1);
        }
        while (fread(&user, sizeof(person), 1, fpoint))
        {
            if (!compare_str(user_password->pin, user.pin))
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
                fgetc(stdin);
                switch (opt)
                {
                case 5:
                    printf("Select the service you want to engage:\n");
                    printf(" <<1>> Prepaid <<>>\n");
                    printf(" <<2>> Recharge Card <<>>\n");
                    printf(" <<3>> Satellite Subscription <<>>\n");
                    printf(" <<4>> Data-Services <<>>\n");
                    break;
                case 4:
                    system("cls");
                    disp_trans(user_deposit);
                    break;
                case 3:
                    system("cls");
                    system("color 90");
                    printf("\nYour Account Balance is: $%d", user.bal);
                    printf("\nGood-bye and thanks for banking with us!!!");
                    break;
                case 2:
                    system("cls");
                    printf("\t\t=========================>Welcome to the Deposit Page<===============================");
                    printf("\nEnter the amount you want to deposit:");
                    scanf("%d", &amount);
                    fgetc(stdin);
                    user.bal += amount;
                    amount = 0;
                    printf("\nDeposit Successful, your new balance is: %d", user.bal);
                    update_file(&user, fpoint, user.bal);
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
                        while (no)
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
                                state = sub_amount(&user, amount,'w');
                                update_file(&user, fpoint, state);
                                no = 0;
                                break;
                            case 2:
                                amount = 500;
                                state = sub_amount(&user, amount,'w');
                                update_file(&user, fpoint, state);
                                no = 0;
                                break;
                            case 3:
                                amount = 1000;
                                state = sub_amount(&user, amount,'w');
                                update_file(&user, fpoint, state);
                                no = 0;
                                break;
                            case 4:
                                amount = 1500;
                                state = sub_amount(&user, amount,'w');
                                update_file(&user, fpoint, state);
                                no = 0;
                                break;
                            case 5:
                                printf("Enter the amount you want to withdraw:");
                                scanf("%d", &amount);
                                if (amount % 100 != 0 || amount % 200 != 0 || amount % 500 != 0 || amount % 1000 != 0)
                                {
                                    printf("Amount entered is not a multiple of the selected denomination!!!\n");
                                }
                                else
                                {
                                    state = sub_amount(&user, amount,'w');
                                    update_file(&user, fpoint, state);
                                    no = 0;
                                }
                                break;
                            }
                        case 2:
                            system("cls");
                            while (no)
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
                                    state = sub_amount(&user, amount,'w');
                                    update_file(&user, fpoint, state);
                                    no = 0;
                                    break;
                                case 2:
                                    amount = 1000;
                                    state = sub_amount(&user, amount,'w');
                                    update_file(&user, fpoint, state);
                                    no = 0;
                                    break;
                                case 3:
                                    amount = 2000;
                                    state = sub_amount(&user, amount,'w');
                                    update_file(&user, fpoint, state);
                                    no = 0;
                                    break;
                                case 4:
                                    amount = 5000;
                                    state = sub_amount(&user, amount,'w');
                                    update_file(&user, fpoint, state);
                                    no = 0;
                                    break;
                                case 5:
                                    printf("Enter the amount you want to withdraw:");
                                    scanf("%d", &amount);
                                    if (amount % 400 != 0 || amount % 1000 != 0 || amount % 2000 != 0 || amount % 5000 != 0)
                                    {
                                        printf("\nAmount entered is not a multiple of the selected denomination!!!\n");
                                    }
                                    else
                                    {
                                        state = sub_amount(&user, amount,'w');
                                        update_file(&user, fpoint, state);
                                        no = 0;
                                    }
                                    break;
                                default:
                                    printf("Invalid input!!!!");
                                    break;
                                }
                            }
                            break;
                        case 3:
                            system("cls");
                            while (no)
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
                                    state = sub_amount(&user, amount,'w');
                                    update_file(&user, fpoint, state);
                                    no = 0;
                                    break;
                                case 2:
                                    amount = 1000;
                                    state = sub_amount(&user, amount,'w');
                                    update_file(&user, fpoint, state);
                                    no = 0;
                                    break;
                                case 3:
                                    amount = 2000;
                                    state = sub_amount(&user, amount,'w');
                                    update_file(&user, fpoint, state);
                                    no = 0;
                                    break;
                                case 4:
                                    amount = 5000;
                                    state = sub_amount(&user, amount,'w');
                                    update_file(&user, fpoint, state);
                                    no = 0;
                                    break;
                                case 5:
                                    printf("Enter the amount you want to withdraw:");
                                    scanf("%d", &amount);
                                    if (amount % 500 != 0)
                                    {
                                        printf("\nAmount entered is not a multiple of the selected denomination!!!\n");
                                    }
                                    else
                                    {
                                        state = sub_amount(&user, amount,'w');
                                        update_file(&user, fpoint, state);
                                        no = 0;
                                    }
                                default:
                                    printf("Invalid input!!!!");
                                    break;
                                }
                            }
                            break;
                        case 4:
                            system("cls");
                            while (no)
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
                                    state = sub_amount(&user, amount,'w');
                                    update_file(&user, fpoint, state);
                                    no = 0;
                                    break;
                                case 2:
                                    amount = 1000;
                                    state = sub_amount(&user, amount,'w');
                                    update_file(&user, fpoint, state);
                                    no = 0;
                                    break;
                                case 3:
                                    amount = 2000;
                                    state = sub_amount(&user, amount,'w');
                                    update_file(&user, fpoint, state);
                                    no = 0;
                                    break;
                                case 4:
                                    amount = 5000;
                                    state = sub_amount(&user, amount,'w');
                                    update_file(&user, fpoint, state);
                                    no = 0;
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
                                        state = sub_amount(&user, amount,'w');
                                        update_file(&user, fpoint, state);
                                        no = 0;
                                        break;
                                    }
                                default:
                                    printf("Invalid input!!!!");
                                    break;
                                }
                            }
                        default:
                            printf("Invalid Input!!!");
                            break;
                        }
                        break;
                    }
                default:
                    printf("Invalid input!!!!");
                    break;
                }
            }
        }
    default:
        printf("Invalid input!!!!");
        break;
    }
    return 0;
}