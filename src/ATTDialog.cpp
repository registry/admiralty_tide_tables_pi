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

#include "ATTDialog.h"
#include "ATTCalculation.h"
#include "ATTServices.h"
#include "ATTTime.h"
#include "ATTPortFactory.h"
#include "ATTTimeValidator.h"
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <wx/dateevt.h>
#include <wx/valnum.h>


ATTDialog::ATTDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    att_calculation = new ATTCalculation();
    att_factory = new ATTPortFactory();
    my_validator = new ATTTimeValidator();;
    my_dvalidator = new wxFloatingPointValidator< double >() ;
    CreateLayout();     

}

void ATTDialog::CreateLayout( )
{
    main_sizer = new wxBoxSizer( wxVERTICAL );

    wxStaticBoxSizer* sbSizer0;
    sbSizer0 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("General info") ), wxHORIZONTAL );
    main_sizer->Add(sbSizer0);
    
    wxStaticText* m_DateLabel = new wxStaticText( this, wxID_ANY, _("Date"), wxDefaultPosition, wxDefaultSize, 0 );
    sbSizer0->Add(m_DateLabel,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    
    m_Date = new  wxDatePickerCtrl ( this, wxID_ANY);
    sbSizer0->Add(m_Date,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 ); 
    m_Date->Connect(  wxEVT_DATE_CHANGED , wxCommandEventHandler( ATTDialog::OnSetDate ), NULL, this);
     

  
    
    wxStaticBoxSizer* sbSizer1;
    sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Tide") ), wxHORIZONTAL );
    main_sizer->Add(sbSizer1);
    
    wxStaticBoxSizer* sbStPSizer;
    sbStPSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Standard Port") ), wxVERTICAL );
    sbSizer1->Add(sbStPSizer,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        5 );
    
    wxFlexGridSizer * _stp_name_sizer = new  wxFlexGridSizer 	( 	2   );
    sbStPSizer->Add( _stp_name_sizer);
    
    
        
    wxStaticText* m_StPNameLabel = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
    _stp_name_sizer->Add(m_StPNameLabel,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    
    m_StPName= new wxComboBox (this, wxID_ANY );
    _stp_name_sizer->Add(m_StPName,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    m_StPName->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnStPEnter ), NULL, this);
       
    
    
    
    wxFlexGridSizer * _stp_tide_sizer = new  wxFlexGridSizer 	( 	3   );
    sbStPSizer->Add( _stp_tide_sizer);
    
          
    wxStaticText* m_StPLW1Label = new wxStaticText( this, wxID_ANY, _("LW1"), wxDefaultPosition, wxDefaultSize, 0 );
    _stp_tide_sizer->Add(m_StPLW1Label,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    
    m_StPLW1T= new wxTextCtrl (this, wxID_ANY,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_validator );
    _stp_tide_sizer->Add(m_StPLW1T,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 ); 
    m_StPLW1T->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnStPLW1T ), NULL, this); 
    *m_StPLW1T << "0000";   
   
    m_StPLW1H= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_dvalidator );
    _stp_tide_sizer->Add(m_StPLW1H,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );   
    m_StPLW1H->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnStPLW1H ), NULL, this); 
     *m_StPLW1H << "0";     
    
    wxStaticText* m_StPHW1Label = new wxStaticText( this, wxID_ANY, _("HW1"), wxDefaultPosition, wxDefaultSize, 0 );
    _stp_tide_sizer->Add(m_StPHW1Label,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    
    m_StPHW1T= new wxTextCtrl (this, wxID_ANY,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_validator  );
    _stp_tide_sizer->Add(m_StPHW1T,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    m_StPHW1T->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnStPHW1T ), NULL, this); 
    *m_StPHW1T << "0000";
    
    m_StPHW1H= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_dvalidator );
    _stp_tide_sizer->Add(m_StPHW1H,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    m_StPHW1H->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnStPHW1H ), NULL, this); 
     *m_StPHW1H << "0";  
    
    wxStaticText* m_StPLW2Label = new wxStaticText( this, wxID_ANY, _("LW2"), wxDefaultPosition, wxDefaultSize, 0 );
    _stp_tide_sizer->Add(m_StPLW2Label,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    
    m_StPLW2T= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_validator );
    _stp_tide_sizer->Add(m_StPLW2T,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    m_StPLW2T->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnStPLW2T ), NULL, this); 
    *m_StPLW2T << "0000";
    
    m_StPLW2H= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_dvalidator );
    _stp_tide_sizer->Add(m_StPLW2H,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    m_StPLW2H->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnStPLW2H ), NULL, this); 
     *m_StPLW2H << "0";  
    
    
    wxStaticText* m_StPHW2Label = new wxStaticText( this, wxID_ANY, _("HW2"), wxDefaultPosition, wxDefaultSize, 0 );
    _stp_tide_sizer->Add(m_StPHW2Label,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    
    m_StPHW2T= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_validator );
    _stp_tide_sizer->Add(m_StPHW2T,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    m_StPHW2T->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnStPHW2T ), NULL, this); 
    *m_StPHW2T << "0000";
    
    m_StPHW2H= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_dvalidator );
    _stp_tide_sizer->Add(m_StPHW2H,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    m_StPHW2H->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnStPHW2H ), NULL, this); 
     *m_StPHW2H << "0";   
    
    
    
    
    
    
    
    wxStaticBoxSizer* sbScPSizer;
    sbScPSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Secondary Port") ), wxVERTICAL );
    sbSizer1->Add(sbScPSizer,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        5 );   
    
    wxFlexGridSizer * _scp_name_sizer = new  wxFlexGridSizer 	( 	2   );
    sbScPSizer->Add( _scp_name_sizer);
    
    
    wxStaticText* m_ScPNameLabel = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_name_sizer->Add(m_ScPNameLabel,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    
    m_ScPName= new wxComboBox (this, wxID_ANY );
    _scp_name_sizer->Add(m_ScPName,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    m_ScPName->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPEnter ), NULL, this);
       
     
    wxFlexGridSizer * _scp_tide_sizer = new  wxFlexGridSizer 	( 	3   );
    sbScPSizer->Add( _scp_tide_sizer);
    
    
        
          
    wxStaticText* m_ScPLW1Label = new wxStaticText( this, wxID_ANY, _("LW1"), wxDefaultPosition, wxDefaultSize);
    _scp_tide_sizer->Add(m_ScPLW1Label,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3
        );   
    
    m_ScPLW1T= new wxTextCtrl (this, wxID_ANY, _(""), wxDefaultPosition, wxDefaultSize,  wxTE_READONLY  );
    _scp_tide_sizer->Add(m_ScPLW1T,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3
        );   
    
    m_ScPLW1H= new wxTextCtrl (this, wxID_ANY, _(""), wxDefaultPosition, wxDefaultSize,  wxTE_READONLY   );
    _scp_tide_sizer->Add(m_ScPLW1H,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3
        );   
    
    
    wxStaticText* m_ScPHW1Label = new wxStaticText( this, wxID_ANY, _("HW1"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_sizer->Add(m_ScPHW1Label,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3
        );   
    
    m_ScPHW1T= new wxTextCtrl (this, wxID_ANY, _(""), wxDefaultPosition, wxDefaultSize,  wxTE_READONLY    );
    _scp_tide_sizer->Add(m_ScPHW1T,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3
        );   
    
    m_ScPHW1H= new wxTextCtrl (this, wxID_ANY, _(""), wxDefaultPosition, wxDefaultSize,  wxTE_READONLY    );
    _scp_tide_sizer->Add(m_ScPHW1H,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3
        );    
    
        wxStaticText* m_ScPLW2Label = new wxStaticText( this, wxID_ANY, _("LW2"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_sizer->Add(m_ScPLW2Label,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3
        );   
    
    m_ScPLW2T= new wxTextCtrl (this, wxID_ANY, _(""), wxDefaultPosition, wxDefaultSize,  wxTE_READONLY    );
    _scp_tide_sizer->Add(m_ScPLW2T,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3
        );    
    
    m_ScPLW2H= new wxTextCtrl (this, wxID_ANY, _(""), wxDefaultPosition, wxDefaultSize,  wxTE_READONLY    );
    _scp_tide_sizer->Add(m_ScPLW2H,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3
        );    
    
    
        wxStaticText* m_ScPHW2Label = new wxStaticText( this, wxID_ANY, _("HW2"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_sizer->Add(m_ScPHW2Label,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3
        );   
    
    m_ScPHW2T= new wxTextCtrl (this, wxID_ANY, _(""), wxDefaultPosition, wxDefaultSize,  wxTE_READONLY    );
    _scp_tide_sizer->Add(m_ScPHW2T,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3
        );   
    
    m_ScPHW2H= new wxTextCtrl (this, wxID_ANY, _(""), wxDefaultPosition, wxDefaultSize,  wxTE_READONLY    );
    _scp_tide_sizer->Add(m_ScPHW2H,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3
        );   
    
    
    
    
    
    
    wxStaticBoxSizer* sbSizer2;
    sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Calculation") ), wxVERTICAL );

    
    wxFlexGridSizer * _scp_tide_calc_sizer = new  wxFlexGridSizer 	( 	8   );
    sbSizer2->Add( _scp_tide_calc_sizer);
    
    wxStaticText* m_ScPCalcHolderLabel = new wxStaticText( this, wxID_ANY, _("Port"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPCalcHolderLabel,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    
     wxStaticText* m_ScPCalcHWLabel = new wxStaticText( this, wxID_ANY, _("HW"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPCalcHWLabel,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
     
    wxStaticText* m_ScPCalcLWLabel = new wxStaticText( this, wxID_ANY, _("LW"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPCalcLWLabel,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );   
    
      wxStaticText* m_ScPCalcMHWSLabel = new wxStaticText( this, wxID_ANY, _("MHWS"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPCalcMHWSLabel,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
  
      wxStaticText* m_ScPCalcMHWNLabel = new wxStaticText( this, wxID_ANY, _("MHWN"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPCalcMHWNLabel,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );

      wxStaticText* m_ScPCalcMLWSLabel = new wxStaticText( this, wxID_ANY, _("MLWS"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPCalcMLWSLabel,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
  
      wxStaticText* m_ScPCalcMLWNLabel = new wxStaticText( this, wxID_ANY, _("MLWN"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPCalcMLWNLabel,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    
       wxStaticText* m_ScPCalcSCLabel = new wxStaticText( this, wxID_ANY, _("SC"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPCalcSCLabel,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );   
    
    
     m_StPName2Label = new wxStaticText( this, wxID_ANY, _(""), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_StPName2Label,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
   
    // --- times for HW
    wxFlexGridSizer * _scp_hw_calc_sizer = new  wxFlexGridSizer 	( 	2   );
    _scp_tide_calc_sizer->Add( _scp_hw_calc_sizer);
    
    m_ScPHWT1= new wxTextCtrl (this, wxID_ANY,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_validator );
    _scp_hw_calc_sizer->Add(m_ScPHWT1,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    m_ScPHWT1->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPHWT1 ), NULL, this); 
    *m_ScPHWT1 << "0000";
    
    m_ScPHWT2= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_validator);
    _scp_hw_calc_sizer->Add(m_ScPHWT2,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );   
    m_ScPHWT2->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPHWT2 ), NULL, this); 
    *m_ScPHWT2 << "0600";
        
    wxStaticText* m_ScPHWT1and1 = new wxStaticText( this, wxID_ANY, _("and"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_hw_calc_sizer->Add(m_ScPHWT1and1,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
     wxStaticText* m_ScPHWT1and2 = new wxStaticText( this, wxID_ANY, _("and"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_hw_calc_sizer->Add(m_ScPHWT1and2,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    
      
    m_ScPHWT3= new wxTextCtrl (this, wxID_ANY,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_validator );
    _scp_hw_calc_sizer->Add(m_ScPHWT3,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    m_ScPHWT3->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPHWT3 ), NULL, this); 
     *m_ScPHWT3 << "1200";
    
    m_ScPHWT4= new wxTextCtrl (this, wxID_ANY,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_validator );
    _scp_hw_calc_sizer->Add(m_ScPHWT4,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );    
    m_ScPHWT4->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPHWT4 ), NULL, this); 
    *m_ScPHWT4 << "1800";

      // --- times for LW
    wxFlexGridSizer * _scp_lw_calc_sizer = new  wxFlexGridSizer 	( 	2   );
    _scp_tide_calc_sizer->Add( _scp_lw_calc_sizer);
    
    m_ScPLWT1= new wxTextCtrl (this, wxID_ANY,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_validator );
    _scp_lw_calc_sizer->Add(m_ScPLWT1,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );   
    m_ScPLWT1->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPLWT1 ), NULL, this); 
    *m_ScPLWT1 << "0100";
    
    m_ScPLWT2= new wxTextCtrl (this, wxID_ANY,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_validator );
    _scp_lw_calc_sizer->Add(m_ScPLWT2,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );   
    m_ScPLWT2->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPLWT2 ), NULL, this); 
    *m_ScPLWT2 << "0800";
        
    wxStaticText* m_ScPLWT1and1 = new wxStaticText( this, wxID_ANY, _("and"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_lw_calc_sizer->Add(m_ScPLWT1and1,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
     wxStaticText* m_ScPLWT1and2 = new wxStaticText( this, wxID_ANY, _("and"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_lw_calc_sizer->Add(m_ScPLWT1and2,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    
      
    m_ScPLWT3= new wxTextCtrl (this, wxID_ANY,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_validator );
    _scp_lw_calc_sizer->Add(m_ScPLWT3,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    m_ScPLWT3->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPLWT3 ), NULL, this); 
    *m_ScPLWT3 << "1400";
    
    m_ScPLWT4= new wxTextCtrl (this, wxID_ANY,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_validator );
    _scp_lw_calc_sizer->Add(m_ScPLWT4,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 ); 
    m_ScPLWT4->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPLWT4 ), NULL, this); 
    *m_ScPLWT4 << "2000";   
    
    // mean leavel on st p
    
    m_StPMHWS= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_dvalidator );
    _scp_tide_calc_sizer->Add(m_StPMHWS,
        0,            // make vertically stretchable
            // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    m_StPMHWS->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnStPMHWS ), NULL, this); 
    *m_StPMHWS << 0;   
    
    m_StPMHWN= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_dvalidator );
    _scp_tide_calc_sizer->Add(m_StPMHWN,
        0,            // make vertically stretchable
            // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
     m_StPMHWN->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnStPMHWN ), NULL, this); 
    *m_StPMHWN << 0;   
      
    m_StPMLWS= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_dvalidator );
    _scp_tide_calc_sizer->Add(m_StPMLWS,
        0,            // make vertically stretchable
            // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
     m_StPMLWS->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnStPMLWS ), NULL, this); 
    *m_StPMLWS << 0;   
    
    m_StPMLWN= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_dvalidator );
    _scp_tide_calc_sizer->Add(m_StPMLWN,
        0,            // make vertically stretchable
            // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
     m_StPMLWN->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnStPMLWN ), NULL, this); 
     *m_StPMLWN << 0;   
        
    m_StPSC= new wxTextCtrl (this, wxID_ANY  ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_dvalidator);
    _scp_tide_calc_sizer->Add(m_StPSC,
        0,            // make vertically stretchable
            // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );   
     m_StPSC->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnStPSC ), NULL, this); 
    *m_StPSC << 0;
    
    // differences for secondary port 
    
    m_ScPName2Label = new wxStaticText( this, wxID_ANY, _(""), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPName2Label,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
  
          // --- differences for HW
    wxFlexGridSizer * _scp_diff_hw_calc_sizer = new  wxFlexGridSizer 	( 	2   );
    _scp_tide_calc_sizer->Add( _scp_diff_hw_calc_sizer);
    
    m_ScPDHWT1= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_validator);
    _scp_diff_hw_calc_sizer->Add(m_ScPDHWT1,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
     m_ScPDHWT1->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPDHWT1 ), NULL, this); 
     *m_ScPDHWT1 << 0;
    
    m_ScPDHWT2= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_validator);
    _scp_diff_hw_calc_sizer->Add(m_ScPDHWT2,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );   
     m_ScPDHWT2->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPDHWT2 ), NULL, this); 
    *m_ScPDHWT2 << 0;
    
      // --- differences for LW
    wxFlexGridSizer * _scp_diff_lw_calc_sizer = new  wxFlexGridSizer 	( 	2   );
    _scp_tide_calc_sizer->Add( _scp_diff_lw_calc_sizer);
    
    m_ScPDLWT1= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_validator);
    _scp_diff_lw_calc_sizer->Add(m_ScPDLWT1,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
     m_ScPDLWT1->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPDLWT1 ), NULL, this); 
    *m_ScPDLWT1 << 0;
    
    m_ScPDLWT2= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_validator);
    _scp_diff_lw_calc_sizer->Add(m_ScPDLWT2,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
     m_ScPDLWT2->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPDLWT2 ), NULL, this); 
    *m_ScPDLWT2 << 0; 
        
    
    
    
        
    m_ScPMHWS= new wxTextCtrl (this, wxID_ANY  ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_dvalidator);
    _scp_tide_calc_sizer->Add(m_ScPMHWS,
        0,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
     m_ScPMHWS->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPMHWS ), NULL, this); 
    *m_ScPMHWS << 0; 
    
    m_ScPMHWN= new wxTextCtrl (this, wxID_ANY  ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_dvalidator);
    _scp_tide_calc_sizer->Add(m_ScPMHWN,
        0,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
     m_ScPMHWN->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPMHWN ), NULL, this); 
    *m_ScPMHWN << 0; 
      
    m_ScPMLWS= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_dvalidator );
    _scp_tide_calc_sizer->Add(m_ScPMLWS,
        0,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );    
     m_ScPMLWS->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPMLWS ), NULL, this); 
    *m_ScPMLWS << 0; 
    
    m_ScPMLWN= new wxTextCtrl (this, wxID_ANY ,wxEmptyString,wxDefaultPosition,wxDefaultSize,0, *my_dvalidator );
    _scp_tide_calc_sizer->Add(m_ScPMLWN,
        0,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );    
     m_ScPMLWN->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPMLWN ), NULL, this); 
    *m_ScPMLWN << 0; 
    
    m_ScPSC= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_calc_sizer->Add(m_ScPSC,
        0,            // make vertically stretchable
            // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
     m_ScPSC->Connect(  wxEVT_TEXT , wxCommandEventHandler( ATTDialog::OnScPSC ), NULL, this); 
    *m_ScPSC << 0;
    
    main_sizer->Add(sbSizer2);
    
     
    wxFlexGridSizer* sbButtonSizer = new wxFlexGridSizer(  4 );
    
    
    m_bPrint = new wxButton( this, wxID_ANY, _("Print")); 
    sbButtonSizer->Add(m_bPrint,
        0,            // make vertically stretchable
            // make horizontally stretchable
        wxALL,        //   and make border all around
        3);
    m_bSave = new wxButton( this, wxID_ANY, _("Save")); 
     sbButtonSizer->Add(m_bSave,
        0,            // make vertically stretchable
            // make horizontally stretchable
        wxALL,        //   and make border all around
        3);
    m_bCalculate = new wxButton( this, wxID_ANY, _("CALCULATE!")); 
     sbButtonSizer->Add(m_bCalculate,
        0,            // make vertically stretchable
            // make horizontally stretchable
        wxALL,        //   and make border all around
        3);
    m_bClose = new wxButton( this, wxID_ANY, _("Close")); 
     sbButtonSizer->Add(m_bClose,
        0,            // make vertically stretchable
            // make horizontally stretchable
        wxALL,        //   and make border all around
        3);
    m_bSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ATTDialog::OnSave ) , NULL, this);
    m_bClose->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ATTDialog::OnClose ) , NULL, this);
    m_bCalculate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ATTDialog::OnCalculate ), NULL, this );
        
     
     
    main_sizer->Add(sbButtonSizer);
    
    
    

    this->SetSizer( main_sizer );
    SetMinClientSize( main_sizer->GetMinSize()); 
    this->Layout();
    this->Centre( wxBOTH );
}



