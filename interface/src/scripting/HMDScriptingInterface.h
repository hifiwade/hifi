//
//  HMDScriptingInterface.h
//  interface/src/scripting
//
//  Created by Thijs Wenker on 1/12/15.
//  Copyright 2015 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#ifndef hifi_HMDScriptingInterface_h
#define hifi_HMDScriptingInterface_h

#include "Application.h"
#include "devices/OculusManager.h"

class HMDScriptingInterface : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool magnifier READ getMagnifier)
    Q_PROPERTY(bool VRMode READ getVRMode)
public:
    static HMDScriptingInterface& getInstance();

public slots:
    void toggleMagnifier() { Application::getInstance()->getApplicationOverlay().toggleMagnifier(); };

private:
    HMDScriptingInterface() {};
    bool getMagnifier() const { return Application::getInstance()->getApplicationOverlay().hasMagnifier(); };
    bool getVRMode() const { return OculusManager::isConnected(); }

};

#endif // hifi_HMDScriptingInterface_h
