#define _CRT_SECURE_NO_WARNINGS
/*********************************
* Class: MAGSHIMIM C2			 *
* Week: 11             			 *
* Name: Final Project            *
* Credits: Yonka                 *
**********************************/

#include "linkedList.h"
#include "view.h"
#include "projectManager.h"


#define EXIT 0
#define ADD 1
#define REMOVE 2
#define CHANGE_INDEX 3
#define CHANGE_DURATION 4
#define CHANGE_ALL_DURATIONS 5
#define FRAME_LIST 6
#define PLAY 7
#define SAVE 8

int selectMenu();

int main(void)
{
	int choice = 1;

	FrameNode* head = NULL;
	Frame* newFrame = NULL;

	head = askLoadProject(&head);

	while (choice != EXIT)
	{
		choice = selectMenu();
		switch (choice)
		{
			case EXIT:
				freeMemory(head);
				printf("\nBye!\n");
				break;
			case ADD:
				newFrame = initFrame(head);
				if (newFrame != NULL)
				{
					insertAtEnd(&head, newFrame);
				}
				break;
			case REMOVE:
			{
				char name[STR_LEN] = { 0 };

				printf("Enter the name of the frame you wish to erase\n");
				myFgets(name, STR_LEN);

				if (!removeFrame(&head, name))
				{
					printf("This frame doesn't exist!\n");
				}
				break;
			}
			case CHANGE_INDEX:
			{
				char name[STR_LEN] = { 0 };
				int newIndex = 0;

				printf("Enter the name of the frame\n");
				myFgets(name, STR_LEN);

				printf("Enter the new index in the movie you wish to place the frame\n");
				scanf("%d", &newIndex);
				getchar();

				changeIndex(&head, name, newIndex);
				break;
			}
			case CHANGE_DURATION:
			{
				char name[STR_LEN] = { 0 };
				int newDuration = 0;

				printf("Enter the name of the frame you wish to change his duration\n");
				myFgets(name, STR_LEN);

				printf("Enter the new duration to this frame\n");
				scanf("%d", &newDuration);
				getchar();

				changeDuration(&head, name, newDuration);
				break;
			}
			case CHANGE_ALL_DURATIONS:
			{
				int newDuration = 0;

				printf("Enter the new duration to all frames\n");
				scanf("%d", &newDuration);
				getchar();

				changeAllDurations(&head, newDuration);
				break;
			}
			case FRAME_LIST:
				printList(head);
				break;
			case PLAY:
				play(head);
				break;
			case SAVE:
				saveProject(head);
				break;
			default:
				printf("Invalid Input, please try again\n");
				break;
		}
	}
	getchar();
	return 0;
}
/// <summary>
/// Shows the user the menu and returns the selected option
/// </summary>
/// <returns>Selected option (0 to 8)</returns>
int selectMenu()
{
	int choice = 0;

	printf("What would you like to do?\n"
		"   [0] Exit\n"
		"   [1] Add new Frame\n"
		"   [2] Remove a Frame\n"
		"   [3] Change frame index\n"
		"   [4] Change frame duration\n"
		"   [5] Change duration of all frames\n"
		"   [6] List frames\n"
		"   [7] Play movie!\n"
		"   [8] Save project\n");
	scanf("%d", &choice);
	getchar();

	return choice;
}