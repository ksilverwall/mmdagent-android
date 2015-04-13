/* ----------------------------------------------------------------- */
/*           Toolkit for Building Voice Interaction Systems          */
/*           MMDAgent developed by MMDAgent Project Team             */
/*           http://www.mmdagent.jp/                                 */
/* ----------------------------------------------------------------- */
/*                                                                   */
/*  Copyright (c) 2009-2014  Nagoya Institute of Technology          */
/*                           Department of Computer Science          */
/*                                                                   */
/* All rights reserved.                                              */
/*                                                                   */
/* Redistribution and use in source and binary forms, with or        */
/* without modification, are permitted provided that the following   */
/* conditions are met:                                               */
/*                                                                   */
/* - Redistributions of source code must retain the above copyright  */
/*   notice, this list of conditions and the following disclaimer.   */
/* - Redistributions in binary form must reproduce the above         */
/*   copyright notice, this list of conditions and the following     */
/*   disclaimer in the documentation and/or other materials provided */
/*   with the distribution.                                          */
/* - Neither the name of the MMDAgent project team nor the names of  */
/*   its contributors may be used to endorse or promote products     */
/*   derived from this software without specific prior written       */
/*   permission.                                                     */
/*                                                                   */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND            */
/* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,       */
/* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF          */
/* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE          */
/* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS */
/* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,          */
/* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED   */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     */
/* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON */
/* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,   */
/* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY    */
/* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE           */
/* POSSIBILITY OF SUCH DAMAGE.                                       */
/* ----------------------------------------------------------------- */

#ifndef __mmdagent_h__
#define __mmdagent_h__

/* definitions */

#define MMDAGENT_MAXBUFLEN    MMDFILES_MAXBUFLEN
#define MMDAGENT_DIRSEPARATOR MMDFILES_DIRSEPARATOR
#define MMDAGENT_MAXNCOMMAND  10

#ifdef MMDAGENT_OVERWRITEEXEFILE
#define MMDAGENT_EXEFILE(binaryFileName) "%s", MMDAGENT_OVERWRITEEXEFILE
#else
#define MMDAGENT_EXEFILE(binaryFileName) "%s", binaryFileName
#endif /* MMDAGENT_OVERWRITEEXEFILE */

#ifdef MMDAGENT_OVERWRITECONFIGFILE
#define MMDAGENT_CONFIGFILE(configFileName) "%s", MMDAGENT_OVERWRITECONFIGFILE
#else
#define MMDAGENT_CONFIGFILE(configFileName) "%s", configFileName
#endif /* MMDAGENT_OVERWRITECONFIGFILE */

#ifdef MMDAGENT_OVERWRITESYSDATADIR
#define MMDAGENT_SYSDATADIR(binaryDirName) "%s", MMDAGENT_OVERWRITESYSDATADIR
#else
#define MMDAGENT_SYSDATADIR(binaryDirName) "%s%c%s", binaryDirName, MMDAGENT_DIRSEPARATOR, "AppData"
#endif /* MMDAGENT_OVERWRITESYSDATADIR */

#ifdef MMDAGENT_OVERWRITEPLUGINDIR
#define MMDAGENT_PLUGINDIR(binaryDirName) "%s", MMDAGENT_OVERWRITEPLUGINDIR
#else
#define MMDAGENT_PLUGINDIR(binaryDirName) "%s%c%s", binaryDirName, MMDAGENT_DIRSEPARATOR, "Plugins"
#endif /* MMDAGENT_OVERWRITEPLUGINDIR */

/* headers */
#include <string>

#include "MMDFiles.h"

#include "GL/glfw.h"

class MMDAgent;

#include "MMDAgent_utils.h"

#include "TextRenderer.h"
#include "LogText.h"
#include "LipSync.h"
#include "PMDObject.h"

#include "Option.h"
#include "ScreenWindow.h"
#include "Message.h"
#include "TileTexture.h"
#include "Stage.h"
#include "Render.h"
#include "Timer.h"
#include "Plugin.h"
#include "MotionStocker.h"

class MMDAgent
{
private:
   bool m_enable;

   char *m_configFileName;
   char *m_configDirName;
   char *m_appDirName;

   Option *m_option;
   ScreenWindow *m_screen;
   Message *m_message;
   BulletPhysics *m_bullet;
   Plugin *m_plugin;
   Stage *m_stage;
   SystemTexture *m_systex;
   LipSync *m_lipSync;
   Render *m_render;
   Timer *m_timer;
   TextRenderer *m_text;
   LogText *m_logger;

   PMDObject *m_model;
   int *m_renderOrder;
   int m_numModel;
   MotionStocker *m_motion;

   CameraController m_camera;
   bool m_cameraControlled;

   bool m_keyCtrl;
   bool m_keyShift;
   int m_selectedModel;
   int m_highLightingModel;
   bool m_doubleClicked;
   int m_mousePosX;
   int m_mousePosY;
   bool m_leftButtonPressed;
   double m_restFrame;

   bool m_enablePhysicsSimulation;
   bool m_dispLog;
   bool m_dispBulletBodyFlag;
   bool m_dispModelDebug;
   bool m_holdMotion;

   //----------------------------------------

   int getNewModelId();

   void removeRelatedModels(int modelId);

   void updateLight();
   void setHighLight(int modelId);

   bool updateScene();
   bool renderScene();

