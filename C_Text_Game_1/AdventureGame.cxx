#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Team 20 Simon Accamando, Kyle Kessler, Louis Sauter
//The goal of this game is to create an experience like Oregon trail, 
//where the user is able to interact with the game as to complete an end goal.
//Unlike the Oregon trail, we have created different smaller adventures for the user to experience





/*Game- Oregon trail type adventure game

Main--access fun1
	 

fun1--gets user name, checks.
* switch case for which adventure to take                           Switch Case
	array contains locations
	possible ask what kind of adventure to take

fun2--inventory array,													purchase looping
	needs to apply to which ever adventure is chosen
	
fun3--options for the adventure,										application loops
	needs to apply to which ever adventure is chose

fun4--possible display of pictures relating to the adventure chosen     Display images


fun5--final message to the game
	summary of decisions and events
*/
//Functions:

char fun1();


//Main function
int main(){
	fun1();
	return 0;
}


char fun1(){
	char name,check1='y';
	printf("Welcome to Team 20's Adventure game,\nIn this game you will have the option to select from different adventures.\nBut before we begin any expiditions what would you like to be called during your experience?\n");
	scanf(" %c", &name);
	printf("You will be called %c",'name');
	printf(" is this correct? (y)yes (n)no");
	scanf(" %c", &check1);
	while (check1!='y' && check1!='n'&& check1!='Y' && check1!='N'){
		printf("\nError!!\tThat was not an option Please enter one of the options provided");
		printf("You will be called %s,",name); 
		printf(" is this correct? (y)yes (n)no");
		scanf(" %c", &check1);
	}
	return name;
}
	