ATTDialog::~ATTDialog()
{
    delete att_calculation;
    delete att_factory;
    delete my_validator;
    delete my_dvalidator;
}


void ATTDialog::OnSetDate( wxCommandEvent& event )
{
    m_StPName->Clear();
    m_StPName->Append(att_factory->getStandardPorts ( m_Date->GetValue()) );
    m_ScPName->Clear();
    m_ScPName->Append(att_factory->getSecondaryPorts ( m_Date->GetValue()) );
    
    event.Skip();
}






void ATTDialog::OnCalculate( wxCommandEvent& event )
{
    att_calculation->calculate();
    m_ScPLW1T->SetValue( ATTServices::convertATTTimeAsDouble2String( att_calculation->getScPLW1T()) );
    wxString _s;
    _s <<  att_calculation->getScPLW1H() ;
    m_ScPLW1H->SetValue( _s );

    m_ScPLW2T->SetValue( ATTServices::convertATTTimeAsDouble2String( att_calculation->getScPLW2T()) );
    _s = "";
     _s <<  att_calculation->getScPLW2H() ;
    m_ScPLW2H->SetValue(_s);
        
    m_ScPHW1T->SetValue( ATTServices::convertATTTimeAsDouble2String( att_calculation->getScPHW1T()) );
    _s = "";
     _s <<  att_calculation->getScPHW1H() ;
    m_ScPHW1H->SetValue( _s );

    m_ScPHW2T->SetValue( ATTServices::convertATTTimeAsDouble2String( att_calculation->getScPHW2T()) );
    _s = "";
     _s <<  att_calculation->getScPHW2H() ;
    m_ScPHW2H->SetValue( _s );
        

    
    event.Skip();
}


