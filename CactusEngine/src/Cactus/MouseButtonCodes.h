#pragma once

// --------------------From glfw3.h--------------------

/*! @} */

/*! @defgroup mods Modifier key flags
 *
 *  See [key input](@ref input_key) for how these are used.
 *
 *  @ingroup input
 *  @{ */

/*! @brief If this bit is set one or more Shift keys were held down.
 */
#define CC_MOD_SHIFT           0x0001
/*! @brief If this bit is set one or more Control keys were held down.
 */
#define CC_MOD_CONTROL         0x0002
/*! @brief If this bit is set one or more Alt keys were held down.
 */
#define CC_MOD_ALT             0x0004
/*! @brief If this bit is set one or more Super keys were held down.
 */
#define CC_MOD_SUPER           0x0008

/*! @} */

/*! @defgroup buttons Mouse buttons
 *
 *  See [mouse button input](@ref input_mouse_button) for how these are used.
 *
 *  @ingroup input
 *  @{ */
#define CC_MOUSE_BUTTON_1         0
#define CC_MOUSE_BUTTON_2         1
#define CC_MOUSE_BUTTON_3         2
#define CC_MOUSE_BUTTON_4         3
#define CC_MOUSE_BUTTON_5         4
#define CC_MOUSE_BUTTON_6         5
#define CC_MOUSE_BUTTON_7         6
#define CC_MOUSE_BUTTON_8         7
#define CC_MOUSE_BUTTON_LAST      CC_MOUSE_BUTTON_8
#define CC_MOUSE_BUTTON_LEFT      CC_MOUSE_BUTTON_1
#define CC_MOUSE_BUTTON_RIGHT     CC_MOUSE_BUTTON_2
#define CC_MOUSE_BUTTON_MIDDLE    CC_MOUSE_BUTTON_3
/*! @} */