/* ----------------------------------------------------------------- */
/*           The Toolkit for Building Voice Interaction Systems      */
/*           "MMDAgent" developed by MMDAgent Project Team           */
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

/* definitions */

#define VIMANAGERLOGGER_LINESTEP   0.85f
#define VIMANAGERLOGGER_TEXTHEIGHT 15
#define VIMANAGERLOGGER_SCALE      0.9f

#define VIMANAGERLOGGER_POSITION1  20.f,17.0f,-16.5f
#define VIMANAGERLOGGER_ROTATE1    -30.0f,0.0f,1.0f,0.0f
#define VIMANAGERLOGGER_WIDTH1     45.0f
#define VIMANAGERLOGGER_HEIGHT1    ((VIMANAGERLOGGER_TEXTHEIGHT + 1) * VIMANAGERLOGGER_LINESTEP)
#define VIMANAGERLOGGER_BGCOLOR1   0.0f,0.0f,0.0f,0.8f
#define VIMANAGERLOGGER_TEXTCOLOR1 0.5f,0.8f,0.0f,1.0f

#define VIMANAGERLOGGER_POSITION2  20.f,3.0f,-16.5f
#define VIMANAGERLOGGER_ROTATE2    -30.0f,0.0f,1.0f,0.0f
#define VIMANAGERLOGGER_WIDTH2     45.0f
#define VIMANAGERLOGGER_HEIGHT2    ((VIMANAGERLOGGER_TEXTHEIGHT + 1) * VIMANAGERLOGGER_LINESTEP)
#define VIMANAGERLOGGER_BGCOLOR2   0.0f,0.0f,0.0f,0.8f
#define VIMANAGERLOGGER_TEXTCOLOR2 0.2f,0.7f,0.5f,1.0f

#define VIMANAGERLOGGER_TEXTCOLOR3 0.7f,0.4f,0.2f,1.0f

/* VIManager_Logger: Debug output VIManager status in OpenGL */
class VIManager_Logger
{
private:

   MMDAgent *m_mmdagent;

   VIManager_Arc *m_history[VIMANAGERLOGGER_TEXTHEIGHT + 1];

   /* drawArc: draw arc string */
   void drawArc(unsigned int from, VIManager_Arc *arc);

   /* drawVariable: draw variable string */
   void drawVariable(VIManager_Variable *v);

   /* initialize: initialize logger */
   void initialize();

   /* clear: free logger */
   void clear();

public:

   /* VIManager_Logger: constructor */
   VIManager_Logger();

   /* ~VIManager_Logger: destructor */
   ~VIManager_Logger();

   /* setup: setup logger */
   void setup(MMDAgent *mmdagent);

   /* setTransition: store state transition */
   bool setTransition(VIManager_Arc *arc);

   /* render: render log */
   void render(VIManager_State *currentState, VIManager_VList *variableList);
};
