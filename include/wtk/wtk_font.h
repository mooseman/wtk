
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


#ifndef _WTK_FONT_H_
#define _WTK_FONT_H_

#include <wtk/wtk_config.h>
#include <wtk/wtk_compat.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct wtk_font;
typedef struct wtk_font wtk_font;

typedef enum wtk_font_style {
    WTK_FONT_STYLE_DEFAULT   = 0,
    WTK_FONT_STYLE_BOLD      = (1 << 0),
    WTK_FONT_STYLE_UNDERLINE = (1 << 1),
    WTK_FONT_STYLE_ITALIC    = (1 << 2),
    WTK_FONT_STYLE_STRIKEOUT = (1 << 3)
} wtk_font_style;

extern WTK_EXPORT struct wtk_font* WTK_API wtk_font_create( const char* font_family, unsigned int font_size, unsigned int font_style );
extern WTK_EXPORT struct wtk_font* WTK_API wtk_font_default();
extern WTK_EXPORT void WTK_API wtk_font_destroy( struct wtk_font* font );

extern WTK_EXPORT void wtk_font_set_user_ptr( struct wtk_font* font, void* user_ptr );
extern WTK_EXPORT void* wtk_font_get_user_ptr( struct wtk_font* font );

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // _WTK_FONT_H_
