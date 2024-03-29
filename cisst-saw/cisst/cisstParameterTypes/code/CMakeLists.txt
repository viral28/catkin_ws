#
# (C) Copyright 2003-2015 Johns Hopkins University (JHU), All Rights Reserved.
#
# --- begin cisst license - do not edit ---
#
# This software is provided "as is" under an open source license, with
# no warranty.  The complete license can be found in license.txt and
# http://www.cisst.org/cisst/license.txt.
#
# --- end cisst license ---

project (cisstParameterTypes)

# create data type using the data generator
cisst_data_generator (cisstParameterTypes
                      "${cisst_BINARY_DIR}/include" # where to save the file
                      "cisstParameterTypes/"        # sub directory for include
                      ../prmActuatorJointCoupling.cdg
                      ../prmPositionCartesianGet.cdg
                      ../prmPositionJointGet.cdg
                      ../prmFixtureGainCartesianSet.cdg
                      ../prmIMUSensors.cdg
                      ../prmStateJoint.cdg)

# to compile cisst generated code, need to find header file
include_directories (${CMAKE_CURRENT_BINARY_DIR})


# all source files
set (SOURCE_FILES
     prmEventButton.cpp
     prmMotionBase.cpp

     prmPositionJointSet.cpp
     prmVelocityJointGet.cpp
     prmVelocityJointSet.cpp
     prmForceTorqueJointSet.cpp

     prmPositionCartesianSet.cpp
     prmVelocityCartesianGet.cpp
     prmVelocityCartesianSet.cpp
     prmForceCartesianGet.cpp
     prmForceCartesianSet.cpp

     prmTransformationBase.cpp
     prmTransformationFixed.cpp
     prmTransformationDynamic.cpp
     prmTransformationManager.cpp

     prmActuatorState.cpp
     prmRobotState.cpp
     prmSimulinkDataPacket.cpp
     prmSocketDataPacket.cpp
     prmTwoWaySocket.cpp
     prmActuatorParameters.cpp

     prmClassServices.cpp
     )

# all header files
set (HEADER_FILES
     prmEventButton.h
     prmExport.h
     prmForwardDeclarations.h
     prmMotionBase.h
     prmJointType.h

     prmPositionJointSet.h
     prmVelocityJointGet.h
     prmVelocityJointSet.h
     prmForceTorqueJointSet.h

     prmPositionCartesianSet.h
     prmVelocityCartesianGet.h
     prmVelocityCartesianSet.h
     prmForceCartesianGet.h
     prmForceCartesianSet.h

     prmTransformationBase.h
     prmTransformationFixed.h
     prmTransformationDynamic.h
     prmTransformationManager.h

     prmMaskedVector.h
     prmActuatorState.h
     prmRobotState.h
     prmSimulinkDataPacket.h
     prmSocketDataPacket.h
     prmTwoWaySocket.h
     prmActuatorParameters.h
     prmGainParameters.h
     )

cisst_add_library (LIBRARY cisstParameterTypes
                   FOLDER cisstParameterTypes
                   DEPENDENCIES cisstCommon cisstVector cisstOSAbstraction cisstMultiTask
                   SOURCE_FILES ${SOURCE_FILES}
                   HEADER_FILES ${HEADER_FILES}
                   ADDITIONAL_SOURCE_FILES ${cisstParameterTypes_CISST_DG_SRCS}
                   ADDITIONAL_HEADER_FILES_RELATIVE ${cisstParameterTypes_CISST_DG_HDRS}
                   )

install (FILES ${cisstParameterTypes_CISST_DG_HDRS_FULLPATH}
         DESTINATION "include/cisstParameterTypes")
