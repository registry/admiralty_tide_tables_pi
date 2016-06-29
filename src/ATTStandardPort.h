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

#ifndef __ATT_STANDARD_PORT_H__
#define __ATT_STANDARD_PORT_H__


///////////////////////////////////////////////////////////////////////////
#include <wx/string.h>
///////////////////////////////////////////////////////////////////////////////
/// Class ATTServices 
///////////////////////////////////////////////////////////////////////////////



class ATTStandardPort 
{
    public:
    static const int StPNentries = 8;
    bool  to_save; // signalizes, that one has to store it    
        
    wxString  m_StPName;
    double  m_StPLW1T;
    double  m_StPLW1H;
    double  m_StPHW1T;
    double  m_StPHW1H;
    double  m_StPLW2T;
    double  m_StPLW2H;
    double  m_StPHW2T;
    double  m_StPHW2H;
    
    
    
    ATTStandardPort( );
    ~ATTStandardPort();
    
    
    char * toStream( char * pos ) const; // writes internal values into stream starting from  pos, returns last position
    char * fromStream( char * pos); // initialized self from stream position pos and returns new position

    inline
    size_t getSize() const { return sizeof(double)*ATTStandardPort::StPNentries;  };
    
};



#endif //__ATTSERVICES_H__

