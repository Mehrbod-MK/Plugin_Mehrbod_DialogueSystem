// File: dialogueSystem.cpp
// Developer: Mehrbod Molla Kazemi.

// Main include.
#include "dialogueSystem.h"

// using namespace DialogueSystem;

// Static definitions.
int						DialogueSystem::ActorBase::Settings_Font_Color_Actor1		=	2;
int						DialogueSystem::ActorBase::Settings_Font_Color_Actor2		=	8;
int						DialogueSystem::ActorBase::Settings_Font_Color_Actor3		=	6;
int						DialogueSystem::ActorBase::Settings_Font_Color_Actor4		=	3;
int						DialogueSystem::ActorBase::Settings_Font_Color_Actor5		=	4;
int						DialogueSystem::ActorBase::Settings_Font_Color_Actor6		=	5;
int						DialogueSystem::ActorBase::Settings_Font_Color_Actor7		=	7;
int						DialogueSystem::ActorBase::Settings_Font_Color_Actor8		=	1;

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

// Actor -> GetActorType().
// Gets the current type of this Actor object.
DialogueSystem::ActorTypes DialogueSystem::Actor::GetActorType()
{
	return ActorType_Actor;
}
