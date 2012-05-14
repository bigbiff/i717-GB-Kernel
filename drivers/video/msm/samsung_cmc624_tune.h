#ifndef CMC624_REG_HEADER
#define CMC624_REG_HEADER
#endif

#define CMC624_SERVICE_EXTEND

/** CMC624 registers **/

/* SFR Bank selection */
#define CMC624_REG_SELBANK   0x00

/* A stage configuration */
#define CMC624_REG_DNRHDTROVE 0x01
#define CMC624_REG_DITHEROFF 0x06
#define CMC624_REG_CLKCONT 0x10
#define CMC624_REG_CLKGATINGOFF 0x0a
#define CMC624_REG_INPUTIFCON 0x24
#define CMC624_REG_CLKMONCONT   0x11
#define CMC624_REG_HDRTCEOFF 0x3a
#define CMC624_REG_I2C 0x0d
#define CMC624_REG_BSTAGE 0x0e
#define CMC624_REG_CABCCTRL 0x7c
#define CMC624_REG_PWMCTRL 0xb4
#define CMC624_REG_OVEMAX 0x54

/* A stage image size */
#define CMC624_REG_1280 0x22
#define CMC624_REG_800 0x23

/* B stage image size */
#define CMC624_REG_SCALERINPH 0x09
#define CMC624_REG_SCALERINPV 0x0a
#define CMC624_REG_SCALEROUTH 0x0b
#define CMC624_REG_SCALEROUTV 0x0c

/* EDRAM configuration */
#define CMC624_REG_EDRBFOUT40 0x01
#define CMC624_REG_EDRAUTOREF 0x06
#define CMC624_REG_EDRACPARAMTIM 0x07

/* Vsync Calibartion */
#define CMC624_REG_CALVAL10 0x65

/* tcon output polarity */
#define CMC624_REG_TCONOUTPOL 0x68

/* tcon RGB configuration */
#define CMC624_REG_TCONRGB1 0x6c
#define CMC624_REG_TCONRGB2 0x6d
#define CMC624_REG_TCONRGB3 0x6e

