/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-    */
/* ex: set filetype=cpp softtabstop=4 shiftwidth=4 tabstop=4 cindent expandtab: */

/*
  
  Author(s):	Anton Deguet
  Created on:	2009-02-06

  (C) Copyright 2009 Johns Hopkins University (JHU), All Rights
  Reserved.

--- begin cisst license - do not edit ---

This software is provided "as is" under an open source license, with
no warranty.  The complete license can be found in license.txt and
http://www.cisst.org/cisst/license.txt.

--- end cisst license ---
*/


/*! 
  \file 
  \brief Cartesian force get parameters.
*/


#ifndef _prmForceCartesianGet_h
#define _prmForceCartesianGet_h

#include <cisstVector/vctFixedSizeVectorTypes.h>
#include <cisstMultiTask/mtsGenericObject.h>

// Always include last
#include <cisstParameterTypes/prmExport.h>

/*! Cartesian force get command argument */
class CISST_EXPORT prmForceCartesianGet: public mtsGenericObject
{
    CMN_DECLARE_SERVICES(CMN_DYNAMIC_CREATION, CMN_LOG_ALLOW_DEFAULT);

 public:
    typedef mtsGenericObject BaseType;

    /*! default constructor */
    inline prmForceCartesianGet(void):
        mtsGenericObject()
    {}
    
    /*! constructor with all parameters */
    inline prmForceCartesianGet(const vctDouble6 & force):
        ForceMember(force)
    {
        this->MaskMember.SetAll(true);
    }
    
    /*!destructor
     */
    virtual ~prmForceCartesianGet();
    
    /*! Set and Get methods for force */
    //@{
    CMN_DECLARE_MEMBER_AND_ACCESSORS(vctDouble6, Force);
    //@}


    /*! Set and Get methods for mask */
    //@{
    CMN_DECLARE_MEMBER_AND_ACCESSORS(vctBool6, Mask);
    //@}

public:

    /*! Human readable output to stream. */
    void ToStream(std::ostream & outputStream) const;

    /*! To stream raw data. */
    void ToStreamRaw(std::ostream & outputStream, const char delimiter = ' ',
                     bool headerOnly = false, const std::string & headerPrefix = "") const;
    
    /*! Binary serialization */
    void SerializeRaw(std::ostream & outputStream) const;

    /*! Binary deserialization */
    void DeSerializeRaw(std::istream & inputStream);

}; // _prmForceCartesianGet_h


CMN_DECLARE_SERVICES_INSTANTIATION(prmForceCartesianGet);


#endif // _prmForceCartesianGet_h

