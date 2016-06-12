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
///////////////////////////////////////////////////////////////////////////

ATTDialog::ATTDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
//     this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    CreateLayout();     

}

void ATTDialog::CreateLayout( )
{
    
    wxBoxSizer* main_sizer;
    main_sizer = new wxBoxSizer( wxVERTICAL );

//     m_scrolledWindow = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL );
//     m_scrolledWindow->SetScrollRate( 5, 5 );
// 
//     button_sizer = new wxBoxSizer( wxVERTICAL );
// 
//     m_scrolledWindow->SetSizer( button_sizer );
//     m_scrolledWindow->Layout();
//     button_sizer->Fit( m_scrolledWindow );
//     main_sizer->Add( m_scrolledWindow, 1, wxALL | wxEXPAND, 5 );
    wxStaticBoxSizer* sbSizer0;
    sbSizer0 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("General info") ), wxHORIZONTAL );
    main_sizer->Add(sbSizer0);
    
    wxStaticText* m_DateLabel = new wxStaticText( this, wxID_ANY, _("Date"), wxDefaultPosition, wxDefaultSize, 0 );
    sbSizer0->Add(m_DateLabel);
    
    wxDatePickerCtrl * m_Date = new  wxDatePickerCtrl ( this, wxID_ANY);
    sbSizer0->Add(m_Date); 
    
    
    wxStaticText* m_TideTypeLabel = new wxStaticText( this, wxID_ANY, _("Tide type"), wxDefaultPosition, wxDefaultSize, 0 );
    sbSizer0->Add(m_TideTypeLabel);
    wxRadioButton * m_TideSpring = new wxRadioButton 	( 	this ,
                                                                wxID_ANY,
                                                         _("Spring"),
                                                                wxDefaultPosition,
                                                         wxDefaultSize,
                                                         wxRB_GROUP);
    sbSizer0->Add(m_TideSpring );
    wxRadioButton * m_TideMid = new wxRadioButton 	( 	this ,
                                                                wxID_ANY,
                                                         _("Mid"));
    sbSizer0->Add(m_TideMid );
    wxRadioButton * m_TideNipp = new wxRadioButton 	( 	this ,
                                                                wxID_ANY,
                                                         _("Nipp"));
    sbSizer0->Add(m_TideNipp );

    
    wxStaticBoxSizer* sbSizer1;
    sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Tide") ), wxHORIZONTAL );
    main_sizer->Add(sbSizer1);
    
    wxStaticBoxSizer* sbStPSizer;
    sbStPSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Standard Port") ), wxVERTICAL );
    sbSizer1->Add(sbStPSizer);
    
    wxFlexGridSizer * _stp_name_sizer = new  wxFlexGridSizer 	( 	2   );
    sbStPSizer->Add( _stp_name_sizer);
    
    
        
    wxStaticText* m_StPNameLabel = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
    _stp_name_sizer->Add(m_StPNameLabel);
    
    wxTextCtrl * m_StPName= new wxTextCtrl (this, wxID_ANY );
    _stp_name_sizer->Add(m_StPName);
    
    wxFlexGridSizer * _stp_tide_sizer = new  wxFlexGridSizer 	( 	3   );
    sbStPSizer->Add( _stp_tide_sizer);
    
          
    wxStaticText* m_StPLW1Label = new wxStaticText( this, wxID_ANY, _("LW1"), wxDefaultPosition, wxDefaultSize, 0 );
    _stp_tide_sizer->Add(m_StPLW1Label);
    
    wxTextCtrl * m_StPLW1T= new wxTextCtrl (this, wxID_ANY );
    _stp_tide_sizer->Add(m_StPLW1T);  
    
    wxTextCtrl * m_StPLW1H= new wxTextCtrl (this, wxID_ANY );
    _stp_tide_sizer->Add(m_StPLW1H);   
    
    
    wxStaticText* m_StPHW1Label = new wxStaticText( this, wxID_ANY, _("HW1"), wxDefaultPosition, wxDefaultSize, 0 );
    _stp_tide_sizer->Add(m_StPHW1Label);
    
    wxTextCtrl * m_StPHW1T= new wxTextCtrl (this, wxID_ANY );
    _stp_tide_sizer->Add(m_StPHW1T);  
    
    wxTextCtrl * m_StPHW1H= new wxTextCtrl (this, wxID_ANY );
    _stp_tide_sizer->Add(m_StPHW1H);   
    
        wxStaticText* m_StPLW2Label = new wxStaticText( this, wxID_ANY, _("LW2"), wxDefaultPosition, wxDefaultSize, 0 );
    _stp_tide_sizer->Add(m_StPLW2Label);
    
    wxTextCtrl * m_StPLW2T= new wxTextCtrl (this, wxID_ANY );
    _stp_tide_sizer->Add(m_StPLW2T);  
    
    wxTextCtrl * m_StPLW2H= new wxTextCtrl (this, wxID_ANY );
    _stp_tide_sizer->Add(m_StPLW2H);   
    
    
        wxStaticText* m_StPHW2Label = new wxStaticText( this, wxID_ANY, _("HW2"), wxDefaultPosition, wxDefaultSize, 0 );
    _stp_tide_sizer->Add(m_StPHW2Label);
    
    wxTextCtrl * m_StPHW2T= new wxTextCtrl (this, wxID_ANY );
    _stp_tide_sizer->Add(m_StPHW2T);  
    
    wxTextCtrl * m_StPHW2H= new wxTextCtrl (this, wxID_ANY );
    _stp_tide_sizer->Add(m_StPHW2H);   
    
    
    
    
    
    
    
    wxStaticBoxSizer* sbScPSizer;
    sbScPSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Secondary Port") ), wxVERTICAL );
    sbSizer1->Add(sbScPSizer);   
    
    wxFlexGridSizer * _scp_name_sizer = new  wxFlexGridSizer 	( 	2   );
    sbScPSizer->Add( _scp_name_sizer);
    
    
    wxStaticText* m_ScPNameLabel = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_name_sizer->Add(m_ScPNameLabel);
    
    wxTextCtrl * m_ScPName= new wxTextCtrl (this, wxID_ANY );
    _scp_name_sizer->Add(m_ScPName);
    
    wxFlexGridSizer * _scp_tide_sizer = new  wxFlexGridSizer 	( 	3   );
    sbScPSizer->Add( _scp_tide_sizer);
    
    
        
          
    wxStaticText* m_ScPLW1Label = new wxStaticText( this, wxID_ANY, _("LW1"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_sizer->Add(m_ScPLW1Label);
    
    wxTextCtrl * m_ScPLW1T= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_sizer->Add(m_ScPLW1T);  
    
    wxTextCtrl * m_ScPLW1H= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_sizer->Add(m_ScPLW1H);   
    
    
    wxStaticText* m_ScPHW1Label = new wxStaticText( this, wxID_ANY, _("HW1"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_sizer->Add(m_ScPHW1Label);
    
    wxTextCtrl * m_ScPHW1T= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_sizer->Add(m_ScPHW1T);  
    
    wxTextCtrl * m_ScPHW1H= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_sizer->Add(m_ScPHW1H);   
    
        wxStaticText* m_ScPLW2Label = new wxStaticText( this, wxID_ANY, _("LW2"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_sizer->Add(m_ScPLW2Label);
    
    wxTextCtrl * m_ScPLW2T= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_sizer->Add(m_ScPLW2T);  
    
    wxTextCtrl * m_ScPLW2H= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_sizer->Add(m_ScPLW2H);   
    
    
        wxStaticText* m_ScPHW2Label = new wxStaticText( this, wxID_ANY, _("HW2"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_sizer->Add(m_ScPHW2Label);
    
    wxTextCtrl * m_ScPHW2T= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_sizer->Add(m_ScPHW2T);  
    
    wxTextCtrl * m_ScPHW2H= new wxTextCtrl (this, wxID_ANY );
    _scp_tide_sizer->Add(m_ScPHW2H);   
    
    
    
    
    
    
    wxStaticBoxSizer* sbSizer2;
    sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Calculation") ), wxVERTICAL );

    
    wxFlexGridSizer * _scp_tide_calc_sizer = new  wxFlexGridSizer 	( 	7   );
    sbSizer2->Add( _scp_tide_calc_sizer);
    
    wxStaticText* m_ScPCalcHolderLabel = new wxStaticText( this, wxID_ANY, _(""), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPCalcHolderLabel);
    
     wxStaticText* m_ScPCalcHWLabel = new wxStaticText( this, wxID_ANY, _("HW"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPCalcHWLabel);
     
    wxStaticText* m_ScPCalcLWLabel = new wxStaticText( this, wxID_ANY, _("LW"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPCalcLWLabel);   
    
      wxStaticText* m_ScPCalcMHWSLabel = new wxStaticText( this, wxID_ANY, _("MHWS"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPCalcMHWSLabel);
  
      wxStaticText* m_ScPCalcMHWNLabel = new wxStaticText( this, wxID_ANY, _("MHWN"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPCalcMHWNLabel);

      wxStaticText* m_ScPCalcMLWSLabel = new wxStaticText( this, wxID_ANY, _("MLWS"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPCalcMLWSLabel);
  
      wxStaticText* m_ScPCalcMLWNLabel = new wxStaticText( this, wxID_ANY, _("MLWN"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPCalcMLWNLabel);
    
    wxStaticText* m_ScPName2Label = new wxStaticText( this, wxID_ANY, _(""), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_tide_calc_sizer->Add(m_ScPName2Label);
   
    // --- times for HW
    wxFlexGridSizer * _scp_hw_calc_sizer = new  wxFlexGridSizer 	( 	2   );
    _scp_tide_calc_sizer->Add( _scp_hw_calc_sizer);
    
    wxTextCtrl * m_ScPHWT1= new wxTextCtrl (this, wxID_ANY );
    _scp_hw_calc_sizer->Add(m_ScPHWT1);  
    
    wxTextCtrl * m_ScPHWT2= new wxTextCtrl (this, wxID_ANY );
    _scp_hw_calc_sizer->Add(m_ScPHWT2);   
        
    wxStaticText* m_ScPHWT1and1 = new wxStaticText( this, wxID_ANY, _("and"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_hw_calc_sizer->Add(m_ScPHWT1and1);
     wxStaticText* m_ScPHWT1and2 = new wxStaticText( this, wxID_ANY, _("and"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_hw_calc_sizer->Add(m_ScPHWT1and2);
    
      
    wxTextCtrl * m_ScPHWT3= new wxTextCtrl (this, wxID_ANY );
    _scp_hw_calc_sizer->Add(m_ScPHWT3);  
    
    wxTextCtrl * m_ScPHWT4= new wxTextCtrl (this, wxID_ANY );
    _scp_hw_calc_sizer->Add(m_ScPHWT4);    

      // --- times for LW
    wxFlexGridSizer * _scp_lw_calc_sizer = new  wxFlexGridSizer 	( 	2   );
    _scp_tide_calc_sizer->Add( _scp_lw_calc_sizer);
    
    wxTextCtrl * m_ScPLWT1= new wxTextCtrl (this, wxID_ANY );
    _scp_lw_calc_sizer->Add(m_ScPLWT1);  
    
    wxTextCtrl * m_ScPLWT2= new wxTextCtrl (this, wxID_ANY );
    _scp_lw_calc_sizer->Add(m_ScPLWT2);   
        
    wxStaticText* m_ScPLWT1and1 = new wxStaticText( this, wxID_ANY, _("and"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_lw_calc_sizer->Add(m_ScPLWT1and1);
     wxStaticText* m_ScPLWT1and2 = new wxStaticText( this, wxID_ANY, _("and"), wxDefaultPosition, wxDefaultSize, 0 );
    _scp_lw_calc_sizer->Add(m_ScPLWT1and2);
    
      
    wxTextCtrl * m_ScPLWT3= new wxTextCtrl (this, wxID_ANY );
    _scp_lw_calc_sizer->Add(m_ScPLWT3);  
    
    wxTextCtrl * m_ScPLWT4= new wxTextCtrl (this, wxID_ANY );
    _scp_lw_calc_sizer->Add(m_ScPLWT4);    
    
    
    
    main_sizer->Add(sbSizer2);
    

    this->SetSizer( main_sizer );
    SetMinClientSize( main_sizer->GetMinSize()); 
    this->Layout();
    this->Centre( wxBOTH );
}



ATTDialog::~ATTDialog()
{

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

