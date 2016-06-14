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

#ifndef __ATTTIME_H__
#define __ATTTIME_H__


///////////////////////////////////////////////////////////////////////////
#include <wx/string.h>
///////////////////////////////////////////////////////////////////////////////
/// Class ATTServices 
///////////////////////////////////////////////////////////////////////////////



class ATTTime // in form of hhmm ; 0123 -> 1.3834
{
    int sign;
    double att_time_h;
    double att_time_m;
public:

    
    
    ATTTime( const wxString &);
    ATTTime( const double);
    ~ATTTime();
    
    double normalized_atttime();
    wxString atttime();
    
};



#endif //__ATTSERVICES_H__

