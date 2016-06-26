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
    double HUG =  (double)(wxRound((calculate_hw (  m_StP.m_StPHW1H ))*10))/10.;  
    m_ScPHW1H = m_StP.m_StPHW1H -m_ScP.m_StPSC + HUG + m_ScP.m_ScPSC;
    HUG = (double)(wxRound((calculate_lw (  m_StP.m_StPLW1H ))*10))/10.;  
    m_ScPLW1H = m_StP.m_StPLW1H -m_ScP.m_StPSC + HUG + m_ScP.m_ScPSC;
    HUG = (double)(wxRound((calculate_hw ( m_StP.m_StPHW2H ))*10))/10.;
    m_ScPHW2H =  m_StP.m_StPHW2H -m_ScP.m_StPSC + HUG + m_ScP.m_ScPSC; 
    HUG = (double)(wxRound((calculate_lw (  m_StP.m_StPLW2H ))*10))/10.;  
    m_ScPLW2H = m_StP.m_StPLW2H -m_ScP.m_StPSC + HUG + m_ScP.m_ScPSC;  

    double ZUG = calculate_hwdt( m_StP.m_StPHW1T);
    m_ScPHW1T = m_StP.m_StPHW1T + ZUG;

    ZUG = calculate_hwdt( m_StP.m_StPHW2T);
    m_ScPHW2T = m_StP.m_StPHW2T + ZUG;

    ZUG = calculate_lwdt(m_StP.m_StPLW1T);
    m_ScPLW1T = m_StP.m_StPLW1T + ZUG;

    ZUG = calculate_lwdt(m_StP.m_StPLW2T);
    m_ScPLW2T = m_StP.m_StPLW2T + ZUG;

}




double  
ATTCalculation::calculate_hw( double hwh )
{

    if ( m_ScP.m_StPMHWN != m_ScP.m_StPMHWS)
    {
        return m_ScP.m_ScPMHWN + (m_ScP.m_ScPMHWS - m_ScP.m_ScPMHWN) * ( hwh - m_ScP.m_StPMHWN )/(m_ScP.m_StPMHWS - m_ScP.m_StPMHWN );
    }
    else
    {
        return m_ScP.m_ScPMHWN +( hwh - m_ScP.m_StPMHWN );
    }
}


double  
ATTCalculation::calculate_lw( double lwh )
{

    if ( m_ScP.m_StPMLWN != m_ScP.m_StPMLWS)
    {
        return m_ScP.m_ScPMLWN + (m_ScP.m_ScPMLWS - m_ScP.m_ScPMLWN) * ( lwh - m_ScP.m_StPMLWN )/(m_ScP.m_StPMLWS - m_ScP.m_StPMLWN );
    }
    else
    {
        return m_ScP.m_ScPMLWN +( lwh - m_ScP.m_StPMLWN );
    }
}



double  
ATTCalculation::calculate_hwdt( double hwt )
{
    double t1, dt1, t2, dt2;
    get_pair_hw(hwt, t1, dt1, t2, dt2);
    
    if (t2 != t1) 
        return ( dt1 + (dt2-dt1)*(hwt - t1)/( t2 - t1));
    else
    {
        error_message = "t2 == t1 !!!";
        return 0.;
    }
    
}

double  
ATTCalculation::calculate_lwdt( double lwt )
{
    double t1, dt1, t2, dt2;
    get_pair_lw(lwt, t1, dt1, t2, dt2);
    
    if (t2 != t1) 
        return ( dt1 + (dt2-dt1)*(lwt - t1)/( t2 - t1));
    else
    {
        error_message = "t2 == t1 !!!";
        return 0.;
    }
    
}