/* Reg update */
#define CMC624_REG_REGMASK 0x28
#define CMC624_REG_SWRESET 0x09
#define CMC624_REG_RGBIFEN 0x26

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CMC624 Register Setting
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static const struct Cmc624RegisterSet cmc624_init[] = {
	// CLOCK_TOP
	{ 0x00, 0x0002 },       // BANK 2
	{ 0x30, 0x0004 },       // S.PLL DISEN, NORMAL, P = 4	(Fout = 420MHz)
	{ 0x31, 0x20AF },       // S = 2, M = 175		(Fout = 420MHz)
	{ 0x30, 0x1004 },       // S.PLL EN, NORMAL, P = 4	(Fout = 420MHz)
	{ 0x3A, 0x0F05 },       // CLOCK DIVIDER VALUE (I2C = 15[28MHz], A = 5)
	{ 0x3B, 0x041C },       // CLOCK DIVIDER VALUE (M1 = 4, M2 = 24)
	{ 0x3C, 0x1203 },       // CLOCK DIVIDER VALUE (B = 18, P = 3)
	{ 0x3D, 0x0400 },       // CLOCK DIVIDER VALUE (PWM = 1024)
	{ 0x39, 0x007F },       // CLOCK DIVIDER ENABLE
	{ 0x3E, 0x2223 },       // CLOCK MUX SEL

	{ 0x00, 0x0000 },       // BANK 0
	{ 0xFD, 0x0000 },       // MODULE REG MASK RELEASE
	{ 0xFE, 0x0004 },       // MODULE REG MASK RELEASE

	{ 0xFF, 0x0000 },       // REG MASK RELEASE

	// INPUT IF
	{ 0x00, 0x0002 },       // BANK 2
	{ 0x50, 0x0021 },     	// RGB BOTTOM ALIGNMENT, VSYNC/HSYNC LOW ACTIVE, DE HIHG ACTIVE

	// TCON
	{ 0x00, 0x0002 },	// BANK 2
	{ 0x60, 0x5400 },	// TCON VSYNC DELAY
	{ 0x63, 0x0310 },	// OUTPUT COLOR MAP, TCON OUTPUT POL(LLH)
	{ 0x67, 0x0002 },	// VSYNC PULSE WIDTH = 2
	{ 0x68, 0x0002 },	// HSYNC PULSE WIDTH = 64
	{ 0x69, 0x0001 },	// VBP = 1
	{ 0x6A, 0x000D },	// VFP = 13
	{ 0x6B, 0x0084 },	// HBP = 140
	{ 0x6C, 0x0082 },	// HFP = 146
	{ 0x66, 0x8000 },	// CDC

	// IP
	{ 0x00, 0x0000 },	// BANK 0
	{ 0x01, 0x0077 },	// HSYNC/DE MASK RELEASE
	{ 0x03, 0x0320 },	// WIDTH = 1280
	{ 0x04, 0x0500 },	// HEIGHT = 800
	{ 0x08, 0x0000 },	// ALGO MODULE OFF
	{ 0x09, 0x0000 },	// ALGO MODULE OFF
	{ 0x0A, 0x0000 },	// ALGO MODULE OFF

	// CONV
	{ 0x00, 0x0003 },	// BANK 3
	{ 0x01, 0x0001 },	// I2C TO MIPI
    { 0x07, 0xC000 },   //	# MIPI_CONV INT_MASK	
	{ 0x43, 0x8000 },	// M_BAND_CTL
	{ 0x42, 0x4641 },	// M_PLL SETTING (Fout = 480MHz)
	{ 0x41, 0x8000 },	// M_PLL SETTING & M_PLL ENABLE
	{ 0x44, 0x000A },	// S_HSSETTLE
	{ 0x40, 0x0030 },	// M/S CLOCK LANE ENABLE

	{ 0x00, 0x0000 },	// BANK 0
	{ 0xFD, 0xFFFF },	// MODULE REG MASK RELEASE
	{ 0xFE, 0xFFFF },	// MODULE REG MASK RELEASE
	{ 0xFF, 0x0000 },	// MASK RELEASE

	// DSI HOST
	{ 0x00, 0x0003 },	// BANK 3
	{ 0x84, 0xFFFF },	// INTERRUPT ENABLE
	{ 0x85, 0x1FEF },	// INTERRUPT ENABLE
	{ 0x86, 0x6204 },	// DSI FUNCTION (CMD  8 BIT DATA, RGB888, CMD VC 0, VIDEO VC 0, 4 LANE)
	{ 0x88, 0xFFFF },	// HIGH SPEED RECEIVE TIMEOUT
	{ 0x89, 0x00FF },	// HIGH SPEED RECEIVE TIMEOUT
	{ 0x8A, 0xFFFF },	// LOW POWER RECEIVE TIMEOUT
	{ 0x8B, 0x00FF },	// LOW POWER RECEIVE TIMEOUT
	{ 0x8C, 0x0028 },	// TURN AROUND TIMEOUT
	{ 0x8E, 0x00FF },	// DEVICE RESET TIMER
	{ 0x90, 0x0320 },	// HORIZANTAL RESOLUTION = 1280
	{ 0x91, 0x0500 },	// VERTICAL RESOLUTION = 800

	{ 0x94, 0x0002 },	// HORIZANTAL SYNC PADDING COUNT
	{ 0x96, 0x0063 },	// HORIZANTAL BACK PORCH COUNT
	{ 0x98, 0x0062 },	// HORIZANTAL FRONT FORCH COUNT
	{ 0x9A, 0x0258 },	// HORIZANTAL ACTIVE AREA

	{ 0x9C, 0x0002 },	// VERTICAL SYNC PADDING COUNT
	{ 0x9E, 0x0001 },	// VERTICAL BACK PORCH COUNT
	{ 0xA0, 0x000D },	// VERTICAL FRONT FORCH COUNT
	{ 0xA8, 0x0d07 },	// MASTER INIT TIME
	{ 0xAC, 0x0002 },	// VIDEO MODE FORMAT = NON BURST SYNC EVENT
	{ 0xB0, 0x0008 },	// VSYNC, HSYNC, COLOR MODE, SHUT DOWN POLARITY

	{ 0xB4, 0x0007 },	// LP EQUIVALENT BYTECLK
	{ 0xA2, 0x0014 },	// HIGH SPEED <-> LOW POWER SWITCHING COUNTER FOR DATA LANE
	{ 0xB2, 0x000B },	// HIGH SPEED -> LOW POWER SWITCHING COUNTER FOR CLOCK LANE
	{ 0xB3, 0x001C },	// HIGH SPEED <- LOW POWER SWITCHING COUNTER FOR CLOCK LANE

	{ 0x80, 0x0001 },	// DEVICE READY
	{ 0xA4, 0x0002 },	// COLOR MODE OFF, DPI ON

	// DSI DEVICE
	{ 0x00, 0x0003 },	// BANK 3
	{ 0xC4, 0xFFFF },	// INTERRUPT ENABLE
	{ 0xC5, 0x01FF },	// INTERRUPT ENABLE
	{ 0xC6, 0x0064 },	// DSI FUNCTION : BURST & NON BURST SYNC EVENT
	{ 0xC8, 0xFFFF },	// HIGH SPEED RECEIVE TIMEOUT
	{ 0xC9, 0x0FFF },	// HIGH SPEED RECEIVE TIMEOUT
	{ 0xCA, 0x005E },	// LOW POWER RECEIVE TIMEOUT
	{ 0xCB, 0x0000 },	// LOW POWER RECEIVE TIMEOUT
	{ 0xCC, 0x0025 },	// TURN AROUND TIMEOUT
	{ 0xCE, 0x07D0 },	// DEVICE RESET TIMER
	{ 0xD2, 0x0000 },	// CRC, ECC, EOT ENABLE
	{ 0xD4, 0x0002 },	// HSYNC COUNT = 64
	{ 0xD5, 0x0002 },	// VSYNC COUNT = 2
	{ 0xC0, 0x0001 },	// DEVICE READY

	{ 0x00, 0x0000 },	// BANK 0
	{ 0xFD, 0xFFFF },	
	{ 0xFE, 0xFFFF },	
	{ 0xFF, 0x0000 },	// MASK RELEASE

	{ 0x00, 0x0002 },  // BANK 2
	{ 0x3F, 0x0125 }, // MON_CLK :TXBYTECLKHS (60MHz)

	// LP Operation
	{ 0x00, 0x0003 },  // BANK 3
	{ 0x07, 0x1000 }, // 

	// LP Operation1 (Write Auto Pow On)
	{ 0x03, 0x0003 },  // Write Length
	{ 0x02, 0x1301 }, // LP enable, Generic Long Write, VC=0
	{ 0x05, 0x00FC }, // FCh
	{ 0x05, 0x005A }, // 5Ah
	{ 0x05, 0x005A }, // 5Ah

};

