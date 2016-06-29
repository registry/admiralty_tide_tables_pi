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
public:
    
    static const int ScPNentries = 22;
    
    bool  to_save; // signalizes, that one has to store it    
    
    wxString  m_ScPName;
    double  m_ScPHWT1;
    double  m_ScPHWT2;
    double  m_ScPHWT3;
    double  m_ScPHWT4;
    
    double  m_ScPLWT1;
    double  m_ScPLWT2;
    double  m_ScPLWT3;
    double  m_ScPLWT4;
    
    double  m_StPMHWS;
    double  m_StPMHWN;
    double  m_StPMLWS;
    double  m_StPMLWN;
    double  m_StPSC;

    double  m_ScPDHWT1;
    double  m_ScPDHWT2;
    double  m_ScPDLWT1;
    double  m_ScPDLWT2;
    
    double  m_ScPMHWS;
    double  m_ScPMHWN;
    double  m_ScPMLWS;
    double  m_ScPMLWN;
    double  m_ScPSC;
    
    
    ATTSecondaryPort( );
    ~ATTSecondaryPort();


    char * toStream( char * pos ) const; // writes internal values into stream starting from  pos, returns last position
    char * fromStream( char * pos); // initialized self from stream position pos and returns new position
    
    inline
    size_t getSize() const { return sizeof(double)*ATTSecondaryPort::ScPNentries;  };
    
};



#endif //__ATTSERVICES_H__

