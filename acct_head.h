#ifndef ACCT_H
#define ACCT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>
#define ENTER 13    // ASCII value for enter key
#define TAB 9       // ASCII value for tab key
#define BACKSPACE 8 // ASCII value for tab key
#define BUFFER 25   // Upper bound for characters

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

void take_password(person *p_word, int n);
void take_passwordi(person *p_word, int n);
void take_input(person *user, char n);
void take_inputi(person *user, char n);
int compare_str(char a[], char b[]);
int compare_stri(char a[], char b[]);
void deposit(person *depo);
void depositi(person *depo);
int sub_amount(person *bal_ance, int amount, char a);
int sub_amounti(person *bal_ance, int amount, char a);
void update_file(person *acct_details, FILE *fp, int amount);
void update_filei(person *acct_details, FILE *fp, int amount);
void disp_trans(person *user);
void disp_transi(person *user);
void english();
void change_money();
void change_moneyi();

void yoruba();

#endif