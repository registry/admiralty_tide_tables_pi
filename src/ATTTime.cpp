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

#include "ATTTime.h"
#include <wx/regex.h>
#include <wx/string.h>
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>


ATTTime::ATTTime(const wxString & __s)
{
    wxRegEx atttime("([+-])?([[:digit:]]{2})([[:digit:]]{2})");
    if (atttime.Matches(__s) )
    {
        wxString _s = atttime.GetMatch(__s, 1);
        wxString _h = atttime.GetMatch(__s, 2);
        wxString _m = atttime.GetMatch(__s, 3);
        long _sign ;
        if ((_s+wxString("1")).ToLong(&_sign))
        {
            sign = (int)_sign;
        }
        long _hh ;
        if (_h.ToLong(&_hh))
        {
            att_time_h = (double)_hh;
        }
        long _mm;
        if (_m.ToLong(&_mm))
        {
            att_time_m = (double)_mm;
        }    
    }
}


ATTTime::ATTTime(const double t)
{
    sign = (t<0)?-1:((t==0)?0.:1);
    double _t = fabs(t);
    
    att_time_h = (double)((int)_t);
    att_time_m =  (double)((int)((_t - att_time_h)*60.));
}

ATTTime::~ATTTime()
{
}

  
double 
ATTTime::normalized_atttime()
{
    return sign*(att_time_h  + att_time_m/60.);
}


wxString 
ATTTime::atttime()
{
    wxString _t;
    _t << ((sign!=-1)?"":"-") << ((att_time_h<10)?"0":"") << att_time_h << ((att_time_m<10)?"0":"") << (int)(att_time_m);
    return _t;
}