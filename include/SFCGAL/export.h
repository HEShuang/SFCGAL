#ifndef _SFCGAL_EXPORT_H_
#define _SFCGAL_EXPORT_H_

#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
     #define SFCGAL_API_IMPORT __declspec(dllimport)
     #define SFCGAL_API_EXPORT __declspec(dllexport)

     #define SFCGAL_API_TEMPLATE_EXPORT extern
     #define SFCGAL_API_TEMPLATE_IMPORT
#else
     #define SFCGAL_API_IMPORT
     #define SFCGAL_API_EXPORT
     #define SFCGAL_API_TEMPLATE_EXPORT
     #define SFCGAL_API_TEMPLATE_IMPORT
#endif

#endif

