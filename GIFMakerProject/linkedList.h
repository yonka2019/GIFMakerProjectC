#ifndef LINKEDLISTH
#define LINKEDLISTH

#define STR_LEN 50
#define FALSE 0
#define TRUE !FALSE

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

// Frame struct
typedef struct Frame
{
	char*		name;
	unsigned int	duration;
	char*		path;  
} Frame;


// Link (node) struct
typedef struct FrameNode
{
	Frame* frame;
	struct FrameNode* next;
} FrameNode;

/// <summary>
/// Changes the index to the given frame name to the given new index
/// </summary>
/// <param name="head">Frames node</param>
/// <param name="name">name of the frame to change his index</param>
/// <param name="index">new index to update to the given frame name</param>
void changeIndex(FrameNode** head, char* name, int index);
/// <summary>
/// Changes the duration to the given frame name to the given new duration
/// </summary>
/// <param name="head">Frames node</param>
/// <param name="name">name of the frame to change his duration</param>
/// <param name="duration">new duration to update to the given frame name</param>
void changeDuration(FrameNode** head, char* name, int duration);
/// <summary>
/// Changes duration of the all frames in the node (list)
/// </summary>
/// <param name="head">Frames node (list)</param>
/// <param name="duration">new duration to update to the all frames in the node (list)</param>
void changeAllDurations(FrameNode** head, int duration);
/// <summary>
/// Frees the allocated memory
/// </summary>
/// <param name="head">Frame node (list)</param>
void freeMemory(FrameNode* head);
/// <summary>
/// Inserts the new node into the end of the frame node (list)
/// </summary>
/// <param name="head">Frame node (list)</param>
/// <param name="newNode">new node to insert into the end of the current frame list</param>
void insertAtEnd(FrameNode** head, Frame* newNode);
/// <summary>
/// Prints the given frames list
/// </summary>
/// <param name="head">Frames node (list)</param>
void printList(FrameNode* head);
/// <summary>
/// custom fgets(); with '\n' built-in deletion
/// </summary>
/// <param name="str">string to input</param>
/// <param name="n">length of the string</param>
void myFgets(char str[], int n);
/// <summary>
/// Returns length of the given linkedList
/// </summary>
/// <param name="head">head of the linkedList</param>
/// <returns>length of the given linked list</returns>
int getLength(FrameNode* head);
/// <summary>
/// Checks if the given file path exists in the system 
/// </summary>
/// <param name="path">Path to check if he contains some file or not</param>
/// <returns>TRUE if file exists, either, FALSE</returns>
bool fileExists(char* path);
/// <summary>
/// Checks if frame with the given name alredy exists in the frames node list
/// </summary>
/// <param name="head">Frames node list)</param>
/// <param name="name">Name to check if there is already frame that took this name</param>
/// <returns>TRUE if this name already used by another frame, either, FALSE</returns>
bool frameExist(FrameNode* head, char* name);
/// <summary>
/// Removes frame by the given name from the given frames node list
/// </summary>
/// <param name="head">Frames node (list)</param>
/// <param name="name">Name of the given frame to remove from the given frame list</param>
/// <returns>True if success, false if there is error (which means - there is no frame with the given name)</returns>
bool removeFrame(FrameNode** head, char* name);
/// <summary>
/// Initializes frame
/// </summary>
/// <param name="head">Current frames node (linked list)</param>
/// <returns>Pointer to newly created frame</returns>
Frame* initFrame(FrameNode* head);
/// <summary>
/// Creates and return new frame by the given parameters
/// </summary>
/// <param name="path">path of the picture</param>
/// <param name="duration">duration to show this picture</param>
/// <param name="name">name of this frame</param>
/// <returns>Pointer to the new created frame</returns>
Frame* createFrame(char* path, int duration, char* name);
/// <summary>
/// Creates new frame node which will contains all created earlier frames
/// </summary>
/// <returns>Pointer to the new frame node linked list</returns>
FrameNode* createFrameNode();
#endif
