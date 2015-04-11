LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE           := Plugin_Variables
LOCAL_SRC_FILES        := Plugin_Variables.cpp \
                          Variables.cpp \
                          CountDown_Thread.cpp
LOCAL_LDLIBS           := -landroid -lEGL -lGLESv1_CM
LOCAL_STATIC_LIBRARIES := MMDAgent MMDFiles Bullet_Physics JPEG libpng zlib GLFW GLee
LOCAL_C_INCLUDES       := $(INCLUDE_PATH_MMDAGENT) \
                          $(LOCAL_PATH)/../Library_JPEG/include \
                          $(LOCAL_PATH)/../Library_Bullet_Physics/include \
                          $(LOCAL_PATH)/../Library_GLee/include \
                          $(LOCAL_PATH)/../Library_libpng/include \
                          $(LOCAL_PATH)/../Library_zlib/include \
                          $(LOCAL_PATH)/../Library_MMDFiles/include \
                          $(LOCAL_PATH)/../Library_GLFW/include
LOCAL_CFLAGS           += -DMMDAGENT

include $(BUILD_SHARED_LIBRARY)
