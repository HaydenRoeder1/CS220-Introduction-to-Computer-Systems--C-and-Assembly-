#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum Suit{
	Club, Spade, Heart, Diamond
};
struct Card{
	char suit;
	int value;
};
struct Player{
	struct Card cards[2];
	int highCard; //Value of the player's highest card
	int fourthCard;
	int thirdCard;
	int secondCard;
	int lowCard;
	int score; //Index of the player's best hand
};
int royalFlushCheck(int* club, int* diamond, int* heart, int* spade){
  //dillon
  //function checks each array of suits to see if there is a sequence from 10 to spade
  //royal flush:Ten, Jack, Queen, King, Ace, in same suit.
  for(int i = 8; i < 13; i ++){
    if((*(club + i) == 0)) break;
    if(i == 12) return 1;
  }

  for(int i = 8; i < 13; i ++){
    if((*(diamond + i) == 0)) break;
    if(i == 12) return 1;
  }

  for(int i = 8; i < 13; i ++){
    if((*(heart + i) == 0)) break;
    if(i == 12) return 1;
  }

  for(int i = 8; i < 13; i ++){
    if((*(spade + i) == 0)) break;
    if(i == 12) return 1;
  }
	return 0;
}

int straightFlushCheck(int* club, int* diamond, int* heart, int* spade, struct Player *players, int cp){
  //dillon
  //starting from 2, if a player has a card, we are checking the next 5 cards
  //straight flush: All cards are consecutive values of same suit
  for(int i = 0; i < 13; i ++){
    if(*(club + i) == 1){
      for(int j = 1; j < 5; j ++){
        if(*(club + (i + j)) == 0) break;
        if(j == 4){
				 (*players).highCard = (i + 4);
				 (*players).fourthCard = (i + 3);
				 (*players).thirdCard = (i + 2);
				 (*players).secondCard = (i + 1);
				 (*players).lowCard = (i);
				 return 1;
		      }
		    }
		  }
		}

  for(int i = 0; i < 13; i ++){
    if(*(diamond + i) == 1){
      for(int j = 1; j < 5; j ++){
        if(*(diamond + (i + j)) == 0) break;
				if(j == 4){
				 (*players).highCard = (i + 4);
				 (*players).fourthCard = (i + 3);
				 (*players).thirdCard = (i + 2);
				 (*players).secondCard = (i + 1);
				 (*players).lowCard = (i);
				 return 1;
				 }
	    }
	  }
	}

  for(int i = 0; i < 13; i ++){
    if(*(heart + i) == 1){
      for(int j = 1; j < 5; j ++){
        if(*(heart + (i + j)) == 0) break;
				if(j == 4){
				 (*players).highCard = (i + 4);
				 (*players).fourthCard = (i + 3);
				 (*players).thirdCard = (i + 2);
				 (*players).secondCard = (i + 1);
				 (*players).lowCard = (i);
				 return 1;
				 }
	    }
	  }
	}

  for(int i = 0; i < 13; i ++){
    if(*(spade + i) == 1){
      for(int j = 1; j < 5; j ++){
        if(*(spade + (i + j)) == 0) break;
				if(j == 4){
				 (*players).highCard = (i + 4);
				 (*players).fourthCard = (i + 3);
				 (*players).thirdCard = (i + 2);
				 (*players).secondCard = (i + 1);
				 (*players).lowCard = (i);
				 return 1;
				}
	    }
	  }
	}
  return 0;
}

int fourOfAKindCheck(int* allSuits, struct Player *players, int cp){
  //dillon
  //goes through the cards and if one is found it checks the other three suits in no particular order
  //four of a kind: Four cards of the same value
  for(int i = 0; i < 13; i ++){
    if(*(allSuits + i) == 4){
			 (*players).highCard = i;
			return 1;
		}
  }

  return 0;
}

