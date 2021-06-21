#define _CRT_SECURE_NO_WARNINGS

#include "linkedList.h"
#include "projectManager.h"

FrameNode* askLoadProject()
{
	int loadExistingProject = FALSE;

	printf("Welcome to Magshimim Movie Maker! what would you like to do?\n"
		"   [0] Create a new project\n"
		"   [1] Load existing project \n");
	scanf("%d", &loadExistingProject);
	getchar();

	if (loadExistingProject)
	{
		char path[STR_LEN] = { 0 };

		printf("Enter the path of the project <including project name>:\n");
		myFgets(path, STR_LEN);
		return loadProject(path);
	}

	return NULL;
}
FrameNode* loadProject(char* projectPath)
{
	FrameNode* head = NULL;
	FILE* projectFile = NULL;
	char ch = ' ';
	int delimiterCounter = 0;

	//Frame Data
	char path[STR_LEN] = { 0 };
	char duration[STR_LEN] = { 0 };
	char name[STR_LEN] = { 0 };

	char cToStr[2] = { 0 }; // Char to string to use strcat()
	cToStr[1] = '\0'; // array that ends with '/0' (NULL) is string

	projectFile = fopen(projectPath, "r");
	if (projectFile == NULL)
	{
		printf("Can't open \"%s\" file\n", projectPath);

		exit(-1);
		return NULL;
	}

	while ((ch = (char)fgetc(projectFile)) != EOF)
	{
		cToStr[0] = ch;
		if (ch == '\n')
		{
			insertAtEnd(&head, createFrame(path, atoi(duration), name)); // add frame to frame node

			// reset variables data to be ready to the new frame data
			delimiterCounter = 0;
			path[0] = '\0';
			duration[0] = '\0';
			name[0] = '\0';

			// continue to new frame data

			continue;

		}		
		else if (ch == '|')
		{
			delimiterCounter++;
			continue;
		}
		/* delimiterCounter = 0 (each '|' increases the variable by 1)
		 * -------------------------- 
		 *   0        1          2
	     * FILE: name | duration | path \n
		 */
		switch (delimiterCounter) 
		{
			case 0:
				strcat(name, cToStr);
				break;
			case 1:
				strcat(duration, cToStr);
				break;
			case 2:
				strcat(path, cToStr);
				break;
		}
	}

	fclose(projectFile);
	return head;
}
void saveProject(FrameNode* head)
{
	FILE* projectFile = NULL;
	char path[STR_LEN] = { 0 };
	char duration[STR_LEN] = { 0 };

	printf("Where to save the project? enter a full path and file name\n");
	myFgets(path, STR_LEN);

	projectFile = fopen(path, "w+");
	if (projectFile == NULL)
	{
		printf("Can't open \"%s\" file\n", path);
		freeMemory(head);

		exit(-1);
		return;
	}

	FrameNode* p = head;

	while (p)
	{
		fputs(p->frame->name, projectFile);
		fputc('|', projectFile);

		sprintf(duration, "%d", p->frame->duration); // int to char* (str)
		fputs(duration, projectFile);
		fputc('|', projectFile);

		fputs(p->frame->path, projectFile);

		fputc('\n', projectFile);

		p = p->next;
	}  // FILE: name | duration | path \n
	fclose(projectFile);
}