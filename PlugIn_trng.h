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

// Mehrbod MK - Dialogue System Include.
#include "dialogueSystem.h"

// Mehrbod MK - Object System Include.
#include "objectSystem.h"
using namespace ObjectSystem;

void	Process_ObjectSystem_Param_Check_Interactables_With_Lara();