int fullHouseCheck(int* allSuits, struct Player *players, int cp){
  //dillon
  //finds if there is a 3 of a kind and a pairs
  //full house: Three of a kind and a pair

  int two = 0; //if there is a pair, this var will equal 1
  int three = 0; //if there is a three of a kind, this var will equal 1
  for(int i = 0; i < 13; i ++){
    if(*(allSuits + i) == 2) two = 1;
    if(*(allSuits + i) == 3){
 			three = 1;
			(*players).highCard = i;
		}
  }

  if((two == 1) & (three == 1)) return 1;
  return 0;
}

int flushCheck(int* club, int* diamond, int* heart, int* spade, struct Player *players, int cp){
  //dillon
  //the function goes through each suit array and adds up how many total cards they have
  //flush: All cards of the same suit
  int total = 0;
  for(int i = 0; i < 13; i ++){
    if(*(club + i) == 1){ total ++;}
		if(total == 5){
			for(int j = 0; j < 13; j ++){
				total = 0;
				if(*(club + i) == 1){ total ++;}
				if(total == 5) (*players).highCard = (j);
				else if(total == 4) (*players).fourthCard = (j);
				else if(total == 3) (*players).thirdCard = (j);
				else if(total == 2) (*players).secondCard = (j);
				else if(total == 1) (*players).lowCard = (j);
			}
		}
  }
	total = 0;

  for(int i = 0; i < 13; i ++){
    if(*(diamond + i) == 1){ total ++;}
		if(total == 5){
			for(int j = 0; j < 13; j ++){
				total = 0;
				if(*(diamond + i) == 1){ total ++;}
				if(total == 5) (*players).highCard = (j);
				else if(total == 4) (*players).fourthCard = (j);
				else if(total == 3) (*players).thirdCard = (j);
				else if(total == 2) (*players).secondCard = (j);
				else if(total == 1) (*players).lowCard = (j);
			}
			return 1;
		}
	}
	total = 0;

  for(int i = 0; i < 13; i ++){
    if(*(heart + i) == 1){ total ++;}
		if(total == 5){
			for(int j = 0; j < 13; j ++){
				total = 0;
				if(*(heart + i) == 1){ total ++;}
				if(total == 5) (*players).highCard = (j);
				else if(total == 4) (*players).fourthCard = (j);
				else if(total == 3) (*players).thirdCard = (j);
				else if(total == 2) (*players).secondCard = (j);
				else if(total == 1) (*players).lowCard = (j);
			}
			return 1;
		}
	}
	total = 0;

  for(int i = 0; i < 13; i ++){
    if(*(spade + i) == 1){ total ++;}
		if(total == 5){
			for(int j = 0; j < 13; j ++){
				total = 0;
				if(*(spade + i) == 1){ total ++;}
				if(total == 5) (*players).highCard = (j);
				else if(total == 4) (*players).fourthCard = (j);
				else if(total == 3) (*players).thirdCard = (j);
				else if(total == 2) (*players).secondCard = (j);
				else if(total == 1) (*players).lowCard = (j);
			}
			return 1;
		}
	}
	return 0;
}

int straightCheck(int* allSuits, struct Player *players, int cp){
  //dillon
  //checks all suits to see if there is any
  //straight: All cards are consecutive values
  for(int i = 0; i < 13; i ++){
    if(*(allSuits + i) >= 1){
      for(int j = 1; j < 5; j ++){
        if(*(allSuits + i + j) == 0) break;//if no suit has the next value
        if(j == 4){
					(*players).highCard = (i + j);
					return 1;
				}
      }
    }
  }
  return 0;
}

int threeOfAKindCheck(int* allSuits, struct Player *players, int cp){
  //dillon
  //checks to see if there are 3 cards of the same values
  //three of a kind: Three cards of the same value

  for(int i = 0; i < 13; i ++){
    if(*(allSuits + i) == 3){
			(*players).highCard = i;
      return 1;
    }
  }

  return 0;
}

int twoPairsCheck(int* allSuits, struct Player *players, int cp){
  //dillon
  //checks to see if there are 2 sets of 2 cards of the same values
  //two pair: Two different pairs
  int numPairs = 0;

  for(int i = 0; i < 13; i ++){
    if(*(allSuits + i) == 2){
      numPairs ++;
	  	(*players).highCard = i;
    }
  }

  if(numPairs == 2){
	  return 1;
  }
  return 0;
}

