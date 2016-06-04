/*****************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  demo Plugin
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

#ifndef _DEMOPI_H_
#define _DEMOPI_H_

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#define     PLUGIN_VERSION_MAJOR    0
#define     PLUGIN_VERSION_MINOR    0

#define     MY_API_VERSION_MAJOR    1
#define     MY_API_VERSION_MINOR    9

#include "../../../include/ocpn_plugin.h"

#define ATT_TOOL_POSITION    -1          // Request default positioning of toolbar tool
class attWindow;

//----------------------------------------------------------------------------------------------------------
//    The PlugIn Class Definition
//----------------------------------------------------------------------------------------------------------


class att_pi : public opencpn_plugin_19
{
public:
      att_pi(void *ppimgr);
      ~att_pi();
 
//    The required PlugIn Methods
      int Init(void);
      bool DeInit(void);

      int GetAPIVersionMajor();
      int GetAPIVersionMinor();
      int GetPlugInVersionMajor();
      int GetPlugInVersionMinor();

      wxString GetCommonName();
      wxString GetShortDescription();
      wxString GetLongDescription();

//    The optional method overrides

      void OnContextMenuItemCallback(int id);
      void UpdateAuiStatus(void);

      
//    The override PlugIn Methods
      bool RenderOverlay(wxDC &dc, PlugIn_ViewPort *vp);
      void SetCursorLatLon(double lat, double lon);
      bool RenderGLOverlay(wxGLContext *pcontext, PlugIn_ViewPort *vp);
      int GetToolbarToolCount(void);
      void ShowPreferencesDialog( wxWindow* parent );
      void OnToolbarToolCallback(int id);
      void SetPluginMessage(wxString &message_id, wxString &message_body);
      void SetPositionFixEx(PlugIn_Position_Fix_Ex &pfix);


private:
      wxWindow         *m_parent_window;
      int              m_leftclick_tool_id;

      attWindow        *m_patt_window;
      wxAuiManager     *m_AUImgr;
      int               m_show_id;
      int               m_hide_id;

};



class attWindow : public wxWindow
{
public:
      attWindow(wxWindow *pparent, wxWindowID id);
      ~attWindow();

      void OnPaint(wxPaintEvent& event);
      void SetSentence(wxString &sentence);
      void OnSize(wxSizeEvent& event);



DECLARE_EVENT_TABLE()
};


#endif



