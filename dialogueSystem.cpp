// File: dialogueSystem.cpp
// Developer: Mehrbod Molla Kazemi.

// Main include.
#include "dialogueSystem.h"

// using namespace DialogueSystem;

// Static definitions.
/*int						DialogueSystem::ActorBase::Settings_Font_Color_Actor1 = 2;
int						DialogueSystem::ActorBase::Settings_Font_Color_Actor2		=	8;
int						DialogueSystem::ActorBase::Settings_Font_Color_Actor3		=	6;
int						DialogueSystem::ActorBase::Settings_Font_Color_Actor4		=	3;
int						DialogueSystem::ActorBase::Settings_Font_Color_Actor5		=	4;
int						DialogueSystem::ActorBase::Settings_Font_Color_Actor6		=	5;
int						DialogueSystem::ActorBase::Settings_Font_Color_Actor7		=	7;
int						DialogueSystem::ActorBase::Settings_Font_Color_Actor8		=	1;*/

// Dialogue -> Text -> GetDialogueType().
// Gets the type of this Dialogue object.
DialogueSystem::DialogueTypes				DialogueSystem::DialogueText::GetDialogueType()
{
	return DialogueType_Text;
}

// Dialogue -> Text -> SetFontData().
// Sets font data for this DialogueText object.
void										DialogueSystem::DialogueText::Set_FontData(TRNG_Font fontData)
{
	this->fontData = fontData;
}

// Dialogue -> Text -> GetFontData().
// Gets font data from this DialogueText object.
DialogueSystem::TRNG_Font					DialogueSystem::DialogueText::Get_FontData() const
{
	return TRNG_Font(this->fontData);
}

// Gets frame duration counter from this Dialogue object.
short										DialogueSystem::DialogueBase::Get_FrameCounter() const
{
	return this->frameCounter;
}

// Sets frame duration counter for this Dialogue object.
void										DialogueSystem::DialogueBase::Set_FrameCounter(short frameCount)
{
	this->frameCounter = frameCount;
}

// Decrements duration frame counter by 1 unit and returns true if any frames are left.
bool DialogueSystem::DialogueBase::Decrement_FrameCounter()
{
	if (this->frameCounter <= 0)
		return false;

	this->frameCounter--;
	return true;
}

// Checks if any frames are left to be processed.
bool DialogueSystem::DialogueBase::NotZeroOrLess_FrameCounter()
{
	return this->frameCounter > 0;
}

// Dialogue Text Public Defalt ctor.
DialogueSystem::DialogueText::DialogueText()
{
	TRNG_Font myFont {};
	myFont.color_FC = 1;
	myFont.coordinates = { 500, 800 };	
	myFont.flags_FT = 128;
	myFont.flags_FTS = 0x8000;

	this->fontData = myFont;
	this->Set_FrameCounter(0);
}

// Dialogue Text Public Parametrized ctor.
DialogueSystem::DialogueText::DialogueText(TRNG_Font fontData, int stringIndex, int frameCount)
{
	this->fontData = fontData;
	this->Set_FrameCounter(frameCount);
}

// Dialogue Text dtor.
DialogueSystem::DialogueText::~DialogueText()
{
}

// Actor -> GetActorType().
// Gets the current type of this Actor object.
DialogueSystem::ActorTypes					DialogueSystem::Actor::GetActorType()
{
	return ActorType_Actor;
}

// Makes this actor speak.
void DialogueSystem::Actor::Speak(void ppPrintText(int, int, char*, WORD, int, WORD), char* ppGetString(int), void ppDrawSprite2D(RECT*, WORD, int, BYTE, COLORREF), void ppConvertMicroUnits(RECT*))
{
	// Speak text.
	for(int i = 0; i < MAX_TEXT_DIALOGUES_FOR_ACTOR; i++)
		if (this->textSpeeches[i].NotZeroOrLess_FrameCounter())
		{
			/*TRNG_Font font = this->textSpeeches[i].Get_FontData();
			RECT rect{ 0, 0, 0, 0 };
			rect.left = font.coordinates.x;
			rect.top = font.coordinates.y;

			char* loaded_String = ppGetString(font.stringIndex);
			ppConvertMicroUnits(&rect);

			// Render text to game's Direct3D screen.
			ppPrintText(rect.left, rect.top, loaded_String, font.flags_FT, font.color_FC, font.flags_FTS);

			// Decrement frame counter.
			this->textSpeeches[i].Decrement_FrameCounter();*/
		}
}

// Makes a DialogueText and stores it in class.
bool										DialogueSystem::Actor::Make_Speech_Text(int stringIndex, short frameDuration, DialogueText* out_dlgTextObj)
{
	int freeTextSpeechIndex = this->Find_Free_TextSpeeches_Index();

	if (freeTextSpeechIndex < 0)
		return false;

	this->textSpeeches[freeTextSpeechIndex].Set_FontData(this->actor_Font);
	this->textSpeeches[freeTextSpeechIndex].Set_FrameCounter(frameDuration);

	if (out_dlgTextObj != NULL)
		out_dlgTextObj = &this->textSpeeches[freeTextSpeechIndex];
}

// Actor Default ctor.
DialogueSystem::Actor::Actor()
{	
}

// Actor dtor
DialogueSystem::Actor::~Actor()
{
}

// Finds the next free index in text speech objects.
int DialogueSystem::Actor::Find_Free_TextSpeeches_Index() const
{
	for (int i = 0; i < MAX_TEXT_DIALOGUES_FOR_ACTOR; i++)
		if (this->textSpeeches[i].Get_FrameCounter() <= 0)
			return i;

	return -1;
}
