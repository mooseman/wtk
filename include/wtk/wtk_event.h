
// This is free and unencumbered software released into the public domain.  

// Anyone is free to copy, modify, publish, use, compile, sell, or           
// distribute this software, either in source code form or as a compiled    
// binary, for any purpose, commercial or non-commercial, and by any        
// means.                                                                   

// In jurisdictions that recognize copyright laws, the author or authors    
// of this software dedicate any and all copyright interest in the           
// software to the public domain. We make this dedication for the benefit    
// of the public at large and to the detriment of our heirs and              
// successors. We intend this dedication to be an overt act of               
// relinquishment in perpetuity of all present and future rights to this     
// software under copyright law.                                             

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,          
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF        
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.    
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR         
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,      
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR     
// OTHER DEALINGS IN THE SOFTWARE.                                           

// For more information, please refer to <http://unlicense.org/>    

// Author: Michael Williams (mtwilliams)           


#ifndef _WTK_EVENT_H_
#define _WTK_EVENT_H_

#include <wtk/wtk_config.h>
#include <wtk/wtk_compat.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct wtk_control;

#define WTK_EVENT( event ) WTK_EVENT_##event
typedef enum {
    WTK_EVENT_Invalid = 0,
    WTK_EVENT_OnCreate,
    WTK_EVENT_OnDestroy,
    WTK_EVENT_OnLayoutChanged,
    WTK_EVENT_OnClose,
    WTK_EVENT_OnPaint,
    WTK_EVENT_OnValueChanged,
    WTK_EVENT_OnSelectionChanged,
    WTK_EVENT_OnPressed,
    WTK_EVENT_OnReleased,
    WTK_EVENT_OnClicked,
    WTK_EVENT_OnMouseMoved,
    WTK_EVENT_OnMouseScrolled,
    WTK_EVENT_OnKeyPressed,
    WTK_EVENT_OnKeyReleased,
    WTK_EVENT_OnMinimized,
    WTK_EVENT_OnMaximized,
    WTK_EVENT_OnResized,
    WTK_EVENT_COUNT
} wtk_event;

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // _WTK_EVENT_H_
