/*
 * demo.h
 *
 *  Created on: Aug 20, 2015
 *      Author: yankai
 */

#ifndef SRC_NAVIGATOR_H_
#define SRC_NAVIGATOR_H_

#include <cstdio>
#include <cmath>
#include <cstdarg>

#include "../AI/_SegNet.h"
#include "../Autopilot/_AutoPilot.h"
#include "../Camera/CamInput.h"
#include "../Interface/_MavlinkInterface.h"
#include "../UI/UIMonitor.h"
#include "../Utility/util.h"
#include "../Image/_DenseFlow.h"
#include "../Detector/_FeatureDetector.h"
#include "../Detector/_DepthDetector.h"
#include "../Detector/_MarkerDetector.h"
#include "../Image/_3DFlow.h"
#include "../Tracker/_ROITracker.h"

#define APP_NAME "NAVIGATOR"

using namespace kai;

namespace kai
{

class Navigator
{
public:
	Navigator();
	~Navigator();

	int m_key;
	bool m_bRun;

	_CamStream* m_pCamFront;
	_AutoPilot* m_pAP;
	_MavlinkInterface* m_pMavlink;
	_CascadeDetector* m_pCascade;
	_DenseFlow* m_pDF;
	_FeatureDetector* m_pFeature;
	_3DFlow* m_p3DFlow;
	_ROITracker* m_pROITracker;
	_SegNet* m_pSegNet;
	_DepthDetector* m_pDD;
	_MarkerDetector* m_pMD;

	CamFrame* m_pShow;
	CamFrame* m_pMat;
	CamFrame* m_pMat2;
	UIMonitor* m_pUIMonitor;

	bool start(JSON* pJson);
	void showScreen(void);

	void handleMouse(int event, int x, int y, int flags);
	void showInfo(UMat* pDisplayMat);
	void handleKey(int key);

};

}
#endif
