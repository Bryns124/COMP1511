//Some addition code
//Written on 25/02/2021
//by Bryan (bryan.le1248@gmail.com)
//COMP1511 Lab 02

#include <stdio.h>

int main(void) {
int students, tutors;

printf ("Please enter the number of students and tutors: ");
scanf ("%d %d", &students, &tutors);

int sum = students + tutors;

printf ("%d + %d = %d \n", students, tutors, sum);

return 0;
}
