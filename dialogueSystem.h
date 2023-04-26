// File: dialogueSystem.h
// Developer: Mehrbod Molla Kazemi

#pragma once

#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "bass.h"		// prototypes for extra sound library: bass.dll
// Following header files will be updated for every new version of 
// the tomb_NextGeneration.dll, so it's better you don't change them
//  because they will be replaced for any new update.

#include "Tomb_NextGeneration.h" // mnemonic constants defined in tomb_NextGeneration.dll
#include "structures.h" // structure of tomb4 program and trng dll
#include "DefTomb4Funct.h" // defines of tomb4 procedure prototypes
#include "functions.h"  // assigments of real tomb4 address to each tomb4 procedures
#include "macros.h"  // definition of macros

	// FOR_YOU:
	// While the followings are the headers you can use 
	// to type your structures, constants and new tomb4 procedures you 
	// discovered. 
	// Following files are only yours and trng will not ever change them:
#include "macros_mine.h"  // here you define your own macros
#include "constants_mine.h" // here you define your mnemonic constants
#include "structures_mine.h" // here you type your structure definitions
#include "Tomb4Discoveries_mine.h" // here type tomb4 procedures you discovered

#include "trng.h" // list of trng functions imported from trng.cpp source. 

// DialogueSystem Namespace.
namespace DialogueSystem
{
	// Constants.

	// Parameters=  PARAM_DIALOGUES_TEXT_BRUSH, ...
	const	WORD		PARAM_DIALOGUES_TEXT_BRUSH					=	1;
	// Parameters=  PARAM_DIALOGUES_SEQUENTIAL_TEXT, ...
	const	WORD		PARAM_DIALOGUES_SEQUENTIAL_TEXT				=	2;

	// Enums.

	// Dialogue types supported by this plugin.
	enum DialogueTypes
	{
		DialogueType_None			=	 0,
		DialogueType_Text			=	 1,
	};
	
	// Abstract base class for all kinds of dialogues.
	class DialogueBase
	{
	public:
		// Abstract function for getting the type of derived Dialogue object.
		virtual DialogueTypes			GetDialogueType()	=	0;

	protected:
		// Frame counter. Specifies how many game frames left for the object to vanish.
		short							frameCounter;
	};

	// Dialogue -> Text class.
	class DialogueText : public DialogueBase
	{
		// Gets the type of this Dialogue object.
		DialogueTypes					GetDialogueType();
	};
}
