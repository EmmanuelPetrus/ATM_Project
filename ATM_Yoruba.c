#include "acct_func.c"

void yoruba()
{
    person user, info, user_trans;
    person *user_password, *user_deposit;
    user_deposit = &user;
    user_password = &info;
    int opt, opt1;
    int amount;
    int state;
    int user_found = 0;
    int no = 1;
    FILE *fpoint = NULL;
    system("cls");
    system("color 0b");
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
            user_found = 1;
            system("cls");
            system("color 3A");
            printf("\n\t\t\t\t\t\t\t\t\nKaabo %s", user.fname);
            printf("\t\t\tIru Idinadura Wo Lo Fe Se:\n");
            printf(" <<1>> Gba Owo <<>>\n");
            printf(" <<2>> Sanwo <<>>\n");
            printf(" <<3>> Enquiyary Balanci <<>>\n");
            printf(" <<4>> Fi Owo Ranse <<>>\n");
            printf(" <<5>> Awon Owo Miiran <<>>\n\n");
            printf(" <<6>> Paro Owoda <<>>\n");
            printf(" <<->> Te number ti o mu sibi: ");
            scanf("%d", &opt);
            fgetc(stdin);
            switch (opt)
            {
            case 6:
                change_money();
            case 5:
                printf("Iru Owo wo lo fe se:\n");
                printf(" <<1>> Prepaidi <<>>\n");
                printf(" <<2>> Ra Cardi <<>>\n");
                printf(" <<3>> Sanwo sori Satellite re <<>>\n");
                printf(" <<4>> Ra data <<>>\n");
                break;
            case 4:
                system("cls");
                disp_trans(user_deposit);
                break;
            case 3:
                system("cls");
                system("color 90");
                printf("\nBalanci re ni : $%d", user.bal);
                printf("\nO daabo, O shey ti o lo banki wa!!!");
                break;
            case 2:
                system("cls");
                printf("\t\t=========================>Kaabo Si Ibi Afowopamosi<===============================");
                printf("\nEe lo lo fe fi pamo:");
                scanf("%d", &amount);
                fgetc(stdin);
                user.bal += amount;
                amount = 0;
                printf("\nFifi owo pamo re ti saseyori, balanci re ni: %d", user.bal);
                update_file(&user, fpoint, user.bal);
                break;
            case 1:
                system("cls");
                system("color 3F");
                printf("Irufe owo wo ni o fe gba: ");
                printf("\n <<1>> 100 <<>>");
                printf("\t\t\t\t\t\t\t <<2>> 200 <<>>\n");
                printf(" <<3>> 500 <<>>");
                printf("\t\t\t\t\t\t\t <<4>> 1000 <<>>\n");
                printf(" <<->> Te number ti o mu sibi yii: ");
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
                        printf("Elo lo fe gba: ");
                        printf("\n <<1>> 100 <<>>");
                        printf("\t\t\t\t\t\t\t <<2>> 500 <<>>\n");
                        printf(" <<3>> 1000 <<>>");
                        printf("\t\t\t\t\t\t <<4>> 1500 <<>>\n");
                        printf(" <<5>> Iye miiran <<>>\n");
                        printf(" <<->> Te number ti o mu sibi yii: ");
                        scanf("%d", &opt2);
                        fgetc(stdin);
                        switch (opt2)
                        {
                        case 1:
                            amount = 100;
                            state = sub_amount(&user, amount, 'w');
                            update_file(&user, fpoint, state);
                            no = 0;
                            break;
                        case 2:
                            amount = 500;
                            state = sub_amount(&user, amount, 'w');
                            update_file(&user, fpoint, state);
                            no = 0;
                            break;
                        case 3:
                            amount = 1000;
                            state = sub_amount(&user, amount, 'w');
                            update_file(&user, fpoint, state);
                            no = 0;
                            break;
                        case 4:
                            amount = 1500;
                            state = sub_amount(&user, amount, 'w');
                            update_file(&user, fpoint, state);
                            no = 0;
                            break;
                        case 5:
                            printf("Eelo lo fe gba:");
                            scanf("%d", &amount);
                            if (amount % 100 != 0 || amount % 200 != 0 || amount % 500 != 0 || amount % 1000 != 0)
                            {
                                printf("Ooye ti o mu kosi ninu awon choici ti o wa!!!\n");
                            }
                            else
                            {
                                state = sub_amount(&user, amount, 'w');
                                update_file(&user, fpoint, state);
                                no = 0;
                            }
                            break;
                        }
                    }
                    break;
                case 2:
                    system("cls");
                    while (no)
                    {
                        int opt2;
                        system("color 0b");
                        printf("Eelo lo fe gba: ");
                        printf("\n <<1>> 400 <<>>");
                        printf("\t\t\t\t\t\t\t <<2>> 1000 <<>>\n");
                        printf(" <<3>> 2000 <<>>");
                        printf("\t\t\t\t\t\t <<4>> 5000 <<>>\n");
                        printf(" <<5>> Iye miiran <<>>\n");
                        printf(" <<->> Te number ti o mu sibi yii: ");
                        scanf("%d", &opt2);
                        fgetc(stdin);
                        switch (opt2)
                        {
                        case 1:
                            amount = 400;
                            state = sub_amount(&user, amount, 'w');
                            update_file(&user, fpoint, state);
                            no = 0;
                            break;
                        case 2:
                            amount = 1000;
                            state = sub_amount(&user, amount, 'w');
                            update_file(&user, fpoint, state);
                            no = 0;
                            break;
                        case 3:
                            amount = 2000;
                            state = sub_amount(&user, amount, 'w');
                            update_file(&user, fpoint, state);
                            no = 0;
                            break;
                        case 4:
                            amount = 5000;
                            state = sub_amount(&user, amount, 'w');
                            update_file(&user, fpoint, state);
                            no = 0;
                            break;
                        case 5:
                            printf("Eelo lo fe gba");
                            scanf("%d", &amount);
                            if (amount % 400 != 0 || amount % 1000 != 0 || amount % 2000 != 0 || amount % 5000 != 0)
                            {
                                printf("\nOoye ti o mu kosi ninu awon choici ti o wa!!!\n");
                            }
                            else
                            {
                                state = sub_amount(&user, amount, 'w');
                                update_file(&user, fpoint, state);
                                no = 0;
                            }
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
                        printf("Eelo lo fe gba: ");
                        printf("\n <<1>> 500 <<>>");
                        printf("\t\t\t\t\t\t\t <<2>> 1000 <<>>\n");
                        printf(" <<3>> 2000 <<>>");
                        printf("\t\t\t\t\t\t <<4>> 5000 <<>>\n");
                        printf(" <<5>> Iye miiran <<>>\n");
                        printf(" <<->> Te number ti o mu sibi yii: ");
                        scanf("%d", &opt2);
                        fgetc(stdin);
                        switch (opt2)
                        {
                        case 1:
                            amount = 500;
                            state = sub_amount(&user, amount, 'w');
                            update_file(&user, fpoint, state);
                            no = 0;
                            break;
                        case 2:
                            amount = 1000;
                            state = sub_amount(&user, amount, 'w');
                            update_file(&user, fpoint, state);
                            no = 0;
                            break;
                        case 3:
                            amount = 2000;
                            state = sub_amount(&user, amount, 'w');
                            update_file(&user, fpoint, state);
                            no = 0;
                            break;
                        case 4:
                            amount = 5000;
                            state = sub_amount(&user, amount, 'w');
                            update_file(&user, fpoint, state);
                            no = 0;
                            break;
                        case 5:
                            printf("Eelo lo fe gba");
                            scanf("%d", &amount);
                            if (amount % 500 != 0)
                            {
                                printf("\nOoye ti o mu kosi ninu awon choici ti o wa!!!\n");
                            }
                            else
                            {
                                state = sub_amount(&user, amount, 'w');
                                update_file(&user, fpoint, state);
                                no = 0;
                            }
                        }
                    }
                    break;
                case 4:
                    system("cls");
                    while (no)
                    {
                        int opt2;
                        system("color 0b");
                        printf("Eelo lo fe gba: ");
                        printf("\n <<1>> 500 <<>>");
                        printf("\t\t\t\t\t\t\t <<2>> 1000 <<>>\n");
                        printf(" <<3>> 2000 <<>>");
                        printf("\t\t\t\t\t\t <<4>> 5000 <<>>\n");
                        printf(" <<5>> Iye miiran <<>>\n");
                        printf(" <<->> Te number ti o mu sibi yii: ");
                        scanf("%d", &opt2);
                        fgetc(stdin);
                        switch (opt2)
                        {
                        case 1:
                            amount = 500;
                            state = sub_amount(&user, amount, 'w');
                            update_file(&user, fpoint, state);
                            no = 0;
                            break;
                        case 2:
                            amount = 1000;
                            state = sub_amount(&user, amount, 'w');
                            update_file(&user, fpoint, state);
                            no = 0;
                            break;
                        case 3:
                            amount = 2000;
                            state = sub_amount(&user, amount, 'w');
                            update_file(&user, fpoint, state);
                            no = 0;
                            break;
                        case 4:
                            amount = 5000;
                            state = sub_amount(&user, amount, 'w');
                            update_file(&user, fpoint, state);
                            no = 0;
                            break;
                        case 5:
                            printf("Eelo lo fe gba");
                            scanf("%d", &amount);
                            if (amount % 1000 != 0)
                            {
                                printf("\nOoye ti o mu kosi ninu awon choici ti o wa!!!\n");
                                break;
                            }
                            else
                            {
                                state = sub_amount(&user, amount, 'w');
                                update_file(&user, fpoint, state);
                                no = 0;
                            }
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    if (!user_found)
    {
        printf("\nO ti shi piini te!!!");
        exit(2);
    }
}