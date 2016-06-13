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

#ifndef __ATTSERVICES_H__
#define __ATTSERVICES_H__


#include "ATTTime.h"
#include <wx/string.h>

///////////////////////////////////////////////////////////////////////////
#include <string>

///////////////////////////////////////////////////////////////////////////////
/// Class ATTServices 
///////////////////////////////////////////////////////////////////////////////



class ATTServices
{

public:

    static
    double convertATTTimeAsString2Double(const wxString &); // 0345 -> 3.75
    
    static
    wxString convertATTTimeAsDouble2String(const double ); // 3.75 -> 0345
    
/*    static
    double convertTimeAsString2Double( const wxString &); // 03h45m -> 3.75
    
    static
    wxString convertTimeAsDouble2String( const double ); // 3.75  -> 3h45m
    
    */ 
    
    
    
    ATTServices( );
    ~ATTServices();
    
};



#endif //__ATTSERVICES_H__