int onePairCheck(int* allSuits, struct Player *players, int cp){
  //dillon
  //sees if there are two cards in the player's hand with the same values
  //pair: Two cards of the same value
  for(int i = 0; i < 13; i ++){
    if(*(allSuits + i) == 2){
			(*players).highCard = i;
			return 1;
		}
  }
  return 0;
}
int cardNumToInt(char c){
	//Hayden
	//Converts the value c into the appropriate integer card value
	switch(c){
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case 'T':
			return 10;
		case 'J':
			return 11;
		case 'Q':
			return 12;
		case 'K':
			return 13;
		case 'A':
			return 14;
		default:
			return 0;
	}
}

void printCards(struct Player players[], struct Card com[]){
	//Hayden
	//Prints the current cards on the table
	for(int i = 0; i < 3; i++){
		printf("Player%d:\n%d%c\n%d%c\n\n", i + 1, players[i].cards[0].value, players[i].cards[0].suit,
		players[i].cards[1].value, players[i].cards[1].suit);
	}
	printf("Community:\n");
	for(int i = 0; i < 5; i++){
		printf("%d%c\n",com[i].value, com[i].suit);
	}
	printf("\n");
}

void input(char game[], struct Player players[], struct Card com[]){
	//Hayden
	//Reads in a line of a sample file and sorts cards into the appropriate locations

	char *suits = (char*) malloc(sizeof(char) * 11);
	char *values = (char*) malloc(sizeof(char) * 11);

	//{Gets each useful char out of game
	sscanf(game, "%c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c", values, suits,
	values+1, suits+1,
	values+2, suits+2,
	values+3, suits+3,
	values+4, suits+4,
	values+5, suits+5,
	values+6, suits+6,
	values+7, suits+7,
	values+8, suits+8,
	values+9, suits+9,
	values+10, suits+10);
	//}


	//{Sorts cards to the appropriate players/community
	int counter = 0; //Iterates through each card of the game
	for(int j = 0; j < 3; j++){ //For each Player
		for(int i = 0; i < 2; i++){//Goes through each card
			players[j].cards[i].suit = *(suits + counter);
			//Converts the value char into the appropriate integer card value
			players[j].cards[i].value = cardNumToInt(*(values + counter));
			counter++;
		}
	}
	for(int i = 0; i < 5; i++){
		com[i].suit = *(suits + counter);
		com[i].value = cardNumToInt(*(values + counter));
		counter++;
	}
	//}
	//printCards(players, com);
	free(values);
	free(suits);
	//return;
}

