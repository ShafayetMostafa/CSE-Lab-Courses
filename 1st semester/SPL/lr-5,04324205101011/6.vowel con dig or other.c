#include<stdio.h>
int main()
{
    char ch;
    printf("Enter the character: ");
    scanf("%c",&ch);
    switch(ch)
    {
        case 'a':case 'e':case 'i':case 'o':case 'u':
        case 'A':case 'E':case 'I':case 'O':case 'U':
            printf("VOWEL");
            break;

        case 'b':case 'c':case 'd':case 'f':case 'g':case 'h':case 'j':case 'k':case 'l':case 'm':case 'n':
        case 'p':case 'q':case 'r':case 's':case 't':case 'v':case 'w':case 'x':case 'y':case 'z':
        case 'B':case 'C':case 'D':case 'F':case 'G':case 'H':case 'J':case 'K':case 'L':case 'M':case 'N':
        case 'P':case 'Q':case 'R':case 'S':case 'T':case 'V':case 'W':case 'X':case 'Y':case 'Z':
            printf("CONSONANT");
            break;

        case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
            printf("DIGIT");
            break;

            default: printf("OTHER CHARACTER");
    }
return 0;

}
