#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct chat {
    char text[100];
    char name[100];
    struct chat *next;
    struct chat *prev;
};

typedef struct chat ch;

struct list {
    ch *head;
    ch *headp;
};

typedef struct list l;

void init_list(l *ptr);
void insert(l *ptr, char charac[100], char nam[100]);
void pin(l *ptr, char nam[100]);
void unpin(l *ptr, char nam[100]);
void display(l *ptr);

int main() {
    char cha[100], name[100];
    int choice;
    l chatList;
    
    init_list(&chatList);

    while (1) {
        display(&chatList);
        printf("\n1..insert chat");
        printf("\n2..pin a chat");
        printf("\n3..unpin a chat");
        printf("\n4..display all chats");
        printf("\n5..exit");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the name: ");
                scanf("%s", name);
                printf("\nEnter the chat: ");
                scanf("%s", cha);
                insert(&chatList, cha, name);
                break;
            case 2:
                printf("\nEnter the chat to pin: ");
                scanf("%s", name);
                pin(&chatList, name);
                break;
            case 3:
                printf("\nEnter the chat to unpin: ");
                scanf("%s", name);
                unpin(&chatList, name);
                break;
            case 4:
                display(&chatList);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid choice!");
                break;
        }
    }
}

void init_list(l *ptr) {
    ptr->head = NULL;
    ptr->headp = NULL;
}

void insert(l *ptr, char charac[100], char nam[100]) {
    ch *temp = (ch *)malloc(sizeof(ch));
    strcpy(temp->name, nam);
    strcpy(temp->text, charac);
    temp->prev = temp->next = NULL;

    if (ptr->head == NULL) {
        ptr->head = temp;
    } else {
        temp->next = ptr->head;
        ptr->head->prev = temp;
        ptr->head = temp;
    }
}

void pin(l *ptr, char nam[100]) {
    ch *pres = ptr->head;

    while (pres != NULL && strcmp(pres->text, nam) != 0) {
        pres = pres->next;
    }

    if (pres == NULL) {
        printf("Chat not found.\n");
        return;
    }

    if (ptr->headp == NULL) {
        ptr->headp = pres;
        pres->prev = NULL;
    } else {
        pres->prev = NULL;
        pres->next = ptr->headp;
        ptr->headp->prev = pres;
        ptr->headp = pres;
    }
}

void unpin(l *ptr, char nam[100]) {
    ch *pres = ptr->headp;

    while (pres != NULL && strcmp(pres->text, nam) != 0) {
        pres = pres->next;
    }

    if (pres == NULL) {
        printf("Pinned chat not found.\n");
        return;
    }

    if (pres->prev != NULL) {
        pres->prev->next = pres->next;
    } else {
        ptr->headp = pres->next;
    }

    if (pres->next != NULL) {
        pres->next->prev = pres->prev;
    }

    free(pres);
}

void display(l *ptr) {
    ch *pres = ptr->head;

    if (pres == NULL) {
        printf("\nEmpty list");
    } else {
        printf("\nAll Chats:\n");
        while (pres != NULL) {
            printf("Name: %s Text: %s\n", pres->name, pres->text);
            pres = pres->next;
        }
    }

    pres = ptr->headp;
    if (pres == NULL) {
        printf("\nNo pinned chats");
    } else {
        printf("\nPinned Chats:\n");
        while (pres != NULL) {
            printf("Name: %s Text: %s\n", pres->name, pres->text);
            pres = pres->next;
        }
    }
}