   bool addModel(const char *modelAlias, const char *fileName, btVector3 *pos, btQuaternion *rot, bool useCartoonRendering, const char *baseModelAlias, const char *baseBoneName);
   bool changeModel(const char *modelAlias, const char *fileName);
   bool deleteModel(const char *modelAlias);

   bool addMotion(const char *modelAlias, const char *motionAlias, const char *fileName, bool full, bool once, bool enableSmooth, bool enableRePos, float priority);
   bool changeMotion(const char *modelAlias, const char *motionAlias, const char *fileName);
   bool accelerateMotion(const char *modelAlias, const char *motionAlias, float speed, float durationTime, float targetTime);
   bool deleteMotion(const char *modelAlias, const char *motionAlias);

   bool startMove(const char *modelAlias, btVector3 *pos, bool local, float speed);
   bool stopMove(const char *modelAlias);

   bool startTurn(const char *modelAlias, btVector3 *pos, bool local, float speed);
   bool stopTurn(const char *modelAlias);

   bool startRotation(const char *modelAlias, btQuaternion *rot, bool local, float spped);
   bool stopRotation(const char *modelAlias);

   bool setFloor(const char *fileName);
   bool setBackground(const char *fileName);
   bool setStage(const char *fileName);

   bool changeCamera(const char *pos, const char *rot, const char *distance, const char *fovy, const char *time);
   bool changeLightColor(float r, float g, float b);
   bool changeLightDirection(float x, float y, float z);

   bool startLipSync(const char *modelAlias, const char *seq);
   bool stopLipSync(const char *modelAlias);

   void procReceivedMessage(const char *type, const char *value);
   void procReceivedLogString(const char *log);

   void initialize();
   void clear();

public:

   struct Command {
      static const std::string MODELADD;
      static const std::string MODELCHANGE;
      static const std::string MODELDELETE;
      static const std::string MOTIONADD;
      static const std::string MOTIONCHANGE;
      static const std::string MOTIONACCELERATE;
      static const std::string MOTIONDELETE;
      static const std::string MOVESTART;
      static const std::string MOVESTOP;
      static const std::string TURNSTART;
      static const std::string TURNSTOP;
      static const std::string ROTATESTART;
      static const std::string ROTATESTOP;
      static const std::string STAGE;
      static const std::string LIGHTCOLOR;
      static const std::string LIGHTDIRECTION;
      static const std::string LIPSYNCSTART;
      static const std::string LIPSYNCSTOP;
      static const std::string CAMERA;
      static const std::string PLUGINENABLE;
      static const std::string PLUGINDISABLE;
   };
   struct Event {
      static const std::string MODELADD;
      static const std::string MODELCHANGE;
      static const std::string MODELDELETE;
      static const std::string MOTIONADD;
      static const std::string MOTIONCHANGE;
      static const std::string MOTIONACCELERATE;
      static const std::string MOTIONDELETE;
      static const std::string MOVESTART;
      static const std::string MOVESTOP;
      static const std::string TURNSTART;
      static const std::string TURNSTOP;
      static const std::string ROTATESTART;
      static const std::string ROTATESTOP;
      static const std::string LIPSYNCSTART;
      static const std::string LIPSYNCSTOP;
      static const std::string PLUGINENABLE;
      static const std::string PLUGINDISABLE;
      static const std::string DRAGANDDROP;
      static const std::string KEY;
   };

   MMDAgent();
   ~MMDAgent();

   bool setup(int argc, char **argv, const char *title);
   bool updateAndRender();
   void drawString(const char *str);
   void resetAdjustmentTimer();

   void sendMessage(const char *type, const char *format, ...);
   void sendLogString(const char *format, ...);
   int findModelAlias(const char *alias);

   PMDObject *getModelList();
   short getNumModel();
   void getMousePosition(int *x, int *y);
   void getScreenPointPosition(btVector3 *dst, btVector3 *src);
   void getWindowSize(int *w, int *h);
   char *getConfigFileName();
   char *getConfigDirName();
   char *getAppDirName();

   //==============================
   //  Message Process Interface
   void procWindowDestroyMessage();
   void procMouseLeftButtonDoubleClickMessage(int x, int y);
   void procMouseLeftButtonDownMessage(int x, int y, bool withCtrl, bool withShift);
   void procMouseLeftButtonUpMessage();
   void procMouseWheelMessage(bool zoomup, bool withCtrl, bool withShift);
   void procMousePosMessage(int x, int y, bool withCtrl, bool withShift);
   void procMouseRightButtonDownMessage();
   void procFullScreenMessage();
   void procInfoStringMessage();
   void procVSyncMessage();
   void procShadowMappingMessage();
   void procShadowMappingOrderMessage();
   void procDisplayRigidBodyMessage();
   void procDisplayWireMessage();
   void procDisplayBoneMessage();
   void procCartoonEdgeMessage(bool plus);
   void procTimeAdjustMessage(bool plus);
   void procHorizontalRotateMessage(bool right);
   void procVerticalRotateMessage(bool up);
   void procHorizontalMoveMessage(bool right);
   void procVerticalMoveMessage(bool up);
   void procDeleteModelMessage();
   void procPhysicsMessage();
   void procDisplayLogMessage();
   void procHoldMessage();
   void procWindowSizeMessage(int x, int y);
   void procKeyMessage(char c);
   void procScrollLogMessage(bool up);
   void procDropFileMessage(const char *file, int x, int y);
};

#endif /* __mmdagent_h__ */
