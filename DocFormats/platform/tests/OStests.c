// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#include "DFUnitTest.h"
#include "DFPlatform.h"
#include <stddef.h>
#include <stdlib.h>

static void test_DFGetImageDimensions_gif(void)
{
    // Bullet.gif 21x15
    static unsigned char data_bullet[] = {
        0x47, 0x49, 0x46, 0x38, 0x39, 0x61, 0x15, 0x00, 0x0F, 0x00, 0xB3, 0x00, 0x00, 0xFB, 0xCF, 0x57,
        0xFA, 0xD3, 0x5F, 0xFA, 0xD6, 0x66, 0xFC, 0xBE, 0x38, 0xFD, 0xBA, 0x30, 0xFC, 0xC2, 0x3F, 0xFB,
        0xCB, 0x50, 0xFD, 0xB7, 0x29, 0xF9, 0xD9, 0x6C, 0xFE, 0xB1, 0x1E, 0xFE, 0xB4, 0x23, 0xFB, 0xC7,
        0x48, 0xFE, 0xAF, 0x1A, 0xF9, 0xDC, 0x71, 0xF3, 0x9A, 0x00, 0x00, 0x00, 0x00, 0x21, 0xF9, 0x04,
        0x01, 0x00, 0x00, 0x0E, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x15, 0x00, 0x0F, 0x00, 0x00, 0x04,
        0x30, 0xD0, 0xC9, 0x49, 0xAB, 0xBD, 0x38, 0xEB, 0xCD, 0xBB, 0xFF, 0x20, 0x00, 0x52, 0x40, 0x30,
        0x4A, 0xA5, 0x90, 0x31, 0x89, 0x72, 0x10, 0x43, 0xB1, 0x18, 0x29, 0x82, 0xB1, 0x2E, 0x2C, 0xD3,
        0x81, 0x80, 0x34, 0x17, 0xDC, 0x2B, 0x36, 0xAB, 0x8D, 0x52, 0xA7, 0xD2, 0xC9, 0x21, 0xCA, 0x44,
        0x00, 0x00, 0x3B  };
    static char ext_gif[] = "gif";

    int rc;
    unsigned int width, height;
    char *errmsg;

    // Test gif
    rc = DFGetImageDimensions(data_bullet, sizeof(data_bullet), ext_gif,
                              &width, &height, &errmsg);
    utassert((rc == 1),      "wrong rc");
    utassert((width == 21),  "wrong width");
    utassert((height == 15), "wrong height");
}



static void test_DFGetImageDimensions_jpg(void)
{
    // Banner-gradient.jpg 2x100
    static unsigned char data_banner[] = {
        0xFF, 0xD8, 0xFF, 0xE0, 0x00, 0x10, 0x4A, 0x46, 0x49, 0x46, 0x00, 0x01, 0x01, 0x01, 0x00, 0x48,
        0x00, 0x48, 0x00, 0x00, 0xFF, 0xFE, 0x00, 0x13, 0x43, 0x72, 0x65, 0x61, 0x74, 0x65, 0x64, 0x20,
        0x77, 0x69, 0x74, 0x68, 0x20, 0x47, 0x49, 0x4D, 0x50, 0xFF, 0xDB, 0x00, 0x43, 0x00, 0x05, 0x03,
        0x04, 0x04, 0x04, 0x03, 0x05, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05, 0x06, 0x07, 0x0C, 0x08, 0x07,
        0x07, 0x07, 0x07, 0x0F, 0x0B, 0x0B, 0x09, 0x0C, 0x11, 0x0F, 0x12, 0x12, 0x11, 0x0F, 0x11, 0x11,
        0x13, 0x16, 0x1C, 0x17, 0x13, 0x14, 0x1A, 0x15, 0x11, 0x11, 0x18, 0x21, 0x18, 0x1A, 0x1D, 0x1D,
        0x1F, 0x1F, 0x1F, 0x13, 0x17, 0x22, 0x24, 0x22, 0x1E, 0x24, 0x1C, 0x1E, 0x1F, 0x1E, 0xFF, 0xDB,
        0x00, 0x43, 0x01, 0x05, 0x05, 0x05, 0x07, 0x06, 0x07, 0x0E, 0x08, 0x08, 0x0E, 0x1E, 0x14, 0x11,
        0x14, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E,
        0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E,
        0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E,
        0x1E, 0x1E, 0x1E, 0xFF, 0xC0, 0x00, 0x11, 0x08, 0x00, 0x64, 0x00, 0x02, 0x03, 0x01, 0x22, 0x00,
        0x02, 0x11, 0x01, 0x03, 0x11, 0x01, 0xFF, 0xC4, 0x00, 0x17, 0x00, 0x01, 0x00, 0x03, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x06, 0x08, 0xFF,
        0xC4, 0x00, 0x1B, 0x10, 0x01, 0x00, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0x03, 0x11, 0x13, 0x32, 0x52, 0xFF, 0xC4, 0x00, 0x14,
        0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xFF, 0xC4, 0x00, 0x14, 0x11, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xDA, 0x00, 0x0C, 0x03, 0x01, 0x00, 0x02,
        0x11, 0x03, 0x11, 0x00, 0x3F, 0x00, 0xD9, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x23,
        0xE7, 0xC5, 0xEE, 0x00, 0x52, 0x66, 0xE5, 0x8D, 0xF7, 0x00, 0x1F, 0xFF, 0xD9  };
    static char ext_jpg[] = "jpg";

    int rc;
    unsigned int width, height;
    char *errmsg;

    // Test gif
    rc = DFGetImageDimensions(data_banner, sizeof(data_banner), ext_jpg,
                              &width, &height, &errmsg);
    utassert((rc == 1),       "wrong rc");
    utassert((width == 2),    "wrong width");
    utassert((height == 100), "wrong height");
}



