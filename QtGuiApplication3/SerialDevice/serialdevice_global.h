#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(SERIALDEVICE_LIB)
#  define SERIALDEVICE_EXPORT Q_DECL_EXPORT
# else
#  define SERIALDEVICE_EXPORT Q_DECL_IMPORT
# endif
#else
# define SERIALDEVICE_EXPORT
#endif
