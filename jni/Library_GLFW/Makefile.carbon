
TARGET   = lib/GLFW.a

SOURCES  = src/lib/enable.c \
           src/lib/fullscreen.c \
           src/lib/glext.c \
           src/lib/image.c \
           src/lib/init.c \
           src/lib/input.c \
           src/lib/joystick.c \
           src/lib/stream.c \
           src/lib/tga.c \
           src/lib/thread.c \
           src/lib/time.c \
           src/lib/window.c \
           src/lib/carbon/carbon_enable.c \
           src/lib/carbon/carbon_fullscreen.c \
           src/lib/carbon/carbon_glext.c \
           src/lib/carbon/carbon_init.c \
           src/lib/carbon/carbon_joystick.c \
           src/lib/carbon/carbon_thread.c \
           src/lib/carbon/carbon_time.c \
           src/lib/carbon/carbon_window.c

OBJECTS  = $(SOURCES:.c=.o)

CXX      = gcc
AR       = ar
CXXFLAGS = -Wall -O3 -fomit-frame-pointer -m32 \
           -fno-common \
           -DMMDAGENT
INCLUDE  = -I src/include \
           -I src/lib \
           -I src/lib/carbon

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) cru $(TARGET) $(OBJECTS)
	cp src/include/GL/glfw.h include/GL/glfw.h

.c.o:
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(<:.c=.o) -c $<

clean:
	rm -f $(OBJECTS) $(TARGET)