void ATTDialog::OnSave( wxCommandEvent& event )
{
    ATTStandardPort stp;    
    stp.m_StPName = m_StPName->GetValue();
    
    double _h; // error should be issued
    
    stp.m_StPLW1T = ATTServices::convertATTTimeAsString2Double( m_StPLW1T->GetLineText(0)) ;
    m_StPLW1H->GetLineText(0).ToDouble( & _h);
    stp.m_StPLW1H = _h;
    stp.m_StPHW1T = ATTServices::convertATTTimeAsString2Double( m_StPHW1T->GetLineText(0)) ;
    m_StPHW1H->GetLineText(0).ToDouble( & _h);
    stp.m_StPHW1H = _h;
    stp.m_StPLW2T = ATTServices::convertATTTimeAsString2Double( m_StPLW2T->GetLineText(0)) ;
    m_StPLW2H->GetLineText(0).ToDouble( & _h);
    stp.m_StPLW2H = _h;
    stp.m_StPHW2T = ATTServices::convertATTTimeAsString2Double( m_StPHW2T->GetLineText(0)) ;
    m_StPHW2H->GetLineText(0).ToDouble( & _h);
    stp.m_StPHW2H = _h;
    
    
    ATTSecondaryPort scp;
    scp.m_ScPName = m_ScPName->GetValue();

    scp.m_ScPHWT1 = ATTServices::convertATTTimeAsString2Double( m_ScPHWT1->GetLineText(0)) ;
    scp.m_ScPHWT2 = ATTServices::convertATTTimeAsString2Double( m_ScPHWT2->GetLineText(0)) ;
    scp.m_ScPHWT3 = ATTServices::convertATTTimeAsString2Double( m_ScPHWT3->GetLineText(0)) ;
    scp.m_ScPHWT4 = ATTServices::convertATTTimeAsString2Double( m_ScPHWT4->GetLineText(0)) ;
    
    scp.m_ScPLWT1 = ATTServices::convertATTTimeAsString2Double( m_ScPLWT1->GetLineText(0)) ;
    scp.m_ScPLWT2 = ATTServices::convertATTTimeAsString2Double( m_ScPLWT2->GetLineText(0)) ;
    scp.m_ScPLWT3 = ATTServices::convertATTTimeAsString2Double( m_ScPLWT3->GetLineText(0)) ;
    scp.m_ScPLWT4 = ATTServices::convertATTTimeAsString2Double( m_ScPLWT4->GetLineText(0)) ;
    
    m_StPMHWS->GetLineText(0).ToDouble( & _h);
    scp.m_StPMHWS = _h;
    m_StPMHWN->GetLineText(0).ToDouble( & _h);
    scp.m_StPMHWN = _h;
    m_StPMLWS->GetLineText(0).ToDouble( & _h);
    scp.m_StPMLWS = _h;
    m_StPMLWN->GetLineText(0).ToDouble( & _h);
    scp.m_StPMLWN = _h;
    m_StPSC->GetLineText(0).ToDouble( & _h);
    scp.m_StPSC = _h;

    scp.m_ScPDHWT1 = ATTServices::convertATTTimeAsString2Double( m_ScPDHWT1->GetLineText(0)) ;
    scp.m_ScPDHWT2 = ATTServices::convertATTTimeAsString2Double( m_ScPDHWT2->GetLineText(0)) ;
    scp.m_ScPDLWT1 = ATTServices::convertATTTimeAsString2Double( m_ScPDLWT1->GetLineText(0)) ;
    scp.m_ScPDLWT2 = ATTServices::convertATTTimeAsString2Double( m_ScPDLWT2->GetLineText(0)) ;
    
    m_ScPMHWS->GetLineText(0).ToDouble( & _h);
    scp.m_ScPMHWS = _h;
    m_ScPMHWN->GetLineText(0).ToDouble( & _h);
    scp.m_ScPMHWN = _h;
    m_ScPMLWS->GetLineText(0).ToDouble( & _h);
    scp.m_ScPMLWS = _h;
    m_ScPMLWN->GetLineText(0).ToDouble( & _h);
    scp.m_ScPMLWN = _h;
    m_ScPSC->GetLineText(0).ToDouble( & _h);
    scp.m_ScPSC = _h;
    
    
    
    
    att_factory->saveStandardPort(m_Date->GetValue(),  stp);
    att_factory->saveSecondaryPort(m_Date->GetValue(),  scp);
    
    m_StPName->Clear();
    m_StPName->Append(att_factory->getStandardPorts ( m_Date->GetValue()) );
    m_ScPName->Clear();
    m_ScPName->Append(att_factory->getSecondaryPorts ( m_Date->GetValue()) );
    
    event.Skip();
}


