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
#include <wx/datetime.h>
#include <iostream>
#include <ostream>
#include "ATTStandardPort.h"
#include "ATTSecondaryPort.h"
///////////////////////////////////////////////////////////////////////////////
/// Class ATTCalculation
///////////////////////////////////////////////////////////////////////////////



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
    wxDateTime m_Date;
    
    ATTStandardPort m_StP;
    ATTSecondaryPort m_ScP;
    

 
    double  m_ScPLW1T;
    double  m_ScPLW1H;
    double  m_ScPHW1T;
    double  m_ScPHW1H;
    double  m_ScPLW2T;
    double  m_ScPLW2H;
    double  m_ScPHW2T;
    double  m_ScPHW2H;




public:

    ATTCalculation( );
    ~ATTCalculation();
    
    void calculate(); // false if failed to calculate
    wxString& error(); // delivers an error message . "" if ok
    

    inline
    void
    setStPName( const wxString& d) {  m_StP.m_StPName = d; };   
    
    inline
    void
    setScPName( const wxString& d) {  m_ScP.m_ScPName = d; };   
        
    
    inline
    void
    setStPLW1T( const double d) {  m_StP.m_StPLW1T = d; };
    
    inline
    void
    setStPLW2T( const double d) {  m_StP.m_StPLW2T = d; };
    
    inline
    void
    setStPHW1T( const double d) {  m_StP.m_StPHW1T = d; };
    
    inline
    void
    setStPHW2T( const double d) { m_StP.m_StPHW2T = d; };
    
    inline
    void
    setStPLW1H( const double d) {  m_StP.m_StPLW1H = d; };
    
    inline
    void
    setStPLW2H( const double d) {  m_StP.m_StPLW2H = d; };
    
    inline
    void
    setStPHW1H( const double d) {  m_StP.m_StPHW1H = d; };
    
    inline
    void
    setStPHW2H( const double d) {  m_StP.m_StPHW2H = d; };
    
        
        
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
    setScPHWT1( const double d) {  m_ScP.m_ScPHWT1 = d; };
    
    inline
    void
    setScPHWT2( const double d) {   m_ScP.m_ScPHWT2= d; };
    
    inline
    void
    setScPHWT3( const double d) {   m_ScP.m_ScPHWT3 = d; };
    
    inline
    void
    setScPHWT4( const double d) {  m_ScP. m_ScPHWT4 = d; };
    
     
    inline
    void
    setScPLWT1( const double d) {   m_ScP.m_ScPLWT1 = d; };
    
    inline
    void
    setScPLWT2( const double d) {   m_ScP.m_ScPLWT2= d; };
    
    inline
    void
    setScPLWT3( const double d) {   m_ScP.m_ScPLWT3 = d; };
    
    inline
    void
    setScPLWT4( const double d) {   m_ScP.m_ScPLWT4 = d; };
    
    
    
    inline
    void
    setStPMHWS( const double d) {   m_ScP.m_StPMHWS = d; };
    
    inline
    void
    setStPMHWN( const double d) {   m_ScP.m_StPMHWN= d; };
    
    inline
    void
    setStPMLWS( const double d) {  m_ScP.m_StPMLWS = d; };
    
    inline
    void
    setStPMLWN( const double d) {  m_ScP.m_StPMLWN = d; };
     
    inline
    void
    setStPSC( const double d) {   m_ScP.m_StPSC = d; };

    
    
    
    inline
    void
    setScPDHWT1( const double d) {   m_ScP.m_ScPDHWT1 = d; };
    
    inline
    void
    setScPDHWT2( const double d) {   m_ScP.m_ScPDHWT2= d; };
    
    inline
    void
    setScPDLWT1( const double d) {   m_ScP.m_ScPDLWT1 = d; };
    
    inline
    void
    setScPDLWT2( const double d) {   m_ScP.m_ScPDLWT2 = d; };

    
    inline
    void
    setScPMHWS( const double d) {  m_ScP.m_ScPMHWS = d; };
    
    inline
    void
    setScPMHWN( const double d) {  m_ScP.m_ScPMHWN= d; };
    
    inline
    void
    setScPMLWS( const double d) {   m_ScP.m_ScPMLWS = d; };
    
    inline
    void
    setScPMLWN( const double d) {   m_ScP.m_ScPMLWN = d; };
     
    inline
    void
    setScPSC( const double d) {   m_ScP.m_ScPSC = d; };
    
    friend
    std::ostream& operator<<(std::ostream&, const ATTCalculation&);
    
    
    
};



#endif //__ATTCALCULATION_H__

