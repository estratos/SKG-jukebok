#ifndef CDIO_GLOBAL_H
#define CDIO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CDIO_LIBRARY)
#  define CDIOSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CDIOSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CDIO_GLOBAL_H