void ATTDialog::OnClose( wxCommandEvent& event )
{
    Close();
    event.Skip();
}





void ATTDialog::OnStPEnter( wxCommandEvent& event )
{
    wxString portname =  m_StPName->GetValue();
    
    if ( att_factory->hasStandardPort(portname, m_Date->GetValue() ) )
    {
        ATTStandardPort & port = att_factory->getStandardPort( portname, m_Date->GetValue());
        att_calculation->setStPName( m_StPName->GetValue() );
        m_StPLW1T->Clear();
        *m_StPLW1T <<  ATTServices::convertATTTimeAsDouble2String( port.m_StPLW1T);
        m_StPLW1H->Clear();
        *m_StPLW1H << port.m_StPLW1H;

        m_StPHW1T->Clear();
        *m_StPHW1T <<  ATTServices::convertATTTimeAsDouble2String( port.m_StPHW1T);
        m_StPHW1H->Clear();
        *m_StPHW1H << port.m_StPHW1H;
        
        m_StPLW2T->Clear();
        *m_StPLW2T <<  ATTServices::convertATTTimeAsDouble2String( port.m_StPLW2T);
        m_StPLW2H->Clear();
        *m_StPLW2H << port.m_StPLW2H;

        m_StPHW2T->Clear();
        *m_StPHW2T <<  ATTServices::convertATTTimeAsDouble2String( port.m_StPHW2T);
        m_StPHW2H->Clear();
        *m_StPHW2H << port.m_StPHW2H;            
    }
    m_StPName2Label->SetLabel( portname ) ;
    SetMinClientSize( main_sizer->GetMinSize()); 

    event.Skip();
   
}

