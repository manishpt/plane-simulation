//global variables
int land2count,land3count,tkoff1count,tkoff3count,tkoffqueue,landqueue,loop;
float empty1,empty2,empty3;
//structure which stores plane name/number and the adress to the next node
//used for creating linked lists
struct node{
	struct node *next;
	int name;
}*tkoff,*land,*tnext,*lnext,*lextra,*textra;

//function delarations
void output();
void delay(float seconds);
void laps();
struct node* genmemory(int plane,struct node *inext );
