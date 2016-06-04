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
      :opencpn_plugin_19(ppimgr)
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
        m_patt_window = NULL;

        // Get a pointer to the opencpn display canvas, to use as a parent for windows created
        m_parent_window = GetOCPNCanvasWindow();
      
        //    This PlugIn needs a toolbar icon, so request its insertion if enabled locally
      m_leftclick_tool_id  = InsertPlugInTool(_T(""), _img_att, _img_att, wxITEM_NORMAL,
                                              _("A.T.T. Calculation"), _T(""), NULL,
                                              ATT_TOOL_POSITION, 0, this);
      
        // Create the Context Menu Items

        //    In order to avoid an ASSERT on msw debug builds,
        //    we need to create a dummy menu to act as a surrogate parent of the created MenuItems
        //    The Items will be re-parented when added to the real context meenu
//         wxMenu dummy_menu;
// 
//         wxMenuItem *pmi = new wxMenuItem(&dummy_menu, -1, _("Show A.T.T. Window"));
//         m_show_id = AddCanvasContextMenuItem(pmi, this );
//         SetCanvasContextMenuItemViz(m_show_id, true);
// 
//         wxMenuItem *pmih = new wxMenuItem(&dummy_menu, -1, _("Hide A.T.T. DemoWindow"));
//         m_hide_id = AddCanvasContextMenuItem(pmih, this );
//         SetCanvasContextMenuItemViz(m_hide_id, false);
// 
//         m_patt_window = new attWindow(m_parent_window, wxID_ANY);
// 
//         m_AUImgr = GetFrameAuiManager();
//         m_AUImgr->AddPane(m_patt_window);
//         m_AUImgr->GetPane(m_patt_window).Name(_T("A.T.T. Calculation"));
// 
//         m_AUImgr->GetPane(m_patt_window).Float();
//         m_AUImgr->GetPane(m_patt_window).FloatingPosition(300,30);
// 
//         m_AUImgr->GetPane(m_patt_window).Caption(_T("A.T.T. Calculation Window"));
//         m_AUImgr->GetPane(m_patt_window).CaptionVisible(true);
//         m_AUImgr->GetPane(m_patt_window).GripperTop(true);
//         m_AUImgr->GetPane(m_patt_window).CloseButton(true);
//         m_AUImgr->GetPane(m_patt_window).Show(false);
//         m_AUImgr->Update();

      return (
           WANTS_TOOLBAR_CALLBACK    |
           INSTALLS_TOOLBAR_TOOL     
            );
}

bool att_pi::DeInit(void)
{
      m_AUImgr->DetachPane(m_patt_window);
      if(m_patt_window)
      {
        m_patt_window->Close();
//          m_patt_window->Destroy(); //Gives a Segmentation fault
      }
      return true;
}

int att_pi::GetAPIVersionMajor()
{
      return MY_API_VERSION_MAJOR;
}

int att_pi::GetAPIVersionMinor()
{
      return MY_API_VERSION_MINOR;
}

int att_pi::GetPlugInVersionMajor()
{
      return PLUGIN_VERSION_MAJOR;
}

int att_pi::GetPlugInVersionMinor()
{
      return PLUGIN_VERSION_MINOR;
}

wxString att_pi::GetCommonName()
{
      return _("Admiralty Tide Tables Calculation");
}

wxString att_pi::GetShortDescription()
{
      return _("A.T.T. Calculation PlugIn for OpenCPN");
}

wxString att_pi::GetLongDescription()
{
      return _("A.T.T. Calculation  PlugIn for OpenCPN");

}

// void att_pi::SetNMEASentence(wxString &sentence)
// {
// //      printf("att_pi::SetNMEASentence\n");
//       if(m_patt_window)
//       {
//             m_patt_window->SetSentence(sentence);
//       }
// }


void att_pi::OnContextMenuItemCallback(int id)
{
      wxLogMessage(_T("att_pi OnContextMenuCallBack()"));
     ::wxBell();

      //  Note carefully that this is a "reference to a wxAuiPaneInfo classs instance"
      //  Copy constructor (i.e. wxAuiPaneInfo pane = m_AUImgr->GetPane(m_patt_window);) will not work

      wxAuiPaneInfo &pane = m_AUImgr->GetPane(m_patt_window);
      if(!pane.IsOk())
            return;

      if(!pane.IsShown())
      {
//            printf("show\n");
            SetCanvasContextMenuItemViz(m_hide_id, true);
            SetCanvasContextMenuItemViz(m_show_id, false);

            pane.Show(true);
            m_AUImgr->Update();

      }
      else
      {
//            printf("hide\n");
            SetCanvasContextMenuItemViz(m_hide_id, false);
            SetCanvasContextMenuItemViz(m_show_id, true);

            pane.Show(false);
            m_AUImgr->Update();
      }


      if(NULL == m_patt_window)
      {
            m_patt_window = new attWindow(m_parent_window, wxID_ANY);

            SetCanvasContextMenuItemViz(m_hide_id, true);
            SetCanvasContextMenuItemViz(m_show_id, false);
      }
      else
      {
            m_patt_window->Close();
            m_patt_window->Destroy();
            m_patt_window = NULL;

            SetCanvasContextMenuItemViz(m_hide_id, false);
            SetCanvasContextMenuItemViz(m_show_id, true);
      }

}