static void test_DFGetImageDimensions_png(void)
{
    // Carrr.png 17x10
    static unsigned char data_carr[] = {
        0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52,
        0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x0A, 0x08, 0x03, 0x00, 0x00, 0x00, 0x65, 0xA2, 0x45,
        0x90, 0x00, 0x00, 0x00, 0x2C, 0x74, 0x45, 0x58, 0x74, 0x43, 0x72, 0x65, 0x61, 0x74, 0x69, 0x6F,
        0x6E, 0x20, 0x54, 0x69, 0x6D, 0x65, 0x00, 0x54, 0x75, 0x65, 0x20, 0x32, 0x32, 0x20, 0x41, 0x75,
        0x67, 0x20, 0x32, 0x30, 0x30, 0x36, 0x20, 0x30, 0x30, 0x3A, 0x34, 0x33, 0x3A, 0x31, 0x30, 0x20,
        0x2D, 0x30, 0x35, 0x30, 0x30, 0x60, 0x0C, 0x10, 0x58, 0x00, 0x00, 0x00, 0x07, 0x74, 0x49, 0x4D,
        0x45, 0x07, 0xD6, 0x08, 0x16, 0x05, 0x01, 0x29, 0x10, 0xD3, 0x7D, 0xD6, 0x00, 0x00, 0x00, 0x09,
        0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 0x1E, 0xC2, 0x00, 0x00, 0x1E, 0xC2, 0x01, 0x6E, 0xD0, 0x75,
        0x3E, 0x00, 0x00, 0x00, 0x04, 0x67, 0x41, 0x4D, 0x41, 0x00, 0x00, 0xB1, 0x8F, 0x0B, 0xFC, 0x61,
        0x05, 0x00, 0x00, 0x00, 0x45, 0x50, 0x4C, 0x54, 0x45, 0xFF, 0xFF, 0xFF, 0xCD, 0xC3, 0xB0, 0xD7,
        0xCF, 0xC0, 0x80, 0x66, 0x34, 0x73, 0x57, 0x20, 0xE1, 0xDB, 0xD0, 0x8A, 0x72, 0x44, 0x60, 0x40,
        0x00, 0x62, 0x43, 0x04, 0xDC, 0xD5, 0xC8, 0xE9, 0xE4, 0xDC, 0x96, 0x81, 0x58, 0x7B, 0x60, 0x2C,
        0xAF, 0x9F, 0x80, 0x6C, 0x4E, 0x14, 0x87, 0x6F, 0x40, 0xF5, 0xF3, 0xF0, 0xAA, 0x99, 0x78, 0x64,
        0x45, 0x08, 0xF0, 0xED, 0xE8, 0x9E, 0x8A, 0x64, 0xD0, 0xC6, 0xB4, 0x94, 0x7E, 0x54, 0xD6, 0x77,
        0xC5, 0x76, 0x00, 0x00, 0x00, 0x01, 0x74, 0x52, 0x4E, 0x53, 0x00, 0x40, 0xE6, 0xD8, 0x66, 0x00,
        0x00, 0x00, 0x4D, 0x49, 0x44, 0x41, 0x54, 0x78, 0xDA, 0x63, 0x60, 0x40, 0x01, 0xBC, 0xEC, 0xBC,
        0x30, 0x26, 0x2B, 0x9A, 0x08, 0x97, 0x18, 0x1F, 0x8A, 0x88, 0xB0, 0x08, 0x07, 0xBB, 0x28, 0x92,
        0x88, 0x80, 0xA0, 0x10, 0x3B, 0x3B, 0x0B, 0x2F, 0x04, 0xF0, 0x03, 0x45, 0x58, 0xF9, 0xD8, 0x91,
        0x01, 0x3F, 0x13, 0xD0, 0x0C, 0x6E, 0x20, 0x83, 0x07, 0xAA, 0x86, 0x97, 0x09, 0x62, 0x0F, 0x1B,
        0x3B, 0x07, 0x27, 0xAA, 0x2B, 0x18, 0x98, 0x98, 0x59, 0x18, 0xD0, 0x01, 0x23, 0x9C, 0x05, 0x00,
        0x28, 0x72, 0x03, 0x12, 0x3C, 0xA3, 0x13, 0x22, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44,
        0xAE, 0x42, 0x60, 0x82 };
    static char ext_png[] = "png";

    int rc;
    unsigned int width, height;
    char *errmsg;

    // Test gif
    rc = DFGetImageDimensions(data_carr, sizeof(data_carr), ext_png,
                              &width, &height, &errmsg);
    utassert((rc == 1),      "wrong rc");
    utassert((width == 17),  "wrong width");
    utassert((height == 10), "wrong height");
}