void ATTDialog::OnScPEnter( wxCommandEvent& event )
{
    wxString portname=  m_ScPName->GetValue();
    if ( att_factory->hasSecondaryPort(portname, m_Date->GetValue() ) )
    {
        ATTSecondaryPort & port = att_factory->getSecondaryPort( portname, m_Date->GetValue());
        att_calculation->setScPName( m_ScPName->GetValue() );
        
        
        m_ScPHWT1->Clear();
        *m_ScPHWT1 <<  ATTServices::convertATTTimeAsDouble2String( port.m_ScPHWT1);
        m_ScPHWT2->Clear();
        *m_ScPHWT2 <<  ATTServices::convertATTTimeAsDouble2String( port.m_ScPHWT2);
        m_ScPHWT3->Clear();
        *m_ScPHWT3 <<  ATTServices::convertATTTimeAsDouble2String( port.m_ScPHWT3);
        m_ScPHWT4->Clear();
        *m_ScPHWT4 <<  ATTServices::convertATTTimeAsDouble2String( port.m_ScPHWT4);
        
        m_ScPLWT1->Clear();
        *m_ScPLWT1 <<  ATTServices::convertATTTimeAsDouble2String( port.m_ScPLWT1);
        m_ScPLWT2->Clear();
        *m_ScPLWT2 <<  ATTServices::convertATTTimeAsDouble2String( port.m_ScPLWT2);
        m_ScPLWT3->Clear();
        *m_ScPLWT3 <<  ATTServices::convertATTTimeAsDouble2String( port.m_ScPLWT3);
        m_ScPLWT4->Clear();
        *m_ScPLWT4 <<  ATTServices::convertATTTimeAsDouble2String( port.m_ScPLWT4);
        
        m_StPMHWS->Clear();
        *m_StPMHWS << port.m_StPMHWS;
        m_StPMHWN->Clear();
        *m_StPMHWN << port.m_StPMHWN;
        m_StPMLWS->Clear();
        *m_StPMLWS << port.m_StPMLWS;
        m_StPMLWN->Clear();
        *m_StPMLWN << port.m_StPMLWN;
        m_StPSC->Clear();
        *m_StPSC << port.m_StPSC;
        

        m_ScPDHWT1->Clear();
        *m_ScPDHWT1 <<  ATTServices::convertATTTimeAsDouble2String( port.m_ScPDHWT1);
        m_ScPDHWT2->Clear();
        *m_ScPDHWT2 <<  ATTServices::convertATTTimeAsDouble2String( port.m_ScPDHWT2);
        m_ScPDLWT1->Clear();
        *m_ScPDLWT1 <<  ATTServices::convertATTTimeAsDouble2String( port.m_ScPDLWT1);
        m_ScPDLWT2->Clear();
        *m_ScPDLWT2 <<  ATTServices::convertATTTimeAsDouble2String( port.m_ScPDLWT2);
            
        
        m_ScPMHWS->Clear();
        *m_ScPMHWS << port.m_ScPMHWS;
        m_ScPMHWN->Clear();
        *m_ScPMHWN << port.m_ScPMHWN;        
        m_ScPMLWS->Clear();
        *m_ScPMLWS << port.m_ScPMLWS;
        m_ScPMLWN->Clear();
        *m_ScPMLWN << port.m_ScPMLWN;
        m_ScPSC->Clear();
        *m_ScPSC << port.m_ScPSC;
     
    }
    m_ScPName2Label->SetLabel( portname );
    SetMinClientSize( main_sizer->GetMinSize()); 
    event.Skip();
}


