/*
* rir360.h
* Custom header file
* Created by RIR(Rizvy)
*/

// *** standard libraries ***


// *** macros ***
#define PI 3.1415926536
#define SQUARE(x) (x*x)
#define CUBE(x) (x*x*x)
// maximum characters fit in a line (by default)
#define LINE_MAX_C 80

// *** custom types ***
typedef char* string;

// *** library functions ***
// exponent: base to the power of n
float expo(float base, float power)
{
    int i;
    float expon = 1;
    for (i = 0; i < power; i++) {
        expon *= base;
    }
    return expon;
}
// converts degree to radian
float degToRad(float deg)
{
    return (deg * PI) / 180;
}
// converts radian to degree
float radToDeg(float rad)
{
    return (rad * 180) / PI;
}
// returns factorial of an integer
int fact(int num)
{
    if (num <= 1) return 1;
    else return num * fact(num - 1);
}
// nCr combination
int nCr(int n, int r)
{
    return fact(n)/(fact(n-r)*fact(r));
}
// converts celcius to fahrenheit
float celToFah(float cel)
{
    return ((cel*9)/5) + 32;
}
// converts fahrenheit to celcius
float fahToCel(float fah)
{
    return ((fah - 32)*5) /9;
}
// returns the area of circle from radius
float areaOfCir(float r)
{
    return PI * SQUARE(r);
}
// repeats a function for n times
void repeat(void (*f)(), int n)
{
    int i;
    for(i = 0; i < n; i++) {
        f();
    }
}
// takes integer input from user and returns it
// sends error message if the input wasn't int
int getInt(char prompt[])
{
    int out;
    printf("%s", prompt);

    if(!scanf(" %d", &out))
    {
        printf("Error: You were supposed put an integer.\n\a");
        out = 0;
    }

    return out;
}
// takes float input from user and returns it
// sends error message if the input wasn't float
float getFloat(char prompt[])
{
    float out;
    printf("%s", prompt);

    if(!scanf(" %f", &out)) {
        printf("Error: You were supposed put a float.\n\a");
        out = 0.0;
    }

    return out;
}
// takes single character and returns it
char getChar(char prompt[])
{
    char out;
    printf("%s", prompt);
    scanf(" %c", &out);

    return out;
}
// takes string input from user and returns it as string
char *getString(char prompt[])
{
    char *out;
    printf("%s", prompt);
    scanf("%[^\n]%*c", out);

    return out;
}
// transform string case to lower case
void toLower(char text[])
{
    int count = strlen(text), i;
    
    for(i = 0; i < count; i++) {
        if(text[i] > 64 && text[i] < 97) {
            text[i] += 32;
        } else text[i];
    }
}
// transform string case to upper case
void toUpper(char text[])
{
    int count = strlen(text), i;

    for(i = 0; i < count; i++) {
        if(text[i] > 96) {
            text[i] -= 32;
        } else text[i];
    }
}
// linear search
// returns the index/position of n(th) match for specific integer target in an array
int lSearch(int target, int matchNo, int array[], int arrayLength)
{
    int match = 0;
    int matches = 0;
    int i;

    for(i = 0; i < arrayLength; i++) {
        if(array[i] == target) {
            matches++;
            if(matches == matchNo) {
                match = i;
                break;
            }
        }
    }
    return match;
}
// linear search matches
// returns the available matches for specific integer target in an array
int lMatches(int target, int array[], int arrayLength)
{
    int matches = 0, i;
    for(i = 0; i < arrayLength; i++) {
        if(array[i] == target) {
            matches++;
        }
    }
    return matches;
}
// ask dialogue box
// prompts a question on stdout in a box scans for input and sends 1(if input was y) if or 0(if input was n) to the check variable.
void askBox(char text[],int* check)
{
    int textLength = strlen(text), length = 9, i;
    char out[50];

    if(textLength > length) {
        length = textLength;
    }

    printf("\n");
    for (i = 0; i < length + 3; i++) {
        printf("=");
    }
    printf("\n\n %s\n", text);
    printf("\n [y]yes   [n]no\n\n");
    for (i = 0; i < length + 3; i++) {
        printf("=");
    }
    printf("::==> ");
    scanf(" %s", &out);

    if(out[0] == 'y') {
        printf("Yes registered.");
        *check = 1;
    } else if(out[0] == 'n') {
        printf("No registered.");
        *check = 0;
    } else {
        printf("You're supposed put yes or no.\a");
        check = 2;
    }
}
// Center any length of text in the terminal
// It works only when terminal line width is 80(default)
void centerT(char text[])
{
//    #include<string.h>
//    int LINE_MAX_C = 80;
    int textLength = strlen(text), i;
    int spaceAmount = (LINE_MAX_C - textLength) / 2;

    for (i = 0; i < spaceAmount; i++)
        printf(" ");

    printf("%s", text);
}
