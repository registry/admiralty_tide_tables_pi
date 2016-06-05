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
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* main_sizer;
    main_sizer = new wxBoxSizer( wxVERTICAL );

    m_scrolledWindow = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL );
    m_scrolledWindow->SetScrollRate( 5, 5 );

    button_sizer = new wxBoxSizer( wxVERTICAL );

    m_scrolledWindow->SetSizer( button_sizer );
    m_scrolledWindow->Layout();
    button_sizer->Fit( m_scrolledWindow );
    main_sizer->Add( m_scrolledWindow, 1, wxALL | wxEXPAND, 5 );


    this->SetSizer( main_sizer );
    this->Layout();

    this->Centre( wxBOTH );

}

void ATTDialog::CreateButtons( const wxArrayString& labels )
{
    for ( size_t i = 0; i < labels.Count(); i++ )
    {
        AddButton( labels[i] );
    }
    this->m_scrolledWindow->Layout();
    this->button_sizer->Fit( m_scrolledWindow );
    this->Layout();
}

void ATTDialog::AddButton( const wxString& label )
{
    LauncherButton *m_bAction = new wxButton( m_scrolledWindow, wxID_ANY, label, wxDefaultPosition, wxDefaultSize, 0 );
    button_sizer->Add( m_bAction, 1, wxALL | wxEXPAND, 5 );

    m_bAction->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ATTDialog::OnBtnClick ), NULL, this );
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



