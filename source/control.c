//-------------------------------------------------------------------------
/*
Copyright (C) 1996, 2003 - 3D Realms Entertainment

This file is part of Duke Nukem 3D version 1.5 - Atomic Edition

Duke Nukem 3D is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Original Source: 1996 - Todd Replogle
Prepared for public release: 03/21/2003 - Charlie Wiederhold, 3D Realms
*/
//-------------------------------------------------------------------------

#include "duke3d.h"
#include "control.h"
#include "mouse.h"

//***************************************************************************
//
// GLOBALS
//
//***************************************************************************

boolean  CONTROL_RudderEnabled;
boolean  CONTROL_MousePresent;
boolean  CONTROL_JoysPresent[ MaxJoys ];
boolean  CONTROL_MouseEnabled;
boolean  CONTROL_JoystickEnabled;
byte     CONTROL_JoystickPort;
uint32   CONTROL_ButtonState1;
uint32   CONTROL_ButtonHeldState1;
uint32   CONTROL_ButtonState2;
uint32   CONTROL_ButtonHeldState2;


//***************************************************************************
//
// FUNCTIONS
//
//***************************************************************************

void CONTROL_MapKey( int32 which, kb_scancode key1, kb_scancode key2 )
{
	STUBBED("CONTROL_MapKey");
}

void CONTROL_MapButton
        (
        int32 whichfunction,
        int32 whichbutton,
        boolean doubleclicked
        )
{
	STUBBED("CONTROL_MapButton");
}

void CONTROL_DefineFlag( int32 which, boolean toggle )
{
	STUBBED("CONTROL_DefineFlag");
}

boolean CONTROL_FlagActive( int32 which )
{
	STUBBED("CONTROL_FlagActive");
	return false;
}

void CONTROL_ClearAssignments( void )
{
	STUBBED("CONTROL_ClearAssignments");
}

void CONTROL_GetUserInput( UserInput *info )
{
	STUBBED("CONTROL_GetUserInput");
}

void CONTROL_GetInput( ControlInfo *info )
{
	STUBBED("CONTROL_GetInput");
    memset(info, '\0', sizeof (ControlInfo));
}

void CONTROL_ClearButton( int32 whichbutton )
{
	STUBBED("CONTROL_ClearButton");
}

void CONTROL_ClearUserInput( UserInput *info )
{
	STUBBED("CONTROL_ClearUserInput");
}

void CONTROL_WaitRelease( void )
{
	STUBBED("CONTROL_WaitRelease");
}

void CONTROL_Ack( void )
{
	STUBBED("CONTROL_Ack");
}

void CONTROL_CenterJoystick
   (
   void ( *CenterCenter )( void ),
   void ( *UpperLeft )( void ),
   void ( *LowerRight )( void ),
   void ( *CenterThrottle )( void ),
   void ( *CenterRudder )( void )
   )
{
	STUBBED("CONTROL_CenterJoystick");
}

static int32 mouseSensitivity = 0;
int32 CONTROL_GetMouseSensitivity( void )
{
    return mouseSensitivity;
}

void CONTROL_SetMouseSensitivity( int32 newsensitivity )
{
	mouseSensitivity = newsensitivity;
}

void CONTROL_Startup
   (
   controltype which,
   int32 ( *TimeFunction )( void ),
   int32 ticspersecond
   )
{
	STUBBED("CONTROL_Startup");
}

void CONTROL_Shutdown( void )
{
	STUBBED("CONTROL_Shutdown");
}


void CONTROL_MapAnalogAxis
   (
   int32 whichaxis,
   int32 whichanalog
   )
{
	STUBBED("CONTROL_MapAnalogAxis");
}


void CONTROL_MapDigitalAxis
   (
   int32 whichaxis,
   int32 whichfunction,
   int32 direction
   )
{
	STUBBED("CONTROL_MapDigitalAxis");
}

void CONTROL_SetAnalogAxisScale
   (
   int32 whichaxis,
   int32 axisscale
   )
{
	STUBBED("CONTROL_SetAnalogAxisScale");
}

void CONTROL_PrintAxes( void )
{
	STUBBED("CONTROL_PrintAxes");
}

boolean MOUSE_Init( void )
{
	//STUBBED("MOUSE_Init");  // buildengine handles this.
	return true;
}

void    MOUSE_Shutdown( void )
{
	STUBBED("MOUSE_Shutdown");
}

void    MOUSE_ShowCursor( void )
{
	STUBBED("MOUSE_ShowCursor");
}

void    MOUSE_HideCursor( void )
{
	STUBBED("MOUSE_HideCursor");
}

static int32 mousePositionX = 0;
static int32 mousePositionY = 0;
static int32 mouseRelativeX = 0;
static int32 mouseRelativeY = 0;
static short mouseButtons = 0;

static void updateMouse(void)
{
    // this is in buildengine.
    short x, y;
    getmousevalues(&x, &y, &mouseButtons);

    mouseRelativeX += x;
    mouseRelativeY += y;
    mousePositionX += x;
    mousePositionY += y;
}

int32   MOUSE_GetButtons( void )
{
    updateMouse();
    return ((int32) mouseButtons);
}

void    MOUSE_GetPosition( int32*x, int32*y  )
{
    if (x) *x = mousePositionX;
    if (y) *y = mousePositionY;
}

void    MOUSE_GetDelta( int32*x, int32*y  )
{
    updateMouse();

    if (x) *x = mouseRelativeX;
    if (y) *y = mouseRelativeY;

    mouseRelativeX = mouseRelativeY = 0;
}

