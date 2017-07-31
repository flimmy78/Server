
#ifndef __GLOG_H__
#define __GLOG_H__

#if (defined _WIN32 || defined _WIN64)
#   ifdef GLOG_EXPORTS
#       define GLOG_DECLARE extern "C" __declspec(dllexport)
#   else
#		pragma comment(lib, "log.lib")
#       define GLOG_DECLARE extern "C" __declspec(dllimport)
#   endif
#   define GLOG_API __stdcall
#else
#   ifdef __linux__
#       define GLOG_DECLARE extern "C"
#   else
#       define GLOG_DECLARE
#   endif
#   define GLOG_API
#endif

/** @enum GLOG_LEVEL
 *  @brief ��־����
 */
typedef enum {
    GLOG_LEVEL_OFF    = 7,
    GLOG_LEVEL_FATAL  = 6,
    GLOG_LEVEL_ERROR  = 5,
    GLOG_LEVEL_WARN   = 4,
    GLOG_LEVEL_INFO   = 3,
    GLOG_LEVEL_DEBUG  = 2,
    GLOG_LEVEL_TRACE  = 1,
    GLOG_LEVEL_ALL    = 0
} GLOG_LEVEL;

#ifdef __GNUC__
#define LOG_CHECK_FMT(a, b) __attribute__((format(printf, a, b)))
#define CALLBACK
#else
#define LOG_CHECK_FMT(a, b)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    typedef void (GLOG_API *GLOG_CB)(GLOG_LEVEL level, const char* message);

    /** @fn void glog_init(const char* name, bool async = false)
    *   @brief ��־��Ϣ��ʼ��
    *   @param name ���ƣ���־�ļ���ǰ׺�������ļ�xxx.log4cxx��xxx���֣�Ҳ������log4cxx.properties��log4cxx.xml
    *   @param async �Ƿ������첽д��־����
    */
    GLOG_DECLARE void GLOG_API glog_init(const char* name, bool async = false);

    /** @fn void glog_ocx_init(const char* name, const char* path, bool async = false)
    *   @brief ��־��Ϣ��ʼ��
    *   @param name ���ƣ���־�ļ���ǰ׺�������ļ�xxx.log4cxx��xxx���֣�Ҳ������log4cxx.properties��log4cxx.xml
    *   @param path �����ļ�·��,path��󲻱ؼ�"/"
    *   @param async �Ƿ������첽д��־����
    */
    GLOG_DECLARE void GLOG_API glog_ocx_init(const char* name, const char* path, bool async = false);

    /** @fn void glog_fini()
    *   @brief ��־ϵͳ����ʼ��
    */
    GLOG_DECLARE void GLOG_API glog_fini();

    /** @fn void glog_set_callback(GLOG_CB callback)
    *   @brief ������־�Ļص�����
    *   @param callback ���ڴ�����־��Ϣ�Ļص�����
    */
    GLOG_DECLARE void GLOG_API glog_set_callback(GLOG_CB callback);

    /** @fn void glog_level(GLOG_LEVEL level)
    *   @brief ������־���������
    *   @param level ��־����
    */
    GLOG_DECLARE void GLOG_API glog_level(GLOG_LEVEL level);

    /** @fn void glog_format(GLOG_LEVEL level, const char* module, const char* format, ...)
    *   @brief д��־��ʽ������
    *   @param level ��־����
    *   @param module ��־ģ��
    *   @param format ��־��ʽ���ַ�������ӿɱ����
    *   @note glog_format�����glog_set_callback����Ļص�����
    */
    GLOG_DECLARE void GLOG_API glog_format(GLOG_LEVEL level, const char* module, const char* format, ...) LOG_CHECK_FMT(3, 4);

    /** @fn void glog_message(GLOG_LEVEL level, const char* module, const char* message)
    *   @brief д��־�ַ���
    *   @param level ��־����
    *   @param module ��־ģ��
    *   @param message ��־�ַ���
    *   @note glog_message�������glog_set_callback����Ļص�����
    */
    GLOG_DECLARE void GLOG_API glog_message(GLOG_LEVEL level, const char* module, const char* message);

