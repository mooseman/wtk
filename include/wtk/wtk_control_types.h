
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


#ifndef _WTK_CONTROL_TYPES_H_
#define _WTK_CONTROL_TYPES_H_

#define WTK_CONTROL_TYPE( type ) WTK_CONTROL_TYPE_##type

typedef enum {
    WTK_CONTROL_TYPE_Invalid = 0,
    WTK_CONTROL_TYPE_Base,
    WTK_CONTROL_TYPE_Window,
    WTK_CONTROL_TYPE_Menu,
    WTK_CONTROL_TYPE_MenuItem,
    WTK_CONTROL_TYPE_Label,
    WTK_CONTROL_TYPE_Frame,
    WTK_CONTROL_TYPE_Button,
    WTK_CONTROL_TYPE_CheckBox,
    WTK_CONTROL_TYPE_TextBox,
    WTK_CONTROL_TYPE_ListBox,
    WTK_CONTROL_TYPE_ListView,
    WTK_CONTROL_TYPE_ComboBox,
    WTK_CONTROL_TYPE_COUNT
} wtk_control_type;

#endif // _WTK_CONTROL_TYPES_H_
