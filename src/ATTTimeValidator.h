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

#ifndef __ATT_TIME_VALIDATOR_H__
#define __ATT_TIME_VALIDATOR_H__


///////////////////////////////////////////////////////////////////////////
#include <wx/string.h>
#include <wx/datetime.h>
#include <wx/valtext.h>
#include <iostream>
#include <ostream>
///////////////////////////////////////////////////////////////////////////////
/// Class ATTTimeValidator
///////////////////////////////////////////////////////////////////////////////



class ATTTimeValidator : public wxTextValidator
{
    
private:
    wxArrayString stringList;
    
    
    void  fillIncluding(void);

public:

    ATTTimeValidator( const ATTTimeValidator& valid) : wxTextValidator( wxFILTER_EMPTY  | wxFILTER_INCLUDE_CHAR_LIST )
    {
        fillIncluding();
    }
    
    
    ATTTimeValidator( ) : wxTextValidator( wxFILTER_EMPTY |  wxFILTER_INCLUDE_CHAR_LIST )
    {
        fillIncluding();
    }
    
    virtual
    ATTTimeValidator*
    Clone() const ;
    
    
    
    
    
};



#endif //__ATT_TIME_VALIDATOR_H__