#ifdef __cplusplus
}
#endif

// ���Ǽ����ԣ�������log_printf_def��log_printf_dst
#if (defined _WIN32 || defined _WIN64)
#define log_printf_def(level, format, ...)      glog_format(level, "", format, ##__VA_ARGS__)
#else
#define log_printf_def(level, format, args...)  glog_format(level, "", format, ##args)
#endif
#define log_printf_dst glog_format

// for defualt module
#if (defined _WIN32 || defined _WIN64)
    #define LOG_ERROR(fmt, ...)         glog_format(GLOG_LEVEL_ERROR, "", "<%d>\t<%s>,"fmt, __LINE__, __FUNCTION__, ##__VA_ARGS__)
    #define LOG_WARN(fmt, ...)          glog_format(GLOG_LEVEL_WARN, "", "<%d>\t<%s>,"fmt,  __LINE__, __FUNCTION__, ##__VA_ARGS__)    
    #define LOG_INFO(fmt, ...)          glog_format(GLOG_LEVEL_INFO, "", "<%d>\t<%s>,"fmt,  __LINE__, __FUNCTION__, ##__VA_ARGS__)    
    #define LOG_DEBUG(fmt, ...)         glog_format(GLOG_LEVEL_DEBUG, "", "<%d>\t<%s>,"fmt, __LINE__, __FUNCTION__, ##__VA_ARGS__)    
    #define LOG_TRACE(fmt, ...)         glog_format(GLOG_LEVEL_TRACE, "", "<%d>\t<%s>,"fmt, __LINE__, __FUNCTION__, ##__VA_ARGS__)    
#else
    #define LOG_ERROR(fmt, args...)     glog_format(GLOG_LEVEL_ERROR, "", "<%s>|<%d>\t<%s>,"fmt, __FILE__, __LINE__, __FUNCTION__, ##args)
    #define LOG_WARN(fmt, args...)      glog_format(GLOG_LEVEL_WARN, "", "<%s>|<%d>\t<%s>,"fmt,  __FILE__, __LINE__, __FUNCTION__, ##args)
    #define LOG_INFO(fmt, args...)      glog_format(GLOG_LEVEL_INFO, "", "<%s>|<%d>\t<%s>,"fmt,  __FILE__, __LINE__, __FUNCTION__, ##args)
    #define LOG_DEBUG(fmt, args...)     glog_format(GLOG_LEVEL_DEBUG, "", "<%s>|<%d>\t<%s>,"fmt, __FILE__, __LINE__, __FUNCTION__, ##args)
    #define LOG_TRACE(fmt, args...)     glog_format(GLOG_LEVEL_TRACE, "", "<%s>|<%d>\t<%s>,"fmt, __FILE__, __LINE__, __FUNCTION__, ##args)
#endif

// for HPP module
#if (defined _WIN32 || defined _WIN64)
    #define HPP_ERROR(fmt, ...)         glog_format(GLOG_LEVEL_ERROR, "HPP", "<%d>\t<%s>,"fmt, __LINE__, __FUNCTION__, ##__VA_ARGS__)
    #define HPP_WARN(fmt, ...)          glog_format(GLOG_LEVEL_WARN, "HPP", "<%d>\t<%s>,"fmt,  __LINE__, __FUNCTION__, ##__VA_ARGS__)    
    #define HPP_INFO(fmt, ...)          glog_format(GLOG_LEVEL_INFO, "HPP", "<%d>\t<%s>,"fmt,  __LINE__, __FUNCTION__, ##__VA_ARGS__)    
    #define HPP_DEBUG(fmt, ...)         glog_format(GLOG_LEVEL_DEBUG, "HPP", "<%d>\t<%s>,"fmt, __LINE__, __FUNCTION__, ##__VA_ARGS__)    
    #define HPP_TRACE(fmt, ...)         glog_format(GLOG_LEVEL_TRACE, "HPP", "<%d>\t<%s>,"fmt, __LINE__, __FUNCTION__, ##__VA_ARGS__)    
