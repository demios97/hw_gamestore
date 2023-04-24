#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100


typedef struct game_node {
    char* title;
    char* genre;
    int year;
    float rating;
    struct game_node* next;
    struct dlc_node* dlc_head;
}GameNode;

typedef struct dlc_node {
    char* title;
    float price;
    struct dlc_node* next;
}DLCNode;

typedef struct {
    GameNode* head;
}GameLinkedList;

GameNode* createGame(){
    char title[MAX_LENGTH];
    char genre[MAX_LENGTH];
    int year;
    float rating;
    printf("Game Title - ");
    scanf("%s", &title);
    printf("Game Genre - ");
    scanf("%s", &genre);
    printf("Year - ");
    scanf("%d", &year);
    printf("Rating - ");
    scanf("%f", &rating);
    GameNode *newNode = (GameNode *)malloc(sizeof(GameNode));
    if(newNode==NULL) return NULL;
    newNode->title = (char *)malloc(strlen(title) + 1);
    if(newNode->title==NULL){
        free(newNode);
        return NULL;
    }
    strcpy(newNode->title, title);
    newNode->genre = (char *)malloc(strlen(genre) + 1);
    if(newNode->genre==NULL){//TODO do we need to also free the memory allocated prev in newndoe->title aswell?
        free(newNode);
        return NULL;
    }
    strcpy(newNode->genre, genre);
    newNode->year = year;
    newNode->rating = rating;
    newNode->dlc_head = NULL;
    return newNode;
}

/*GameNode* insert_game_at_beginning(GameNode* head){
    GameNode *newNode = createGame();
    if(newNode==NULL) return head;
    newNode->next = head;
    return newNode;
}*/ // Not sure that we need the function

GameNode* insert_game_at_end(GameNode* head){
    GameNode *newNode = createGame();//creating a memory for the new game and storing the game in the memory.
    if(newNode==NULL) return head;
    if(head==NULL){//storing the newly created game at the start
        newNode->next = NULL;
        head = newNode;
        return head;
    }
    else{//if a game exist
        GameNode *curr = head;

        while (curr != NULL)
            curr = curr->next;
        
        newNode->next = NULL; 
        curr = newNode;
    }
    return head;
}

void printList(GameNode* head){
    GameNode *curr = head;
    int i = 1;
    while(curr != NULL){
        printf("%d : Title - %s Genre - %s Year - %d Rating - %f\n", i++, curr->title, curr->genre, curr->year, curr->rating);
        curr = curr->next;
    }
}



GameNode* ratingSort(GameNode *head){//TODO check if there is something to add to function, and edge cases(have not checked egde cases).
    GameNode *curr = head->next;
    GameNode *insertion = head;
    GameNode temp;

    if(insertion == NULL || curr == NULL){
        return;
    }

    while(curr != NULL){
        if(curr->rating < insertion->rating){//checking between 2 nodes and swap between them if the right one is smaller
            temp = *insertion;
            *insertion = *curr;
            *curr = temp;
            curr = insertion->next;
        }
        curr = curr->next;
        insertion = insertion->next;

    }
    return head;
    
}







int main(){
    int operation;
    GameLinkedList games;
    games.head==NULL;
    while(1){
    printf("Video Game List Operations\n");
    printf("-----------------------------\n");
    printf("1. Insert game at beginning\n");
    printf("2. Insert game at end\n");
    printf("3. Delete game from beginning\n");
    printf("4. Delete game from end\n");
    printf("5. Print list\n");
    printf("6. Find game by title\n");
    printf("7. Update game information\n");
    printf("8. Sort list by title\n");
    printf("9. Exit\n");
    scanf("%d", &operation);
    switch(operation){
        case 1:
            //games.head = insert_game_at_beginning(games.head);
            break;
        case 2:
            games.head = insert_game_at_end(games.head);
            break;
        case 3:
            //deleteBeg();
            break;
        case 4:
            //deleteEnd();
            break;
        case 5:
            printList(games.head);
            break;
        case 6:
            //findGame();
            break;
        case 7:
            //updateInfo();
            break;
        case 8:
            //sortTitles();
            break;
        case 9:
            //free();
            return 0;
        default:
            printf("Error! There is no such operation\n");
            break;
    }
    }
}