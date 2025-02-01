#include <stdio.h>

int main()
{
    int tp,tnm,tnw,tlm,tlw,tim,tiw;
    // Given data
    tp=80000;
    float percentmen=52;
    float percentliteracy=48;
    float percentliteratemen=35;

    // Number of men and women
    tnm=(tp/100)*percentmen;
    tnw=tp-tnm;

    // Number of literate men and women
    tlm=(tp/100)*percentliteratemen;
    tlw=(tp/100)*(percentliteracy-percentliteratemen);

    // Number of illiterate men and women
    tim=tnm-tlm;
    tiw=tnw-tlw;
    printf("Total Illiterate man and women: %d, %d",tim,tiw);

    return 0;
}
