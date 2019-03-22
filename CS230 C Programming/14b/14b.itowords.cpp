
#include "14b.h"

void itowords(int x, char* ansr) {

        char* units[10] = {"zero","one","two","three","four","five","six","seven","eight","nine" };
        char* tens[10] = {"","","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety" };
        int num;
        ansr[0] = 0;

        if (x > 0) {    // if the number is not zero
                if (x > 9) {    // if the number is greater than 9
                        if ( x > 99) {  // if the number is greater than 99
                                num = x / 100;  // find the 100's place number
                                strcat(ansr, units[num]);
                                strcat(ansr, " hundred");
                                // remove the hundreds place
                                for (; x > 99; x -= 100);  
                                // if more numbers put " "
                                if (x != 0) strcat(ansr, " ");
                                else return;
                        }
                        // take care of the teen's and return when done
                        if (x > 9 && x < 20) {
                                switch (x) {
                                        case 10 : strcat(ansr, "ten"); return;
                                        case 11 : strcat(ansr, "eleven"); return;
                                        case 12 : strcat(ansr, "twelve"); return;
                                        case 13 : strcat(ansr, "thirteen"); return;
                                        case 14 : strcat(ansr, "fourteen"); return;
                                        case 15 : strcat(ansr, "fifteen"); return;
                                        case 16 : strcat(ansr, "sixteen"); return;
                                        case 17 : strcat(ansr, "seventeen"); return;
                                        case 18 : strcat(ansr, "eighteen"); return;
                                        case 19 : strcat(ansr, "nineteen"); return;
                                }
                        }
                        // take care of numbers that are 20-99
                        else if (x > 19) {
                                num = x / 10;
                                strcat(ansr, tens[num]);
                        }
                        // add the hypher if there if number needs one
                        if ((x % 10) != 0 && x > 20) strcat(ansr, "-");
                        for (; x > 9; x -= 10);
                
                }
                if (x > 0) strcat(ansr, units[x]);
                if (x = 0) return;

        }
        else strcat(ansr, units[0]);
        return;
}