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

#ifndef __ATTCALCULATION_H__
#define __ATTCALCULATION_H__


///////////////////////////////////////////////////////////////////////////
#include <wx/string.h>
#include <iostream>
#include <ostream>

///////////////////////////////////////////////////////////////////////////////
/// Class ATTCalculation
///////////////////////////////////////////////////////////////////////////////

enum TideType { SPRING_TIDE=0, MID_TIDE = 1, NIPP_TIDE = 2};


class ATTCalculation
{
private:
    double  calculate_hw( double hwh );
    double  calculate_lw( double lwh );
      
    


double  
calculate_hwdt( double hwt );

double  
calculate_lwdt( double lwt );



void  
get_pair_lw(const double t,  
            double& t1, 
            double&dt1, 
            double &t2, 
            double&dt2 );

void  
get_pair_hw(const double t,  
            double& t1, 
            double&dt1, 
            double &t2, 
            double&dt2 );

int  
get_pair ( const double t, 
           const double& t1, 
           const double& t2, 
           const double& t3, 
           const double& t4);


    
    
    
    
protected:

    wxString error_message;
    

    // all input elements:
//     wxDatePickerCtrl * m_Date;
    TideType m_TideType;
    
    wxString  m_StPName;
    double  m_StPLW1T;
    double  m_StPLW1H;
    double  m_StPHW1T;
    double  m_StPHW1H;
    double  m_StPLW2T;
    double  m_StPLW2H;
    double  m_StPHW2T;
    double  m_StPHW2H;
    
    wxString  m_ScPName;
    double  m_ScPLW1T;
    double  m_ScPLW1H;
    double  m_ScPHW1T;
    double  m_ScPHW1H;
    double  m_ScPLW2T;
    double  m_ScPLW2H;
    double  m_ScPHW2T;
    double  m_ScPHW2H;

    double  m_ScPHWT1;
    double  m_ScPHWT2;
    double  m_ScPHWT3;
    double  m_ScPHWT4;
    
    double  m_ScPLWT1;
    double  m_ScPLWT2;
    double  m_ScPLWT3;
    double  m_ScPLWT4;
    
    double  m_StPMHWS;
    double  m_StPMHWN;
    double  m_StPMLWS;
    double  m_StPMLWN;
    double  m_StPSC;

    double  m_ScPDHWT1;
    double  m_ScPDHWT2;
    double  m_ScPDLWT1;
    double  m_ScPDLWT2;
    
    double  m_ScPMHWS;
    double  m_ScPMHWN;
    double  m_ScPMLWS;
    double  m_ScPMLWN;
    double  m_ScPSC;
    



public:

    ATTCalculation( );
    ~ATTCalculation();
    
    void calculate(); // false if failed to calculate
    wxString& error(); // delivers an error message . "" if ok
    
    inline 
    void
    setTideType( const TideType _t) {  m_TideType = _t;  };
    
    
    inline
    void
    setStPName( const wxString& d) {  m_StPName = d; };   
    
    inline
    void
    setScPName( const wxString& d) {  m_ScPName = d; };   
        
    
    inline
    void
    setStPLW1T( const double d) {  m_StPLW1T = d; };
    
    inline
    void
    setStPLW2T( const double d) {  m_StPLW2T = d; };
    
    inline
    void
    setStPHW1T( const double d) {  m_StPHW1T = d; };
    
    inline
    void
    setStPHW2T( const double d) {  m_StPHW2T = d; };
    
    inline
    void
    setStPLW1H( const double d) {  m_StPLW1H = d; };
    
    inline
    void
    setStPLW2H( const double d) {  m_StPLW2H = d; };
    
    inline
    void
    setStPHW1H( const double d) {  m_StPHW1H = d; };
    
    inline
    void
    setStPHW2H( const double d) {  m_StPHW2H = d; };
    
        
        
    inline
    double
    getScPLW1T( ) {  return m_ScPLW1T; };
   
    inline
    double
    getScPLW2T( ) {  return m_ScPLW2T; };
   
    inline
    double
    getScPHW1T( ) {  return m_ScPHW1T; };
   
    inline
    double
    getScPHW2T( ) {  return m_ScPHW2T; };
   
       
    inline
    double
    getScPLW1H( ) {  return m_ScPLW1H; };
   
    inline
    double
    getScPLW2H( ) {  return m_ScPLW2H; };
   
    inline
    double
    getScPHW1H( ) {  return m_ScPHW1H; };
   
    inline
    double
    getScPHW2H( ) {  return m_ScPHW2H; };
   
  
    
    
    
    
    inline
    void
    setScPHWT1( const double d) {  m_ScPHWT1 = d; };
    
    inline
    void
    setScPHWT2( const double d) {  m_ScPHWT2= d; };
    
    inline
    void
    setScPHWT3( const double d) {  m_ScPHWT3 = d; };
    
    inline
    void
    setScPHWT4( const double d) {  m_ScPHWT4 = d; };
    
     
    inline
    void
    setScPLWT1( const double d) {  m_ScPLWT1 = d; };
    
    inline
    void
    setScPLWT2( const double d) {  m_ScPLWT2= d; };
    
    inline
    void
    setScPLWT3( const double d) {  m_ScPLWT3 = d; };
    
    inline
    void
    setScPLWT4( const double d) {  m_ScPLWT4 = d; };
    
    
    
    inline
    void
    setStPMHWS( const double d) {  m_StPMHWS = d; };
    
    inline
    void
    setStPMHWN( const double d) {  m_StPMHWN= d; };
    
    inline
    void
    setStPMLWS( const double d) {  m_StPMLWS = d; };
    
    inline
    void
    setStPMLWN( const double d) {  m_StPMLWN = d; };
     
    inline
    void
    setStPSC( const double d) {  m_StPSC = d; };

    
    
    
    inline
    void
    setScPDHWT1( const double d) {  m_ScPDHWT1 = d; };
    
    inline
    void
    setScPDHWT2( const double d) {  m_ScPDHWT2= d; };
    
    inline
    void
    setScPDLWT1( const double d) {  m_ScPDLWT1 = d; };
    
    inline
    void
    setScPDLWT2( const double d) {  m_ScPDLWT2 = d; };

    
    inline
    void
    setScPMHWS( const double d) {  m_ScPMHWS = d; };
    
    inline
    void
    setScPMHWN( const double d) {  m_ScPMHWN= d; };
    
    inline
    void
    setScPMLWS( const double d) {  m_ScPMLWS = d; };
    
    inline
    void
    setScPMLWN( const double d) {  m_ScPMLWN = d; };
     
    inline
    void
    setScPSC( const double d) {  m_ScPSC = d; };
    
    friend
    std::ostream& operator<<(std::ostream&, const ATTCalculation&);
    
    
    
};



#endif //__ATTCALCULATION_H__

