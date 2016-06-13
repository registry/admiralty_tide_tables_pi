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

#include "ATTServices.h"
///////////////////////////////////////////////////////////////////////////
#include <iostream>



ATTServices::ATTServices()
{
}
ATTServices::~ATTServices()
{
}


double 
ATTServices::convertATTTimeAsString2Double( const wxString & _s)
{
    ATTTime _t(_s);
    return _t.normalized_atttime();
}


wxString 
ATTServices::convertATTTimeAsDouble2String(const  double _t)
{
    ATTTime _s(_t);
    return _s.atttime();
}


// double 
// ATTServices::convertTimeAsString2Double( const wxString & _s)
// {
//     return 0.;
// }
// 
// 
// wxString 
// ATTServices::convertTimeAsDouble2String( const double _t)
// {
//     return "23h45m";
// }

     
    