/**
 *   === Fil compiler ===
 * Created by Kevin Traini
 *      Under GPL-3.0
 * -----------------------
 */
#ifndef FILC_VERSION_H
#define FILC_VERSION_H

#define FILC_VERSION_MAJOR 0
#define FILC_VERSION_MINOR 1
#define FILC_VERSION_PATCH 0

#define MAKE_VERSION(major, minor, patch) ((major) * 1000000 + (minor) * 1000 + (patch))

#define FILC_VERSION MAKE_VERSION(FILC_VERSION_MAJOR, FILC_VERSION_MINOR, FILC_VERSION_PATCH)
#define FILC_VERSION_STRING "0.1.0"

#endif //FILC_VERSION_H
