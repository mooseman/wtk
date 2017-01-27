
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


#include "_wtk_controls.h"
#include "_wtk_layout.h"

void WTK_API wtk_on_layout_changed( struct wtk_control* control )
{
    WTK_ASSERT(control);

    if( control->auto_fill && control->type != WTK_CONTROL_TYPE(Window) ) {
        struct wtk_control* parent_control;
        int parent_width, parent_height;

        wtk_control_get_property(control, WTK_CONTROL_PROP(Parent), &parent_control);
        if( !parent_control ) return;

        // TODO: Take into account menu on windows?

        wtk_control_get_property(parent_control, WTK_CONTROL_PROP(Size), &parent_width, &parent_height);
        wtk_control_set_property(control, WTK_CONTROL_PROP(Position), control->margin_left, control->margin_top);
        wtk_control_set_property(control, WTK_CONTROL_PROP(Size), parent_width - control->margin_right - control->margin_left, parent_height - control->margin_bottom - control->margin_top);
    }
}
