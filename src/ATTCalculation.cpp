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

#include "ATTCalculation.h"
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <wx/math.h>



ATTCalculation::ATTCalculation()
{
    error_message = "";
}
ATTCalculation::~ATTCalculation()
{
}


void 
ATTCalculation::calculate()
{
  double HUG =  (double)(wxRound((calculate_hw (  m_StPHW1H ))*10))/10.;  
  m_ScPHW1H = m_StPHW1H -m_StPSC + HUG + m_ScPSC;
  HUG = (double)(wxRound((calculate_lw (  m_StPLW1H ))*10))/10.;  
  m_ScPLW1H = m_StPLW1H -m_StPSC + HUG + m_ScPSC;
  HUG = (double)(wxRound((calculate_hw (  m_StPHW2H ))*10))/10.;
  m_ScPHW2H =   m_StPHW2H -m_StPSC + HUG + m_ScPSC; 
  HUG = (double)(wxRound((calculate_lw (  m_StPLW2H ))*10))/10.;  
  m_ScPLW2H = m_StPLW2H -m_StPSC + HUG + m_ScPSC;  
}




double  
ATTCalculation::calculate_hw( double hwh )
{

    if ( m_StPMHWN != m_StPMHWS)
    {
        return m_ScPMHWN + (m_ScPMHWS - m_ScPMHWN) * ( hwh - m_StPMHWN )/(m_StPMHWS - m_StPMHWN );
    }
    else
    {
        return m_ScPMHWN +( hwh - m_StPMHWN );
    }
}


double  
ATTCalculation::calculate_lw( double lwh )
{

    if ( m_StPMLWN != m_StPMLWS)
    {
        return m_ScPMLWN + (m_ScPMLWS - m_ScPMLWN) * ( lwh - m_StPMLWN )/(m_StPMLWS - m_StPMLWN );
    }
    else
    {
        return m_ScPMLWN +( lwh - m_StPMLWN );
    }
}








wxString& ATTCalculation::error()
{
    return error_message;
}
    
    
std::ostream& operator<<(std::ostream& out, const ATTCalculation& obj)
{
    out <<  "error_message " << obj.error_message  << std::endl;
    
    out <<  "m_TideType " << obj.m_TideType << std::endl;
    
    out <<  "m_StPName " << obj.m_StPName << std::endl;
    out <<  "m_StPLW1T " << obj.m_StPLW1T << std::endl;
    out <<  "m_StPLW1H " << obj.m_StPLW1H << std::endl;
    out <<  "m_StPHW1T " << obj.m_StPHW1T << std::endl;
    out <<  "m_StPHW1H " << obj.m_StPHW1H << std::endl;
    out <<  "m_StPLW2T " << obj.m_StPLW2T << std::endl;
    out <<  "m_StPLW2H " << obj.m_StPLW2H << std::endl;
    out <<  "m_StPHW2T " << obj.m_StPHW2T << std::endl;
    out <<  "m_StPHW2H " << obj.m_StPHW2H << std::endl;
    
    out <<  "m_ScPName " << obj.m_ScPName << std::endl;
    out <<  "m_ScPLW1T " << obj.m_ScPLW1T << std::endl;
    out <<  "m_ScPLW1H " << obj.m_ScPLW1H << std::endl;
    out <<  "m_ScPHW1T " << obj.m_ScPHW1T << std::endl;
    out <<  "m_ScPHW1H " << obj.m_ScPHW1H << std::endl;
    out <<  "m_ScPLW2T " << obj.m_ScPLW2T << std::endl;
    out <<  "m_ScPLW2H " << obj.m_ScPLW2H << std::endl;
    out <<  "m_ScPHW2T " << obj.m_ScPHW2T << std::endl;
    out <<  "m_ScPHW2H " << obj.m_ScPHW2H << std::endl;

    out <<  "m_ScPHWT1 " << obj.m_ScPHWT1 << std::endl;
    out <<  "m_ScPHWT2 " << obj.m_ScPHWT2 << std::endl;
    out <<  "m_ScPHWT3 " << obj.m_ScPHWT3 << std::endl;
    out <<  "m_ScPHWT4 " << obj.m_ScPHWT4 << std::endl;
    
    out <<  "m_ScPLWT1 " << obj.m_ScPLWT1 << std::endl;
    out <<  "m_ScPLWT2 " << obj.m_ScPLWT2 << std::endl;
    out <<  "m_ScPLWT3 " << obj.m_ScPLWT3 << std::endl;
    out <<  "m_ScPLWT4 " << obj.m_ScPLWT4 << std::endl;
    
    out <<  "m_StPMHWS " << obj.m_StPMHWS << std::endl;
    out <<  "m_StPMHWN " << obj.m_StPMHWN << std::endl;
    out <<  "m_StPMLWS " << obj.m_StPMLWS << std::endl;
    out <<  "m_StPMLWN " << obj.m_StPMLWN << std::endl;
    out <<  "m_StPSC " << obj.m_StPSC << std::endl;

    out <<  "m_ScPDHWT1 " << obj.m_ScPDHWT1 << std::endl;
    out <<  "m_ScPDHWT2 " << obj.m_ScPDHWT2 << std::endl;
    out <<  "m_ScPDLWT1 " << obj.m_ScPDLWT1 << std::endl;
    out <<  "m_ScPDLWT2 " << obj.m_ScPDLWT2 << std::endl;
    
    out <<  "m_ScPMHWS " << obj.m_ScPMHWS << std::endl;
    out <<  "m_ScPMHWN " << obj.m_ScPMHWN << std::endl;
    out <<  "m_ScPMLWS " << obj.m_ScPMLWS << std::endl;
    out <<  "m_ScPMLWN " << obj.m_ScPMLWN << std::endl;
    out <<  "m_ScPSC " << obj.m_ScPSC << std::endl;
    
    return out; 
}
     
    