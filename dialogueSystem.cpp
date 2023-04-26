// File: dialogueSystem.cpp
// Developer: Mehrbod Molla Kazemi.

// Main include.
#include "dialogueSystem.h"

// Dialogue -> Text -> GetDialogueType().
// Gets the type of this Dialogue object.
DialogueSystem::DialogueTypes DialogueSystem::DialogueText::GetDialogueType()
{
	return DialogueType_Text;
}
