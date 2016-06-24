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

#ifndef __ATT_SECONDARY_PORT_H__
#define __ATT_SECONDARY_PORT_H__


///////////////////////////////////////////////////////////////////////////
#include <wx/string.h>
///////////////////////////////////////////////////////////////////////////////
/// Class ATTServices 
///////////////////////////////////////////////////////////////////////////////



class ATTSecondaryPort // in form of hhmm ; 0123 -> 1.3834
{
    wxString name;
    double att_time_hw1;
    double att_time_lw1;
    double att_time_hw2;
    double att_time_lw2;

    double hw1;
    double lw1;
    double hw2;
    double lw2;


public:

    
    
    ATTSecondaryPort( );
    ~ATTSecondaryPort();
    
    
};



#endif //__ATTSERVICES_H__

