LIB_JULIUS = jni/Library_Julius

all:
	@echo "-------------------------------------------------------------------------------------------------------"
	@echo "  make android          to compile MMDAgent for Android"
	@echo "  make android-clean    to remove any files generated for Android"
	@echo "-------------------------------------------------------------------------------------------------------"

${LIB_JULIUS}/include/julius/config.h: ${LIB_JULIUS}/src/libjulius/include/julius/config.h.in
	echo '#define JULIUS_PRODUCTNAME ""'   >  ${LIB_JULIUS}/include/julius/config.h
	echo '#define JULIUS_VERSION "4.3"'    >> ${LIB_JULIUS}/include/julius/config.h
	echo '#define JULIUS_SETUP "fast"'     >> ${LIB_JULIUS}/include/julius/config.h
	echo '#define JULIUS_HOSTINFO ""'      >> ${LIB_JULIUS}/include/julius/config.h
	echo '#define RETSIGTYPE void'         >> ${LIB_JULIUS}/include/julius/config.h
	echo '#define STDC_HEADERS 1'          >> ${LIB_JULIUS}/include/julius/config.h
	echo '#define UNIGRAM_FACTORING 1'     >> ${LIB_JULIUS}/include/julius/config.h
	echo '#define LOWMEM2 1'               >> ${LIB_JULIUS}/include/julius/config.h
	echo '#define PASS1_IWCD 1'            >> ${LIB_JULIUS}/include/julius/config.h
	echo '#define SCAN_BEAM 1'             >> ${LIB_JULIUS}/include/julius/config.h
	echo '#define GPRUNE_DEFAULT_BEAM 1'   >> ${LIB_JULIUS}/include/julius/config.h
	echo '#define CONFIDENCE_MEASURE 1'    >> ${LIB_JULIUS}/include/julius/config.h
	echo '#define LM_FIX_DOUBLE_SCORING 1' >> ${LIB_JULIUS}/include/julius/config.h
	echo '#define GRAPHOUT_DYNAMIC 1'      >> ${LIB_JULIUS}/include/julius/config.h
	echo '#define GRAPHOUT_SEARCH 1'       >> ${LIB_JULIUS}/include/julius/config.h
	echo '#define HAVE_STRCASECMP 1'       >> ${LIB_JULIUS}/include/julius/config.h

${LIB_JULIUS}/include/sent/config.h: ${LIB_JULIUS}/src/libsent/include/sent/config.h.in
	echo '#define LIBSENT_VERSION "4.3"'   >  ${LIB_JULIUS}/include/sent/config.h
	echo '#define AUDIO_API_NAME ""'       >> ${LIB_JULIUS}/include/sent/config.h
	echo '#define AUDIO_API_DESC ""'       >> ${LIB_JULIUS}/include/sent/config.h
	echo '#define AUDIO_FORMAT_DESC ""'    >> ${LIB_JULIUS}/include/sent/config.h
	echo '#define GZIP_READING_DESC ""'    >> ${LIB_JULIUS}/include/sent/config.h
	echo '#define STDC_HEADERS 1'          >> ${LIB_JULIUS}/include/sent/config.h
	echo '#define USE_MIC 1'               >> ${LIB_JULIUS}/include/sent/config.h
	echo '#define USE_ADDLOG_ARRAY 1'      >> ${LIB_JULIUS}/include/sent/config.h
	echo '#define HAVE_SOCKLEN_T 1'        >> ${LIB_JULIUS}/include/sent/config.h
	echo '#define HAVE_UNISTD_H 1'         >> ${LIB_JULIUS}/include/sent/config.h
	echo '#define HAVE_ZLIB 1'             >> ${LIB_JULIUS}/include/sent/config.h
	echo '#define HAVE_STRCASECMP 1'       >> ${LIB_JULIUS}/include/sent/config.h
	echo '#define HAVE_SLEEP 1'            >> ${LIB_JULIUS}/include/sent/config.h
	echo '#define CLASS_NGRAM 1'           >> ${LIB_JULIUS}/include/sent/config.h
	echo '#define MFCC_SINCOS_TABLE 1'     >> ${LIB_JULIUS}/include/sent/config.h

android: ${LIB_JULIUS}/include/julius/config.h ${LIB_JULIUS}/include/sent/config.h
	ndk-build NDK_DEBUG=0

android-clean:
	rm -f ${LIB_JULIUS}/include/julius/config.h ${LIB_JULIUS}/include/sent/config.h
	ndk-build clean