void  
ATTCalculation::get_pair_lw(const double t,  double& t1, double&dt1, double &t2, double&dt2 )
{
    switch (get_pair(t, m_ScP.m_ScPLWT1,  m_ScP.m_ScPLWT2, m_ScP.m_ScPLWT3,  m_ScP.m_ScPLWT4 ))
        {
            case 0:
                t1 = m_ScP.m_ScPLWT4-24;
                dt1 = m_ScP.m_ScPDLWT2;
                t2 = m_ScP.m_ScPLWT1;
                dt2 = m_ScP.m_ScPDLWT1;
                break;
            case 1:
                t1 = m_ScP.m_ScPLWT1;
                dt1 = m_ScP.m_ScPDLWT1;
                t2 = m_ScP.m_ScPLWT2;
                dt2 = m_ScP.m_ScPDLWT2;
                break;    
            case 2:
                t1 = m_ScP.m_ScPLWT2;
                dt1 = m_ScP.m_ScPDLWT2;
                t2 = m_ScP.m_ScPLWT3;
                dt2 = m_ScP.m_ScPDLWT1;
                break;     
            case 3:
                t1 = m_ScP.m_ScPLWT3;
                dt1 = m_ScP.m_ScPDLWT1;
                t2 = m_ScP.m_ScPLWT4;
                dt2 = m_ScP.m_ScPDLWT2;
                break;      
            case 4:
                t1 = m_ScP.m_ScPLWT4;
                dt1 = m_ScP.m_ScPDLWT2;
                t2 = m_ScP.m_ScPLWT1+24;
                dt2 = m_ScP.m_ScPDLWT1;
                break;   
            default:
                error_message = " something is really wrong in LW dt calculation ";
                break;
        }
    
}

void  
ATTCalculation::get_pair_hw(const double t,  double& t1, double&dt1, double &t2, double&dt2 )
{
    switch (get_pair(t, m_ScP.m_ScPHWT1,  m_ScP.m_ScPHWT2, m_ScP.m_ScPHWT3,  m_ScP.m_ScPHWT4 ))
    {
        case 0:
            t1 = m_ScP.m_ScPHWT4-24;
            dt1 = m_ScP.m_ScPDHWT2;
            t2 = m_ScP.m_ScPHWT1;
            dt2 = m_ScP.m_ScPDHWT1;
            break;
        case 1:
            t1 = m_ScP.m_ScPHWT1;
            dt1 = m_ScP.m_ScPDHWT1;
            t2 = m_ScP.m_ScPHWT2;
            dt2 = m_ScP.m_ScPDHWT2;
            break;    
        case 2:
            t1 = m_ScP.m_ScPHWT2;
            dt1 = m_ScP.m_ScPDHWT2;
            t2 = m_ScP.m_ScPHWT3;
            dt2 = m_ScP.m_ScPDHWT1;
            break;     
        case 3:
            t1 = m_ScP.m_ScPHWT3;
            dt1 = m_ScP.m_ScPDHWT1;
            t2 = m_ScP.m_ScPHWT4;
            dt2 = m_ScP.m_ScPDHWT2;
            break;      
        case 4:
            t1 = m_ScP.m_ScPHWT4;
            dt1 = m_ScP.m_ScPDHWT2;
            t2 = m_ScP.m_ScPHWT1+24;
            dt2 = m_ScP.m_ScPDHWT1;
            break;   
        default:
            error_message = " something is really wrong in HW dt calculation. ";
            break;
    }
}


int  
ATTCalculation::get_pair ( const double t, const double& t1, const double& t2, const double& t3, const double& t4)
{
    if (t < t1 )
    {
        return 0;
    }
    if (t < t2 )
    {
        return 1 ;
    }
    if (t < t3 )
    {
        return 2 ;
    }    
    if (t < t4 )
    {
        return 3;
    }
    return 4 ;
}



