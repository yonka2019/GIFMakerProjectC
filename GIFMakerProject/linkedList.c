#define _CRT_SECURE_NO_WARNINGS
/*********************************
* Class: MAGSHIMIM C2			 *
* Week: 11             			 *
* Name: Final Project            *
* Credits: Yonka                 *
**********************************/

#include "linkedList.h"

Frame* initFrame(FrameNode* head)
{
	char path[STR_LEN] = { 0 };
	char name[STR_LEN] = { 0 };
	int duration = 0;
	bool alreadyFrameExist = FALSE;

	printf("*** Creating new Frame ***\n");

	printf("Please insert Frame path:\n");
	myFgets(path, STR_LEN);
	if (!fileExists(path))
	{
		printf("File %s doesn't exist.\n", path);
		return NULL;
	}

	printf("Please insert frame duration(in milliseconds):\n");
	scanf("%d", &duration);
	getchar();

	printf("Please choose a name for that frame:\n");
	do
	{
		myFgets(name, STR_LEN);
		alreadyFrameExist = frameExist(head, name);
		if (alreadyFrameExist)
		{
			printf("The name is already taken, please enter another name\n");
		}
	} while (alreadyFrameExist);

	return createFrame(path, duration, name);
}
Frame* createFrame(char* path, int duration, char* name)
{
	Frame* newFrame = (Frame*)malloc(sizeof(Frame));
	newFrame->path = (char*)malloc((strlen(path) + 1) * sizeof(char));
	newFrame->name = (char*)malloc((strlen(name) + 1) * sizeof(char));

	strcpy(newFrame->path, path);
	newFrame->duration = duration;
	strcpy(newFrame->name, name);

	return newFrame;
}
FrameNode* createFrameNode()
{
	FrameNode* newFrameNode = (FrameNode*)malloc(sizeof(FrameNode));

	newFrameNode->frame = NULL;
	newFrameNode->next = NULL;

	return newFrameNode;
}
void myFgets(char* str, int n)
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}
bool frameExist(FrameNode* head, char* name)
{
	FrameNode* p = head;

	while (p)
	{
		if (strcmp(p->frame->name, name) == 0)
		{
			return TRUE;
		}
		p = p->next;
	}
	return FALSE;
}
void insertAtEnd(FrameNode** head, Frame* newFrame)
{
	if (!*head)
	{
		(*head) = createFrameNode();
		(*head)->frame = newFrame;
	}
	else
	{
		FrameNode* p = *head;
		while (p->next)
		{
			p = p->next;
		}
		p->next = createFrameNode();
		p->next->frame = newFrame;
	}
}
void printList(FrameNode* head)
{
	FrameNode* p = head;

	printf("\t\tName\t\tDuration\t\tPath\n");
	while (p)
	{
		printf("\t\t%s", p->frame->name);
		printf("\t\t%d ms", p->frame->duration);
		printf("\t\t\t%s\n", p->frame->path);

		p = p->next;
	}
	printf("\n");
}
bool removeFrame(FrameNode** head, char* name)
{
	FrameNode* p = *head;
	FrameNode* dNode = NULL;

	if (*head)
	{
		if (0 == strcmp((*head)->frame->name, name))
		{
			*head = (*head)->next;
			free(p->frame->path);
			free(p->frame->name);
			free(p->frame);
			free(p);

			return TRUE;
		}
		else
		{
			while (p->next &&
				0 != strcmp(p->next->frame->name, name))
			{
				p = p->next;
			}
			if (p->next)
			{
				dNode = p->next;
				p->next = dNode->next;
				free(dNode);

				return TRUE;
			}
		}
	}
	return FALSE;
}
void changeIndex(FrameNode** head, char* name, int index)
{
	FrameNode* root = *head;
	FrameNode* link = root;
	FrameNode* prev = 0;

	int count = 0;
	if (getLength(root) < index)
	{
		printf("The index is greater than the list size\n");
		return;
	}
	index--;
	while (link && strcmp(link->frame->name, name) != 0)
	{
		prev = link;
		link = link->next;
		count++;
	}
	if (!link)  // Name not found - no swap
	{
		printf("This frame doesn't exist!\n");
		return;
	}
	if (count == index)   // Already in target position - no swap
	{
		printf("This frame already in this index\n");
		return;
	}
	if (count == 0)     // Moving first item; update root
	{
		*head = root->next;
		root = *head;
	}
	else
	{
		prev->next = link->next;
	}
	// link is detached; now where does it go?
	if (index == 0)       // Move to start; update root
	{
		link->next = root;
		*head = link;
		return;
	}
	FrameNode* node = root;
	for (int i = 0; i < index - 1 && node->next != 0; i++)
	{
		node = node->next;
	}
	link->next = node->next;
	node->next = link;
}
int getLength(FrameNode* head)
{
	int count = 0;
	FrameNode* current = head;

	while (current)
	{
		count++;
		current = current->next;
	}

	return count;
}
void changeDuration(FrameNode** head, char* name, int duration)
{
	FrameNode* p = *head;
	while (p && strcmp(p->frame->name, name) != 0)
	{
		p = p->next;
	}
	if (!p)  // Name not found - no swap
	{
		printf("This frame doesn't exist!\n");
		return;
	}
	p->frame->duration = duration;
}
void changeAllDurations(FrameNode** head, int duration)
{
	FrameNode* p = *head;
	while (p)
	{
		p->frame->duration = duration;
		p = p->next;
	}
}
void freeMemory(FrameNode* head)
{
	FrameNode* temp = head;
	while (head)
	{
		temp = head->next;
		free(head->frame->path);
		free(head->frame->name);
		free(head->frame);
		free(head);
		head = temp;
	}
}
bool fileExists(char* path)
{
	FILE* file = NULL;
	if ((file = fopen(path, "r")))
	{
		fclose(file);
		return TRUE;
	}
	return FALSE;
}