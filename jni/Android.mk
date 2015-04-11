LOCAL_ARM_MODE := arm
LOCAL_ARM_NEON := true
TARGET_ARCH_ABI := armeabi-v7a

INCLUDE_PATH_MMDAGENT := Library_MMDAgent/src/include

include $(call all-subdir-makefiles)
