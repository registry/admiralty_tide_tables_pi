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

#ifndef __ATT_PORT_FACTORY_H__
#define __ATT_PORT_FACTORY_H__


///////////////////////////////////////////////////////////////////////////
#include <wx/datetime.h>
#include <wx/hashmap.h>
#include <wx/arrstr.h>

#include "ATTStandardPort.h"
#include "ATTSecondaryPort.h"
///////////////////////////////////////////////////////////////////////////////
/// Class ATTPortFactory 
///////////////////////////////////////////////////////////////////////////////


class ATTPortFactory // provides and stores standart/secondary port to given date/year if presend... 
{
    
     
WX_DECLARE_HASH_MAP( time_t,
                     ATTSecondaryPort,
                     wxIntegerHash,
                     wxIntegerEqual,
                     ScPsList );
WX_DECLARE_HASH_MAP( time_t, 
                     ATTStandardPort,
                     wxIntegerHash,
                     wxIntegerEqual,
                     StPsList );   
    
    
WX_DECLARE_STRING_HASH_MAP( 
                     ScPsList,
                     ScPs );
WX_DECLARE_STRING_HASH_MAP( 
                     StPsList,
                     StPs );

    void Save();
    void writeStandardPort( const wxString&, const  wxDateTime &,const  ATTStandardPort& ) const;   
    void writeSecondaryPort( const wxString&, const wxDateTime &,const  ATTSecondaryPort& ) const;
 
    void Load();
    void readStandardPort( const wxString&, const  wxDateTime &, ATTStandardPort& ) ;   
    void readSecondaryPort( const wxString&,  ATTSecondaryPort& ) ;
      
    
    
    wxDateTime 
    readPortDate( const wxString &) const;
    
    
public:

    wxString path_to;
    wxString s;
    
    static const wxString pathStandardPort;
    static const wxString pathSecondaryPort;
    static const time_t timeStampOffset = sizeof(time_t);
    
    ScPs ScPorts;
    StPs StPorts;
    
    ATTPortFactory( );
    ~ATTPortFactory();
    
    bool hasStandardPort( const wxString&, const  wxDateTime & ) ;
    bool hasSecondaryPort(const  wxString&, const  wxDateTime & ) ;
     
    ATTStandardPort & getStandardPort( const wxString&, const  wxDateTime & );
    ATTSecondaryPort & getSecondaryPort(const  wxString&, const  wxDateTime & );
    
    void saveStandardPort(const  wxDateTime &,const  ATTStandardPort& );   
    void saveSecondaryPort( const wxDateTime &,const  ATTSecondaryPort& );
    
    wxArrayString
    getStandardPorts(const  wxDateTime &) const;
    wxArrayString
    getSecondaryPorts(const  wxDateTime &) const;
    

    
    
    
    
};



#endif //__ATTSERVICES_H__

