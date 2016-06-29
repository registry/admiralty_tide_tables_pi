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

#include "ATTSecondaryPort.h"
#include <wx/regex.h>
#include <wx/string.h>
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>


ATTSecondaryPort::ATTSecondaryPort()
{
    to_save = true;
}


ATTSecondaryPort::~ATTSecondaryPort()
{
}

char * 
ATTSecondaryPort::toStream( char * pos ) const// writes internal values into stream starting from  pos, returns last position
{
    double * tmp = (double*)pos;
    
    tmp[ 0 ] = m_ScPHWT1;
    tmp[ 1 ] = m_ScPHWT2;
    tmp[ 2 ] = m_ScPHWT3;
    tmp[ 3 ] = m_ScPHWT4;
        
    tmp[ 4 ] = m_ScPLWT1;
    tmp[ 5 ] = m_ScPLWT2;
    tmp[ 6 ] = m_ScPLWT3;
    tmp[ 7 ] = m_ScPLWT4;
        
    tmp[ 8 ] = m_StPMHWS;
    tmp[ 9 ] = m_StPMHWN;
    tmp[ 10 ] = m_StPMLWS;
    tmp[ 11 ] = m_StPMLWN;
    tmp[ 12 ] = m_StPSC;

    tmp[ 13 ] = m_ScPDHWT1;
    tmp[ 14 ] = m_ScPDHWT2;
    tmp[ 15 ] = m_ScPDLWT1;
    tmp[ 16 ] = m_ScPDLWT2;
        
    tmp[ 17 ] = m_ScPMHWS;
    tmp[ 18 ] = m_ScPMHWN;
    tmp[ 19 ] = m_ScPMLWS;
    tmp[ 20 ] = m_ScPMLWN;
    tmp[ 21 ] = m_ScPSC;
    
    return pos + getSize();
}

char * 
ATTSecondaryPort::fromStream( char * pos) // initialized self from stream position pos and returns new position
{
    double * tmp = (double*)pos;
    
    m_ScPHWT1 = tmp[ 0 ];
    m_ScPHWT2 = tmp[ 1 ];
    m_ScPHWT3 = tmp[ 2 ];
    m_ScPHWT4 = tmp[ 3 ];
    
    m_ScPLWT1 = tmp[ 4 ];
    m_ScPLWT2 = tmp[ 5 ];
    m_ScPLWT3 = tmp[ 6 ];
    m_ScPLWT4 = tmp[ 7 ];
    
    m_StPMHWS = tmp[ 8 ];
    m_StPMHWN = tmp[ 9 ];
    m_StPMLWS = tmp[ 10 ];
    m_StPMLWN = tmp[ 11 ];
    m_StPSC = tmp[ 12 ];

    m_ScPDHWT1 = tmp[ 13 ];
    m_ScPDHWT2 = tmp[ 14 ];
    m_ScPDLWT1 = tmp[ 15 ];
    m_ScPDLWT2 = tmp[ 16 ];
    
    m_ScPMHWS = tmp[ 17 ];
    m_ScPMHWN = tmp[ 18 ];
    m_ScPMLWS = tmp[ 19 ];
    m_ScPMLWN = tmp[ 20 ];
    m_ScPSC = tmp[ 21 ];

    return pos + getSize();
}
    
  