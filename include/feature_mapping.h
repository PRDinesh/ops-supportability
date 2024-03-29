
/* Feature Mapping Header file
 * Copyright (C) 2016 Hewlett Packard Enterprise Development LP
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * File: feature_mapping.h
 *
 * Purpose: header file for feature_mapping.c
 */

#ifndef __FEATURE_MAPPING_H
#define __FEATURE_MAPPING_H

#define FEATURE_MAPPING_CONF   "/etc/openswitch/supportability/ops_featuremapping.yaml"
#define FEATURE_SIZE           20



struct daemon {
   char* name;
   struct daemon* next;
};

struct feature {
   char* name;
   char* desc;
   struct daemon*   p_daemon;
   struct feature*   next;
};

enum  {
   VALUE,
   FEATURE_NAME,
   FEATURE_DESC,
   DAEMON,
   MAX_NUM_KEYS
} ;


struct feature* get_feature_mapping(void);

#endif  /* __FEATURE_MAPPING_H */
