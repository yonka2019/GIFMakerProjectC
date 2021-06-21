/*********************************
* Class: MAGSHIMIM Final Project *
* Play function declaration	 	 *
**********************************/

#define _CRT_SECURE_NO_WARNINGS
#define CV_IGNORE_DEBUG_BUILD_GUARD

#ifndef VIEWH
#define VIEWH

#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <opencv2\core\core_c.h>
#include <opencv2\highgui\highgui_c.h>
#include "linkedList.h"

#define GIF_REPEAT 5

/// <summary>
/// Plays all pictures as GIF file
/// </summary>
/// <param name="list">Node of all frames (/pictures)</param>
void play(FrameNode *list);

#endif