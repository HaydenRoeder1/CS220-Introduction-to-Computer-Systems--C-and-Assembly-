#include "poker.h"
char INPUT[] = "sample_hands.txt";
char EXPECT[] = "expected.txt";


int main(){
	FILE *fp = fopen(INPUT, "r"); //Opens file of sample hands
	FILE *expected = fopen(EXPECT, "r");
	char curGame[256];
	char curExpect[256];
	char winStr[256];
	int expectWinner;
	struct Player players[3];
	struct Card community[5];
	int counter = 1;
	FILE *writeFile = fopen("Output.txt", "w");
	while(fgets(curGame, 256, fp) != NULL && counter < 50){//Loops through every line of the sample file
		input(curGame, players, community); //Calls input from poker.h to setup players and community for this game
		for(int i = 0; i < 3; i++){
			//players[i].highCard = 0;
			players[i].score = findBestHand(&(players[i]), community, i);
		}
		int winner = calcWinner(players);
		//fprintf(writeFile, "Game %d: Player %d Wins with a score of %d \n", counter, winner + 1, players[winner].score);
		//printf("Game %d: Player %d Wins with a score of %d \n", counter, winner + 1, players[winner].score);
		//sprintf(winStr, "Player %d wins.", winner + 1);
		fgets(curExpect, 256, expected);
		sscanf(curExpect, "Player %d wins.", &expectWinner);
		if(expectWinner == winner + 1){
			printf("Game: %d worked\n", counter);
		}
		else{
			printf("Game: %d did not work, winner: %d, expected: %d, score: %d, expected: %d\n", counter, winner + 1, expectWinner, players[winner].fourthCard + 2, players[expectWinner - 1].fourthCard + 2);
		}
		counter++;
	}
	fclose(writeFile);
	//fgets(curGame, 256, fp);
	//input(curGame, players, community);
	//for(int i = 0; i < 3; i++){
	//	players[i].score = findBestHand(players[i], community);
	//}
	fclose(fp);
	return 0;
}
