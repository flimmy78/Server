#ifndef LOG_MACROS_H
#define LOG_MACROS_H

#define WWFILE strrchr(__FILE__,'\\')?strrchr(__FILE__,'\\')+1:__FILE__
#include "glog.h"
#define VIDEODETECTSERVER_ERROR(fmt, ...)         glog_format(GLOG_LEVEL_ERROR, "VideoDetect", "[%s:%d] " fmt, WWFILE , __LINE__,##__VA_ARGS__)
#define VIDEODETECTSERVER_WARN(fmt, ...)          glog_format(GLOG_LEVEL_WARN, "VideoDetect",  "[%s:%d] " fmt, WWFILE , __LINE__,##__VA_ARGS__)  
#define VIDEODETECTSERVER_INFO(fmt, ...)          glog_format(GLOG_LEVEL_INFO, "VideoDetect",  "[%s:%d] " fmt, WWFILE , __LINE__,##__VA_ARGS__)  
#define VIDEODETECTSERVER_DEBUG(fmt, ...)         glog_format(GLOG_LEVEL_DEBUG, "VideoDetect", "[%s:%d] " fmt, WWFILE , __LINE__,##__VA_ARGS__) 
#define VIDEODETECTSERVER_TRACE(fmt, ...)         glog_format(GLOG_LEVEL_TRACE, "VideoDetect", "[%s:%d] " fmt, WWFILE , __LINE__,##__VA_ARGS__)    

#endif