static const struct Cmc624RegisterSet cmc624_wakeup[] = {
	// CLOCK_TOP
	{ 0x00, 0x0002 },        // BANK 2
	{ 0x30, 0x0004 },        // S.PLL DISEN, NORMAL, P = 4	(Fout = 420MHz)
	{ 0x31, 0x20AF },        // S = 2, M = 175		(Fout = 420MHz)
	{ 0x30, 0x1004 },        // S.PLL EN, NORMAL, P = 4	(Fout = 420MHz)
	{ 0x3A, 0x0F05 },        // CLOCK DIVIDER VALUE (I2C = 15[28MHz], A = 5)
	{ 0x3B, 0x0418 },        // CLOCK DIVIDER VALUE (M1 = 4, M2 = 24)
	{ 0x3C, 0x1203 },        // CLOCK DIVIDER VALUE (B = 18, P = 3)
	{ 0x3D, 0x0400 },        // CLOCK DIVIDER VALUE (PWM = 1024)
	{ 0x39, 0x007F },        // CLOCK DIVIDER ENABLE
	{ 0x3E, 0x2223 },        // CLOCK MUX SEL

	{ 0x00, 0x0000 },        // BANK 0
	{ 0xFD, 0x0000 },        // MODULE REG MASK RELEASE
	{ 0xFE, 0x0004 },        // MODULE REG MASK RELEASE

	{ 0xFF, 0x0000 },        // REG MASK RELEASE

	// INPUT IF
	{ 0x00, 0x0002 },        // BANK 2
	{ 0x50, 0x0021 },      	// RGB BOTTOM ALIGNMENT, VSYNC/HSYNC LOW ACTIVE, DE HIHG ACTIVE

	// TCON
	{ 0x00, 0x0002 },	// BANK 2
	{ 0x60, 0x5400 },	// TCON VSYNC DELAY
	{ 0x63, 0x0310 },	// OUTPUT COLOR MAP, TCON OUTPUT POL(LLH)
	{ 0x67, 0x0002 },	// VSYNC PULSE WIDTH = 2
	{ 0x68, 0x0040 },	// HSYNC PULSE WIDTH = 64
	{ 0x69, 0x0003 },	// VBP = 3
	{ 0x6A, 0x000D },	// VFP = 13
	{ 0x6B, 0x008C },	// HBP = 140
	{ 0x6C, 0x0092 },	// HFP = 146
	{ 0x66, 0x8000 },	// CDC

	// IP
	{ 0x00, 0x0000 },	// BANK 0
	{ 0x01, 0x0077 },	// HSYNC/DE MASK RELEASE
	{ 0x03, 0x0500 },	// WIDTH = 1280
	{ 0x04, 0x0320 },	// HEIGHT = 800
	{ 0x08, 0x0000 },	// ALGO MODULE OFF
	{ 0x09, 0x0000 },	// ALGO MODULE OFF
	{ 0x0A, 0x0000 },	// ALGO MODULE OFF

	// CONV
	{ 0x00, 0x0003 },	// BANK 3
	{ 0x01, 0x0001 },	// MIPI TO MIPI
	{ 0x43, 0x8000 },	// M_BAND_CTL
	{ 0x42, 0x4641 },	// M_PLL SETTING (Fout = 480MHz)
	{ 0x41, 0x8000 },	// M_PLL SETTING & M_PLL ENABLE
	{ 0x44, 0x000A },	// S_HSSETTLE
	{ 0x40, 0x0030 },	// M/S CLOCK LANE ENABLE

	{ 0x00, 0x0000 },	// BANK 0
	{ 0xFD, 0xFFFF },	// MODULE REG MASK RELEASE
	{ 0xFE, 0xFFFF },	// MODULE REG MASK RELEASE
	{ 0xFF, 0x0000 },	// MASK RELEASE

	// DSI HOST
	{ 0x00, 0x0003 },	// BANK 3
	{ 0x84, 0xFFFF },	// INTERRUPT ENABLE
	{ 0x85, 0x1FEF },	// INTERRUPT ENABLE
	{ 0x86, 0x6204 },	// DSI FUNCTION (CMD  8 BIT DATA, RGB888, CMD VC 0, VIDEO VC 0, 4 LANE)
	{ 0x88, 0xFFFF },	// HIGH SPEED RECEIVE TIMEOUT
	{ 0x89, 0x00FF },	// HIGH SPEED RECEIVE TIMEOUT
	{ 0x8A, 0xFFFF },	// LOW POWER RECEIVE TIMEOUT
	{ 0x8B, 0x00FF },	// LOW POWER RECEIVE TIMEOUT
	{ 0x8C, 0x001F },	// TURN AROUND TIMEOUT
	{ 0x8E, 0x00FF },	// DEVICE RESET TIMER
	{ 0x90, 0x0500 },	// HORIZANTAL RESOLUTION = 1280
	{ 0x91, 0x0320 },	// VERTICAL RESOLUTION = 800

	{ 0x94, 0x0030 },	// HORIZANTAL SYNC PADDING COUNT
	{ 0x96, 0x0069 },	// HORIZANTAL BACK PORCH COUNT
	{ 0x98, 0x006E },	// HORIZANTAL FRONT FORCH COUNT
	{ 0x9A, 0x03C0 },	// HORIZANTAL ACTIVE AREA

	{ 0x9C, 0x0002 },	// VERTICAL SYNC PADDING COUNT
	{ 0x9E, 0x0003 },	// VERTICAL BACK PORCH COUNT
	{ 0xA0, 0x000D },	// VERTICAL FRONT FORCH COUNT
	{ 0xA8, 0x0d07 },	// MASTER INIT TIME
	{ 0xAC, 0x0002 },	// VIDEO MODE FORMAT = NON BURST SYNC EVENT
	{ 0xB0, 0x0008 },	// VSYNC, HSYNC, COLOR MODE, SHUT DOWN POLARITY

	{ 0xB4, 0x000A },	// LP EQUIVALENT BYTECLK
	{ 0xA2, 0x0014 },	// HIGH SPEED <-> LOW POWER SWITCHING COUNTER FOR DATA LANE
	{ 0xB2, 0x000B },	// HIGH SPEED -> LOW POWER SWITCHING COUNTER FOR CLOCK LANE
	{ 0xB3, 0x001C },	// HIGH SPEED <- LOW POWER SWITCHING COUNTER FOR CLOCK LANE

	{ 0x80, 0x0001 },	// DEVICE READY
	{ 0xA4, 0x0002 },	// COLOR MODE OFF, DPI ON

	// DSI DEVICE
	{ 0x00, 0x0003 },	// BANK 3
	{ 0xC4, 0xFFFF },	// INTERRUPT ENABLE
	{ 0xC5, 0x01FF },	// INTERRUPT ENABLE
	{ 0xC6, 0x0064 },	// DSI FUNCTION : BURST & NON BURST SYNC EVENT
	{ 0xC8, 0xFFFF },	// HIGH SPEED RECEIVE TIMEOUT
	{ 0xC9, 0x0FFF },	// HIGH SPEED RECEIVE TIMEOUT
	{ 0xCA, 0x005E },	// LOW POWER RECEIVE TIMEOUT
	{ 0xCB, 0x0000 },	// LOW POWER RECEIVE TIMEOUT
	{ 0xCC, 0x0025 },	// TURN AROUND TIMEOUT
	{ 0xCE, 0x07D0 },	// DEVICE RESET TIMER
	{ 0xD2, 0x0000 },	// CRC, ECC, EOT ENABLE
	{ 0xD4, 0x0040 },	// HSYNC COUNT = 64
	{ 0xD5, 0x0002 },	// VSYNC COUNT = 2
	{ 0xC0, 0x0001 },	// DEVICE READY

	{ 0x00, 0x0002 },	// BANK 2
	{ 0x52, 0x0001 },	// RGB IF ENABLE

	{ 0x3f, 0x011B },	// MON_CLK : TXBYTECLKHS (60MHz)

};

