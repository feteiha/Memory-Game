// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 3 - Problem 3
// Program: CS213-2018-A1-T3-P3
// Purpose: Memory matching game
// Author:  Hussien Ashraf
// ID:      20170093
// Date:    5 October 2018
// Version: 1.0


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <iomanip>

using namespace std;
void print(char mat[][4]);

int main()
{
int numbers[16] = {1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8}; //The numbers used in the matrix
int r1,c1; //row and column for first point
int r2,c2;
//row and column for second point
int t1 , t2; //point 1 and point 2
int endd= 8; //winning condition variable

char astrics[4][4] =   {'*' , '*' , '*' , '*', //matrix that displays and gets printed
                        '*' , '*' , '*' , '*',
                        '*' , '*' , '*' , '*',
                        '*' , '*' , '*' , '*'};
int gamee[4][4] = {}; //the matrix where the numbers get shuffled in
srand(time(0));//used to shuffle the matrix every second in a different way
for (int i=0; i<16; i++){
    while (numbers[i]!= 0){
        int one = rand()%4; int two = rand()%4; //random number generated then mod 4 in order to make it only 4 or less
        if (gamee[one][two] == 0) //if the matrix is still 0, we change it by a random number from the data array named numbers
        {
            gamee[one][two]=numbers[i]; //change the element in game matrix to the given number from the numbers array
            numbers[i]=0;
        }
    }
}
for (int i=0; i < 4; i++){// prints the matrix without astrics
        for (int j = 0; j < 4; j++){
    cout << gamee[i][j] ;
}
cout << endl;}


while (endd != 0){ //winning condition (repeats until endd is 0)
        cout << "Current Matrix is: " <<endl;
        print(astrics);
        do{
        cout << "Enter column and row of first number: ";
        cin >> r1 >> c1 ; //first element (point)

        }

        while ((r1 > 4) || (c1 > 4) || (astrics[c1-1][r1-1] != '*')); //checks that the input is valid

        t1 = gamee [c1-1][r1-1];
        astrics[c1-1][r1-1] = t1 + 48;

        do{
        cout << "Enter column and row of second number: ";
        cin >> r2 >> c2 ; //second element (point)

        }
        while ((r2 > 4 || (c2 > 4) ||(astrics [c2-1][r2-1] != '*')) || ((r2 == r1) && (c2 == c1)));//checks input valid & not same

        t2 = gamee [c2-1][r2-1];
        astrics[c2-1][r2-1] = t2 + 48; //adds 48 in order to show the number in ASCII
        system ("CLS"); //clears console screen
        print(astrics); //prints matrix with the two points showing
        system ("pause"); //pauses the console
        system ("CLS");
        if (t1 == t2){ // if the two elements are equal and aren't the same point then we decrease the winning variable end by 1
            if (r1 == r2 && c1 == c2){
                    astrics[c1-1][r1-1]= '*'; //returns the point to astric
                    astrics[c2-1][r2-1]='*';
                    continue;
            } // if same point, don't reduce one and start loop all over again
            --endd;
        }

        else if (t1 != t2){
            astrics[c1-1][r1-1]= '*'; //returns the point to astric
            astrics[c2-1][r2-1]='*';
        }
}
cout <<"\t\t YOU WIN!" <<endl;



    return 0;

}




void print(char mat[][4]){ //prints the whole matrix
cout << "     1  2  3  4 "; //prints the header row of the matrix
cout << endl << "------------------" << endl ;
for (int i=0; i<4; i++){
        cout << i+1 << " |"; //prints the column number of the matrix
    for (int j=0; j<4; j++)
        cout << setw (3) << mat[i][j]; //prints the matrix elements
    cout << endl;
}
}
