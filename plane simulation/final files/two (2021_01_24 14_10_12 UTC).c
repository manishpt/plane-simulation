#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include "server.h"
void output()
{
struct node *flush; //will be used for deleting used memory
if(tkoff!=NULL || land!=NULL)
{
if(tkoff!=NULL)
{	
	printf("plane %d has tookoff from runway1\n",(tkoff->name));
	tkoff1count++ ;tkoffqueue--; 
	flush=tkoff;
	tkoff=tkoff->next;
	free(flush);  //deleting used memory 
	
	if(landqueue<=1 && tkoff!=NULL)		//the plane will takoff only when there are no planes in the queue to land on runway 3
	{
		printf("less than 2 planes in the landing queue hence \nplane %d has tookoff from runway3\n",(tkoff->name));
		tkoff3count++ ;tkoffqueue--;
		flush=tkoff;
		tkoff=tkoff->next;
		free(flush);
		
	}
}
if(land!=NULL)
{
	printf("plane %d has landed on runway2\n",(land->name));
	land2count++; landqueue--;
	flush=land;
	land=land->next;
	free(flush);//deleting used memory


	if(land!=NULL)
	{
		printf("plane %d has landed on runway3\n",(land->name));
		land3count++ ;landqueue--; 
		flush=land;
		land=land->next;
		free(flush);
	}
}
}
else
{printf("the runways are empty");} //if the land and takeoff queues are empty

}




struct node* genmemory(int plane,struct node *inext )
{	
	// creates linked lits for take off and land queue.
	//takes input of plane number and the pointer to that node.	
	
	struct node *ptr=NULL;
	
	inext->next=ptr;	//assignment of values 
	inext->name=plane;	//to a node of either tkoff or land
	
    
}


void laps()
{	
	int p=1,n=0,TIME=5;	//p=plane count  n=outputfunctionfrequency/units of simulation time  
	
	
	while(n<loop) //frequency of simulation
	{
	if(tkoffqueue==0)
		empty1+=5;
	if(landqueue==0)				//counting amount of idle time on each runway
		empty2+=5;
	if(tkoffqueue<2 && landqueue<2)
		empty3+=5;
		
	
	if(TIME%45==0)	// plane frequency=450 milli seconds can be changed to any multiple of 5
								
	{	
	
	// use either one of the two below commands under comments to generate random  numbers each time the program runs
	//remove the comments of the commands to be used 
		srand(clock());		// works on (ubuntu)gcc compiler			
		//srand(time(NULL));   // works in an ide(windows)
		int SEC=rand();	// generates random numbers which creates random plane arrival or departure probabilities.
	
		if(SEC%3==2)
		{	printf("remainder is 2\n");//if remainder is 2, a plane will be in the queue for departure
			if(tkoff==NULL)
			{	
				printf("plane %d, in the queue for departure\n",p);
				tkoff=malloc(sizeof(struct node));
				textra=tkoff;
				genmemory(p,tkoff);
				p++; tkoffqueue++;
				
			}		
			else
			{
				tnext=malloc(sizeof(struct node));
				textra->next=tnext;
				textra=tnext;
				genmemory(p,tnext);
				printf("plane %d, in the queue for departure\n",p);
				p++; tkoffqueue++;
			
			}
		
		}
		if(SEC%3==1)
		{	printf("remainder is 1\n");//if remainder is 1, a plane will be in the queue for arrival
			if(land==NULL)
			{	land=malloc(sizeof(struct node));
				printf("plane %d, in the queue for arrival\n",p);
				lextra=land;
				genmemory(p,land);
				p++; landqueue++;
				
			}		
			else
			{
				lnext=malloc(sizeof(struct node));
				lextra->next=lnext;
				lextra=lnext;
				genmemory(p,lnext);
				printf("plane %d, in the queue for arrival\n",p);
				p++; landqueue++;
			}
		}
	}
		
		if(TIME%100==0) // simulation frequency=100(ie.1sec), ie a plane will either land or takeoff with a lapse of 1second
						// can be reduced to a multiple of 5 if faster simulation is required.
		{
			printf("number of planes in the queue for depature: %d\n",tkoffqueue);
			printf("number of planes in the queue for arrival: %d\n",landqueue);
			output(); // simulation by the control tower
			n++;
			printf("\n \n");
		}
		delay(0.05);// basis of clock with 50 milliseconds as the least count 
		TIME+=5;//gives a delay of 50 milliseconds.
		
	}
}

void delay(float seconds)	
{
	int milli=1000*seconds;
	clock_t start=clock();
	while(clock()<start+milli);
	
}

