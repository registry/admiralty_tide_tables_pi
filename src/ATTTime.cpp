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
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>


ATTTime::ATTTime(const std::string & _s)
{
}


ATTTime::ATTTime(const double t)
{
    double _t = t;
    days = 0;
    while (_t<0.)
    {
        _t += 24.;
        days -=1;
    }
    
    while (_t>24.)
    {
        _t -= 24.;
        days +=1;
    }
    
    att_time_h = (double)((int)_t);
    att_time_m =  (double)((int)((_t - att_time_h)*60.));
    
    std::cout << " Convert " << t << "to " << att_time_h << "h" << att_time_m << "m " << days << " days" << std::endl;
    
}

ATTTime::~ATTTime()
{
}