void ATTDialog::OnStPLW1T( wxCommandEvent& event )
{
    att_calculation->setStPLW1T( ATTServices::convertATTTimeAsString2Double( m_StPLW1T->GetLineText(0)) );
    event.Skip();
};

void ATTDialog::OnStPLW2T( wxCommandEvent& event )
{
    att_calculation->setStPLW2T( ATTServices::convertATTTimeAsString2Double( m_StPLW2T->GetLineText(0)) );
    event.Skip();
};

void ATTDialog::OnStPHW1T( wxCommandEvent& event )
{
    att_calculation->setStPHW1T( ATTServices::convertATTTimeAsString2Double( m_StPHW1T->GetLineText(0)) );
     event.Skip();
};

void ATTDialog::OnStPHW2T( wxCommandEvent& event )
{
    att_calculation->setStPHW2T( ATTServices::convertATTTimeAsString2Double( m_StPHW2T->GetLineText(0)) );
    event.Skip();
};



void ATTDialog::OnStPLW1H( wxCommandEvent& event )
{
    double _h; // error should be issued
    m_StPLW1H->GetLineText(0).ToDouble( & _h);
    att_calculation->setStPLW1H( _h );
    event.Skip();
};

void ATTDialog::OnStPLW2H( wxCommandEvent& event )
{
    double _h; // error should be issued
    m_StPLW2H->GetLineText(0).ToDouble( & _h);
    att_calculation->setStPLW2H( _h );
    event.Skip();
};