void att_pi::UpdateAuiStatus(void)
{
      //    This method is called after the PlugIn is initialized
      //    and the frame has done its initial layout, possibly from a saved wxAuiManager "Perspective"
      //    It is a chance for the PlugIn to syncronize itself internally with the state of any Panes that
      //    were added to the frame in the PlugIn ctor.

      //    We use this callback here to keep the context menu selection in sync with the window state


      wxAuiPaneInfo &pane = m_AUImgr->GetPane(m_patt_window);
      if(!pane.IsOk())
            return;

//       printf("update %d\n",pane.IsShown());

      SetCanvasContextMenuItemViz(m_hide_id, pane.IsShown());
      SetCanvasContextMenuItemViz(m_show_id, !pane.IsShown());

}

bool att_pi::RenderOverlay(wxDC &dc, PlugIn_ViewPort *vp)
{
  /*    if(m_pGribDialog && m_pGRIBOverlayFactory)
      {
            if(m_pGRIBOverlayFactory->IsReadyToRender())
            {
                  m_pGRIBOverlayFactory->RenderGribOverlay ( dc, vp );
                  return true;
            }
            else
                  return false;
      }
      else*/
            return false;
}
void att_pi::SetCursorLatLon(double lat, double lon)
{

}
bool att_pi::RenderGLOverlay(wxGLContext *pcontext, PlugIn_ViewPort *vp)
{
   /*   if(m_pGribDialog && m_pGRIBOverlayFactory)
      {
            if(m_pGRIBOverlayFactory->IsReadyToRender())
            {
                  m_pGRIBOverlayFactory->RenderGLGribOverlay ( pcontext, vp );
                  return true;
            }
            else
                  return false;
      }
      else*/
            return false;

}
int att_pi::GetToolbarToolCount(void)
{
      return 1;
}
void att_pi::ShowPreferencesDialog( wxWindow* parent )
{

}
void att_pi::OnToolbarToolCallback(int id)
{

}
void att_pi::SetPluginMessage(wxString &message_id, wxString &message_body)
{

}
void att_pi::SetPositionFixEx(PlugIn_Position_Fix_Ex &pfix)
{

}

//----------------------------------------------------------------
//
//    demo Window Implementation
//
//----------------------------------------------------------------

BEGIN_EVENT_TABLE(attWindow, wxWindow)
  EVT_PAINT ( attWindow::OnPaint )
  EVT_SIZE(attWindow::OnSize)


END_EVENT_TABLE()

attWindow::attWindow(wxWindow *pparent, wxWindowID id)
      :wxWindow(pparent, id, wxPoint(10,10), wxSize(200,200),
             wxSIMPLE_BORDER, _T("OpenCPN PlugIn"))
{
//       mLat = 0.0;
//       mLon = 1.0;
//       mSog = 2.0;
//       mCog = 3.0;
//       mVar = 4.0;
}

attWindow::~attWindow()
{
}

void attWindow::OnSize(wxSizeEvent& event)
{
//       printf("attWindow OnSize()\n");
}


void attWindow::SetSentence(wxString &sentence)
{
//       m_NMEA0183 << sentence;
// 
//       bool bGoodData = false;
// 
//       if(m_NMEA0183.PreParse())
//       {
//             if(m_NMEA0183.LastSentenceIDReceived == _T("RMC"))
//             {
//                   if(m_NMEA0183.Parse())
//                   {
//                               if(m_NMEA0183.Rmc.IsDataValid == NTrue)
//                               {
//                                     float llt = m_NMEA0183.Rmc.Position.Latitude.Latitude;
//                                     int lat_deg_int = (int)(llt / 100);
//                                     float lat_deg = lat_deg_int;
//                                     float lat_min = llt - (lat_deg * 100);
//                                     mLat = lat_deg + (lat_min/60.);
//                                     if(m_NMEA0183.Rmc.Position.Latitude.Northing == South)
//                                           mLat = -mLat;
// 
//                                     float lln = m_NMEA0183.Rmc.Position.Longitude.Longitude;
//                                     int lon_deg_int = (int)(lln / 100);
//                                     float lon_deg = lon_deg_int;
//                                     float lon_min = lln - (lon_deg * 100);
//                                     mLon = lon_deg + (lon_min/60.);
//                                     if(m_NMEA0183.Rmc.Position.Longitude.Easting == West)
//                                           mLon = -mLon;
// 
//                                     mSog = m_NMEA0183.Rmc.SpeedOverGroundKnots;
//                                     mCog = m_NMEA0183.Rmc.TrackMadeGoodDegreesTrue;
// 
//                                     if(m_NMEA0183.Rmc.MagneticVariationDirection == East)
//                                           mVar =  m_NMEA0183.Rmc.MagneticVariation;
//                                     else if(m_NMEA0183.Rmc.MagneticVariationDirection == West)
//                                           mVar = -m_NMEA0183.Rmc.MagneticVariation;
// 
//                                     bGoodData = true;
// 
//                               }
//                         }
//                   }
//         }

      //    Got the data, now do something with it
/*
      if(bGoodData)
      {
            Refresh(false);
      }*/
}

void attWindow::OnPaint(wxPaintEvent& event)
{
      wxLogMessage(_T("att_pi onpaint"));

      wxPaintDC dc ( this );

//      printf("onpaint\n");

      {
            dc.Clear();

            wxString data;
            data.Printf(_T("Lat: %g "), 12.);
            dc.DrawText(data, 10, 10);
/*
            data.Printf(_T("Lon: %g"), mLon);
            dc.DrawText(data, 10, 40);

            data.Printf(_T("Sog: %g"), mSog);
            dc.DrawText(data, 10, 70);

            data.Printf(_T("Cog: %g"), mCog);
            dc.DrawText(data, 10, 100);*/
      }
}
