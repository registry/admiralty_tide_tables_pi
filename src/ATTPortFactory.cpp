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

#include "ATTPortFactory.h"
#include "iostream"


ATTPortFactory::ATTPortFactory()
{

}


ATTPortFactory::~ATTPortFactory()
{
   
}


bool 
ATTPortFactory::hasSecondaryPort(const wxString& portname, const wxDateTime & date) 
{
    wxDateTime y_date = date;
    y_date.ResetTime();
    y_date.SetDay(1);
    y_date.SetMonth(wxDateTime::Jan);
    
    
   if ( ScPorts.find( portname ) == ScPorts.end())
       return false;
   else
   {
        ScPsList& _list = ScPorts[ portname];
        if ( _list.find(  y_date.GetTicks()  ) == _list.end())
        return false;
   }
    return true;
}

bool 
ATTPortFactory::hasStandardPort(const wxString& portname, const wxDateTime & date) 
{
   if ( StPorts.find( portname ) == StPorts.end())
       return false;
   else
   {
        StPsList& _list = StPorts[ portname];
        if ( _list.find(  date.GetTicks()  ) == _list.end())
        return false;
   }
    return true;
}



ATTSecondaryPort & 
ATTPortFactory::getSecondaryPort(const wxString& portname, const wxDateTime & date)
{
    wxDateTime y_date = date;
    y_date.ResetTime();
    y_date.SetDay(1);
    y_date.SetMonth(wxDateTime::Jan);
    
    ScPsList& _list = ScPorts[ portname];
    return _list[ y_date.GetTicks()  ];
}

ATTStandardPort & 
ATTPortFactory::getStandardPort(const wxString& portname, const wxDateTime & date)
{
    StPsList& _list = StPorts[ portname ];
    return _list[ date.GetTicks()   ];
}

void 
ATTPortFactory::saveStandardPort(const wxDateTime & date, const ATTStandardPort& port)
{
    if ( port.m_StPName.size() == 0)
        return;
    long ticks = date.GetTicks();
    StPorts[ port.m_StPName][ ticks ] = port;
}

void 
ATTPortFactory::saveSecondaryPort(const wxDateTime & date, const ATTSecondaryPort& port)
{
    wxDateTime y_date = date;
    y_date.ResetTime();
    y_date.SetDay(1);
    y_date.SetMonth(wxDateTime::Jan);
    
    if ( port.m_ScPName.size() == 0)
        return;
    long ticks = y_date.GetTicks();
    ScPorts[ port.m_ScPName][ ticks ] = port;
    
}

    
wxArrayString
ATTPortFactory::getStandardPorts(const  wxDateTime & date) const
{
    
    wxArrayString stp;
    for ( StPs::const_iterator n_iter = StPorts.begin(); n_iter != StPorts.end(); ++n_iter)
    {
        const wxString & port_name = n_iter->first;
        const StPsList & st_list = n_iter->second;
        for ( StPsList::const_iterator p_iter = st_list.begin(); p_iter != st_list.end(); ++p_iter)
        {
            if ( p_iter->first == date.GetTicks())
            {
                const ATTStandardPort & _p = p_iter->second;
                stp.Add( _p.m_StPName );
            }
        }
    
    }
    return stp;
}

wxArrayString
ATTPortFactory::getSecondaryPorts(const  wxDateTime & date) const
{
    wxDateTime y_date = date;
    y_date.ResetTime();
    y_date.SetDay(1);
    y_date.SetMonth(wxDateTime::Jan);
    
    wxArrayString scp;
    for ( ScPs::const_iterator n_iter = ScPorts.begin(); n_iter != ScPorts.end(); ++n_iter)
    {
        const wxString & port_name = n_iter->first;
        const ScPsList & sc_list = n_iter->second;
        for ( ScPsList::const_iterator p_iter = sc_list.begin(); p_iter != sc_list.end(); ++p_iter)
        {
            if ( p_iter->first == y_date.GetTicks())
            {
                 const ATTSecondaryPort & _p = p_iter->second;
                scp.Add( _p.m_ScPName );
            }
        }
    }   
    return scp;
}

    
  
  
  