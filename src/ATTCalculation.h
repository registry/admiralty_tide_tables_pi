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

#ifndef __ATTCALCULATION_H__
#define __ATTCALCULATION_H__


///////////////////////////////////////////////////////////////////////////
#include <string>

///////////////////////////////////////////////////////////////////////////////
/// Class ATTCalculation
///////////////////////////////////////////////////////////////////////////////

enum TideType { SPRING_TIDE=0, MID_TIDE = 1, NIPP_TIDE = 2};


class ATTCalculation
{
private:

      
protected:

    

    // all input elements:
//     wxDatePickerCtrl * m_Date;
    TideType * m_TideType;
    
    std::string  m_StPName;
    double  m_StPLW1T;
    double  m_StPLW1H;
    double  m_StPHW1T;
    double  m_StPHW1H;
    double  m_StPLW2T;
    double  m_StPLW2H;
    double  m_StPHW2T;
    double  m_StPHW2H;
    
    std::string  m_ScPName;
    double  m_ScPLW1T;
    double  m_ScPLW1H;
    double  m_ScPHW1T;
    double  m_ScPHW1H;
    double  m_ScPLW2T;
    double  m_ScPLW2H;
    double  m_ScPHW2T;
    double  m_ScPHW2H;

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
    



public:

    ATTCalculation( );
    ~ATTCalculation();
    
};



#endif //__ATTCALCULATION_H__

