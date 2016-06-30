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
#include "ATTDirectoryLister.h"
#include "iostream"
#include <wx/filename.h>
#include <wx/dcmemory.h>
#include <wx/event.h>
#include <wx/menuitem.h>
#include <wx/dialog.h>
#include "ocpn_plugin.h"

const wxString ATTPortFactory::pathStandardPort = _T("StP");
const wxString ATTPortFactory::pathSecondaryPort = _T("ScP");


ATTPortFactory::ATTPortFactory()
{
    s =wxFileName::GetPathSeparator();
    
    path_to = (*GetpSharedDataLocation() + _T("plugins")
        + s + _T("att_pi") + s + _T("data") + s);
    Load();
}


ATTPortFactory::~ATTPortFactory()
{
   Save();
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

    
void
ATTPortFactory::Save()
{
   
    // Standar ports 
    for ( StPs::const_iterator n_iter = StPorts.begin(); n_iter != StPorts.end(); ++n_iter)
    {
        const wxString & port_name = n_iter->first;
        const StPsList & st_list = n_iter->second;
        for ( StPsList::const_iterator p_iter = st_list.begin(); p_iter != st_list.end(); ++p_iter)
        {
            wxDateTime _date (  p_iter->first );
            _date.ResetTime();
            int year = _date.GetYear();
            wxDateTime::Month month = _date.GetMonth();
            const ATTStandardPort & stp = p_iter->second;
            
            if ( stp.to_save)
            {            
                wxString path;
                path << pathStandardPort << s << year << s << month << s;
                wxFileName::Mkdir( path_to + path, wxS_DIR_DEFAULT, wxPATH_MKDIR_FULL );
                writeStandardPort(path_to + path, _date, stp );
            }
            
        }
    }
    
    for ( ScPs::const_iterator n_iter = ScPorts.begin(); n_iter != ScPorts.end(); ++n_iter)
    {
        const wxString & port_name = n_iter->first;
        const ScPsList & sc_list = n_iter->second;
        for ( ScPsList::const_iterator p_iter = sc_list.begin(); p_iter != sc_list.end(); ++p_iter)
        {
            wxDateTime _date (  p_iter->first );
            _date.ResetTime();
            int year = _date.GetYear();
            const ATTSecondaryPort & scp = p_iter->second;
            if ( scp.to_save)
            {   
                wxString path;
                path  << pathSecondaryPort << s  << year << s ;
                wxFileName::Mkdir( path_to + path, wxS_DIR_DEFAULT, wxPATH_MKDIR_FULL  );
                writeSecondaryPort(path_to + path, _date, scp );
            }
        }
    } 
    
    
    
    
    std::cout << "Saving ports" << std::endl;
}

void 
ATTPortFactory::writeStandardPort( const wxString& path, const  wxDateTime & date,const  ATTStandardPort& port) const
{
    wxFile file;
    if ( wxFile::Exists( path + port.m_StPName))
    {
        file.Open( path + port.m_StPName, wxFile::read_write);
        if (wxInvalidOffset == file.Seek(0) )
        {
            std::cerr << "Cannot open file to modify " << port.m_StPName << std::endl;
            return ;
        }
    }
    else
        file.Create( path + port.m_StPName, false);
    
    
    wxDateTime _date = date;
    _date = _date.SetDay(1);
    time_t timestamp = _date.GetTicks();
    file.Write((char*) &timestamp, timeStampOffset );
    
    unsigned int day = date.GetDay();
    if (wxInvalidOffset == file.Seek ((day-1)*port.getSize() + timeStampOffset ))
    {
        std::cerr << "Cannot seek while writing " << port.m_StPName << std::endl;
        return ;
    }
    char buffer[ port.getSize()];
    
    
    
    port.toStream( buffer );
    
    size_t written = 0;
    while ( written != port.getSize())
    {
        written += file.Write( buffer + written, port.getSize() - written );
    }
    
    file.Close();  
}

void 
ATTPortFactory::writeSecondaryPort(  const wxString& path, const wxDateTime & date,const  ATTSecondaryPort& port) const
{
    
    wxFile file;
    file.Create( path + port.m_ScPName, true);
    
    wxDateTime _date = date;
    _date = _date.SetDay(1);
    time_t timestamp = _date.GetTicks();
    file.Write( (char*)&timestamp, timeStampOffset );
    
    
    char buffer[ port.getSize()];
    
    port.toStream( buffer );
    
    size_t written = 0;
    while ( written != port.getSize())
    {
        written += file.Write( buffer + written, port.getSize() - written );
    }
    file.Close();  
}
    
   
void
ATTPortFactory::Load()
{
    std::cout << "Load standard ports" << std::endl;
    wxDir stp_dir ( path_to + pathStandardPort + s);
    // get the names of all files in the array
    wxArrayString stp_files;
    ATTDirectoryLister stp_traverser(stp_files);
    stp_dir.Traverse(stp_traverser);
    
    std::cout << "Load secondary ports" << std::endl;
    wxDir scp_dir ( path_to + pathSecondaryPort + s);
    // get the names of all files in the array
    wxArrayString scp_files;
    ATTDirectoryLister scp_traverser(scp_files);
    scp_dir.Traverse(scp_traverser); 
    
}

void 
ATTPortFactory::readStandardPort( const wxString& path, const  wxDateTime & date,  ATTStandardPort& port) 
{

}

void 
ATTPortFactory::readSecondaryPort(  const wxString& path, const wxDateTime & date,  ATTSecondaryPort& port) 
{
    

}
    
    
   
  