int findBestHand(struct Player *player, struct Card *com, int currentPlayer){
	//Hayden
	//Calculates the score of the best hand a player can play
	//Creates 4 boolean arrays to simplify hand checking
	int *hearts = (int*) calloc(13, sizeof(int));
	int *clubs = (int*) calloc(13, sizeof(int));
	int *spades = (int*) calloc(13, sizeof(int));
	int *diamonds = (int*) calloc(13, sizeof(int));

	for(int i = 0; i < 2; i++){//Assigns all relevant cards into the arrays
		if((*player).cards[i].suit == 'C'){
			*(clubs + (*player).cards[i].value - 2) = 1;
		}
		if((*player).cards[i].suit == 'D'){
			*(diamonds + (*player).cards[i].value - 2) = 1;
		}
		if((*player).cards[i].suit == 'H'){
			*(hearts + (*player).cards[i].value - 2) = 1;
		}
		if((*player).cards[i].suit == 'S'){
			*(spades + (*player).cards[i].value - 2) = 1;
		}
	}
	for(int i = 0; i < 5; i++){
		if(com[i].suit == 'C'){
			*(clubs + com[i].value - 2) = 1;
		}if(com[i].suit == 'D'){
			*(diamonds + com[i].value - 2) = 1;
		}
		if(com[i].suit == 'H'){
			*(hearts + com[i].value - 2) = 1;
		}
		if(com[i].suit == 'S'){
			*(spades + com[i].value - 2) = 1;
		}
	}
	int* allSuits = (int*) calloc(13, sizeof(int));
	for(int i = 0; i < 13; i ++){
		if(*(clubs + i)){
			*(allSuits + i) += 1;
		}
		if(*(diamonds + i)){
			*(allSuits + i) += 1;
		}
		if(*(hearts + i)){
			*(allSuits + i) += 1;
		}
		if(*(spades + i)){
			*(allSuits + i) += 1;
		}
	}
	if(royalFlushCheck(clubs, diamonds, hearts, spades) == 1){
			free(hearts);
			free(clubs);
			free(spades);
			free(diamonds);
			free(allSuits);
			return 10;
	}if(straightFlushCheck(clubs, diamonds, hearts, spades, player, currentPlayer) == 1){
			free(hearts);
			free(clubs);
			free(spades);
			free(diamonds);
			free(allSuits);
			return 9;
	}if(fourOfAKindCheck(allSuits, player, currentPlayer) == 1){
			free(hearts);
			free(clubs);
			free(spades);
			free(diamonds);
			free(allSuits);
			return 8;
	}if(fullHouseCheck(allSuits, player, currentPlayer) == 1){
			free(hearts);
			free(clubs);
			free(spades);
			free(diamonds);
			free(allSuits);
			return 7;
	}if(flushCheck(clubs, diamonds, hearts, spades, player, currentPlayer) == 1){
			free(hearts);
			free(clubs);
			free(spades);
			free(diamonds);
			free(allSuits);
			return 6;
	}if(straightCheck(allSuits, player, currentPlayer) == 1){
			free(hearts);
			free(clubs);
			free(spades);
			free(diamonds);
			free(allSuits);
			return 5;
	}if(threeOfAKindCheck(allSuits, player, currentPlayer) == 1){
			free(hearts);
			free(clubs);
			free(spades);
			free(diamonds);
			free(allSuits);
			return 4;
	}if(twoPairsCheck(allSuits, player, currentPlayer) == 1){
			free(hearts);
			free(clubs);
			free(spades);
			free(diamonds);
			free(allSuits);
			return 3;
	}if(onePairCheck(allSuits, player, currentPlayer) == 1){
			free(hearts);
			free(clubs);
			free(spades);
			free(diamonds);
			free(allSuits);
			return 2;
	}

	free(hearts);
	free(clubs);
	free(spades);
	free(diamonds);
	free(allSuits);
	return 1;
}
int findHighCard(struct Player player){
	//Hayden
	//Calculates the highest value card in the player's hand
	if(player.cards[0].value > player.cards[1].value){
		return player.cards[0].value;
	}
	return player.cards[1].value;
}
int find2ndCard(struct Player player){
	//Hayden
	//In the case of a tie, finds the second highest card in the players hand (the other card they have)
	if(player.cards[0].value > player.cards[1].value){
		return player.cards[1].value;
	}
	return player.cards[0].value;
}
int calcWinner(struct Player *player){
	//Hayden
	//Returns the index of the winning player
	int winner = 0;
	for(int i = 0; i < 3; i++){
		if(player[i].score > player[winner].score){
			winner = i;
		}
		else if((player[i].score == player[winner].score) && (i != winner)){ //If there is a tie, check high cards
			if(player[i].highCard > player[winner].highCard){
				winner = i;
			}
			else if(player[i].highCard == player[winner].highCard){//If high cards tie check next cards
				if(player[i].fourthCard > player[winner].fourthCard){
					winner = i;
				}
				if(player[i].fourthCard == player[winner].fourthCard){//If 2nd cards tie check next cards
					if(player[i].thirdCard > player[winner].thirdCard){
						winner = i;
					}
				}
			}

		}
	}
	if(player[winner].score == 1){//If there is a tie at 1, check for highest card
		winner = 0;
		for(int i = 0; i < 3; i++){
			player[i].highCard = findHighCard(player[i]);
			if(player[i].highCard >= player[winner].highCard){
				winner = i;
			}
		}
	}
	return winner;
}