void ATTDialog::OnStPHW1H( wxCommandEvent& event )
{
    double _h; // error should be issued
    m_StPHW1H->GetLineText(0).ToDouble( & _h);
    att_calculation->setStPHW1H( _h );
     event.Skip();
};

void ATTDialog::OnStPHW2H( wxCommandEvent& event )
{
    double _h; // error should be issued
    m_StPHW2H->GetLineText(0).ToDouble( & _h);
    att_calculation->setStPHW2H( _h );
    event.Skip();
};


    
void ATTDialog::OnScPHWT1( wxCommandEvent& event )
{
    att_calculation->setScPHWT1( ATTServices::convertATTTimeAsString2Double( m_ScPHWT1->GetLineText(0)) );
    event.Skip();
}

void ATTDialog::OnScPHWT2( wxCommandEvent& event )
{
    att_calculation->setScPHWT2( ATTServices::convertATTTimeAsString2Double( m_ScPHWT2->GetLineText(0)) );
    event.Skip();
}

void ATTDialog::OnScPHWT3( wxCommandEvent& event )
{
    att_calculation->setScPHWT3( ATTServices::convertATTTimeAsString2Double( m_ScPHWT3->GetLineText(0)) );
    event.Skip();
}

void ATTDialog::OnScPHWT4( wxCommandEvent& event )
{
    att_calculation->setScPHWT4( ATTServices::convertATTTimeAsString2Double( m_ScPHWT4->GetLineText(0)) );
    event.Skip();
}

