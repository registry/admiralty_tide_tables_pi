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

#include "ATTStandardPort.h"
#include <wx/regex.h>
#include <wx/string.h>
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>


ATTStandardPort::ATTStandardPort()
{
    to_save = true;
}


ATTStandardPort::~ATTStandardPort()
{
}

  
char * 
ATTStandardPort::toStream( char * pos ) const // writes internal values into stream starting from  pos, returns last position
{
   
    double * tmp = (double*)pos;
    
    tmp[ 0 ] = m_StPLW1T;
    tmp[ 1 ] = m_StPLW1H;
    tmp[ 2 ] = m_StPHW1T;
    tmp[ 3 ] = m_StPHW1H;
        
    tmp[ 4 ] = m_StPLW2T;
    tmp[ 5 ] = m_StPLW2H;
    tmp[ 6 ] = m_StPHW2T;
    tmp[ 7 ] = m_StPHW2H;
  
    return pos + getSize();
}

char * 
ATTStandardPort::fromStream( char * pos) // initialized self from stream position pos and returns new position
{
    double * tmp = (double*)pos;
    
    m_StPLW1T = tmp[ 0 ];
    m_StPLW1H = tmp[ 1 ];
    m_StPHW1T = tmp[ 2 ];
    m_StPHW1H = tmp[ 3 ];
    
    m_StPLW2T = tmp[ 4 ];
    m_StPLW2H = tmp[ 5 ];
    m_StPHW2T = tmp[ 6 ];
    m_StPHW2H = tmp[ 7 ];
    
    return pos + getSize();
}
    
  