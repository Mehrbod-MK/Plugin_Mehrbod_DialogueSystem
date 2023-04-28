// File: dialogueSystem.h
// Developer: Mehrbod Molla Kazemi

#pragma once

#include <stdint.h>
#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "Tomb_NextGeneration.h"

// DialogueSystem Namespace.
namespace DialogueSystem
{
	// Constants.

	// Parameters=  PARAM_DIALOGUES_TEXT_BRUSH, ...
	const	WORD		PARAM_DIALOGUES_TEXT_BRUSH					=	1;
	// Parameters=  PARAM_DIALOGUES_SEQUENTIAL_TEXT, ...
	const	WORD		PARAM_DIALOGUES_SEQUENTIAL_TEXT				=	2;

	// Maximum number of text dialogues per actor.
	const	int			MAX_TEXT_DIALOGUES_FOR_ACTOR				=	10;

	// Enums.

	// Dialogue types supported by this plugin.
	enum DialogueTypes
	{
		DialogueType_None			=	 0,
		DialogueType_Text			=	 1,
	};
	// Actor types.
	enum ActorTypes
	{
		ActorType_None				=	0,
		ActorType_Actor				=	1,
	};
	// Actor indices.
	/*enum ActorIndices
	{
		ActorIndex_NoIndex			=	0,
		ActorIndex_1				=	1,
		ActorIndex_2				=	2,
		ActorIndex_3				=	3,
		ActorIndex_4				=	4,
		ActorIndex_5				=	5,
		ActorIndex_6				=	6,
		ActorIndex_7				=	7,
		ActorIndex_8				=	8,
	};*/

	// TRNG Font Structure.
	typedef struct TRNG_Font
	{
		POINT coordinates;
		WORD flags_FT;
		int color_FC;
		WORD flags_FTS;

		TRNG_Font() :	coordinates({ 500, 700 }), 
						flags_FT(FT_SIZE_ATOMIC_CHAR), 
						color_FC(FC_WHITE),
						flags_FTS(FTS_ALIGN_CENTER)
		{}
	} TRNG_Font;

	// Subtitle sequence structure.
	typedef struct DialogueSys_SubtitleSequence
	{
		TRNG_Font subtitleFont;
		int indexNow;
		int stringIndices[500]; int delayIndices[500];

		DialogueSys_SubtitleSequence(): indexNow(-1), stringIndices(), delayIndices() {}
		
	} DialogueSys_SubtitleSequence;
	
	// Abstract base class for all kinds of dialogues.
	class DialogueBase
	{
	public:
		// Abstract function for getting the type of derived Dialogue object.
		virtual DialogueTypes			GetDialogueType()	=	0;

		// Gets frame duration counter from this Dialogue object.
		short							Get_FrameCounter() const;
		// Sets frame duration counter for this Dialogue object.
		void							Set_FrameCounter(short frameCount);
		// Decrements duration frame counter by 1 unit and returns true if any frames are left.
		bool							Decrement_FrameCounter();
		// Checks if any frames are left to be processed.
		bool							NotZeroOrLess_FrameCounter();

	private:
		// Frame counter. Specifies how many game frames left for the object to vanish.
		short							frameCounter;
	};

	// Dialogue -> Text class.
	class DialogueText : public DialogueBase
	{
	public:
		// Gets the type of this Dialogue object.
		DialogueTypes					GetDialogueType();

		// Sets font data for this DialogueText object.
		void							Set_FontData(TRNG_Font);
		// Gets font data from this DialogueText object.
		TRNG_Font						Get_FontData() const;

		// Dialogue Text Public Defalt ctor.
		DialogueText();
		
		// Dialogue Text Public Parametrized ctor.
		DialogueText(TRNG_Font, int, int);

		// Dialogue Text dtor.
		virtual ~DialogueText();

	private:
		// Font data.
		TRNG_Font						fontData;
	};

	// Abstract base class for all kinds of Actor objects.
	class ActorBase
	{
	public:
		// Abstract void for making speech.
		virtual void					Speak(void ppPrintText(int, int, char*, WORD, int, WORD),
											  char* ppGetString(int),
											  void ppDrawSprite2D(RECT*, WORD, int, BYTE, COLORREF),
											  void ppConvertMicroUnits(RECT*))	=	0;

		// Abstract function for getting the type of actor.
		virtual ActorTypes				GetActorType()	=	0;
	};

	// Actor class.
	class Actor : public ActorBase
	{
	public:
		// Gets the current type of this Actor object.
		ActorTypes						GetActorType();

		// Makes this actor speak.
		void							Speak(void ppPrintText(int, int, char*, WORD, int, WORD),
											  char* ppGetString(int),
											  void ppDrawSprite2D(RECT*, WORD, int, BYTE, COLORREF),
											  void ppConvertMicroUnits(RECT*));

		// Makes a DialogueText and stores it in class.
		bool							Make_Speech_Text(int, short, DialogueText* = NULL);

		// Actor Default ctor.
		Actor();

		// Actor dtor.
		virtual ~Actor();

	private:
		// Text Dialogs.
		DialogueText	textSpeeches[MAX_TEXT_DIALOGUES_FOR_ACTOR];

		// Actor index type.
		// ActorIndices	actorIndex;

		// Actor font data.
		TRNG_Font		actor_Font;

		// Finds the next free index in text speech objects.
		int				Find_Free_TextSpeeches_Index() const;
	};
}
