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
///////////////////////////////////////////////////////////////////////////
#include <iostream>



ATTDialog::ATTDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    att_calculation = new ATTCalculation();
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
    
    
    wxStaticText* m_TideTypeLabel = new wxStaticText( this, wxID_ANY, _("Tide type"), wxDefaultPosition, wxDefaultSize, 0 );
    sbSizer0->Add(m_TideTypeLabel,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    m_TideSpring = new wxRadioButton 	( 	this ,
                                                                wxID_ANY,
                                                         _("Spring"),
                                                                wxDefaultPosition,
                                                         wxDefaultSize,
                                                         wxRB_GROUP);
    sbSizer0->Add(m_TideSpring ,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    m_TideMid = new wxRadioButton 	( 	this ,
                                                                wxID_ANY,
                                                         _("Mid"));
    sbSizer0->Add(m_TideMid ,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    m_TideNipp = new wxRadioButton 	( 	this ,
                                                                wxID_ANY,
                                                         _("Nipp"));
    sbSizer0->Add(m_TideNipp,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3  );

    
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
    
    m_StPName= new wxTextCtrl (this, wxID_ANY );
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
    
    m_StPLW1T= new wxTextCtrl (this, wxID_ANY );
    _stp_tide_sizer->Add(m_StPLW1T,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    
    m_StPLW1H= new wxTextCtrl (this, wxID_ANY );
    _stp_tide_sizer->Add(m_StPLW1H,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );   
    
    
    wxStaticText* m_StPHW1Label = new wxStaticText( this, wxID_ANY, _("HW1"), wxDefaultPosition, wxDefaultSize, 0 );
    _stp_tide_sizer->Add(m_StPHW1Label,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    
    m_StPHW1T= new wxTextCtrl (this, wxID_ANY );
    _stp_tide_sizer->Add(m_StPHW1T,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    
    m_StPHW1H= new wxTextCtrl (this, wxID_ANY );
    _stp_tide_sizer->Add(m_StPHW1H,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );   
    
    wxStaticText* m_StPLW2Label = new wxStaticText( this, wxID_ANY, _("LW2"), wxDefaultPosition, wxDefaultSize, 0 );
    _stp_tide_sizer->Add(m_StPLW2Label,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    
    m_StPLW2T= new wxTextCtrl (this, wxID_ANY );
    _stp_tide_sizer->Add(m_StPLW2T,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    
    m_StPLW2H= new wxTextCtrl (this, wxID_ANY );
    _stp_tide_sizer->Add(m_StPLW2H,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );   
    
    
    wxStaticText* m_StPHW2Label = new wxStaticText( this, wxID_ANY, _("HW2"), wxDefaultPosition, wxDefaultSize, 0 );
    _stp_tide_sizer->Add(m_StPHW2Label,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );
    
    m_StPHW2T= new wxTextCtrl (this, wxID_ANY );
    _stp_tide_sizer->Add(m_StPHW2T,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    
    m_StPHW2H= new wxTextCtrl (this, wxID_ANY );
    _stp_tide_sizer->Add(m_StPHW2H,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );   
    
    
    
    
    
    
    
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
    
    m_ScPName= new wxTextCtrl (this, wxID_ANY );
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
    
    m_ScPHWT1= new wxTextCtrl (this, wxID_ANY );
    _scp_hw_calc_sizer->Add(m_ScPHWT1,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    
    m_ScPHWT2= new wxTextCtrl (this, wxID_ANY );
    _scp_hw_calc_sizer->Add(m_ScPHWT2,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );   
        
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
    
      
    m_ScPHWT3= new wxTextCtrl (this, wxID_ANY );
    _scp_hw_calc_sizer->Add(m_ScPHWT3,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    
    m_ScPHWT4= new wxTextCtrl (this, wxID_ANY );
    _scp_hw_calc_sizer->Add(m_ScPHWT4,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );    

      // --- times for LW
    wxFlexGridSizer * _scp_lw_calc_sizer = new  wxFlexGridSizer 	( 	2   );
    _scp_tide_calc_sizer->Add( _scp_lw_calc_sizer);
    
    m_ScPLWT1= new wxTextCtrl (this, wxID_ANY );
    _scp_lw_calc_sizer->Add(m_ScPLWT1,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    
    m_ScPLWT2= new wxTextCtrl (this, wxID_ANY );
    _scp_lw_calc_sizer->Add(m_ScPLWT2,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );   
        
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
    
      
    m_ScPLWT3= new wxTextCtrl (this, wxID_ANY );
    _scp_lw_calc_sizer->Add(m_ScPLWT3,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    
    m_ScPLWT4= new wxTextCtrl (this, wxID_ANY );
    _scp_lw_calc_sizer->Add(m_ScPLWT4,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );    
    
    // mean leavel on st p
    
    m_StPMHWS= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_calc_sizer->Add(m_StPMHWS,
        0,            // make vertically stretchable
            // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    
    m_StPMHWN= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_calc_sizer->Add(m_StPMHWN,
        0,            // make vertically stretchable
            // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
      
    m_StPMLWS= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_calc_sizer->Add(m_StPMLWS,
        0,            // make vertically stretchable
            // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    
    m_StPMLWN= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_calc_sizer->Add(m_StPMLWN,
        0,            // make vertically stretchable
            // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
        
    m_StPSC= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_calc_sizer->Add(m_StPSC,
        0,            // make vertically stretchable
            // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
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
    
    m_ScPDHWT1= new wxTextCtrl (this, wxID_ANY );
    _scp_diff_hw_calc_sizer->Add(m_ScPDHWT1,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    
    m_ScPDHWT2= new wxTextCtrl (this, wxID_ANY );
    _scp_diff_hw_calc_sizer->Add(m_ScPDHWT2,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );   
        
    
      // --- differences for LW
    wxFlexGridSizer * _scp_diff_lw_calc_sizer = new  wxFlexGridSizer 	( 	2   );
    _scp_tide_calc_sizer->Add( _scp_diff_lw_calc_sizer);
    
    m_ScPDLWT1= new wxTextCtrl (this, wxID_ANY );
    _scp_diff_lw_calc_sizer->Add(m_ScPDLWT1,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    
    m_ScPDLWT2= new wxTextCtrl (this, wxID_ANY );
    _scp_diff_lw_calc_sizer->Add(m_ScPDLWT2,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );   
        
    
    
    
        
    m_ScPMHWS= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_calc_sizer->Add(m_ScPMHWS,
        0,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    
    m_ScPMHWN= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_calc_sizer->Add(m_ScPMHWN,
        0,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
      
    m_ScPMLWS= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_calc_sizer->Add(m_ScPMLWS,
        0,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    
    m_ScPMLWN= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_calc_sizer->Add(m_ScPMLWN,
        0,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
    
    m_ScPSC= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_calc_sizer->Add(m_ScPSC,
        0,            // make vertically stretchable
            // make horizontally stretchable
        wxALL,        //   and make border all around
        3 );  
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
    m_bClose->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ATTDialog::OnClose ) , NULL, this);
    m_bCalculate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ATTDialog::OnBtnClick ), NULL, this );
        
     
     
    main_sizer->Add(sbButtonSizer);
    
    
    

    this->SetSizer( main_sizer );
    SetMinClientSize( main_sizer->GetMinSize()); 
    this->Layout();
    this->Centre( wxBOTH );
}



ATTDialog::~ATTDialog()
{
    delete att_calculation;
}

void ATTDialog::OnBtnClick( wxCommandEvent& event )
{
//     LauncherButton *button = ( LauncherButton* )event.GetEventObject();
//     this->Hide();
//     wxString cmd = button->GetCommand();
//     cmd.Replace( _T( "%BOAT_LAT%" ), wxString::Format( _T( "%f" ), m_Lat ) );
//     cmd.Replace( _T( "%BOAT_LON%" ), wxString::Format( _T( "%f" ), m_Lon ) );
//     cmd.Replace( _T( "%BOAT_SOG%" ), wxString::Format( _T( "%f" ), m_Sog ) );
//     cmd.Replace( _T( "%BOAT_COG%" ), wxString::Format( _T( "%f" ), m_Cog ) );
//     cmd.Replace( _T( "%BOAT_VAR%" ), wxString::Format( _T( "%f" ), m_Var ) );
//     cmd.Replace( _T( "%BOAT_FIXTIME%" ), wxString::Format( _T( "%d" ), m_FixTime ) );
//     cmd.Replace( _T( "%BOAT_NSATS%" ), wxString::Format( _T( "%d" ), m_nSats ) );
//     wxExecute( cmd, wxEXEC_ASYNC );
    event.Skip();
}


void ATTDialog::OnClose( wxCommandEvent& event )
{
    Close();
}

void ATTDialog::OnStPEnter( wxCommandEvent& event )
{
   m_StPName2Label->SetLabel( m_StPName->GetLineText(0));
   SetMinClientSize( main_sizer->GetMinSize()); 
   
}

void ATTDialog::OnScPEnter( wxCommandEvent& event )
{
   m_ScPName2Label->SetLabel( m_ScPName->GetLineText(0));
   SetMinClientSize( main_sizer->GetMinSize()); 
}



