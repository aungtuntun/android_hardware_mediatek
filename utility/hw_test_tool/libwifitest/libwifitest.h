/* MediaTek Inc. (C) 2012. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#ifndef __LIBWIFITEST_H__
#define __LIBWIFITEST_H__

/* basic definitions
 * -------------------------------------------------------------------------- */
#ifndef bool
#define bool int
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

/* types
 * -------------------------------------------------------------------------- */
typedef enum {
	WIFI_TEST_PREAMBLE_LONG = 0,
	WIFI_TEST_PREAMBLE_SHORT,
} PreambleType_t;

/* WIFI_TEST_TxDataRate */
#define WIFI_TEST_RATE_AUTO         0
#define WIFI_TEST_RATE_1MBPS		1
#define WIFI_TEST_RATE_2MBPS		2
#define WIFI_TEST_RATE_5_5MBPS		3
#define WIFI_TEST_RATE_6MBPS		4
#define WIFI_TEST_RATE_9MBPS		5
#define WIFI_TEST_RATE_11MBPS		6
#define WIFI_TEST_RATE_12MBPS		7
#define WIFI_TEST_RATE_18MBPS		8
#define WIFI_TEST_RATE_24MBPS		9
#define WIFI_TEST_RATE_36MBPS		10
#define WIFI_TEST_RATE_48MBPS		11
#define WIFI_TEST_RATE_54MBPS		12

/* Supported MCS rates */
typedef enum _tagENUM_WIFI_TEST_MCS_RATE {
	WIFI_TEST_MCS_RATE_0 = 0,
	WIFI_TEST_MCS_RATE_1 = 1,
	WIFI_TEST_MCS_RATE_2 = 2,
	WIFI_TEST_MCS_RATE_3 = 3,
	WIFI_TEST_MCS_RATE_4 = 4,
	WIFI_TEST_MCS_RATE_5 = 5,
	WIFI_TEST_MCS_RATE_6 = 6,
	WIFI_TEST_MCS_RATE_7 = 7,
	WIFI_TEST_MCS_RATE_32= 32,
} ENUM_WIFI_TEST_MCS_RATE, *P_ENUM_WIFI_TEST_MCS_RATE;

/* bandwidth */
#define WIFI_TEST_BW_20  0
#define WIFI_TEST_BW_40  1
#define WIFI_TEST_BW_20U 2
#define WIFI_TEST_BW_20L 3

/* Preamble Type */
typedef enum _tagENUM_WIFI_TEST_PREAMBLE_TYPE {
    WIFI_TEST_PREAMBLE_TYPE_MIXED_MODE = 0,
    WIFI_TEST_PREAMBLE_TYPE_GREENFIELD = 1
} ENUM_WIFI_TEST_PREAMBLE_TYPE, *P_ENUM_WIFI_TEST_PREAMBLE_TYPE;

/* Guard Interval Type */
typedef enum _tagENUM_WIFI_TEST_GI_TYPE {
    WIFI_TEST_GI_TYPE_NORMAL_GI = 0,
    WIFI_TEST_GI_TYPE_SHORT_GI  = 1
} ENUM_WIFI_TEST_GI_TYPE, *P_ENUM_WIFI_TEST_GI_TYPE;

/* functions
 * -------------------------------------------------------------------------- */
bool WIFI_TEST_OpenDUT(void);
bool WIFI_TEST_CloseDUT(void);
bool WIFI_TEST_TxDataRate(int TxDataRate);
bool WIFI_TEST_SetPreamble(PreambleType_t PreambleType);
bool WIFI_TEST_Channel(int ChannelNo);
bool WIFI_TEST_SetBandWidth(int bandwidth);
bool WIFI_TEST_TxGain(int TxGain);
bool WIFI_TEST_TxBurstInterval(int SIFS);
bool WIFI_TEST_TxPayloadLength(int TxPayLength);
bool WIFI_TEST_TxBurstFrames(int Frames);
bool WIFI_TEST_TxDestAddress(unsigned char *addr);
bool WIFI_TEST_TxStart(void);
bool WIFI_TEST_TxStop(void);
bool WIFI_TEST_RxStart(void);
bool WIFI_TEST_RxStop(void);
bool WIFI_TEST_FRError(int *FError);
bool WIFI_TEST_FRGood(int *FRGood);
bool WIFI_TEST_RSSI(signed char *RSSI);
bool WIFI_TEST_IsRunning(void);
bool WIFI_TEST_IsUp(void);
bool WIFI_TEST_TxDataRate11n(ENUM_WIFI_TEST_MCS_RATE eDataRate11n, ENUM_WIFI_TEST_PREAMBLE_TYPE ePreambleType, ENUM_WIFI_TEST_GI_TYPE eGIType);
bool WIFI_TEST_FrequencyAccuracy(int ChannelNo);
bool WIFI_TEST_FrequencyAccuracy_Stop();
bool WIFI_TEST_MCR_Read(unsigned int addr, unsigned int *val);
bool WIFI_TEST_MCR_Write(unsigned int addr, unsigned int val);
bool WIFI_TEST_EFUSE_Read(unsigned int offset, unsigned int *val);
bool WIFI_TEST_EFUSE_Write(unsigned int offset, unsigned int val);
bool WIFI_TEST_CW_MODE(int mode);

/*added  by mtk54425 for combotool.apk*/
bool WIFI_TEST_Tx_Output_Power(void);
bool WIFI_TEST_Local_Leakage(void);
bool WIFI_TEST_Carrier_Suppression(void);


#endif /* __LIBWIFITEST_H__ */
