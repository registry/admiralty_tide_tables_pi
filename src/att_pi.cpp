/******************************************************************************
 * updated: 4-5-2012  
 * Project:  OpenCPN
 * Purpose:  demo Plugin
 * Author:   David Register
 *
 ***************************************************************************
 *   Copyright (C) 2010 by David S. Register   *
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


#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include <wx/aui/aui.h>

#include "att_pi.h"

#include "tool_icon.h"

// the class factories, used to create and destroy instances of the PlugIn

static att_pi *s_att_pi;
extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new att_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
    delete p;
}





//---------------------------------------------------------------------------------------------------------
//
//    demo PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------


att_pi::att_pi(void *ppimgr)
      :opencpn_plugin_117(ppimgr)
{
      // Create the PlugIn icons
      initialize_images();
      s_att_pi = this;
}

att_pi::~att_pi(void)
{
      delete _img_att;
}


//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------


int att_pi::Init(void)
{

        // Get a pointer to the opencpn display canvas, to use as a parent for windows created
        m_parent_window = GetOCPNCanvasWindow();
      
        //    This PlugIn needs a toolbar icon, so request its insertion if enabled locally
      m_leftclick_tool_id  = InsertPlugInTool(_T(""), _img_att, _img_att, wxITEM_NORMAL,
                                              _("A.T.T. Calculation"), _T(""), NULL,
                                              ATT_TOOL_POSITION, 0, this);
        m_pATTDialog = new ATTDialog( m_parent_window );


      return (
           WANTS_TOOLBAR_CALLBACK    |
           INSTALLS_TOOLBAR_TOOL     
            );
}

bool att_pi::DeInit(void)
{
       if ( m_pATTDialog )
    {
        m_pATTDialog->Close();
        delete m_pATTDialog;
        m_pATTDialog = NULL;
    }
      
      return true;
}

int att_pi::GetAPIVersionMajor() { return OCPN_API_VERSION_MAJOR; }

int att_pi::GetAPIVersionMinor() { return OCPN_API_VERSION_MINOR; }

int att_pi::GetPlugInVersionMajor() { return PLUGIN_VERSION_MAJOR; }

int att_pi::GetPlugInVersionMinor() { return PLUGIN_VERSION_MINOR; }

int att_pi::GetPlugInVersionPatch() { return PLUGIN_VERSION_PATCH; }

int att_pi::GetPlugInVersionPost() { return PLUGIN_VERSION_TWEAK; }


wxString att_pi::GetCommonName() { return _T(PLUGIN_COMMON_NAME); }

wxString att_pi::GetShortDescription() { return _(PLUGIN_SHORT_DESCRIPTION); }

wxString att_pi::GetLongDescription() { return _(PLUGIN_LONG_DESCRIPTION); }

int att_pi::GetToolbarToolCount(void) { return 1; }

void att_pi::ShowPreferencesDialog( wxWindow* parent )
{

}
void att_pi::OnToolbarToolCallback(int id)
{
    SetToolbarItemState( id, false );
    m_pATTDialog->Show();
}

