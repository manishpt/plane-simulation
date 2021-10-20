#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

/*
program structure:
starts from main function
laps function is called
enters the loop for n(20 times) units of time of simulation
within the loop
creates linked lists and stores the information of planes in tkoff and landing queue by calling genmemory function
and calls the output function for simulation by the automated control tower
repeats n times
comes out of the loop
exits the laps function
prints the status of simulation in main function
the program terminates 	
*/


void output();
void delay(float seconds);
void laps();
struct node* genmemory(int plane,struct node *inext );


int land2count=0,land3count=0,tkoff1count=0,tkoff3count=0,tkoffqueue=0,landqueue=0,loop;
float empty1=0,empty2=0,empty3=0;

struct node{
	struct node *next;
	int name;
}*tkoff=NULL,*land=NULL,*tnext=NULL,*lnext=NULL,*lextra=NULL,*textra=NULL;


int main()
{int n=0,p=1;
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


void output()
{
struct node *flush; 
if(tkoff!=NULL || land!=NULL)
{
if(tkoff!=NULL)
{	
	printf("plane %d has tookoff from runway1\n",(tkoff->name));
	tkoff1count++ ;tkoffqueue--; 
	flush=tkoff;
	tkoff=tkoff->next;
	free(flush);   
	
	if(landqueue<=1 && tkoff!=NULL)		
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
	free(flush);


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
{printf("the runways are empty");} 

}




struct node* genmemory(int plane,struct node *inext )
{	
		
	
	struct node *ptr=NULL;
	
	inext->next=ptr;	 
	inext->name=plane;	
	
    
}


void laps()
{	
	int p=1,n=0,TIME=5;	  
	
	srand(time(NULL));
	while(n<loop) 
	{
	if(tkoffqueue==0)
		empty1+=5;
	if(landqueue==0)				
		empty2+=5;
	if(tkoffqueue<2 && landqueue<2)
		empty3+=5;
		
	
	if(TIME%45==0)	
								
	{
		srand(time(NULL));
		int SEC=rand();	
	
		if(SEC%3==2)
		{	printf("remainder is 2\n");
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
		{	printf("remainder is 1\n");
			if(land==NULL)
			{	land=malloc(sizeof(struct node));
				lextra=land;
				printf("plane %d, in the queue for arrival\n",p);
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
		
		if(TIME%100==0) 
		{
			printf("number of planes in the queue for depature: %d\n",tkoffqueue);
			printf("number of planes in the queue for arrival: %d\n",landqueue);
			output(); 
			n++;
			printf("\n \n");
		}
		delay(0.05); 
		TIME+=5;
		
	}
}

void delay(float seconds)	
{
	int milli=1000*seconds;
	clock_t start=clock();
	while(clock()<start+milli);
	
}

