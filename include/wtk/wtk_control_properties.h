
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


#ifndef _WTK_CONTROL_PROPERTIES_H_
#define _WTK_CONTROL_PROPERTIES_H_

#define WTK_CONTROL_PROP( property ) WTK_CONTROL_PROP_##property
typedef enum {
    WTK_CONTROL_PROP_Invalid = 0,
    WTK_CONTROL_PROP_UserPtr,
    WTK_CONTROL_PROP_Parent,
    WTK_CONTROL_PROP_Hidden,
    WTK_CONTROL_PROP_AutoFill,
    WTK_CONTROL_PROP_Resizable,
    WTK_CONTROL_PROP_Position,
    WTK_CONTROL_PROP_Size,
    WTK_CONTROL_PROP_Margins,
    WTK_CONTROL_PROP_Font,
    WTK_CONTROL_PROP_Icon,
    WTK_CONTROL_PROP_Icons,
    WTK_CONTROL_PROP_Title,
    WTK_CONTROL_PROP_Menu,
    WTK_CONTROL_PROP_Text,
    WTK_CONTROL_PROP_TextAlign,
    WTK_CONTROL_PROP_Value,
    WTK_CONTROL_PROP_Column,
    WTK_CONTROL_PROP_ImageList,
    WTK_CONTROL_PROP_COUNT
} wtk_control_property;

#endif // _WTK_CONTROL_PROPERTIES_H_
