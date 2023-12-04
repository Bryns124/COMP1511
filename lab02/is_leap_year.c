//Leap Year Calculator
//Written 25/02/2021
//By Bryan Le (bryan.le1248@gmail.com)
//COMP1511 Lab 02

#include <stdio.h>

int main(void) {
int year;

printf ("Enter year:");
scanf ("%d", &year);

if (!(year % 4 == 0)) {
printf ("%d is not a leap year. \n", year); }

else if (year % 4 == 0 && !(year % 100 == 0)) {
printf("%d is a leap year.\n", year); }

else if (year % 4 == 0 && year % 400 == 0) {
printf("%d is a leap year.\n", year); }

else if (year % 4 == 0 && year % 100 == 0 && !(year % 400 == 0)) {
printf("%d is not a leap year.\n", year); }

return 0;
}
