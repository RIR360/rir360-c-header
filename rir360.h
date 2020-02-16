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

// *** custom types ***
typedef char sstr[50]; // short string holds 50 characters
typedef char str[100]; // string holds 100 characters
typedef char lstr[500]; // long string holds 500 characters
typedef char llstr[1000]; // long long string holds 1000 characters

// *** library functions ***
// exponent: base to the power of n
float expo(float base, float power)
{
    float expon = 1;
    for (int i = 0; i < power; i++) {
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
    int factorial = 1;
    for (int i = 0; i < num; i++) {
        factorial *= num - i;
    }
    return factorial;
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
    for(int i = 0; i < n; i++) {
        f();
    }
}
// return largest number from two
float LargeF2(float a, float b)
{
    return (a>b) ? a : b;
}
// return smallest number from two
float smallF2(float a, float b)
{
    return (a>b) ? b : a;
}
// return largest number from three
float largeF3(float a, float b, float c)
{
    float output;
    if(a>b && a>c)
        output = a;
    if(b>a && b>c)
        output = b;
    if(c>b && c>a)
        output = c;

    return output;
}
// return smallest number from three
float smallF3(float a, float b, float c)
{
    float output;
    if(a<b && a<c)
        output = a;
    if(b<a && b<c)
        output = b;
    if(c<b && c<a)
        output = c;

    return output;
}
// takes integer input from user and returns it
// sends error message if the input wasn't int
int getInt(char prompt[])
{
    int out;
    printf("%s", prompt);

    if(!scanf("%d", &out))
        printf("Error: You were supposed put an integer.\n\a");
        out = 0;

    return out;
}
// takes float input from user and returns it
// sends error message if the input wasn't float
float getFloat(char prompt[])
{
    float out;
    printf("%s", prompt);

    if(!scanf("%f", &out))
        printf("Error: You were supposed put a float.\n\a");
        out = 0.0;

    return out;
}
// takes string input from user and returns it
/*
char* getString(char prompt[])
{
    char* out[500];
    printf("%s", prompt);
    //scanf("%s", &out);

    out[500] = "rizvy";

    return out;
}
*/
