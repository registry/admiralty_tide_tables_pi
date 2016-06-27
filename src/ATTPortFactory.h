/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  A.T.T. Calculation Plugin
 * Author:   Pavel Saviankou
 *
 ***************************************************************************
 *   Copyright (C) 2016 by Pavel Saviankou                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 ***************************************************************************
 */

#ifndef __ATT_PORT_FACTORY_H__
#define __ATT_PORT_FACTORY_H__


///////////////////////////////////////////////////////////////////////////
#include <wx/datetime.h>
#include <wx/hashmap.h>


#include "ATTStandardPort.h"
#include "ATTSecondaryPort.h"
///////////////////////////////////////////////////////////////////////////////
/// Class ATTPortFactory 
///////////////////////////////////////////////////////////////////////////////

class ATTStandardPort;
class ATTSecondaryPort;

class ATTPortFactory // provides and stores standart/secondary port to given date/year if presend... 
{
    
     
WX_DECLARE_HASH_MAP( int,
                     ATTSecondaryPort,
                     wxIntegerHash,
                     wxIntegerEqual,
                     ScPsList );
WX_DECLARE_HASH_MAP( int, 
                     ATTStandardPort,
                     wxIntegerHash,
                     wxIntegerEqual,
                     StPsList );   
    
    
WX_DECLARE_STRING_HASH_MAP( 
                     ScPsList,
                     ScPs );
WX_DECLARE_STRING_HASH_MAP( 
                     StPsList,
                     StPs );
public:

    ScPs ScPorts;
    StPs StPorts;
    
    ATTPortFactory( );
    ~ATTPortFactory();
    
    ATTSecondaryPort & getSecondaryPort( wxString&, wxDateTime & );
    ATTStandardPort & getStandardPort( wxString&, wxDateTime & );
    
    
};



#endif //__ATTSERVICES_H__