static const struct Cmc624RegisterSet cmc624_bypass[] = {

};


static const struct Cmc624RegisterSet standard_video_cabcoff[] = {
	//start P8 standard video
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0030},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2 HDR1
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
	{0x00b2,0x0060},	//DE pe
	{0x00b3,0x0060},	//DE pf
	{0x00b4,0x0060},	//DE pb
	{0x00b5,0x0060},	//DE ne
	{0x00b6,0x0060},	//DE nf
	{0x00b7,0x0060},	//DE nb
	{0x00b8,0x1000},	//DE max ratio
	{0x00b9,0x0100},	//DE min ratio
	{0x00c0,0x1010},	//CS hg ry
	{0x00c1,0x1010},	//CS hg gc
	{0x00c2,0x1010},	//CS hg bm
	{0x00c3,0x1204},	//CS weight grayTH
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet standard_dmb_cabcoff[] = {
	//start P8 standard dmb
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0036},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
	{0x0080,0x1001},	//NR col con ring bl
	{0x0081,0x3f04},	//NR blRedTH maxmin
	{0x0082,0x1006},	//NR edgeTH blDecTH
	{0x0083,0x3f04},	//NR conRedTH maxmin
	{0x0090,0x0430},	//WIENER br
	{0x0091,0x0040},	//WIENER hf
	{0x0092,0x1000},	//WIENER lf
	{0x00b2,0x0100},	//DE pe
	{0x00b3,0x0100},	//DE pf
	{0x00b4,0x0100},	//DE pb
	{0x00b5,0x0100},	//DE ne
	{0x00b6,0x0100},	//DE nf
	{0x00b7,0x0100},	//DE nb
	{0x00b8,0x1000},	//DE max ratio
	{0x00b9,0x0010},	//DE min ratio
	{0x00c0,0x1010},	//CS hg ry
	{0x00c1,0x1010},	//CS hg gc
	{0x00c2,0x1010},	//CS hg bm
	{0x00c3,0x1804},	//CS weight grayTH
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet standard_ui_cabcoff[] = {
	//start P8 standard ui
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0030},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
	{0x00b2,0x0020},	//DE pe
	{0x00b3,0x0020},	//DE pf
	{0x00b4,0x0020},	//DE pb
	{0x00b5,0x0020},	//DE ne
	{0x00b6,0x0020},	//DE nf
	{0x00b7,0x0020},	//DE nb
	{0x00b8,0x1000},	//DE max ratio
	{0x00b9,0x0100},	//DE min ratio
	{0x00c0,0x1010},	//CS hg ry
	{0x00c1,0x1010},	//CS hg gc
	{0x00c2,0x1010},	//CS hg bm
	{0x00c3,0x1604},	//CS weight grayTH
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet standard_gallery_cabcoff[] = {
	//start P8 standard gallery
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0030},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2 HDR1
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
	{0x00b2,0x0060},	//DE pe
	{0x00b3,0x0060},	//DE pf
	{0x00b4,0x0060},	//DE pb
	{0x00b5,0x0060},	//DE ne
	{0x00b6,0x0060},	//DE nf
	{0x00b7,0x0060},	//DE nb
	{0x00b8,0x1000},	//DE max ratio
	{0x00b9,0x0100},	//DE min ratio
	{0x00c0,0x1010},	//CS hg ry
	{0x00c1,0x1010},	//CS hg gc
	{0x00c2,0x1010},	//CS hg bm
	{0x00c3,0x1204},	//CS weight grayTH
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet standard_vtcall_cabcoff[] = {
	//start P8 standard vtcall
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0032},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
	{0x0080,0x1111},	//NR col con ring bl
	{0x0081,0x3f04},	//NR blRedTH maxmin
	{0x0082,0x1006},	//NR edgeTH blDecTH
	{0x0083,0x3f04},	//NR conRedTH maxmin
	{0x00b2,0x0080},	//DE pe
	{0x00b3,0x0080},	//DE pf
	{0x00b4,0x0080},	//DE pb
	{0x00b5,0x0080},	//DE ne
	{0x00b6,0x0080},	//DE nf
	{0x00b7,0x0080},	//DE nb
	{0x00b8,0x1000},	//DE max ratio
	{0x00b9,0x0010},	//DE min ratio
	{0x00c0,0x1010},	//CS hg ry
	{0x00c1,0x1010},	//CS hg gc
	{0x00c2,0x1010},	//CS hg bm
	{0x00c3,0x1804},	//CS weight grayTH
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet movie_video_cabcoff[] = {
	//start P8 movie video
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0200},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2 HDR1
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
	{0x0000,0x0001},	//BANK 1
	{0x0071,0xf000},	//SCR RrCr
	{0x0072,0x25f0},	//SCR RgCg
	{0x0073,0x28f0},	//SCR RbCb
	{0x0074,0x60f0},	//SCR GrMr
	{0x0075,0xd800},	//SCR GgMg
	{0x0076,0x20f0},	//SCR GbMb
	{0x0077,0x00f0},	//SCR BrYr
	{0x0078,0x50f0},	//SCR BgYg
	{0x0079,0xf000},	//SCR BbYb
	{0x007a,0x00ff},	//SCR KrWr
	{0x007b,0x00fb},	//SCR KgWg
	{0x007c,0x00f0},	//SCR KbWb
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet movie_dmb_cabcoff[] = {
	//start P8 movie dmb
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0236},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
	{0x0080,0x1001},	//NR col con ring bl
	{0x0081,0x3f04},	//NR blRedTH maxmin
	{0x0082,0x1006},	//NR edgeTH blDecTH
	{0x0083,0x3f04},	//NR conRedTH maxmin
	{0x0090,0x0430},	//WIENER br
	{0x0091,0x0040},	//WIENER hf
	{0x0092,0x1000},	//WIENER lf
	{0x00a0,0x0010},	//LoG neg
	{0x00a1,0x0010},	//LoG pos
	{0x00b2,0x0080},	//DE pe
	{0x00b3,0x0080},	//DE pf
	{0x00b4,0x0080},	//DE pb
	{0x00b5,0x0080},	//DE ne
	{0x00b6,0x0080},	//DE nf
	{0x00b7,0x0080},	//DE nb
	{0x00b8,0x1000},	//DE max ratio
	{0x00b9,0x0010},	//DE min ratio
	{0x00c0,0x1010},	//CS hg ry
	{0x00c1,0x1010},	//CS hg gc
	{0x00c2,0x1010},	//CS hg bm
	{0x00c3,0x1004},	//CS weight grayTH
	{0x0000,0x0001},	//BANK 1
	{0x0071,0xf000},	//SCR RrCr
	{0x0072,0x25f0},	//SCR RgCg
	{0x0073,0x28f0},	//SCR RbCb
	{0x0074,0x60f0},	//SCR GrMr
	{0x0075,0xd800},	//SCR GgMg
	{0x0076,0x20f0},	//SCR GbMb
	{0x0077,0x00f0},	//SCR BrYr
	{0x0078,0x50f0},	//SCR BgYg
	{0x0079,0xf000},	//SCR BbYb
	{0x007a,0x00ff},	//SCR KrWr
	{0x007b,0x00fb},	//SCR KgWg
	{0x007c,0x00f0},	//SCR KbWb
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet movie_ui_cabcoff[] = {
	//start P8 movie ui
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0200},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2 HDR1
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
	{0x0000,0x0001},	//BANK 1
	{0x0071,0xf000},	//SCR RrCr
	{0x0072,0x25f0},	//SCR RgCg
	{0x0073,0x28f0},	//SCR RbCb
	{0x0074,0x60f0},	//SCR GrMr
	{0x0075,0xd800},	//SCR GgMg
	{0x0076,0x20f0},	//SCR GbMb
	{0x0077,0x00f0},	//SCR BrYr
	{0x0078,0x50f0},	//SCR BgYg
	{0x0079,0xf000},	//SCR BbYb
	{0x007a,0x00ff},	//SCR KrWr
	{0x007b,0x00fb},	//SCR KgWg
	{0x007c,0x00f0},	//SCR KbWb
	{0x00ff,0x0000},	//Mask Release
	//end
};


