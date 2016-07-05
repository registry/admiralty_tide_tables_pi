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

#ifndef __ATTDIALOG_H__
#define __ATTDIALOG_H__

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include <wx/artprov.h>
#include <wx/button.h>
#include <wx/colour.h>
#include <wx/combobox.h>
#include <wx/datectrl.h>
#include <wx/dialog.h>
#include <wx/font.h>
#include <wx/gdicmn.h>
#include <wx/intl.h>
#include <wx/radiobut.h>
#include <wx/scrolwin.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/xrc/xmlres.h>
#include <wx/valnum.h>
///////////////////////////////////////////////////////////////////////////


class ATTCalculation;
class ATTPortFactory;
class ATTTimeValidator;

///////////////////////////////////////////////////////////////////////////////
/// Class ATTDialog
///////////////////////////////////////////////////////////////////////////////
class ATTDialog : public wxDialog
{
private:

      
protected:
    ATTCalculation * att_calculation;
    
    ATTPortFactory * att_factory;
    wxBoxSizer* main_sizer;
    ATTTimeValidator * my_validator;
    wxFloatingPointValidator< double > * my_dvalidator;

    // all input elements:
    wxDatePickerCtrl * m_Date;
    
    wxComboBox * m_StPName;
    wxTextCtrl * m_StPLW1T;
    wxTextCtrl * m_StPLW1H;
    wxTextCtrl * m_StPHW1T;
    wxTextCtrl * m_StPHW1H;
    wxTextCtrl * m_StPLW2T;
    wxTextCtrl * m_StPLW2H;
    wxTextCtrl * m_StPHW2T;
    wxTextCtrl * m_StPHW2H;
    
    wxComboBox * m_ScPName;
    wxTextCtrl * m_ScPLW1T;
    wxTextCtrl * m_ScPLW1H;
    wxTextCtrl * m_ScPHW1T;
    wxTextCtrl * m_ScPHW1H;
    wxTextCtrl * m_ScPLW2T;
    wxTextCtrl * m_ScPLW2H;
    wxTextCtrl * m_ScPHW2T;
    wxTextCtrl * m_ScPHW2H;
    
    wxStaticText* m_StPName2Label;
    wxTextCtrl * m_ScPHWT1;
    wxTextCtrl * m_ScPHWT2;
    wxTextCtrl * m_ScPHWT3;
    wxTextCtrl * m_ScPHWT4;
    
    wxTextCtrl * m_ScPLWT1;
    wxTextCtrl * m_ScPLWT2;
    wxTextCtrl * m_ScPLWT3;
    wxTextCtrl * m_ScPLWT4;
    
    wxTextCtrl * m_StPMHWS;
    wxTextCtrl * m_StPMHWN;
    wxTextCtrl * m_StPMLWS;
    wxTextCtrl * m_StPMLWN;
    wxTextCtrl * m_StPSC;
    
    wxStaticText* m_ScPName2Label;
    wxTextCtrl * m_ScPDHWT1;
    wxTextCtrl * m_ScPDHWT2;
    wxTextCtrl * m_ScPDLWT1;
    wxTextCtrl * m_ScPDLWT2;
    
    wxTextCtrl * m_ScPMHWS;
    wxTextCtrl * m_ScPMHWN;
    wxTextCtrl * m_ScPMLWS;
    wxTextCtrl * m_ScPMLWN;
    wxTextCtrl * m_ScPSC;
    
    wxButton  * m_bCalculate;
    wxButton  * m_bClose;
    wxButton  * m_bPrint;
    wxButton  * m_bSave;
    
    
    
    // Virtual event handlers, overide them in your derived class
    
    void OnSetDate( wxCommandEvent& event );
    
    void OnCalculate( wxCommandEvent& event );
    void OnSave( wxCommandEvent& event );
    void OnClose( wxCommandEvent& event );
    void OnStPEnter( wxCommandEvent& event );
    void OnScPEnter( wxCommandEvent& event );
    void OnStPLW1T( wxCommandEvent& event );
    void OnStPLW2T( wxCommandEvent& event );
    void OnStPHW1T( wxCommandEvent& event );
    void OnStPHW2T( wxCommandEvent& event );
    void OnStPLW1H( wxCommandEvent& event );
    void OnStPLW2H( wxCommandEvent& event );
    void OnStPHW1H( wxCommandEvent& event );
    void OnStPHW2H( wxCommandEvent& event );
    
    void OnScPHWT1( wxCommandEvent& event );
    void OnScPHWT2( wxCommandEvent& event );
    void OnScPHWT3( wxCommandEvent& event );
    void OnScPHWT4( wxCommandEvent& event );
    
    void OnScPLWT1( wxCommandEvent& event );
    void OnScPLWT2( wxCommandEvent& event );
    void OnScPLWT3( wxCommandEvent& event );
    void OnScPLWT4( wxCommandEvent& event );
        
   
    void OnStPMHWS( wxCommandEvent& event );
    void OnStPMHWN( wxCommandEvent& event );
    void OnStPMLWS( wxCommandEvent& event );
    void OnStPMLWN( wxCommandEvent& event );
    void OnStPSC( wxCommandEvent& event );
    
    void OnScPDHWT1( wxCommandEvent& event );
    void OnScPDHWT2( wxCommandEvent& event );
    void OnScPDLWT1( wxCommandEvent& event );
    void OnScPDLWT2( wxCommandEvent& event );  
    
    void OnScPMHWS( wxCommandEvent& event );
    void OnScPMHWN( wxCommandEvent& event );
    void OnScPMLWS( wxCommandEvent& event );
    void OnScPMLWN( wxCommandEvent& event );
    void OnScPSC( wxCommandEvent& event );
   

public:

    ATTDialog( wxWindow* parent, 
               wxWindowID id = wxID_ANY, 
               const wxString& title = _( "A.T.T. Calculation" ), 
               const wxPoint& pos = wxDefaultPosition, 
               const wxSize& size = wxDefaultSize, 
               long style = wxCAPTION | wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER );
    ~ATTDialog();
    void CreateLayout(  );
};



#endif //__ATTDIALOG_H__

