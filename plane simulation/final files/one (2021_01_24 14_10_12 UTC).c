#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include "server.h"
/*
program structure:
starts from main function
laps function is called
enters the loop for n(20 times) units of time of simulation
within the loop

	UNDER LAPS FUNCTION
USE THE srand() FUNCTION DEPENDING ON THE COMPILER IN USE (read the comments in the laps function for further info)
the srand function generates different set of random numbers each time the program runs, for randomising the incoming and outgoing plane probablities 

creates linked lists and stores the information of planes in tkoff and landing queue by calling genmemory function
and calls the output function for simulation by the automated control tower
repeats n times
comes out of the loop
exits the laps function
prints the status of simulation in main function
the program terminates 	
*/
//global variables
int land2count=0,land3count=0,tkoff1count=0,tkoff3count=0,tkoffqueue=0,landqueue=0,loop;
float empty1=0,empty2=0,empty3=0;
//structure which stores plane name/number and the adress to the next node
//used for creating linked lists
struct node *tkoff=NULL,*land=NULL,*tnext=NULL,*lnext=NULL,*lextra=NULL,*textra=NULL;
int main()
{

int n=0,p=1;
printf("\t\twelcome to nadia aiport simulation\n\n");
printf("through how many units of time must the simulation run?\nenter your response:");
scanf("%d",&loop);
laps();
printf("\n\t\t End of day's work oN simulation \n\t\tFlights landed and took off safely\n");
printf("total number of planes landed: %d\n",land2count+land3count);
printf("total number of planes tookoff: %d\n",tkoff1count+tkoff3count);
printf("number of planes landed on runway3: %d\n",land3count);
printf("number of planes tookoff from runway3: %d\n",tkoff3count);
printf("number of planes which were unable to land: %d\n",landqueue);
printf("number of planes which were unable to takeoff: %d\n",tkoffqueue);
printf("percentage of time runway1 was empty: %f\n",(empty1/20000)*100);
printf("percentage of time runway2 was empty: %f\n",(empty2/20000)*100);
printf("percentage of time runway3 was empty: %f\n",(empty3/2000)*100);
}