static const struct Cmc624RegisterSet movie_gallery_cabcoff[] = {
	//start P8 movie gallery
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0200},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2 HDR1
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
	{0x0000,0x0001},	//BANK 1
	{0x0071,0xf000},	//SCR RrCr
	{0x0072,0x25f0},	//SCR RgCg
	{0x0073,0x28f0},	//SCR RbCb
	{0x0074,0x60f0},	//SCR GrMr
	{0x0075,0xd800},	//SCR GgMg
	{0x0076,0x20f0},	//SCR GbMb
	{0x0077,0x00f0},	//SCR BrYr
	{0x0078,0x50f0},	//SCR BgYg
	{0x0079,0xf000},	//SCR BbYb
	{0x007a,0x00ff},	//SCR KrWr
	{0x007b,0x00fb},	//SCR KgWg
	{0x007c,0x00f0},	//SCR KbWb
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet movie_vtcall_cabcoff[] = {
	//start P8 movie vtcall
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0232},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
	{0x0080,0x1111},	//NR col con ring bl
	{0x0081,0x3f04},	//NR blRedTH maxmin
	{0x0082,0x1006},	//NR edgeTH blDecTH
	{0x0083,0x3f04},	//NR conRedTH maxmin
	{0x00b2,0x0060},	//DE pe
	{0x00b3,0x0060},	//DE pf
	{0x00b4,0x0060},	//DE pb
	{0x00b5,0x0060},	//DE ne
	{0x00b6,0x0060},	//DE nf
	{0x00b7,0x0060},	//DE nb
	{0x00b8,0x1000},	//DE max ratio
	{0x00b9,0x0010},	//DE min ratio
	{0x00c0,0x1010},	//CS hg ry
	{0x00c1,0x1010},	//CS hg gc
	{0x00c2,0x1010},	//CS hg bm
	{0x00c3,0x1604},	//CS weight grayTH
	{0x0000,0x0001},	//BANK 1
	{0x0071,0xf000},	//SCR RrCr
	{0x0072,0x25f0},	//SCR RgCg
	{0x0073,0x28f0},	//SCR RbCb
	{0x0074,0x60f0},	//SCR GrMr
	{0x0075,0xd800},	//SCR GgMg
	{0x0076,0x20f0},	//SCR GbMb
	{0x0077,0x00f0},	//SCR BrYr
	{0x0078,0x50f0},	//SCR BgYg
	{0x0079,0xf000},	//SCR BbYb
	{0x007a,0x00ff},	//SCR KrWr
	{0x007b,0x00fb},	//SCR KgWg
	{0x007c,0x00f0},	//SCR KbWb
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet dynamic_video_cabcoff[] = {
	//start P8 dynamic video
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0130},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2 HDR1
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
	{0x00b2,0x0080},	//DE pe
	{0x00b3,0x0080},	//DE pf
	{0x00b4,0x0080},	//DE pb
	{0x00b5,0x0080},	//DE ne
	{0x00b6,0x0080},	//DE nf
	{0x00b7,0x0080},	//DE nb
	{0x00b8,0x1000},	//DE max ratio
	{0x00b9,0x0100},	//DE min ratio
	{0x00c0,0x1010},	//CS hg ry
	{0x00c1,0x1010},	//CS hg gc
	{0x00c2,0x1010},	//CS hg bm
	{0x00c3,0x1804},	//CS weight grayTH
	{0x0000,0x0001},	//BANK 1
	{0x003f,0x0080},	//CC chsel strength
	{0x0040,0x0000},	//CC lut r  0
	{0x0041,0x0d93},	//CC lut r  16 144 
	{0x0042,0x1aa5},	//CC lut r  32 160
	{0x0043,0x29b7},	//CC lut r  48 176
	{0x0044,0x39c8},	//CC lut r  64 192
	{0x0045,0x4bd8},	//CC lut r  80 208
	{0x0046,0x5de6},	//CC lut r  96 224
	{0x0047,0x6ff4},	//CC lut r 112 240
	{0x0048,0x81ff},	//CC lut r 128 255
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet dynamic_dmb_cabcoff[] = {
	//start P8 dynamic dmb
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0136},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
	{0x0080,0x1001},	//NR col con ring bl
	{0x0081,0x3f04},	//NR blRedTH maxmin
	{0x0082,0x1006},	//NR edgeTH blDecTH
	{0x0083,0x3f04},	//NR conRedTH maxmin
	{0x0090,0x0430},	//WIENER br
	{0x0091,0x0040},	//WIENER hf
	{0x0092,0x1000},	//WIENER lf
	{0x00a0,0x0010},	//LoG neg
	{0x00a1,0x0010},	//LoG pos
	{0x00b2,0x0140},	//DE pe
	{0x00b3,0x0140},	//DE pf
	{0x00b4,0x0140},	//DE pb
	{0x00b5,0x0140},	//DE ne
	{0x00b6,0x0140},	//DE nf
	{0x00b7,0x0140},	//DE nb
	{0x00b8,0x1000},	//DE max ratio
	{0x00b9,0x0010},	//DE min ratio
	{0x00c0,0x1010},	//CS hg ry
	{0x00c1,0x1010},	//CS hg gc
	{0x00c2,0x1010},	//CS hg bm
	{0x00c3,0x1904},	//CS weight grayTH
	{0x0000,0x0001},	//BANK 1
	{0x003f,0x0080},	//CC chsel strength
	{0x0040,0x0000},	//CC lut r  0
	{0x0041,0x0d93},	//CC lut r  16 144
	{0x0042,0x1aa5},	//CC lut r  32 160
	{0x0043,0x29b7},	//CC lut r  48 176
	{0x0044,0x39c8},	//CC lut r  64 192
	{0x0045,0x4bd8},	//CC lut r  80 208
	{0x0046,0x5de6},	//CC lut r  96 224
	{0x0047,0x6ff4},	//CC lut r 112 240
	{0x0048,0x81ff},	//CC lut r 128 255
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet dynamic_ui_cabcoff[] = {
	//start P8 dynamic ui
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0130},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
	{0x00b2,0x0040},	//DE pe
	{0x00b3,0x0040},	//DE pf
	{0x00b4,0x0040},	//DE pb
	{0x00b5,0x0040},	//DE ne
	{0x00b6,0x0040},	//DE nf
	{0x00b7,0x0040},	//DE nb
	{0x00b8,0x1000},	//DE max ratio
	{0x00b9,0x0100},	//DE min ratio
	{0x00c0,0x1010},	//CS hg ry
	{0x00c1,0x1010},	//CS hg gc
	{0x00c2,0x1010},	//CS hg bm
	{0x00c3,0x1804},	//CS weight grayTH
	{0x0000,0x0001},	//BANK 1
	{0x003f,0x0080},	//CC chsel strength
	{0x0040,0x0000},	//CC lut r  0
	{0x0041,0x0d93},	//CC lut r  16 144 
	{0x0042,0x1aa5},	//CC lut r  32 160
	{0x0043,0x29b7},	//CC lut r  48 176
	{0x0044,0x39c8},	//CC lut r  64 192
	{0x0045,0x4bd8},	//CC lut r  80 208
	{0x0046,0x5de6},	//CC lut r  96 224
	{0x0047,0x6ff4},	//CC lut r 112 240
	{0x0048,0x81ff},	//CC lut r 128 255
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet dynamic_gallery_cabcoff[] = {
	//start P8 dynamic gallery
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0130},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2 HDR1
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
	{0x00b2,0x0080},	//DE pe
	{0x00b3,0x0080},	//DE pf
	{0x00b4,0x0080},	//DE pb
	{0x00b5,0x0080},	//DE ne
	{0x00b6,0x0080},	//DE nf
	{0x00b7,0x0080},	//DE nb
	{0x00b8,0x1000},	//DE max ratio
	{0x00b9,0x0100},	//DE min ratio
	{0x00c0,0x1010},	//CS hg ry
	{0x00c1,0x1010},	//CS hg gc
	{0x00c2,0x1010},	//CS hg bm
	{0x00c3,0x1804},	//CS weight grayTH
	{0x0000,0x0001},	//BANK 1
	{0x003f,0x0080},	//CC chsel strength
	{0x0040,0x0000},	//CC lut r  0
	{0x0041,0x0d93},	//CC lut r  16 144 
	{0x0042,0x1aa5},	//CC lut r  32 160
	{0x0043,0x29b7},	//CC lut r  48 176
	{0x0044,0x39c8},	//CC lut r  64 192
	{0x0045,0x4bd8},	//CC lut r  80 208
	{0x0046,0x5de6},	//CC lut r  96 224
	{0x0047,0x6ff4},	//CC lut r 112 240
	{0x0048,0x81ff},	//CC lut r 128 255
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet dynamic_vtcall_cabcoff[] = {
	//start P8 dynamic vtcall
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0132},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
	{0x0080,0x1111},	//NR col con ring bl
	{0x0081,0x3f04},	//NR blRedTH maxmin
	{0x0082,0x1006},	//NR edgeTH blDecTH
	{0x0083,0x3f04},	//NR conRedTH maxmin
	{0x00b2,0x00c0},	//DE pe
	{0x00b3,0x00c0},	//DE pf
	{0x00b4,0x00c0},	//DE pb
	{0x00b5,0x00c0},	//DE ne
	{0x00b6,0x00c0},	//DE nf
	{0x00b7,0x00c0},	//DE nb
	{0x00b8,0x1000},	//DE max ratio
	{0x00b9,0x0010},	//DE min ratio
	{0x00c0,0x1010},	//CS hg ry
	{0x00c1,0x1010},	//CS hg gc
	{0x00c2,0x1010},	//CS hg bm
	{0x00c3,0x1a04},	//CS weight grayTH
	{0x0000,0x0001},	//BANK 1
	{0x003f,0x0080},	//CC chsel strength
	{0x0040,0x0000},	//CC lut r  0
	{0x0041,0x0d93},	//CC lut r  16 144
	{0x0042,0x1aa5},	//CC lut r  32 160
	{0x0043,0x29b7},	//CC lut r  48 176
	{0x0044,0x39c8},	//CC lut r  64 192
	{0x0045,0x4bd8},	//CC lut r  80 208
	{0x0046,0x5de6},	//CC lut r  96 224
	{0x0047,0x6ff4},	//CC lut r 112 240
	{0x0048,0x81ff},	//CC lut r 128 255
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet camera[] = {
	//start P8 camera
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0030},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2 HDR1
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
	{0x00b2,0x0060},	//DE pe
	{0x00b3,0x0060},	//DE pf
	{0x00b4,0x0060},	//DE pb
	{0x00b5,0x0060},	//DE ne
	{0x00b6,0x0060},	//DE nf
	{0x00b7,0x0060},	//DE nb
	{0x00b8,0x1000},	//DE max ratio
	{0x00b9,0x0100},	//DE min ratio
	{0x00c0,0x1010},	//CS hg ry
	{0x00c1,0x1010},	//CS hg gc
	{0x00c2,0x1010},	//CS hg bm
	{0x00c3,0x1204},	//CS weight grayTH
	{0x00ff,0x0000},	//Mask Release
	//end 
};