void ATTDialog::OnScPLWT1( wxCommandEvent& event )
{
    att_calculation->setScPLWT1( ATTServices::convertATTTimeAsString2Double( m_ScPLWT1->GetLineText(0)) );
    event.Skip();
}

void ATTDialog::OnScPLWT2( wxCommandEvent& event )
{
    att_calculation->setScPLWT2( ATTServices::convertATTTimeAsString2Double( m_ScPLWT2->GetLineText(0)) );
    event.Skip();
}

void ATTDialog::OnScPLWT3( wxCommandEvent& event )
{
    att_calculation->setScPLWT3( ATTServices::convertATTTimeAsString2Double( m_ScPLWT3->GetLineText(0)) );
    event.Skip();
}

void ATTDialog::OnScPLWT4( wxCommandEvent& event )
{
    att_calculation->setScPLWT4( ATTServices::convertATTTimeAsString2Double( m_ScPLWT4->GetLineText(0)) );
    event.Skip();
}


   
void ATTDialog::OnStPMHWS( wxCommandEvent& event )
{
    double _h; // error should be issued
    m_StPMHWS->GetLineText(0).ToDouble( & _h);
    att_calculation->setStPMHWS( _h );
    event.Skip();
};

void ATTDialog::OnStPMHWN( wxCommandEvent& event )
{
    double _h; // error should be issued
    m_StPMHWN->GetLineText(0).ToDouble( & _h);
    att_calculation->setStPMHWN( _h );
    event.Skip();
};

void ATTDialog::OnStPMLWS( wxCommandEvent& event )
{
    double _h; // error should be issued
    m_StPMLWS->GetLineText(0).ToDouble( & _h);
    att_calculation->setStPMLWS( _h );
    event.Skip();
};

void ATTDialog::OnStPMLWN( wxCommandEvent& event )
{
    double _h; // error should be issued
    m_StPMLWN->GetLineText(0).ToDouble( & _h);
    att_calculation->setStPMLWN( _h );
    event.Skip();
};

void ATTDialog::OnStPSC( wxCommandEvent& event )
{
    double _h; // error should be issued
    m_StPSC->GetLineText(0).ToDouble( & _h);
    att_calculation->setStPSC( _h );
    event.Skip();
};

void ATTDialog::OnScPDHWT1( wxCommandEvent& event )
{
    att_calculation->setScPDHWT1( ATTServices::convertATTTimeAsString2Double( m_ScPDHWT1->GetLineText(0)) );
    event.Skip();
}

void ATTDialog::OnScPDHWT2( wxCommandEvent& event )
{
    att_calculation->setScPDHWT2( ATTServices::convertATTTimeAsString2Double( m_ScPDHWT2->GetLineText(0)) );
    event.Skip();
}

void ATTDialog::OnScPDLWT1( wxCommandEvent& event )
{
    att_calculation->setScPDLWT1( ATTServices::convertATTTimeAsString2Double( m_ScPDLWT1->GetLineText(0)) );
    event.Skip();
}

void ATTDialog::OnScPDLWT2( wxCommandEvent& event )
{
    att_calculation->setScPDLWT2( ATTServices::convertATTTimeAsString2Double( m_ScPDLWT2->GetLineText(0)) );
    event.Skip();
}
  

   
void ATTDialog::OnScPMHWS( wxCommandEvent& event )
{
    double _h; // error should be issued
    m_ScPMHWS->GetLineText(0).ToDouble( & _h);
    att_calculation->setScPMHWS( _h );
    event.Skip();
};

void ATTDialog::OnScPMHWN( wxCommandEvent& event )
{
    double _h; // error should be issued
    m_ScPMHWN->GetLineText(0).ToDouble( & _h);
    att_calculation->setScPMHWN( _h );
    event.Skip();
};

void ATTDialog::OnScPMLWS( wxCommandEvent& event )
{
    double _h; // error should be issued
    m_ScPMLWS->GetLineText(0).ToDouble( & _h);
    att_calculation->setScPMLWS( _h );
    event.Skip();
};

void ATTDialog::OnScPMLWN( wxCommandEvent& event )
{
    double _h; // error should be issued
    m_ScPMLWN->GetLineText(0).ToDouble( & _h);
    att_calculation->setScPMLWN( _h );
    event.Skip();
};

void ATTDialog::OnScPSC( wxCommandEvent& event )
{
    double _h; // error should be issued
    m_ScPSC->GetLineText(0).ToDouble( & _h);
    att_calculation->setScPSC( _h );
    event.Skip();
};
    





