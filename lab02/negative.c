//Some program about being negative or something
//Written 25/02/2021
//by Bryan Le (bryan.le1248@gmail.com)
//for COMP1511

#include <stdio.h>

int main(void) {
int number;

scanf ("%d",& number);
if (number == 0) {
printf ("You have entered zero.\n"); }
else if (number > 0) {
printf ("You have entered a positive number.\n"); }
else if (number < 0) {
printf ("Don't be so negative!\n"); }

return 0;
}