static const struct Cmc624RegisterSet camera_ove[] = {
//start P8 camera outdoor
{0x0000,0x0000},	//BANK 0
{0x0008,0x0030},	//SCR2 CC1 | CS2 DE1 | LoG8 WIENER4 NR2
{0x0009,0x0000},	//MCM off
{0x000a,0x0001},	//UC
{0x0030,0x0000},	//FA cs1 de8 hdr2 fa1
{0x00b2,0x0060},	//DE pe
{0x00b3,0x0060},	//DE pf
{0x00b4,0x0060},	//DE pb
{0x00b5,0x0060},	//DE ne
{0x00b6,0x0060},	//DE nf
{0x00b7,0x0060},	//DE nb
{0x00b8,0x1000},	//DE max ratio
{0x00b9,0x0100},	//DE min ratio
{0x00c0,0x1010},	//CS hg RY
{0x00c1,0x1010},	//CS hg GC
{0x00c2,0x1010},	//CS hg BM
{0x00c3,0x1204},	//CS weight grayTH
{0x0000,0x0001},	//BANK 1
{0x00e0,0x01a0},	//UC y
{0x00e1,0x01a0},	//UC cs
{0x00ff,0x0000},	//Mask Release
//end
};

static const struct Cmc624RegisterSet cold_ove_cabcoff[] = {
	//start P8 cold outdoor
	{0x0000,0x0000},	//BANK 0
	{0x0009,0x0001},	//MCM
	{0x000a,0x0001},	//UC
	{0x0000,0x0001},	//BANK 1
	{0x0001,0x0064},	//MCM 10000K
	{0x0009,0x8784},	//MCM 5cb 1cr W
	{0x000b,0x7d7d},	//MCM 4cr 5cr W
	{0x000e,0x8080},	//MCM 5cb 1cr K
	{0x0010,0x8080},	//MCM 4cr 5cr K
	{0x00e0,0x01a0},	//UC y
	{0x00e1,0x01a0},	//UC cs
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet cold_cabcoff[] = {
	//start P8 cold
	{0x0000,0x0000},	//BANK 0
	{0x0009,0x0001},	//MCM
	{0x000a,0x0000},	//UC off
	{0x0000,0x0001},	//BANK 1
	{0x0001,0x0064},	//MCM 10000K
	{0x0009,0x8784},	//MCM 5cb 1cr W
	{0x000b,0x7d7d},	//MCM 4cr 5cr W
	{0x000e,0x8080},	//MCM 5cb 1cr K
	{0x0010,0x8080},	//MCM 4cr 5cr K
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet warm_ove_cabcoff[] = {
	//start P8 warm outdoor
	{0x0000,0x0000},	//BANK 0
	{0x0009,0x0001},	//MCM
	{0x000a,0x0001},	//UC
	{0x0000,0x0001},	//BANK 1
	{0x0001,0x0028},	//MCM 4000K
	{0x0007,0x7979},	//MCM 1cb 2cb W
	{0x0009,0x8784},	//MCM 5cb 1cr W
	{0x000c,0x8080},	//MCM 1cb 2cb K
	{0x000e,0x8080},	//MCM 5cb 1cr K
	{0x00e0,0x01a0},	//UC y
	{0x00e1,0x01a0},	//UC cs
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet warm_cabcoff[] = {
	//start P8 warm
	{0x0000,0x0000},	//BANK 0
	{0x0009,0x0001},	//MCM
	{0x000a,0x0000},	//UC off
	{0x0000,0x0001},	//BANK 1
	{0x0001,0x0028},	//MCM 4000K
	{0x0007,0x7979},	//MCM 1cb 2cb W
	{0x0009,0x8784},	//MCM 5cb 1cr W
	{0x000c,0x8080},	//MCM 1cb 2cb K
	{0x000e,0x8080},	//MCM 5cb 1cr K
	{0x00ff,0x0000},	//Mask Release
	//end
};

static const struct Cmc624RegisterSet ove_cabcoff[] = {
	//start P8 outdoor
	{0x0000,0x0000},	//BANK 0
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0001},	//UC
	{0x0000,0x0001},	//BANK 1
	{0x00e0,0x01a0},	//UC y
	{0x00e1,0x01a0},	//UC cs
	{0x00ff,0x0000},	//Mask Release
	//end
};            

static const struct Cmc624RegisterSet cmc624_tune_dmb_test[] = {
	//start P8 dmb test
	{0x0000,0x0000},	//BANK 0
	{0x0008,0x0136},	//CC CS DE
	{0x0009,0x0000},	//MCM off
	{0x000a,0x0000},	//UC off
	{0x0082,0x1005},	//edgeTH BLDecTH
	{0x0083,0x3f00},	//ConRedTH maxmin
	{0x0090,0x0420},	//Wiener Br
	{0x0091,0x0500},	//Wiener hf
	{0x00b2,0x00a0},	//DE pe
	{0x00b3,0x0030},	//DE pf
	{0x00b4,0x0028},	//DE pb
	{0x00b5,0x00a0},	//DE ne
	{0x00b6,0x0030},	//DE nf
	{0x00b7,0x0028},	//DE nb
	{0x00c0,0x1010},	//hg RY
	{0x00c1,0x1010},	//hg GC
	{0x00c2,0x1010},	//hg BM
	{0x00c3,0x1804},	//CS weight grayTH
	{0x0000,0x0001},	//BANK 1
	{0x003f,0x0080},	//CC chsel strength
	{0x0040,0x0000},
	{0x0041,0x1090},	//0x0c96,
	{0x0042,0x20a0},	//0x18a8,
	{0x0043,0x30b0},	//0x2aba,
	{0x0044,0x40c0},	//0x3ccc,
	{0x0045,0x50d0},	//0x4edc,
	{0x0046,0x60e0},	//0x60ea,
	{0x0047,0x70F0},	//0x72f6,
	{0x0048,0x80ff},	//0x84ff,
	{0x00ff,0x0000},	//Mask Release
	//end
};