wxString& ATTCalculation::error()
{
    return error_message;
}
    
    
std::ostream& operator<<(std::ostream& out, const ATTCalculation& obj)
{
    out <<  "error_message " << obj.error_message  << std::endl;

    
    out <<  "m_StPName " << obj.m_StP.m_StPName << std::endl;
    out <<  "m_StPLW1T " << obj.m_StP.m_StPLW1T << std::endl;
    out <<  "m_StPLW1H " << obj.m_StP.m_StPLW1H << std::endl;
    out <<  "m_StPHW1T " << obj.m_StP.m_StPHW1T << std::endl;
    out <<  "m_StPHW1H " << obj.m_StP.m_StPHW1H << std::endl;
    out <<  "m_StPLW2T " << obj.m_StP.m_StPLW2T << std::endl;
    out <<  "m_StPLW2H " << obj.m_StP.m_StPLW2H << std::endl;
    out <<  "m_StPHW2T " << obj.m_StP.m_StPHW2T << std::endl;
    out <<  "m_StPHW2H " << obj.m_StP.m_StPHW2H << std::endl;
    
    out <<  "m_ScPName " << obj.m_ScP.m_ScPName << std::endl;
    out <<  "m_ScPLW1T " << obj.m_ScPLW1T << std::endl;
    out <<  "m_ScPLW1H " << obj.m_ScPLW1H << std::endl;
    out <<  "m_ScPHW1T " << obj.m_ScPHW1T << std::endl;
    out <<  "m_ScPHW1H " << obj.m_ScPHW1H << std::endl;
    out <<  "m_ScPLW2T " << obj.m_ScPLW2T << std::endl;
    out <<  "m_ScPLW2H " << obj.m_ScPLW2H << std::endl;
    out <<  "m_ScPHW2T " << obj.m_ScPHW2T << std::endl;
    out <<  "m_ScPHW2H " << obj.m_ScPHW2H << std::endl;

    out <<  "m_ScPHWT1 " << obj.m_ScP.m_ScPHWT1 << std::endl;
    out <<  "m_ScPHWT2 " << obj.m_ScP.m_ScPHWT2 << std::endl;
    out <<  "m_ScPHWT3 " << obj.m_ScP.m_ScPHWT3 << std::endl;
    out <<  "m_ScPHWT4 " << obj.m_ScP.m_ScPHWT4 << std::endl;
    
    out <<  "m_ScPLWT1 " << obj.m_ScP.m_ScPLWT1 << std::endl;
    out <<  "m_ScPLWT2 " << obj.m_ScP.m_ScPLWT2 << std::endl;
    out <<  "m_ScPLWT3 " << obj.m_ScP.m_ScPLWT3 << std::endl;
    out <<  "m_ScPLWT4 " << obj.m_ScP.m_ScPLWT4 << std::endl;
    
    out <<  "m_StPMHWS " << obj.m_ScP.m_StPMHWS << std::endl;
    out <<  "m_StPMHWN " << obj.m_ScP.m_StPMHWN << std::endl;
    out <<  "m_StPMLWS " << obj.m_ScP.m_StPMLWS << std::endl;
    out <<  "m_StPMLWN " << obj.m_ScP.m_StPMLWN << std::endl;
    out <<  "m_StPSC " << obj.m_ScP.m_StPSC << std::endl;

    out <<  "m_ScPDHWT1 " << obj.m_ScP.m_ScPDHWT1 << std::endl;
    out <<  "m_ScPDHWT2 " << obj.m_ScP.m_ScPDHWT2 << std::endl;
    out <<  "m_ScPDLWT1 " << obj.m_ScP.m_ScPDLWT1 << std::endl;
    out <<  "m_ScPDLWT2 " << obj.m_ScP.m_ScPDLWT2 << std::endl;
    
    out <<  "m_ScPMHWS " << obj.m_ScP.m_ScPMHWS << std::endl;
    out <<  "m_ScPMHWN " << obj.m_ScP.m_ScPMHWN << std::endl;
    out <<  "m_ScPMLWS " << obj.m_ScP.m_ScPMLWS << std::endl;
    out <<  "m_ScPMLWN " << obj.m_ScP.m_ScPMLWN << std::endl;
    out <<  "m_ScPSC " << obj.m_ScP.m_ScPSC << std::endl;
    
    return out; 
}
     
    