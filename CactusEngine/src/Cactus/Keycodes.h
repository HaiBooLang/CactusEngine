#pragma once

// --------------------From glfw3.h--------------------

/* The unknown key */
#define CC_KEY_UNKNOWN            -1

/* Printable keys */
#define CC_KEY_SPACE              32
#define CC_KEY_APOSTROPHE         39  /* ' */
#define CC_KEY_COMMA              44  /* , */
#define CC_KEY_MINUS              45  /* - */
#define CC_KEY_PERIOD             46  /* . */
#define CC_KEY_SLASH              47  /* / */
#define CC_KEY_0                  48
#define CC_KEY_1                  49
#define CC_KEY_2                  50
#define CC_KEY_3                  51
#define CC_KEY_4                  52
#define CC_KEY_5                  53
#define CC_KEY_6                  54
#define CC_KEY_7                  55
#define CC_KEY_8                  56
#define CC_KEY_9                  57
#define CC_KEY_SEMICOLON          59  /* ; */
#define CC_KEY_EQUAL              61  /* = */
#define CC_KEY_A                  65
#define CC_KEY_B                  66
#define CC_KEY_C                  67
#define CC_KEY_D                  68
#define CC_KEY_E                  69
#define CC_KEY_F                  70
#define CC_KEY_G                  71
#define CC_KEY_H                  72
#define CC_KEY_I                  73
#define CC_KEY_J                  74
#define CC_KEY_K                  75
#define CC_KEY_L                  76
#define CC_KEY_M                  77
#define CC_KEY_N                  78
#define CC_KEY_O                  79
#define CC_KEY_P                  80
#define CC_KEY_Q                  81
#define CC_KEY_R                  82
#define CC_KEY_S                  83
#define CC_KEY_T                  84
#define CC_KEY_U                  85
#define CC_KEY_V                  86
#define CC_KEY_W                  87
#define CC_KEY_X                  88
#define CC_KEY_Y                  89
#define CC_KEY_Z                  90
#define CC_KEY_LEFT_BRACKET       91  /* [ */
#define CC_KEY_BACKSLASH          92  /* \ */
#define CC_KEY_RIGHT_BRACKET      93  /* ] */
#define CC_KEY_GRAVE_ACCENT       96  /* ` */
#define CC_KEY_WORLD_1            161 /* non-US #1 */
#define CC_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define CC_KEY_ESCAPE             256
#define CC_KEY_ENTER              257
#define CC_KEY_TAB                258
#define CC_KEY_BACKSPACE          259
#define CC_KEY_INSERT             260
#define CC_KEY_DELETE             261
#define CC_KEY_RIGHT              262
#define CC_KEY_LEFT               263
#define CC_KEY_DOWN               264
#define CC_KEY_UP                 265
#define CC_KEY_PAGE_UP            266
#define CC_KEY_PAGE_DOWN          267
#define CC_KEY_HOME               268
#define CC_KEY_END                269
#define CC_KEY_CAPS_LOCK          280
#define CC_KEY_SCROLL_LOCK        281
#define CC_KEY_NUM_LOCK           282
#define CC_KEY_PRINT_SCREEN       283
#define CC_KEY_PAUSE              284
#define CC_KEY_F1                 290
#define CC_KEY_F2                 291
#define CC_KEY_F3                 292
#define CC_KEY_F4                 293
#define CC_KEY_F5                 294
#define CC_KEY_F6                 295
#define CC_KEY_F7                 296
#define CC_KEY_F8                 297
#define CC_KEY_F9                 298
#define CC_KEY_F10                299
#define CC_KEY_F11                300
#define CC_KEY_F12                301
#define CC_KEY_F13                302
#define CC_KEY_F14                303
#define CC_KEY_F15                304
#define CC_KEY_F16                305
#define CC_KEY_F17                306
#define CC_KEY_F18                307
#define CC_KEY_F19                308
#define CC_KEY_F20                309
#define CC_KEY_F21                310
#define CC_KEY_F22                311
#define CC_KEY_F23                312
#define CC_KEY_F24                313
#define CC_KEY_F25                314
#define CC_KEY_KP_0               320
#define CC_KEY_KP_1               321
#define CC_KEY_KP_2               322
#define CC_KEY_KP_3               323
#define CC_KEY_KP_4               324
#define CC_KEY_KP_5               325
#define CC_KEY_KP_6               326
#define CC_KEY_KP_7               327
#define CC_KEY_KP_8               328
#define CC_KEY_KP_9               329
#define CC_KEY_KP_DECIMAL         330
#define CC_KEY_KP_DIVIDE          331
#define CC_KEY_KP_MULTIPLY        332
#define CC_KEY_KP_SUBTRACT        333
#define CC_KEY_KP_ADD             334
#define CC_KEY_KP_ENTER           335
#define CC_KEY_KP_EQUAL           336
#define CC_KEY_LEFT_SHIFT         340
#define CC_KEY_LEFT_CONTROL       341
#define CC_KEY_LEFT_ALT           342
#define CC_KEY_LEFT_SUPER         343
#define CC_KEY_RIGHT_SHIFT        344
#define CC_KEY_RIGHT_CONTROL      345
#define CC_KEY_RIGHT_ALT          346
#define CC_KEY_RIGHT_SUPER        347
#define CC_KEY_MENU               348

#define CC_KEY_LAST               CC_KEY_MENU