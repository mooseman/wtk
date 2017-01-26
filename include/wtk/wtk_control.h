
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


#ifndef _WTK_CONTROL_H_
#define _WTK_CONTROL_H_

#include <wtk/wtk_config.h>
#include <wtk/wtk_compat.h>
#include <wtk/wtk_event.h>
#include <wtk/wtk_control_types.h>
#include <wtk/wtk_control_properties.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct wtk_control;
typedef struct wtk_control wtk_control;

extern WTK_EXPORT struct wtk_control* WTK_API wtk_control_create( int x, int y, unsigned int width, unsigned int height, struct wtk_control* parent );
extern WTK_EXPORT void WTK_API wtk_control_destroy( struct wtk_control* control );

typedef void* wtk_property;

extern WTK_EXPORT void WTK_API wtk_control_get_property( struct wtk_control* control, wtk_control_property property, ... );
extern WTK_EXPORT void WTK_API wtk_control_set_property( struct wtk_control* control, wtk_control_property property, ... );

typedef int wtk_child;

extern WTK_EXPORT void WTK_API wtk_control_get_child_property( struct wtk_control* control, wtk_control_property property, wtk_child child, ... );
extern WTK_EXPORT void WTK_API wtk_control_set_child_property( struct wtk_control* control, wtk_control_property property, wtk_child child, ... );

typedef void* wtk_event_callback;

extern WTK_EXPORT void WTK_API wtk_control_set_callback( struct wtk_control* control, wtk_event event, wtk_event_callback callback );

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // _WTK_CONTROL_H_
