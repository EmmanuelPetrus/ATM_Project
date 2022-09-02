#include "acct_head.h"

int main()
{

    int opt;
    int amount;

    char m = 'y';
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
        while (tolower(m) == 'y')
        {
            english();
            printf("\nDo you still want to perform another operation? [Y] or [N] ? ");
            scanf("%c", &m);
        }
        break;
    case 3:
        printf("\tMegwa oo");
        break;
    }
    return 0;
}