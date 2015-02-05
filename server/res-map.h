
/* Copyright (c) 2015 Open Networking Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef RES_MAP_H
#define RES_MAP_H

#include <uuid.h>

/**
 * tuple of resource-id string and UUID
 */
typedef struct ofc_tuple {
    char *resource_id;  /* resource-id */
    struct uuid uuid;   /* UUID */
} ofc_tuple_t;

/**
 * Resource map structure, used for mapping resource-id and UUID
 */
typedef struct ofc_resmap {
    struct ofc_tuple *records;   /* array of records */
    size_t n_records;            /* number of stored records */
    size_t records_length;       /* size of array -- maximal number of records */
    struct ofc_tuple **index_r;  /* resource_id index -- sorted array of pointers */
    struct ofc_tuple **index_u;  /* uuid index -- sorted array of pointers */
} ofc_resmap_t;

/*
 * Initialize resource map structure.
 * \param[in] init_size  initial number of records, will be enlarged when needed
 */
ofc_resmap_t *ofc_resmap_init(size_t init_size);

/*
 * Inserts record into resource map.
 * \param[in] init_size  initial number of records, will be enlarged when needed
 * \return true on success
 */
bool ofc_resmap_insert(ofc_resmap_t *rm, const char *resource_id, const struct uuid *uuid);

bool ofc_resmap_remove_r(ofc_resmap_t *rm, const char *resource_id);
bool ofc_resmap_remove_u(ofc_resmap_t *rm, const struct uuid *uuid);

ofc_tuple_t *ofc_resmap_find_r(ofc_resmap_t *rm, const char *resource_id);
ofc_tuple_t *ofc_resmap_find_u(ofc_resmap_t *rm, const struct uuid *uuid);

/*
 * Free allocated memory, sets poiter to NULL.
 * \param[in,out] rm  pointer to resource map structure
 */
void ofc_resmap_destroy(ofc_resmap_t **rm);

void ofc_resmap_print(ofc_resmap_t *rm);

#endif