static int testOnceCount;
static void testOnce(void)
{
    testOnceCount++;
}

static void test_DFInitOnce(void)
{
    static DFOnce once = DF_ONCE_INIT;
    DFInitOnce(&once, testOnce);
    utassert((testOnceCount == 1), "function not called");

    DFInitOnce(&once, testOnce);
    utassert((testOnceCount == 1), "function called twice");
}



static void test_DFMkdirIfAbsent(void)
{
    char *errmsg;
    int  rc;

    rmdir("xxyz_testdir");
    rc = DFMkdirIfAbsent("xxyz_testdir", &errmsg);
    utassert((rc == 1), "Cannot create directory");

    rc = DFMkdirIfAbsent("xxyz_testdir", &errmsg);
    utassert((rc == 1), "Cannot use existing directory");

    rc = rmdir("xxyz_testdir");
    utassert((rc == 0), "did not create directory");

}



static void test_DFAddDirContents(void)
{
    DFDirEntryList *list = NULL;
    DFDirEntryList **listptr = &list;
    char            *errmsg;
    int              rc;

    rc = DFAddDirContents(".", "", 1, &listptr, &errmsg);
    utassert((rc == 1), "could not read dir");

    DFDirEntryList *next;
    for (DFDirEntryList *l = list; l != NULL; l = next) {
        next = l->next;
        free(l->name);
        free(l);
    }
}


TestGroup PlatformOSTests = {
    "platform.os", {
        { "DFGetImageDimensions (gif)", PlainTest, test_DFGetImageDimensions_gif },
        { "DFGetImageDimensions (jpg)", PlainTest, test_DFGetImageDimensions_jpg },
        { "DFGetImageDimensions (png)", PlainTest, test_DFGetImageDimensions_png },
        { "DFInitOnce", PlainTest, test_DFInitOnce },
        { "DFMkdirIfAbsent",            PlainTest, test_DFMkdirIfAbsent },
        { "DFAddDirContents",           PlainTest, test_DFAddDirContents },
        { NULL,                         PlainTest, NULL }
    }
};