#else
    #define HPP_ERROR(fmt, args...)     glog_format(GLOG_LEVEL_ERROR, "HPP", "<%s>|<%d>\t<%s>,"fmt, __FILE__, __LINE__, __FUNCTION__, ##args)
    #define HPP_WARN(fmt, args...)      glog_format(GLOG_LEVEL_WARN, "HPP", "<%s>|<%d>\t<%s>,"fmt,  __FILE__, __LINE__, __FUNCTION__, ##args)
    #define HPP_INFO(fmt, args...)      glog_format(GLOG_LEVEL_INFO, "HPP", "<%s>|<%d>\t<%s>,"fmt,  __FILE__, __LINE__, __FUNCTION__, ##args)
    #define HPP_DEBUG(fmt, args...)     glog_format(GLOG_LEVEL_DEBUG, "HPP", "<%s>|<%d>\t<%s>,"fmt, __FILE__, __LINE__, __FUNCTION__, ##args)
    #define HPP_TRACE(fmt, args...)     glog_format(GLOG_LEVEL_TRACE, "HPP", "<%s>|<%d>\t<%s>,"fmt, __FILE__, __LINE__, __FUNCTION__, ##args)
#endif

// for MQ module
#if (defined _WIN32 || defined _WIN64)
    #define MQ_ERROR(fmt, ...)          glog_format(GLOG_LEVEL_ERROR, "MQ", "<%d>\t<%s>,"fmt, __LINE__, __FUNCTION__, ##__VA_ARGS__)
    #define MQ_WARN(fmt, ...)           glog_format(GLOG_LEVEL_WARN, "MQ", "<%d>\t<%s>,"fmt,  __LINE__, __FUNCTION__, ##__VA_ARGS__)    
    #define MQ_INFO(fmt, ...)           glog_format(GLOG_LEVEL_INFO, "MQ", "<%d>\t<%s>,"fmt,  __LINE__, __FUNCTION__, ##__VA_ARGS__)    
    #define MQ_DEBUG(fmt, ...)          glog_format(GLOG_LEVEL_DEBUG, "MQ", "<%d>\t<%s>,"fmt, __LINE__, __FUNCTION__, ##__VA_ARGS__)    
    #define MQ_TRACE(fmt, ...)          glog_format(GLOG_LEVEL_TRACE, "MQ", "<%d>\t<%s>,"fmt, __LINE__, __FUNCTION__, ##__VA_ARGS__)    
#else
    #define MQ_ERROR(fmt, args...)      glog_format(GLOG_LEVEL_ERROR, "MQ", "<%s>|<%d>\t<%s>,"fmt, __FILE__, __LINE__, __FUNCTION__, ##args)
    #define MQ_WARN(fmt, args...)       glog_format(GLOG_LEVEL_WARN, "MQ", "<%s>|<%d>\t<%s>,"fmt,  __FILE__, __LINE__, __FUNCTION__, ##args)
    #define MQ_INFO(fmt, args...)       glog_format(GLOG_LEVEL_INFO, "MQ", "<%s>|<%d>\t<%s>,"fmt,  __FILE__, __LINE__, __FUNCTION__, ##args)
    #define MQ_DEBUG(fmt, args...)      glog_format(GLOG_LEVEL_DEBUG, "MQ", "<%s>|<%d>\t<%s>,"fmt, __FILE__, __LINE__, __FUNCTION__, ##args)
    #define MQ_TRACE(fmt, args...)      glog_format(GLOG_LEVEL_TRACE, "MQ", "<%s>|<%d>\t<%s>,"fmt, __FILE__, __LINE__, __FUNCTION__, ##args)
#endif

#endif // __GLOG_H__
